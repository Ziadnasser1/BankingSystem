//
// Created by Ziad Nasser on 2022-11-08.
//

#include "BankApplication.h"
#include <fstream>
#include <iomanip>
#include <string>

void BankApplication::BankApp() {
    bool ok = true;
    while(ok) {
        char c;
        cout << "Welcome to FCAI Banking application" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. List Clients and accounts" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Please Enter Choice " << "=========> ";
        cin >> c;
        cin.ignore();
        cout<<"-----------------------------------------------------------------------------"<<endl;
        switch (c) {
            case '1':
                addAccount();
                break;
            case '2':
                listClients();
                break;
            case '3':
                withdrawMoney();
                deleteTempFile();
                break;
            case '4':
                depositMoney();
                deleteTempFile();
                break;
            case '5':
                ok = false;
            default:
                break;
        }
    }
}

void BankApplication::addAccount() {
    Client *client = nullptr;
    string name, address, phone;
    double balance=0;
    int choice;
    cout<<"Please enter Client Name =========> ";
    getline(cin, name);
    cout<<"Please enter Client Address =========> ";
    getline(cin, address);
    cout<<"Please enter Client Phone ==========> ";
    cin>>phone;
    cout<<endl;
    cout<<"What Type of Account do you like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
    cin>>choice;
    cout<<"Please enter the starting balance =====> ";
    cin>>balance;
    if (choice == 1){
        auto *account = new BankAccount();
        client = new Client(name, address, phone, account);
        client->getAccount()->setBalance(balance);
        client->getAccount()->setAccountID(generateID());
        fillUserData(name, address, phone, client->getAccount()->getAccountID(), balance,"B");
        cout<<"An Acccount was created with ID "<<client->getAccount()->getAccountID()<<" and Starting Balance "<<balance<<endl;

    } else if (choice == 2){
        auto *account2 = new SavingsBankAccount();
        client = new Client(name, address, phone, account2);
        if(balance <= 1000){
            cout<<"Enter balance more than 1000 :";
            cin>>balance;
        }else{
            client->getSavingsAccount()->setBalance(balance);
        }
        client->getSavingsAccount()->setAccountID(generateID());
        fillUserData(name, address, phone, client->getSavingsAccount()->getAccountID(),balance,"S");
        cout<<"An Acccount was created with ID "<<client->getSavingsAccount()->getAccountID()<<" and Starting Balance "<<balance<<endl;
    } else {
        cout<<"Invalid Choice"<<endl;
    }
}



string BankApplication::generateID() {
    string userID = "FCAI-";
    int id = 0;
    ifstream file("UsersData.txt");
    string line;
    while (getline(file, line)) {
        id++;
    }
    userID += to_string(id);
    return userID;

}

string newBalance;
string accID;
char type;
void BankApplication::withdrawMoney() {
    double amount;
    cout << "Please Enter Account ID (FCAI-4) =========> ";
    cin >> accID;
    cout << "Account ID : " << accID << endl;
    string b = getbalance(accID);
    type = b[b.size()-1];
    if(type == 'B')
        cout<<"Account Type: Basic"<<endl;
    else
        cout<<"Account Type: Savings"<<endl;
    b.pop_back();
    cout << "Balance : " << b << endl;
    cout << "Please Enter The Amount to Withdraw =========> ";
    cin>>amount;
    if(type == 'S'){
        SavingsBankAccount sa;
        sa.setMinimumBalance(1000);
        double accountBalance = stod(b);
        sa.setBalance(accountBalance);
        bool ok = true;
        while(ok){
            if(sa.withdraw(amount)){
                ok = false;
            }else{
                cout<<"Enter valid amount:";
                cin>>amount;
            }
        }
        newBalance = to_string(sa.getBalance());
        cout << "Thank You" << endl;
        cout<<"Account Id : "<<accID<<endl;
        cout << "New Balance : " << newBalance << endl;
    }else{
        BankAccount ba;
        double accountBalance = stod(b);
        ba.setBalance(accountBalance);
        bool ok = true;
        while(ok){
            if(ba.withdraw(amount)){
                ok = false;
            }else{
                cout<<"Enter valid amount:";
                cin>>amount;
            }
        }
        newBalance = to_string(ba.getBalance());
        cout << "Thank You" << endl;
        cout<<"Account Id : "<<accID<<endl;
        cout << "New Balance : " << newBalance << endl;
    }
    changeOldFile();
}

