#include "utils.h"

#include <mariadb/conncpp.hpp>

#ifndef SERVERDBCONNECTION_H_
#define SERVERDBCONNECTION_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ServerDBConnection{
    private:
        string serverPort = "3306";
		string serverIP = "localhost";
		string serverDatabase = "Si300A2024_07";
		string serverUser = "root";
		string serverPassword = "MySqlPass2";

        sql::Driver *driver = NULL;
        sql::Connection *connection = NULL;

    public:
        ServerDBConnection();
        virtual ~ServerDBConnection();
        sql::Connection* getConnection() const;
        void loadEnv(const string path);
        void migrations(sql::Connection *conn);
};

#endif



