#include <mariadb/conncpp.hpp>

#ifndef SERVERDBCONNECTION_H_
#define SERVERDBCONNECTION_H_

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class ServerDBConnection{
    private:
        string serverPort = "3306";
		string serverIP = "143.106.243.64";
		string serverDatabase = "Si300A2024_07";
		string serverUser = "Si300A2024_07";
		string serverPassword = "56SaOaoAjM";

        sql::Driver *driver = NULL;
        sql::Connection *connection = NULL;

    public:
        ServerDBConnection();
        virtual ~ServerDBConnection();
        sql::Connection* getConnection() const;

};

#endif



