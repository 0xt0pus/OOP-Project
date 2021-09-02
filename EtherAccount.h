
#ifndef EtherAccount_H_
#define EtherAccount_H_
#include<iostream>
#include <string>
#include"Account.h"
#include"Ether.h"
using namespace std;

class EtherAcount : public Account 
{

public:
EtherAcount() : Account()
{

	//coins = new Ether;	
	//currency pointer in Account is allocated a memory of
	//type Ether. An ether account has a default amount of 120 ethers when created
}


EtherAcount(string PBkey,string PVkey) : Account (PBkey,getHash(PVkey)) 
{
	//cout<<"In ether account "<<endl;
	//cout<<"The public key is "<<PBkey<<endl;
	//cout<<"Private key is "<<PVkey<<endl;
	//cout<<"Hashed as "<<getHash(PVkey)<<endl;


/*(this->Account::GetCurrency())->setAmount(120);

cout<<"IN Ether constructor, The amount of public key"<<PBkey<<" and private key "<<PVkey<<" amount  "<<(Account::GetCurrency())->getAmount()<<endl;
*/
//Nothing to do here as the parameters goes for account class

coins =new Ether;
}



string getHash(string privateKey)
{

	int h=0;
h=static_cast<int>(privateKey[0]);

for(int i=1;i<privateKey.length();i++)
{

	if(static_cast<int>(privateKey[i])>99)
	{
		h=h*1000;
	}
	else {
		h=h*100;
	}

	h=h+static_cast<int>(privateKey[i]);
}
 
	//cout<<"Private key "<<privateKey<<" Hashed  as "<<h<<endl;
	string ha;
	ha= to_string(h);//Convert the integer to string

return ha; 

	/*append the ascii of every character in the string into the resulted string
For example: “abc” hashes to “979899” because ascii of a is 97,b is 98 and c is 99.
*/
}



~EtherAcount()
{
	
}

};
#endif