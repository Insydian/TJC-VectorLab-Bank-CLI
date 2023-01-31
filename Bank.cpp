#include <iostream>
#include "BankAccount.h"
#include "MyVector.h"
#include "Person.h"
using namespace std;

int addBankAccount(BankAccount account1);
int addPerson(Person client);
int addClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people);
// Code By Caleb LaRue
// Bank is designed as the interface between BankAccounts and people
MyVector<BankAccount> bankAccounts;
MyVector<Person> clients;
int main (int argc, char *argv[])
{
    BankAccount b1;
    addBankAccount(b1);
    Person p1;
    p1.setName("Caleb LaRue");
    p1.setAge(18);
    p1.setCreditScore(700);
    addPerson(p1);
    cout << clients.getElementAt(0).getName() << endl;
    return 0;
}
int addBankAccount(BankAccount account1)
{
    const BankAccount constAccount = account1;
    
    bankAccounts.pushBack(constAccount);
    int size = bankAccounts.getSize();
    return size;
}
//TODO: the person needs to be established before entering this class. I have a default constructor but I need to add Name etc...
int addPerson(Person client)
{
    const Person constClient = client;
    clients.pushBack(constClient);
    int size = clients.getSize();
    return size;
}

int addClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people)
{
    return 0;
}
