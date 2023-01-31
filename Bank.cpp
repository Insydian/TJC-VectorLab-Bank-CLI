#include <iostream>
#include "BankAccount.h"
#include "MyVector.h"
#include "Person.h"
using namespace std;

int AddBankAccount(MyVector<BankAccount> bankAccounts);
int AddPerson(MyVector<Person> people);
int AddClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people);
/// Code By Caleb LaRue
/// Bank is designed as the interface between BankAccounts and people
int main (int argc, char *argv[])
{
    MyVector<BankAccount> bankAccounts;
    MyVector<Person> clients;
    return 0;
}
int AddBankAccount(MyVector<BankAccount> bankAccounts, BankAccount account1)
{
    int capacity = bankAccounts.getCapacity();
    int size = bankAccounts.getSize();

    
    return 0;
}

int AddPerson(MyVector<Person> people)
{
    return 0;
}

int AddClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people)
{
    return 0;
}
