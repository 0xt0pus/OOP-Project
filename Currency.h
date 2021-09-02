class Currency{
    double amount;
    public:
    Currency()
    {
        amount=0;
        
    }
   virtual void DeductTransaction()// This function will be used as the virtual function
    {
        //Deducts transaction fee from amount
        //if amount is less than transaction fee it still deducts and leave the user in debt e.g negative amount
       // if (Currency=ether)
    	cout<<"WTH this should not be printed"<<endl;
    }
    void setAmount(double a)
{
	amount=a;

}
void Deductamount(double i)
{
	amount-=i;
}
void Addamount(double aa)
{
	amount+=aa;
}

void AddTransactionFee(double am)
{
	amount=amount+am;
}

int justexample()
{
return 34;
}

    void operator+=(double c)//these have 5
    {
        //add c to the amount

        //amount=amount+c;

    }//arr[a][b]=arr[a][b]+amoun;

    void operator-=(double c)
    {
        //deducte c from amount

        //dont understand bcz we must have  some object in parameter but here we have double instead of object
    }

    double getAmount()
    {
        return this->amount;
    }


	~Currency()
	{
		
	}

};