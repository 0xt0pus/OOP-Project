#include<stdlib.h>
#include<iostream>
#include<ctime>
using namespace std;
#include"AccountManager.h"
AccountManager manager;
int main()
{
   srand(120);

   Account miner("miner","123");  
   manager.AddAccount(miner);

int check=0;
char option,optionB;
string sender_public_key,sender_private_key,reciever_public_key;
double amount;

do
{
  cout<<endl;
  cout<<"Choose option from the given menu :"<<endl;
  cout<<"1.Create Account"<<endl;
  cout<<"2.Make a Transaction"<<endl;
  cout<<"3.See Transaction Log"<<endl;
  cout<<"4.See All Accounts"<<endl;
  cout<<"5.To write the current stat in file"<<endl;
  cout<<"6.Exit the program"<<endl;
  cin>>option;

  while(option!='1' && option!='2' && option!='3' && option!='4' && option!='5' && option!='6')
  {


    cout<<"Wrong choice!!!!. Try again "<<endl;
    cin>>option;
  }


    switch(option)
    {
            case '1':
            { 
              cout<<"What type of account you want to make"<<endl;
              cout<<"1.BITCOIN"<<endl;
              cout<<"2.ETHER"<<endl;
              cin>>optionB;
              while(optionB!='1' && optionB!='2')
              {
                cout<<"Sorry! Try again with valid input"<<endl;
                cin>>optionB;
              }

              if(optionB=='1')
              {
                manager.CreateAccount(BITCOIN);//will create an account type of BITCOIN
              }
              else if(optionB=='2')
              {
                manager.CreateAccount(ETHER);
              }
          break;
          }
            case '2':
            {
              cout<<"Enter the public key of sender"<<endl;
              cin>>sender_public_key;
              cout<<"Enter the private key of sender"<<endl;
              cin>>sender_private_key;
              cout<<"Enter the public key of reciever"<<endl;
              cin>>reciever_public_key;
              cout<<"Enter the amount you wish to transfer"<<endl;
              cin>>amount;

              bool a=manager.MakeTransaction(sender_public_key,sender_private_key,reciever_public_key,amount);
              if(a==1)
              {
                cout<<"Transaction successful"<<endl;

              }
              else if(a==0)
              {
                cout<<"Transaction failed"<<endl;
              }
              break;
            }

            case '3':
            {
              cout<<"TRANSACTIONS:"<<endl;
              cout<<manager.ToStringTransactionLog()<<endl;
              break;

            }

            case '4':
            {
              cout<<"ACCOUNTS:"<<endl;
              cout<<manager.ToStringAccounts()<<endl;
              break;
            }
            case '5':
            {
              manager.WriteToFile("hello.txt");
              cout<<"successfully written to file"<<endl;
              break;
            }

            case '6':
            {
              check=98;
              break;
            }



      }
}


while(check==0);


}





