#include <iostream>
#include <string>
#include "BankAccount.h"
#include "MyVector.h"
#include <cctype>
#include "Person.h"
using namespace std;

#define MAX_NAME_LEN 60  // Maximum len of your name can't be more than 60

int addBankAccount(BankAccount account1);
int addPerson(Person client);
int addClient(string name, int age, int creditScore);
string convertToString(char* a);
void option1();
void option2();
void option2TextInterface(int position);
int findPosition(string firstName);
// Code By Caleb LaRue
// Bank is designed as the interface between BankAccounts and people
MyVector<BankAccount> bankAccounts;
MyVector<Person> clients;
int main ()
{
    cout << "Welcome to the TJC Bank" << endl;
    cout << "Please choose one of the following:" << endl;
    cout << "[1] New Client" << endl;
    cout << "[2] Bank Operations" << endl;
    cout << "[3] Exit" << endl;
    int option;
    cin >> option;
    if(option == 1)
    {
        option1();
        std::cout << "Thank you for banking with TJC Bank" << std::endl;
        main();
    }
    else if(option == 2)
    {
        cout << "Option 2" << endl;
        option2();
    }
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
void option2()
{
    int position;
    string firstName;
    cout << "Please enter you first name" << endl;
    cin >> firstName;
    position = findPosition(firstName);
    if(position < 0)
    {
        cout << "We are sorry we did not find that name"<< endl;
        return;
    }

}
void option2TextInterface(int position)
{

    int option;
    cout << "Please select an option" << endl;
    cout << "[1] Withdraw from account" << endl;
    cout << "[2] Deposit from account" << endl;
    cout << "[3] Get Bank Account Number" << endl;
    cout << "[4] Get Balance of the account" << endl;
    cout << "[5] Exit" << endl;
    cin >> option;
    if(option == 1)
    {
        double WithdrawnAmount = 0;
        cout << "How much money would you like to withdraw from the account?" << endl;
        cin >> WithdrawnAmount;
        bankAccounts.getElementAt(position).withdraw(WithdrawnAmount);
        cout << "you Withdrew " << WithdrawnAmount << ". You have " << bankAccounts.getElementAt(position).getBalance() << " left in your account" << endl;     
        option2TextInterface(position);
    }
    else if(option == 2)
    {
        double depositAmmount = 0;
        cout << "How much money would you like to deposit into the account" << endl;
        cin >> depositAmmount;
        bankAccounts.getElementAt(position).deposit(depositAmmount);
        cout << "You deposited " << depositAmmount << " into your account. You have " << bankAccounts.getElementAt(position).getBalance() << " in you account." << endl; 
    }
    else if(option == 3)
    {
        cout << "Your bank account number for: " << clients.getElementAt(position).getName() << " is " << bankAccounts.getElementAt(position).getBankAccountNumber() << endl;
    }
    else if(option == 4)
    {
        cout << "Your balance for: " << clients.getElementAt(position).getName() << " is " << bankAccounts.getElementAt(position).getBalance() << endl;
    }
}
int findPosition(string firstName)
{
    int nameLength = 0;
    MyVector<char> arrayOfName;
    for(int i = 0; i < firstName.size(); ++i)
    {
        arrayOfName.pushBack(firstName[i]);
    }

    for(int i = 0; i < clients.getSize(); i++)
    {
        for(int j = 0; j < arrayOfName.getSize(); j++)
        {
            if(toupper(arrayOfName.getElementAt(j)) == toupper(clients.getElementAt(i).getName()[j]))
            {
                nameLength++;
            }
            if(nameLength == arrayOfName.getSize())
            {
                return i;
            }

        }
    }
    return -1;
}