void BankApplication::depositMoney() {
    double amount;
    cout << "Please Enter Account ID (FCAI-4) =========> ";
    cin >> accID;
    cout << "Account ID : " << accID << endl;
    string b = getbalance(accID);
    type = b[b.size()-1];
    cout<<"Balance : "<<b<<endl;
    cout << "Please Enter The Amount to Deposit =========> ";
    cin >> amount;
    if(type == 'S'){
        SavingsBankAccount sa;
        sa.setMinimumBalance(1000);
        double accountBalance = stod(b);
        sa.setBalance(accountBalance);
        bool ok = true;
        while(ok){
            if(sa.deposit(amount)){
                ok = false;
            }else{
                cout << "Sorry. the deposit is less than the required amount (100) Enter another amount: " << endl;
                cin>>amount;
            }
        }
        newBalance = to_string(sa.getBalance());
        cout << "Thank You" << endl;
        cout<<"Account Id : "<<accID<<endl;
        cout << "New Balance : " << newBalance << endl;
    }else{
        BankAccount ba;
        double accountBalance = stod(b);
        ba.setBalance(accountBalance);
        ba.deposit(amount);
        newBalance = to_string(accountBalance);
        cout << "Thank You" << endl;
        cout<<"Account Id : "<<accID<<endl;
        cout << "New Balance : " << newBalance << endl;
    }
    changeOldFile();
}

void BankApplication::listClients() {
    ifstream file;
    file.open("UsersData.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}


//file handling Functions.

string BankApplication::getbalance(string accountID) {
    ifstream file;
    file.open("UsersData.txt");
    string BALANCE;
    bool isFound=false;
    while(!file.eof())
    {
        string temp;
        getline(file,temp);
        for(int i=0;i<accountID.size();i++)
        {
            if(temp[i]==accountID[i])
                isFound = true;
            else
            {
                isFound =false;
                break;
            }
        }
        if(isFound)
        {
            for(unsigned long long i = accountID.size()+1;i<temp.size();i++){
                if(temp[i]==':')
                    break;
                else if(temp[i]==' ')
                    continue;
                else{
                    BALANCE.push_back(temp[i]);
                }
            }
            break;
        }
    }

    if(file.eof()&&(!isFound))
    {
        cout << "Name not found!\n";
    }
    file.close();

    return BALANCE;

}
void BankApplication::changeOldFile() {
    string replaceStr = getbalance(accID); //String to replace
    string replacementStr = newBalance + type;	//String To replace with
    ifstream filein("UsersData.txt"); //File to read from
    ofstream fileout("UsersData2.txt"); //Temporary file
    string strTemp,word;

    while(filein >>word)
    {
        if(word==replaceStr){
            word = replacementStr;
            fileout<<left<<setfill(' ')<<setw(27)<<word;
        }
        else if(word=="|")
            fileout<<"|"<<endl;
        else if(word==":")
            fileout<<word;
        else
            fileout<<left<<setfill(' ')<<setw(27)<<word;

    }
    filein.close();
    fileout.close();
}
void BankApplication::deleteTempFile() {
    string status;
    char file1[]="UsersData.txt";
    char file2[]="UsersData2.txt";

    status = remove(file1);

    if (rename(file2, file1) != 0)
        perror("Error renaming file");

}
void BankApplication::fillUserData(string name, string address, string phone, string accountID, double balance,string t) {
    fstream myfile("UsersData.txt",ios::in | ios::out | ios::app);
    if(!myfile.is_open())
        cout<<"error while opening the file"<<endl;
    else{
//        cout<<"file opened successfully"<<endl;
//        cout<<"writing to file"<<endl;
//        cout<<"-------------------------"<<endl;
        string b = to_string(balance);
        myfile<<left
              <<setfill(' ')<<setw(27)<<accountID
              <<setfill(' ')<<setw(27)<<b+t
              <<" : "<<setfill(' ')<<setw(27)<<name
              <<setfill(' ')<<setw(27)<<phone
              <<setfill(' ')<<setw(27)<<address<<"|"<<endl;
    }
    myfile.close();
}
