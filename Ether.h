
#include<iostream>
using namespace std;
class Ether:public Currency
{
     public:
Ether()
{
	setAmount(120);

}

void DeductTransaction()
{
	 //cout<<"Wowo this is in ether account thats right."<<endl;
	 double aa=getAmount();
	 aa=aa-5;
	 setAmount(aa);
	 //cout<<"DeductTransaction fee RS 5"<<endl;

}
       
};