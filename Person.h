#pragma once

#include <cstdlib>
#include <iostream>
using namespace std;
///Code by Caleb LaRue
///Created to be used in Bank.cpp
class Person
{
    string name;
    int age;
    int creditScore;
    public:
        Person(string name, int age, int creditScore)
        {
            this->name = name;
            this->age = age;
            this->creditScore = creditScore;
        }
        Person()
        {
            this->name = " ";
            this->age = -1;
            this->creditScore = -1;
        }
        bool isLoanable()
        {
            if(creditScore > 650)
            {
                return true;
            }
            else {
                return false;
            }
        }
        void setName(string name) { this->name = name;  }
        string getName(){return name;}
        void setAge(int age){   this->age = age;    }
        int getAge(){   return age; }
        void setCreditScore(int creditScore) { this->creditScore = creditScore;}
        int getCreditScore() { return creditScore;   }
};

