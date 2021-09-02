
#ifndef Account_H_
#define Account_H_
#include<iostream>
#include<string>
#include"Currency.h"
#include"Transaction.h"
using namespace std;

class Account
{
    string public_key;//to store public key
    string private_key_hash;//to store hash of private key
   protected:
    Currency *coins;
    
    public:
      int type;//1 for ether and 0 for bitcoin
   
    Account()
    {

    }
    void setPrivateKeyHash(string pk)
    {
        private_key_hash=pk;
    }

    void setPublicKey(string pbk)
    {
        public_key=pbk;
    }

    Currency* GetCurrency()
    {
      return coins;
    }

    string getPublicKey()

    
    {
        return this->public_key;
    }


    Account(string pub,string pri)

     {
        public_key=pub;
        private_key_hash=pri;
      //  cout<<"The private key hashed as "<<pri<<endl;
     }


    string getHash(string s)
    {
        //return the hash of string s as desribed in document;
        //Hash calculated according to the account type which calculated in their respective classes] 
    
        return s;

    }

  bool VerfiyAccount(string pvate_key)
    {

      for(int k=0;k<3;k++)
             {
                  if(private_key_hash[k]!=pvate_key[k])
                  {
                    return false;
                                    
                  }

                  else if(k==2 && private_key_hash[k]==pvate_key[k])
                  {
                    return true;
                  }

               }

        /*Take Hash of the parameter private_key and compare it with hash member variable
        return true if matches 
        */



    return 1;//just to avoid from warning
  }

    
   bool SendCoins(string private_key,double amount)
    {
       
        if(VerfiyAccount(private_key))
        {
          DeductAmount(amount);
          coins->DeductTransaction();


         
          //this place for transaction fee

          return true;
        }
        if(!VerfiyAccount(private_key))
        {
          return false;
        }

         // * Verify account using the private_key (use the function above)
         // * if verfication successful deduct amount from account,deduct transaction fee and return true
         // * if verifaction failed return false;
         // * if verification successful but there is not enough amount in coins then make the user in debt (negative balance)return true
     /*virtual*/

return true;//just to avoid from warning
    }
    void DeductAmount(double amount)
    {
       coins->Deductamount(amount);
       
    }
void AddAmount(double amount)
    {
        
      coins->Addamount(amount);
    }

  double TellmeAMount()
    {
      return coins->getAmount();
    }
    
    
    string ToString()
    {
        //DO NOT MODIFY THIS FUNCTION
      return public_key+"-"+to_string(coins->getAmount());
    
    }


void addtransaction(double h)//this was made to store all transaction fee in fact the minor account
{
  coins->AddTransactionFee(h);
}



 ~Account()
 {

 }

 
};

#endif