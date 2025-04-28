#include "../../include/view/registerServerDAO.h"

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

const string registerServerDAO::SQL_getAllRegisters = "SELECT * FROM registros";

const string registerServerDAO::SQL_getRegisterById = "SELECT * FROM registros WHERE id = ?";

const string registerServerDAO::SQL_addRegister = "INSERT INTO registros (nome, ano_de_lancamento,temporadas, episodios, elenco_principal, personagens_principais, servico_de_streaming, nota) "
                                                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

const string registerServerDAO::SQL_deleteRegister = "DELETE FROM registros WHERE id = ?";

const string registerServerDAO::SQL_editRegister = "UPDATE registros SET nome = ?, ano_de_lancamento = ?,temporadas = ?, episodios = ?, elenco_principal = ?, personagens_principais = ?, servico_de_streaming = ?, nota = ? "
                                                     "WHERE id = ?";

registerServerDAO::registerServerDAO(ServerDBConnection* serverDBConnection):
    serverDBConnection(serverDBConnection){};

registerServerDAO::~registerServerDAO(){};

vector<Register*> registerServerDAO::getAllRegisters(){
    vector<Register*> registersDAO;
    try{
        unique_ptr<sql::Statement> stmnt(serverDBConnection->getConnection()->createStatement());
		sql::ResultSet *res = stmnt->executeQuery(SQL_getAllRegisters);

        while (res->next()){
            int registerId = res->getInt(1);
            string registerName = (res->getString(2)).c_str();
            int registerReleaseYear = res->getInt(3);
            int registerNumOfSeasons = res->getInt(4);
            int registerEpisodesTotal = res->getInt(5);
            string registerMainPlot = (res->getString(6)).c_str();
            string registerMainCharacters = (res->getString(7)).c_str();
            string registerStreaming = (res->getString(8)).c_str();
            float registerScore = res->getFloat(9);

            Register* buffer = new Register(registerId, registerName, registerReleaseYear, registerNumOfSeasons, registerEpisodesTotal, 
                                    registerMainPlot, registerMainCharacters, registerStreaming, registerScore);
            
            registersDAO.push_back(buffer);
        }
    }
    catch (const sql::SQLException &myError){
        cout << "Erro selecionando registros: " << myError.what() << endl;
    }

    return (registersDAO);
}


Register* registerServerDAO::getRegisterById(int registerId){
    Register *buffer = NULL;
    try{
        unique_ptr<sql::PreparedStatement> stmnt(serverDBConnection->getConnection()->prepareStatement(SQL_getRegisterById));
		stmnt->setInt(1, registerId);
		sql::ResultSet *res = stmnt->executeQuery();

        if (res->next()){
            int registerId = res->getInt(1);
            string registerName = (res->getString(2)).c_str();
            int registerReleaseYear = res->getInt(3);
            int registerNumOfSeasons = res->getInt(4);
            int registerEpisodesTotal = res->getInt(5);
            string registerMainPlot = (res->getString(6)).c_str();
            string registerMainCharacters = (res->getString(7)).c_str();
            string registerStreaming = (res->getString(8)).c_str();
            float registerScore = res->getFloat(9);

            buffer = new Register(registerId, registerName, registerReleaseYear, registerNumOfSeasons, registerEpisodesTotal, 
                                registerMainPlot, registerMainCharacters, registerStreaming, registerScore);
        }
    }
    catch (const sql::SQLException &myError){
        cerr << "Erro selecionando registros: " << myError.what() << endl;
    }

    return buffer;
}

void registerServerDAO::addRegister(Register *Register){
    try{
        unique_ptr<sql::PreparedStatement> stmnt(serverDBConnection->getConnection()->prepareStatement(SQL_addRegister));
        stmnt->setString(1, Register->getRegisterName());
        stmnt->setInt(2, Register->getRegisterReleaseYear());
        stmnt->setInt(3, Register->getRegisterNumOfSeasons());
        stmnt->setInt(4, Register->getRegisterEpisodesTotal());
        stmnt->setString(5, Register->getRegisterMainPlot());
        stmnt->setString(6, Register->getRegisterMainCharacters());
        stmnt->setString(7, Register->getRegisterStreaming());
        stmnt->setFloat(8, Register->getRegisterScore());
        stmnt->executeQuery();
    }
    catch(const sql::SQLException &myError){
        cerr << "Erro ao adicionar um registro no MariaDB: " << myError.what() << endl;
    }
}

void registerServerDAO::deleteRegister(int registerId){
   try{
        lastDeleted = getRegisterById(registerId);

        unique_ptr<sql::PreparedStatement> stmnt(serverDBConnection->getConnection()->prepareStatement(SQL_deleteRegister));
        stmnt->setInt(1, registerId);
        stmnt->executeQuery(); 
   } 
   catch(const sql::SQLException &myError){
        cerr << "Erro ao apagar um registro no MariaDB: " << myError.what() << endl;
   }
}

void registerServerDAO::editRegister(Register *oldRegister, string RegisterName, int releaseYear, int NumOfSeasons,
                                    int episodesTotal, string mainPlot, string mainCharacters, string streaming, 
                                    float score){
        try{
            unique_ptr<sql::PreparedStatement> stmnt(serverDBConnection->getConnection()->prepareStatement(SQL_editRegister));
            stmnt->setString(1, ((RegisterName.empty()) ? oldRegister->getRegisterName() : RegisterName));
            stmnt->setInt(2, ((!releaseYear) ? oldRegister->getRegisterReleaseYear() : releaseYear));
            stmnt->setInt(3, ((!NumOfSeasons) ? oldRegister->getRegisterNumOfSeasons() : NumOfSeasons));
            stmnt->setInt(4,((!episodesTotal) ? oldRegister->getRegisterEpisodesTotal() : episodesTotal));
            stmnt->setString(5, (mainPlot.empty() ? oldRegister->getRegisterMainPlot() : mainPlot));
            stmnt->setString(6, (mainCharacters.empty() ? oldRegister->getRegisterMainCharacters() : RegisterName));
            stmnt->setString(7, (streaming.empty() ? oldRegister->getRegisterStreaming() : streaming));
            stmnt->setFloat(8, (!score ? oldRegister->getRegisterScore() : score));
        }                                    
        catch(const sql::SQLException &myError){
            cerr << "Erro ao editar um arquivo no MariaDB: " << myError.what() << endl;
        }
    }

void registerServerDAO::recoverRegister(){
    addRegister(lastDeleted);
    lastDeleted = NULL;
}

Register* registerServerDAO::getLastDeleted(){
    return lastDeleted;
}

DatabaseType registerServerDAO::getDatabaseType(){
    return DatabaseType::MARIADB;
}

