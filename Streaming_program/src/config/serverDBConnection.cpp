#include "../../include/config/serverDBConnection.h"

using namespace std;

ServerDBConnection::ServerDBConnection(){
    try{
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
    cout << setfill('*') << setw(80) << "Conectado à plataforma MariaDB! RDMS em " + serverIP + ":" + serverPort + "/" + serverDatabase << endl;
}

ServerDBConnection::~ServerDBConnection()
	{
	this->connection->close();
	}

sql::Connection* ServerDBConnection::getConnection() const
	{
	return (this->connection);
	}

