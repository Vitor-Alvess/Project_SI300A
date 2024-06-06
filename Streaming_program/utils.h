#ifndef UTILS_H_
#define UTILS_H_

#include<iostream>
#include<iomanip>
#include "registerMemDAO.h"
using namespace std;

#define WIDTH 50

#define SYMBOL "*"

class utils{
    public:
        static void functionToSwap(int i, vector<Register*> &list);
        static void printList(vector<Register*> &list);
};

#endif