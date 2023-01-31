#pragma once
#include "MyVector.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include <string>
using namespace std; 
/* Code by Caleb LaRue
 * Bank account is a class that defines a bank account and 
 * methods to act on the bank account such as withdraw or deposit
 * */ 
class BankAccount
{
    string bankAccountNumber;
    double balance;

    public:

    enum BankAccountType {
        SavingsAccount,
        CheckingAccount,
    };
    /// Purpose: method to generate randomString of Numbers
    /// input: int number of digits zero based
    /// output is psuedo random random String of numbers with specified digits
    string rng(int NumOfDigits)
    {
        string randomString;
        srand(time(0));
        for(int i = 0; i < NumOfDigits; ++i)
        {
            randomString.append(to_string(rand() % 10));
        }

        
        return randomString;
    }
        BankAccount()
        {
           std::cout << "Constructor for BankAccount is called" << std::endl; 
           
            bankAccountNumber = rng(10);
            balance = 0;

        }
        BankAccount(double aBalance)
        {
            this->balance =  aBalance;
            bankAccountNumber = rng(10);
        }
        
    /// Purpose: Method to add money into an account
    /// input a double
    /// output: none
        void deposit(double amount)
        {
            double newBalance = balance + amount;
            balance = newBalance;
            cout << "Deposited" << amount << endl;
        } 
    /// Purpose: Method to subtract from account
    /// input: a double
    /// error: if amount to withdraw exceeds bank account balance
    /// output: boolean

        void withdraw(double amount)
        {
            assert(amount <= balance);

            balance -= amount;
            std::cout << "Withdrew " << amount << std::endl;
        }
        
        string getBankAccountNumber()
        {
            return bankAccountNumber;
        }

        double getBalance()
        {
            return balance;
        }


};
