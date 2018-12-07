#ifndef Pmp
#define Pmp
#include <iostream>
#include "string"
#include <queue>
class Bank;
class Customers
{
private:
	int arriveTime;
	int id;
	int serviceTime;
public:
	Customers(int t,int i,int st);
	int getArriveTime(){return arriveTime;};
	int getId(){return id;};
	int getServiceTime(){return serviceTime;};
	
};
class Bank
{
private:
	std::queue<Customers> Line;
	int globalTime;
	bool operatingStatus;
	int waitSum;
	int numOfCustomers;
public:
	Bank(int global,bool b);
	int getTime(){return globalTime;};
	void advanceTime(){globalTime++;};
	void Arrive(Customers c);
	Customers getCustomers(){if(!Line.empty())
		return Line.front();
	};
	void Depart();
	void changeStatus(){operatingStatus=false;};
	bool open(){return operatingStatus;};
	bool empty(){return Line.empty();};
	double average(){return waitSum/numOfCustomers;};
};
#endif