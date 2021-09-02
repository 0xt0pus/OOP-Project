
#ifndef BitcoinAccount_H_
#define BitcoinAccount_H_
#include<iostream>
#include <string>
#include"Account.h"
#include"BitCoin.h"
using namespace std;

class BitcoinAccount : public Account 

{


public:

BitcoinAccount():Account()
{


}
BitcoinAccount(string pbkey, string pvkey): Account(pbkey,this->getHash(pvkey))
{
	//cout<<"In bit coin account "<<endl;
/*	cout<<"The public key is "<<pbkey<<endl;
	cout<<"Private key is "<<pvkey<<endl;
	cout<<"Hashed as "<<getHash(pvkey)<<endl;
*/

	//Account::GetCurrency();//will return pointer

coins= new BitCoin;//dynamic memory will be created for bitcoin

/*((this->Account::GetCurrency())->setAmount(10));

cout<<"IN bitcoin constructor the amount in public key "<< pbkey<<" and private key "<<pvkey<<" amount "<<  (Account::GetCurrency())->getAmount()<<endl;
*/}

string getHash(string a)
{

char arry[100];
for(int i=0;i<100;i++)
{
	arry[i]='\0';
}
int h=0;
int len=a.length();
int k=0;

while(k<len)
{

	for(int i=0;i<len+1;i++)
	{
		if((a[k]+i)==':')
		{
			arry[h]='0';
			h++;
			continue;
		}
		else if((a[k]+i)==';')
		{
			arry[h]='1';
			h++;
			continue;
		}
		else if((a[k]+i)=='<')
		{
			arry[h]='2';
			h++;
			continue;
		}
		else if((a[k]+i)=='=')
		{
			arry[h]='3';
			h++;
			continue;
		}

		else if((a[k]+i)=='>')
		{
			arry[h]='4';
			h++;
			continue;
		}
		else if((a[k]+i)=='[')
		{
			arry[h]='A';
			h++;
			continue;
		}
		else if((a[k]+i)=='\\')
		{
			arry[h]='B';
			h++;
			continue;
		}
		else if((a[k]+i)==']')
		{
			arry[h]='C';
			h++;
			continue;
		}
		else if((a[k]+i)=='^')
		{
			arry[h]='D';
			h++;
			continue;
		}
		else if((a[k]+i)=='{')
		{
			arry[h]='a';
			h++;
			continue;
		}
		else if((a[k]+i)=='|')
		{
			arry[h]='b';
			h++;
			continue;
		}
		else if((a[k]+i)=='}')
		{
			arry[h]='c';
			h++;
			continue;
		}
		else if((a[k]+i)=='~')
		{
			arry[h]='d';
			h++;
			continue;
		}

		else
		{
		arry[h]=a[k]+i;
		h++;
		}
	}
k++;

}

string hhh;
hhh=arry;//Char array converted to string 

//This will generate the hash of Bitcoin

return hhh;

	
}
  
  
~BitcoinAccount()
{

}

};
#endif