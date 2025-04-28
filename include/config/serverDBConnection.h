#include "utils.h"

#include <mariadb/conncpp.hpp>

#ifndef SERVERDBCONNECTION_H_
#define SERVERDBCONNECTION_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

class ServerDBConnection{
    private:
        std::string serverPort = "3306";
		std::string serverIP = "localhost";
		std::string serverDatabase = "Si300A2024_07";
		std::string serverUser = "root";
		std::string serverPassword = "MySqlPass2";

        sql::Driver *driver = NULL;
        sql::Connection *connection = NULL;

    public:
        ServerDBConnection();
        virtual ~ServerDBConnection();
        sql::Connection* getConnection() const;
        void loadEnv(const std::string path);
        void migrations(sql::Connection *conn);
};

#endif



