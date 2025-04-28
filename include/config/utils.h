#ifndef UTILS_H_
#define UTILS_H_

#include<iostream>
#include<iomanip>
#include<vector>
#include <chrono>
#include<unistd.h>


#include "../model/register.h"

#ifdef WIN32
#define IS_WINDOWS 1
#elif _WIN32
#define IS_WINDOWS 1
#else
#define IS_WINDOWS 0
#endif

#define WIDTH 50

#define SYMBOL "*"

class Utils{
    public:
        static void functionToSwap(int i, std::vector<Register*> &list);
        static void listHeader();
        static void printList(std::vector<Register*> &list);
        static void sleepFunc(unsigned int seconds);
        static void bye();
        static void init();
        static void clear();
        static void pause();
        static void printStatus(std::string status);
};

#endif