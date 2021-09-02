#include<string>
#include<cstring>
#include<string.h>
#include<iostream>
using namespace std;
class Transaction{

    string sender_public_key;
    string receiver_public_key;
    double amount;
  
    public:   
  Transaction()
  {

  }

  Transaction(string sender_public_ke,string receiver_public_ke,double amoun)
  {

sender_public_key=sender_public_ke;
receiver_public_key=receiver_public_ke;
amount=amoun;

  }


  string GetSenderPublicKey()
  {
    return sender_public_key;
  }
  string GetReceiverPublicKet()
  {
    return receiver_public_key;
  }

  double GetAmount()
  {
    return amount;
  }

   
   string ToString()/* Do not modify this function*/
    {
        return this->sender_public_key/*+"-"+this->receiver_public_key+"-"+to_string(amount)*/;
    }
};


/*TransactionHashed inherits class Transaction. It has only one difference that it stores hash of public
keys of sender and receiver. The type of hashing depends upon the account type i.e ASCIIHash for
Ether and RepeatTIllSize for bitcoin.*/
