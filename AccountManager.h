#ifndef AccountManager_H_
#define AccountManager_H_
#include<iostream>
#include <string>
#include <cstdlib>
#include<fstream>
//#include <ctime>
//#include <time.h>
#include"Account.h"
#include"EtherAccount.h"
#include"BitcoinAccount.h"
#include<vector>
using namespace std;
enum ACC_TYPE{BITCOIN,ETHER};
class AccountManager{
Account **arr;
   int NumAccounts;

  vector<Transaction> TransactionLog;
    public:

    AccountManager()
    {
        this->NumAccounts=0;
        
    }


  bool AddAccount(Account &a)//This function will take an account object as parameter and returns true only if account add sucessfully in account otherwise it will give us false
    {
        


//cout<<"I am in add Account"<<endl;

if(NumAccounts==0)//This function will creat and initialize a 2d array ifthere is no account previously
{
arr=new Account*[15];
    for(int i=0;i<15;i++)
    {
        arr[i]=new Account[15];
    }

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {

       arr[i][j].setPublicKey("\0");//will initialize all the members of array with zero

        }
    }


}


int counter_for_matching=1;

for(int i=0;i<15;i++)

{
        for(int j=0;j<15;j++)
        {
            for(int ii=0;ii<3;ii++)

            {

                if((a.getPublicKey())[ii]==(arr[i][j].getPublicKey())[ii])//arr[i][j] is basicallt the array in which accounts are stored 
                {

                    counter_for_matching++;
            
                }

            }

                 if(counter_for_matching==4)
            {
               // cout<<"ACCount already exist"<<endl;
                return false;//If account already exist in array than it will return false;
            }

            counter_for_matching=0;

            for(int t=0;t<15;t++)
            {
                for(int u=0;u<15;u++)
                {
                    if(arr[i][j].getPublicKey()=="\0")
                    {

                        arr[i][j]=a;
                   //     cout<<"successful account added"<<endl;
                        //  cout<<i<<endl;
                          NumAccounts++;//This will return true only if account successfullt added
                          return true;

                    }



                }
            }

        }

}



return 1;//just to avoid from warning

    }


    string GenerateRandomKey()
    {
        
             //  srand((unsigned)time(0));
      

     int MAX_SIZE=62;
        char letters[MAX_SIZE+1] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
        'r','s','t','u','v','w','x',
        'y','z','A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0'};          


    string ran;
char a[3];
for(int i=0;i<3;i++)
{

a[i]=letters[rand() % MAX_SIZE];
ran+=a[i];
}


