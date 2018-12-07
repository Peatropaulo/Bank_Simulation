#include <iostream>
#include "Pmp.cpp"
/*using namespace std;   <---- OTHER UNIT TEST COMMENT
int main()
{
	//Testing initialization
	 Bank B=Bank(1,true);
for(int i=1;i<5;i++)
	{
	Customers C=Customers(B.getTime(),i,1);
		B.advanceTime();
		B.Arrive(C);
	}	
	B.Depart();
	B.Depart();
	B.Depart();
	B.Depart();
//  Customers C=Customers(B.getTime(),4,1);
    Customers C=Customers(B.getTime(),7,2);
// Tests getTime()
	cout<<B.getTime()<<endl;
// Tests advanceTime
	B.advanceTime();
	B.advanceTime();
	cout<<B.getTime()<<endl;
//	Tests arrive() getCustomers() and getId()
	B.Arrive(C);
	cout<<B.getCustomers().getId()<<endl;
//	Tests Depart() 
 	B.Depart();
 	B.Arrive(C);
 	cout<<B.getCustomers().getId()<<endl;
//	Test open()
 	cout<<B.open()<<endl;
//	Test ChangeStaus() and Open
 	B.changeStatus();
	cout<<B.open()<<endl;
//  Tests Empty()
	cout<<B.empty()<<endl;
//  Tests Average
	cout<<B.average()<<endl;
//	Test getArriveTime and Get Customers
	cout<<B.getCustomers().getArriveTime()<<endl;
//	Tests Get customers and different service times and Get Service Time unhighlight above to test with different service time
	cout<<B.getCustomers().getId()<<endl;
 	cout<<B.getCustomers().getServiceTime();
	return 0;
}//C:\\MinGW\bin\TestModuleTotal
*/  //<------ UNIT TEST COMMENT

///THE FOLLOWING TEST USES ALL OF THE MODULES FOR BANK AND CUSTOMERS ITS DOES THIS WHILE TESTING 
///THE OTHER THREE FUNCTIONS FOUND IN MAIN THIS WOULD BE A SYSTEMS TEST AND AN INTEGRATION TEST
///IF YOU WOULD LIKE TO SEE THE UNIT TESTS COMMENT OUT THIS PORTION OF THE CODE AND UNCOMMENT THE ONE ABOVE
/// DOING SO WILL RUN THE AND SHOW THE OUTPUT OF THE UNIT TESTS.
void Simulation(int Tellercount,int ppm,int intialServiceTime);
void addCustomersToBank(Bank &B,int time, int idStarter, int serviceTime,int amount);
void Teller(Bank &B, int amountOfTellers,int &st);
int main()
{
	Simulation(1,1,1);
	Bank Q=Bank(1,true);
	int st=1;
	addCustomersToBank(Q,Q.getTime(),1,1,10);// Adds ten customers to queue
	Teller(Q,10,st);//removes all ten as if there are ten tellers
		addCustomersToBank(Q,Q.getTime(),1,1,10);// Adds ten customers to queue
	Teller(Q,1,st);//removes one as if there is one teller
		//NOTE AVERAGE SHOULD BE NEGATIVE ONE AS I DO NOT ADVANCE THE TIME IN TH BANK
	return 0;
}
void Simulation(int Tellercount,int ppm, int intialServiceTime)
{
 Bank B=Bank(1,true);//Creates a bank to test
	Customers C=Customers(B.getTime(),1,1);// Makes the Queue
		B.Arrive(C);//adds then deletes the Queue
	B.Depart();
 int input;
 std::cout<<"Is the bank open? 0=open,1=closed,-1 to leave:"<<std::endl;
 do                                                     // This test the UI of Bank
 {														// Is the bank  open?
 	if(B.open())										// Changing the Banks status
 	{													// Getting User input
 	std::cin>>input;									// Exiting the loop
 			if(input==1)								// This tests the main functions 
 				B.changeStatus();						// simulation profile
 		std::cout<<std::endl;							// 0 = open
 	}													// 1 = closed
	B.advanceTime();									// -1 = Emergency leave
	if(B.open())
		std::cout<<"Is the bank still open?:";
	std::cout<<std::boolalpha<<B.open()<<std::endl;
}
while(B.open()&& input!=-1);
}
////////////////////////////////////////////////////////////////////////////////////
// The above tests the adding customers to a bank and removing them from the bank
void addCustomersToBank(Bank &B,int time, int idStarter, int serviceTime,int amount)
{
	for(int h=0;h<amount;h++)
 				{
 					Customers C=Customers(B.getTime(),idStarter+h,serviceTime);
					B.Arrive(C);
				}
}
void Teller(Bank &B, int amountOfTellers,int &st)
{
	for(int count=0;count<amountOfTellers;count++)
				B.Depart();

	st=0;
}