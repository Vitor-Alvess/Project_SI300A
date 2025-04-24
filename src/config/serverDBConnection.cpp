#include "../../include/config/serverDBConnection.h"

using namespace std;

ServerDBConnection::ServerDBConnection(){
    try{
		loadEnv("../.env");
	    this->driver = sql::mariadb::get_driver_instance();
        string connString = "jdbc:mariadb://" + serverIP + ":" + serverPort + "/" + serverDatabase;
		sql::SQLString url(connString);
        sql::Properties properties(
			{
				{ "user", this->serverUser },
				{ "password", this->serverPassword } });

		this->connection = driver->connect(url, properties);
    }
    catch(sql::SQLException &myException){
        cerr << "Erro. Conexão com o servivor não estabelecida: " << myException.what() << endl;
        exit (1);
    }

	migrations(this->connection);

    cout << "--> Conectado à plataforma MariaDB! RDMS em " + serverIP + ":" + serverPort + "/" + serverDatabase << endl;
	Utils::sleepFunc(5);
}

ServerDBConnection::~ServerDBConnection()
	{
	this->connection->close();
	}

sql::Connection* ServerDBConnection::getConnection() const
	{
	return (this->connection);
	}


void ServerDBConnection::loadEnv(const string path){
	ifstream file(path);
	if (!file.is_open()){
		cerr << "Erro ao abrir o arquivo de configuração: " << path << endl;
		exit(1);
	}
	string line;
	while (getline(file, line)){
		if (line.find("portDB") != string::npos){
			serverPort = line.substr(line.find("=") + 1);
		}
		else if (line.find("hostDB") != string::npos){
			serverIP = line.substr(line.find("=") + 1);
		}
		else if (line.find("userDB") != string::npos){
			serverUser = line.substr(line.find("=") + 1);
		}
		else if (line.find("passwordDB") != string::npos){
			serverPassword = line.substr(line.find("=") + 1);
		}
		else if (line.find("nameDB") != string::npos){
			serverDatabase = line.substr(line.find("=") + 1);
		}
	}
	file.close();
}

void ServerDBConnection::migrations(sql::Connection *conn){
	try{
		ifstream file("../src/resources/db/migrations/V1.0__databaseStructure.sql");
		if (!file.is_open()){
			throw runtime_error("Erro ao abrir o arquivo de migração: V1.0__databaseStructure.sql");
		}

		sql::Statement *stmt = conn->createStatement();

		string finalQuery;
		string line;

		while(getline(file, line)) finalQuery += line + "\n";
		file.close();

		stmt -> execute(finalQuery);
		cout << "--> Migrations aplicadas com sucesso!" << endl;

		delete stmt;
	}
	catch(exception &myException){
		cerr << "Erro ao aplicar as migrations: " << myException.what() << endl;
		exit (1);
	}
}
