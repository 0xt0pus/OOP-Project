#include<iostream>
using namespace std;
class BitCoin : public Currency
{

public:
BitCoin()
{

setAmount(10);

}
void DeductTransaction()
{


//cout<<"very well this is in bitcoin"<<endl;
setAmount(getAmount()-2);
//cout<<"DeductTransaction fee RS 2"<<endl;

}



};