return ran;//will return the generated string 

    
    }



    string  CreateAccount(ACC_TYPE e)
    {
     
    string random_publicKey;
    string random_privateKey;

random_publicKey=GenerateRandomKey();//the above function called here
random_privateKey=GenerateRandomKey();

cout<<"Account created with public key : "<<random_publicKey<<" and private key : "<<random_privateKey<<endl;//Will show after every creation of account 
     
     
        if(e==BITCOIN)
        {
        BitcoinAccount acc1(random_publicKey,random_privateKey);  
        //cout<<"Sending to AddAccount"<<endl;
        acc1.type=0;
        AddAccount(acc1);//will creat an account of type BITCOIN
       // cout<<"Hello";
     //   cout<<acc1.getPublicKey()<<" account enrolled in addaccount " <<endl;
       //   cout<<a<<endl;
        }


        else if(e==ETHER)
        {
        EtherAcount acc2(random_publicKey,random_privateKey);  
       // cout<<"Sending to AddAccount"<<endl;
        acc2.type=1;

      //  cout<<acc2.getPublicKey()<<" account enrolled in addaccount ";
        AddAccount(acc2);//Will creat an acccount of ETHER
       // cout<<"Hello";
        }
    return random_privateKey; //willl return the private key

    }



     bool MakeTransaction(string sender_public_key,string sender_private_key,string reciever_public_key,double amount)
   {

    int flag=1;

    //Firstly we have to search for the sender public key in arr;
    //and also we have to search for the exact same private key that has given and stored in that particular array;
    //also thirdly we have to search for the receiver public key 

for(int i=0;i<15;i++)
{
    for(int j=0;j<15;j++)
    {   
        for(int g=0;g<3;g++)
        {
            if(sender_public_key[g]!=(arr[i][j].getPublicKey())[g])//this will know whether sender public key exist or not
            {
                if(i==8 && j==8)

                {
                  // cout<<"Your public key does not exist"<<endl;
                    return false;
                }

            }

            else if(sender_public_key[g]==(arr[i][j].getPublicKey())[g])//This will be matching case if both keys match
            {
                flag++;

                if(flag==4)
                {
                    string hash;

                    if(arr[i][j].type==1)
                    {
                        EtherAcount g;


                        hash=g.getHash(sender_private_key); 

                    }
                    else if(arr[i][j].type==0)
                    {
                        BitcoinAccount h;
                        hash=h.getHash(sender_private_key);
                    }

                   // hash=getHash();


                    if(arr[i][j].VerfiyAccount(hash))//this will onlt true if public key match with the private key
                    {
                        


                        for(int a=0;a<15;a++)
                        {
                            for(int b=0;b<15;b++)
                            
                            {
                                for(int c=0;c<3;c++)
                                {
                                    if((arr[a][b].getPublicKey())[c]!=reciever_public_key[c] && a==7)//arr[a][b] is actually the point of reciever account//This is case when coins will be lost
                                    {
                                        if(!arr[i][j].SendCoins(hash,amount))//anount send to sendcoinns where they will be lost
                                        {
                                            return false;
                                        }
                                        else 
                                        {
                                            if(arr[i][j].type==0)//This will store transection in transactionlog in case of coins losts
                                            {
                                                //arr[0][0].addtransaction(2.0);

                                                Transaction a(sender_public_key,"",amount);
                                                TransactionLog.push_back(a);

                                                Transaction c(sender_public_key,"minor",2);//This will deduct transaction fee
                                                  TransactionLog.push_back(c);


                                                return true;//1 used for ether and 0 used for bbitcoins

                                            }// remeber that arr[i][j] always used here for sender 
                                            else if(arr[i][j].type==1)//This will also for ether 
                                            {
                                               // arr[0][0].addtransaction(5.0);
                                                 Transaction a(sender_public_key,reciever_public_key,amount);
                                                TransactionLog.push_back(a);

                                                Transaction c(sender_public_key,"minor",5);//this will deduct transaction fee
                                                TransactionLog.push_back(c);

                                                return true;

                                            }
                                        }

                                     //  cout<<"Sorry coins lost cuz receiver does not exist"<<endl;

                                        return true;

                                    }

                                    else if(c==2 && (arr[a][b].getPublicKey())[c]==reciever_public_key[c])//this is case when reciever public key existt
                                    {

                                        if(arr[a][b].type==arr[i][j].type)
                                        {
                                            //cout<<"Bo zarar jama.  both same"<<endl;
                                            if(!arr[i][j].SendCoins(hash,amount))//both reciever and sender aare the same 
                                                {
                                                    return false;

                                                }
                                            else 
                                            {
                                                        if(amount<0)
                                                    {
                                                   //    cout<<"Amount can not be zero "<<endl;
                                                        return 0;    
                                                    }

                                                    if(arr[i][j].type==0)//for bitcoin
                                                    {
                                                     //arr[0][0].addtransaction(2.0);
                                                    
                                                    Transaction a(sender_public_key,reciever_public_key,amount);//in this case noo need of conversion
                                                    TransactionLog.push_back(a);

                                                    Transaction c(sender_public_key,"minor",2);
                                                    TransactionLog.push_back(c);

                                                    }
                                                    else if(arr[i][j].type==1)//for ether
                                                    {
                                                        //arr[0][0].addtransaction(5.0);
                                                    Transaction a(sender_public_key,reciever_public_key,amount);
                                                    TransactionLog.push_back(a);

                                                    Transaction c(sender_public_key,"minor",5);//the 5 is the transaction fee 
                                                    TransactionLog.push_back(c);

                                                    }

                                                    arr[a][b].AddAmount(amount);//will add amount to receiver account
                                                    return 1;
                                                    //arr[a][b]+arr[i][j];
                                            }
               
                                           
                                        }

                                        else if(arr[a][b].type==0 && arr[i][j].type==1)//0 bit coins//arr[a][b] is reciver
                                        {
                                            double amoun=amount*(1/12.0);
                                           // cout<<amount<<" "<<amoun<<endl;
                                            
                                            if(!arr[i][j].SendCoins(hash,amount))
                                            {
                                                return false;
                                            }
                                            else 
                                            {

                                                if(amoun<(-1))
                                                {
                                                //  cout<<"AMount can not be negative"<<endl;
                                                    return 0;
                                                }

                                                 arr[a][b].AddAmount(amoun);
                                               //arr[0][0].addtransaction(5);
                                                      Transaction a(sender_public_key,reciever_public_key,amount);
                                                       TransactionLog.push_back(a);

                                                Transaction c(sender_public_key,"minor",5);
                                                  TransactionLog.push_back(c);



                                            }
                                            
                                           //cout<<" Amount sendt from ether to BITCOIN"<<endl;
                                            return 1;


                                        }
                                         else if(arr[a][b].type==1 && arr[i][j].type==0)//0 bit coins
                                        {
                                            double amoun=amount*(12.0);
                                           // cout<<amount<<" "<<amoun<<endl;
                                            
                                            if(!arr[i][j].SendCoins(hash,amount))
                                            {
                                                return false;
                                            }

                                            else 
                                            {
                                                if(amoun<-1)
                                            {
                                            //    cout<<"AMount can not be negative"<<endl;
                                                return 0;
                                            }

                                            arr[a][b].AddAmount(amoun);
                                          //arr[a][b]=arr[a][b]+amoun;

                                          // arr[0][0].addtransaction(2);
                                               Transaction a(sender_public_key,reciever_public_key,amount);
                                                       TransactionLog.push_back(a);

                                                        Transaction c(sender_public_key,"minor",2);
                                                  TransactionLog.push_back(c);

                                                       


                                            }
                                          
                                          //  cout<<"AMount sent from BITCOIN to ether"<<endl;
                                              return 1;

                                        }






                                      // cout<<"receiver exist"<<endl;
                                        return true;
                                    }


                                }

                            }

                        }




//cout<<"PUBLIC key and private keys are right"<<endl;
                        return true;




                    }
                    else 
                    {
                   //   cout<<"Your private key does not match with your private key"<<endl;
                        return false;
                    }
                }
            }

        }




    }
}
   
   return 1;}//just to avoid from warning



    string ToStringAccounts()//Only modified here as we dont have a single array i have 2d array so i made it 2d array.
    {
         // DO NOT MODIFY THIS FUNCTION**/

        string res="";
        for(int i=0;i<NumAccounts;i++)
        {
            for(int j=0;j<NumAccounts;j++)
            {
             res+=this->arr[i][j].ToString()+"\n";
        }
        return res;

        }
    

return"";//to avoi from warnings
}


  Account* operator[](int i)
    {
      
        if(i>20 || arr[0][i].getPublicKey()=="\0")
        {
           // cout<<"WTH WRONG THIS IS "<<endl;
            return nullptr;
        }
        else
        {
            Account *ptr;
            ptr=&arr[0][i];
         
           return ptr;

        }       
            


  return nullptr; //just to avoid from warning
   }



   string ToStringTransactionLog()
    {
        string res="";
        for(int i=0;i<TransactionLog.size();++i)
        {
            res+=TransactionLog[i].ToString()+"\n";
        }
        return res;
    }


   void WriteToFile(string filename)
    {


ofstream file;
file.open(filename,ios::app|ios::binary);
file.write((char*)this,sizeof(*this));
file.close();

            /*Write the current state of AccountManager to file. You can use txt files or binary files as you lik    */
    }

   void LoadFromFile(string filename)
    {

ifstream openit;
openit.open(filename,ios::app|ios::binary);
openit.read((char*)this,sizeof(*this));

while(!openit.eof())
{
    openit.read((char*)this,sizeof(*this));

}
openit.close();


        /*Load the state of AccountManager from a file. You can use txt files or binary files as you like*/
    }
//}

/*void tellmeAmount()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)

        {
            //cout<<"So guys balance in account "<<i<<" "<<j<<" is "<<arr[i][j].TellmeAMount()<<endl;

        }
    }
}
*/


/*
void ShowMeTransactionLog()
{
    for(int i=0;i<TransactionLog.size();i++)
    {

        Transaction a;
        a=TransactionLog.at(i);
        cout<<a.GetSenderPublicKey()<<"  "<<a.GetReceiverPublicKet()<< " "<<a.GetAmount()<<endl;

    }
}
*/

~AccountManager()
{

}



};
#endif