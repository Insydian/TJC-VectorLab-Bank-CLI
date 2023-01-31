#include <iostream>
#include <string>
#include "BankAccount.h"
#include "MyVector.h"
#include "Person.h"
using namespace std;

#define MAX_NAME_LEN 60  // Maximum len of your name can't be more than 60

int addBankAccount(BankAccount account1);
int addPerson(Person client);
int addClient(string name, int age, int creditScore);
string convertToString(char* a);
void option1();
// Code By Caleb LaRue
// Bank is designed as the interface between BankAccounts and people
MyVector<BankAccount> bankAccounts;
MyVector<Person> clients;
int main (int argc, char *argv[])
{
    cout << "Welcome to the TJC Bank" << endl;
    cout << "Please choose one of the following:" << endl;
    cout << "[1] New Client" << endl;
    cout << "[2] Bank Operations" << endl;
    int option;
    cin >> option;
    if(option == 1)
    {
        option1();
        std::cout << "Thank you for banking with TJC Bank" << std::endl;
    }
    else if(option == 2)
        cout << "Option 2" << endl;
    return 0;
}
int addBankAccount(BankAccount account1)
{
    const BankAccount constAccount = account1;
    
    bankAccounts.pushBack(constAccount);
    int size = bankAccounts.getSize();
    return size;
}
int addPerson(Person client)
{
    const Person constClient = client;
    clients.pushBack(constClient);
    int size = clients.getSize();
    return size;
}

int addClient(string name, int age, int creditScore)
{
    Person newClient;
    newClient.setName(name);
    newClient.setAge(age);
    newClient.setCreditScore(creditScore);
    
    // Create a new Bank account 
    BankAccount newBankAccount;

    // add to both Arrays
    int bankAccountSize = addBankAccount(newBankAccount);
    int clientSize = addPerson(newClient);

    if(bankAccountSize >= clientSize)
    {
        return bankAccountSize;
    }
    else {
        return clientSize;
    }
}
void option1()
{
        string firstName;
        string lastName;
        int age;
        int creditScore;
        int option;
        cout << "Thank you for choosing TJC Bank" << endl;
        cout << "Please enter your first name" << endl;
     //   cin.getline(c_name,MAX_NAME_LEN);
        cin >> firstName;
        cout << "Please enter your last name" << endl;
        cin >> lastName;
        cout << "Please enter your age" << endl;
        cin >> age;
        cout << "Please enter your credit score" << endl;
        cin >> creditScore;

        cout << "You entered the following:" <<"\n" << "Name: "<< firstName << " " << lastName << ", Age: " << age << ", Credit Score: " << creditScore << endl;
        cout << "\n" << "\n";
        cout << "Is this Correct?" << endl;
        cout << "[1] Yes" << endl;
        cout << "[2] No" << endl;
        cout << "[3] EXIT" << endl;
        cin >> option;

        if(option == 3)
        {return;}
        else if(option == 1)
        {
            string fullName = firstName + lastName;
            addClient(fullName, age, creditScore);
            return;
        }
        else
         option1();
}
string convertToString(char* a)
{
    string s(a);
    return s;
}
