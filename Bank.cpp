#include <iostream>
#include "BankAccount.h"
#include "MyVector.h"
#include "Person.h"
using namespace std;

int addBankAccount(BankAccount account1);
int addPerson(MyVector<Person> people);
int addClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people);
/// Code By Caleb LaRue
/// Bank is designed as the interface between BankAccounts and people
MyVector<BankAccount> bankAccounts;
MyVector<Person> clients;
int main (int argc, char *argv[])
{
    BankAccount b1;
    addBankAccount(b1);
    cout << "back in main" << endl;
    cout << " testing AccountNumber" << bankAccounts.getElementAt(0).getBankAccountNumber() << endl;
    for(int i = 0; i < bankAccounts.getSize(); ++i)
    {
        cout << bankAccounts.getElementAt(i).getBankAccountNumber() << endl;
    }
    
    return 0;
}
int addBankAccount(BankAccount account1)
{
    const BankAccount constAccount = account1;
    int capacity = bankAccounts.getCapacity();
    int size = bankAccounts.getSize();
    
    bankAccounts.pushBack(constAccount);
    cout << "It worked" <<endl; 
    return 0;
}

int addPerson(MyVector<Person> people)
{
    return 0;
}

int addClient(MyVector<BankAccount> bankAccounts, MyVector<Person> people)
{
    return 0;
}
