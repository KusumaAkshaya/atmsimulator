#include<bits/stdc++.h>
using namespace std;

class ATM
{
    private:
    map<int, double> users;
    int Pin;
    
    void trackUsers()
    {
        ifstream fin("users.txt");
        int pin;
        double bal;
        while(fin >> pin >> bal)
        {
            users[pin] = bal;
        }
        fin.close();
    }

    void saveUsers()
    {
        ofstream fout("users.txt");
        for(auto &neww : users)
        {
            fout << neww.first << " " << neww.second << endl;
        }
        fout.close();
    }

    public:
       ATM()
       {
         trackUsers();
       }
       bool login()
       {
          int pinEntered;
          cout << "enter your pin: ";
          cin >> pinEntered;

          if(users.find(pinEntered) != users.end())
          {
            Pin = pinEntered;
            cout << "successfully login!";
            return true;
          }
          else
          {
            cout << "wrong pin entered!" ;
            return false;
          }
       }

       void checkBalance()
       {
           cout << "Current Balance: ₹" << users[Pin] << "\n" ;
       }

       void deposit()
       {
        double amount;
        cout << "Enter deposit amount: ₹";
        cin >> amount;
        if(amount > 0)
        {
            users[Pin] += amount;
            saveUsers();
            cout << "₹ " << amount << "deposited \n";
        }
        else
        {
            cout << "invalid amount \n";
        }
       }

       void withdraw()
       {
         double amount;
         cout << "enter withdraw amount: ₹";
         cin >> amount;

         if(amount > 0 && amount <= users[Pin])
         {
            users[Pin] -= amount;
            saveUsers();
            cout << "₹ " << amount << " withdrawn \n";
         }
         else
         {
            cout << "Wrong amount entered";
         }
       }

       void menu()
       {
        int option;
        do
        {
           cout << "\n ATm Menu \n";
           cout << "1. Check Balance \n";
           cout << "2. Deposit Money \n";
           cout << "3. Withdraw Money \n";
           cout << "4. Exit \n";
           cout << "Enter your Option: ";
           cin >> option;

           switch(option)
           {
            case 1 : 
                checkBalance();
                break;
            case 2 :
                deposit();
                break;
            case 3 :
                withdraw();
                break;
            case 4: 
                cout << "log out \n";
                break;
            default:
                cout << "Invalid option" ;

           }
        } while (option != 4);
        
       }

};

int main()
{
    ATM atm;
    if(atm.login())
    {
        atm.menu();
    }
    else
    {
        cout << "exit \n"; 
    }

    return 0;
}