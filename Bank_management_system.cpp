#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class bank {
    private :
    int acc,balance,pin;
    string name;

    public:
    bank(int accNo,string username,int amount,int password) {
        acc = accNo;
        name = username;
        balance = amount;
        pin = password;
    }

    void setAccNo(int accNo) {
        acc = accNo;
    }
    int getAccNo() {
        return acc;
    }

    void setName(string username) {
        name = username;
    }
    string getName() {
        return name;
    }

    void setBal(int amount) {
        balance = amount;
    }
    int getBal() {
        return balance;
    }

    void setPin(int password) {
        pin = password;
    }
    int getPin() {
        return pin;
    }

    void displayDetail() {
        cout<<"ACCOUNT NO : "<<acc<<endl;
        cout<<"HOLDER'S NAME : "<<name<<endl;
        cout<<"BALANCE : "<<balance<<endl;
        cout<<"PIN : "<<pin<<endl;
    }
};

void addNewUser(vector<bank> &bankDetails) {
    int acc,balance,pin;
    string name;
    
    cout<<"ENTER ACCOUNT NO :"<<endl;
    cin>>acc;
    for(int i=0; i<bankDetails.size(); i++)
    {
        if(bankDetails[i].getAccNo() == acc)
        {
            cout<<"ACCOUNT WITH THIS ACCOUNT NUMBER ALREADY EXISTS"<<endl;
            return;
        }
    }
    
    cout<<"ENTER YOUR NAME : "<<endl;
    cin>>name;
    cout<<"CREATE A STRONG PIN FOR YOUR ACCOUNT :"<<endl;
    cin>>pin;
    cout<<"ENTER THE INITIAL AMOUNT YOU WANT TO DEPOSIT : "<<endl;
    cin>>balance;

    bank record(acc,name,balance,pin);
    bankDetails.push_back(record);
    cout<<"ACCOUNT CREATED SUCCESSFULLY !!!"<<endl;
}

void ShowAllUsers(vector<bank> &bankDetails) {
    if(bankDetails.empty()) {
        cout<<"NO RECORDS FOUND"<<endl;
        return;
    }

    for(int i=0; i<bankDetails.size(); i++) {
        bankDetails[i].displayDetail();
        cout<<endl;
    }
}

void searchUser(vector<bank> &bankDetails) {
    int accNo;
    cout<<"ENTER ACCOUNT NUMBER : ";
    cin>>accNo;

    for(int i=0; i<bankDetails.size(); i++) {
        if(bankDetails[i].getAccNo() == accNo)
        {
            cout<<"ACCOUNT FOUND !!"<<endl;
            cout<<"ACCOUNT IS REGISTER ON THE NAME OF : "<<bankDetails[i].getName();
            cout<<endl;
            return;
        }
    }
    cout<<"SORRY, NO ACCOUNT IS REGISTERED WITH THIS ACCOUNT NUMBER."<<endl;
}

void depositMoney(vector<bank> &bankDetails) {
    int accNo;
    cout<<"ENTER ACCOUNT NUMBER :"<<endl;
    cin>>accNo;

    for(int i=0; i<bankDetails.size(); i++) {
        if(bankDetails[i].getAccNo() == accNo) {
            int password;
            cout<<"ENTER YOUR PIN :";
            cin>>password;
            if(bankDetails[i].getPin() == password)
            {
                cout<<"SUCCESSFULLY LOGGED IN !!!"<<endl;
                int already = bankDetails[i].getBal();
                int dMoney;
                cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT :"<<endl;
                cin>>dMoney;
                int tMoney = dMoney + already;
                bankDetails[i].setBal(tMoney);
                cout<<"MONEY DEPOSITED SUCCESSFULLY IN THE ACCOUNT NUMBER : "<<bankDetails[i].getAccNo()<<endl;
                return;
            }
            else
            {
                cout<<"INCORRECT PIN FOR THIS ACCOUNT NUMBER, PLEASE TRY AGAIN.";
                return;
            }
        }
    }
    cout<<"NO ACCOUNT IS FOUND WITH THIS ACCOUNT NUMBER"<<endl;
}

