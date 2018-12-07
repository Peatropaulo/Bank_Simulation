#include <iostream>
#include <cmath>
#include "Pmp.cpp"
void Simulation(int Tellercount,int ppm,int intialServiceTime);
void addCustomersToBank(Bank &B,int time, int idStarter, int serviceTime,int amount);
void Teller(Bank &B, int amountOfTellers,int &st);
int main()
{
	int t,pm,st;
	std::cout<<"Enter the amount of tellers: ";
	std::cin>>t;
	std::cout<<"Enter the amount of people per minute: ";
	std::cin>>pm;
	std::cout<<"Enter the service time for the transactions you want to test: ";
	std::cin>>st;
	Simulation(t,pm,st);// One Teller, 1 person per minmute, Service time of 1
	return 0;
}
void Simulation(int Tellercount,int ppm, int intialServiceTime)
{
 Bank B=Bank(1,true);//Creates a bank
 int input;//  User input for bank statement	
 int counter=1;// Counter
 int st=1;// Service time counter
 int service=1;// inital service time
 std::cout<<"Is the bank open? 0=open,1=closed,-1 to leave:"<<std::endl;
 do
 {
 	if(B.open())//Checks if the bank is open so people can come in
 	{

 		std::cin>>input;//gets wether the bank is open or closed
 			if(input==1)
 				B.changeStatus();// if its closed we change its boolean value 
 			else
 			{
 					std::cout<<std::endl;//spacing
 					addCustomersToBank(B,B.getTime(),counter,intialServiceTime,ppm);//calls function to add customers to queue
 			}
 	}
	B.advanceTime();//Advances time 
	if(st==B.getCustomers().getServiceTime())
			Teller(B,Tellercount,st);//Calles a teller to service someone
	if(B.empty()&& !B.open())
			input=-1;//if the bank is empty and closed the program is done
	if(B.open())// only ask if the bank is still open if it hasnt closed yet
			std::cout<<"Is the bank still open?:";
		st++;// Increase service counter
		counter+=ppm;//increase counter for people per minute (for id purposes only)

}
while( input!=-1);
std::cout<<"The average wait time is: "<<floor(B.average())<<" units"<<std::endl;//Print average rounded down for neatness
}
void addCustomersToBank(Bank &B,int time, int idStarter, int serviceTime,int amount)
{
	for(int h=0;h<amount;h++)
 				{
 					//std::cout<<"Enter the service time of customer "<<idStarter+h<<": ";
 					//cin>>serviceTime; //TEST FOR DIFFERENT SERVICE INPUT AS REQUIRED ON THE PROJECT OUTLINE
 					Customers C=Customers(B.getTime(),idStarter+h,serviceTime);//ADDS AS MANY CUSTOMERS TO THE QUEUE EQUAL TO PPM NOTE:TAKES ONE TIME INTERVAL FOR THEM TO PILE IN
					B.Arrive(C);//Adds them to queue
				}
}
void Teller(Bank &B, int amountOfTellers,int &st)
{
	for(int count=0;count<amountOfTellers;count++)// removes people once their service time has been hit. For loop is for how many tellers there are.
				B.Depart();//removes them from queue

	st=0;//resets service timer once people are removed
}
//C:\\MinGw\bin\Pm_Main