void withdrawMoney(vector<bank> &bankDetails) {
    int accNo;
    cout<<"ENTER ACCOUNT NUMBER :"<<endl;
    cin>>accNo;

    for(int i=0; i<bankDetails.size(); i++) {
        if(bankDetails[i].getAccNo() == accNo) {
            int password;
            cout<<"ENTER YOUR PIN :";
            cin>>password;
            if(bankDetails[i].getPin() == password)
            {
                cout<<"SUCCESSFULLY LOGGED IN !!"<<endl;
                int already = bankDetails[i].getBal();
                int wMoney;
                cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW :"<<endl;
                cin>>wMoney;

                if(wMoney > already) 
                {
                    cout<<"YOU DONT HAVE ENOUGH MONEY IN YOUR ACCOUNT";
                    return;
                }
                else
                {
                    int tMoney = already - wMoney;
                    bankDetails[i].setBal(tMoney);
                    cout<<"MONEY WITHDRAWAL SUCCESSFULLY FROM THE ACCOUNT NUMBER : "<<bankDetails[i].getAccNo()<<endl;
                    return;
                }
            }
            else
            {
                cout<<"INCORRECT PIN FOR THIS ACCOUNT NUMBER, PLEASE TRY AGAIN.";
                return;
            }
        }
    }
    cout<<"NO ACCOUNT IS FOUND WITH THIS ACCOUNT NUMBER"<<endl;
}

void balanceInquiry(vector<bank> &bankDetails) {
    int accNo;
    cout<<"ENTER ACCOUNT NUMBER :"<<endl;
    cin>>accNo;

    for(int i=0; i<bankDetails.size(); i++) {
        if(bankDetails[i].getAccNo() == accNo) {
            int password;
            cout<<"ENTER YOUR PIN :";
            cin>>password;
            if(bankDetails[i].getPin() == password)
            {
                cout<<"SUCCESSFULLY LOGGED IN !!"<<endl;
                int already = bankDetails[i].getBal();
                cout<<"BALANCE : "<<already<<endl;
                return;
            }
            else
            {
                cout<<"INCORRECT PIN FOR THIS ACCOUNT NUMBER, PLEASE TRY AGAIN.";
                return;
            }
        }
    }
    cout<<"NO ACCOUNT IS FOUND WITH THIS ACCOUNT NUMBER"<<endl;
}

main() {
    vector<bank> bankDetails;
    char choice;

    do
    {
        system("cls");
        int op;
        
        cout<<"---------------------------------------"<<endl;
        cout<<"     BANK MANAGEMENT SYSTEM       "<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1.) CREATE A NEW ACCOUNT "<<endl;
        cout<<"2.) SHOW DETAILS OF ALL ACCOUNTS "<<endl;
        cout<<"3.) SEARCH FOR AN ACCOUNT "<<endl;
        cout<<"4.) DEPOSIT MONEY IN THE ACCOUNT "<<endl;
        cout<<"5.) WITHDRAW MONEY FROM THE ACCOUNT "<<endl;
        cout<<"6.) BALANCE INQUIRY FOR THE ACCOUNT "<<endl;
        cout<<"7.) EXIT "<<endl;
        cin>>op;

        switch (op)
        {
        case 1:
            addNewUser(bankDetails);
            break;
        case 2:
            ShowAllUsers(bankDetails);
            break;
        case 3:
            searchUser(bankDetails);
            break;
        case 4:
            depositMoney(bankDetails);
            break;
        case 5:
            withdrawMoney(bankDetails);
            break;
        case 6:
            balanceInquiry(bankDetails);
            break;
        case 7:
            exit(1);
            break;

        default:
            cout<<"INVALID NUMBER ENTERED !! PLEASE CHOOSE BETWEEN 1-7"<<endl;
            break;
        }

        cout<<"DO YOU WANT TO CONTINUE : [YES/NO]"<<endl;
        cin>>choice;
    }   while (choice == 'Y' || choice == 'y');
}