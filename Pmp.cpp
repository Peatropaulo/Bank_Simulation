# include "Pmp.h"
  Bank::Bank(int Global,bool b)
  {
  	globalTime=Global;
    operatingStatus=b;
    waitSum=0;
    numOfCustomers=0;
    Line;
  }
  void Bank::Arrive(Customers c)
  {
  		Line.push(c);
      numOfCustomers++;
  		std::cout<<"Customer "<<c.getId()<<" has enetered the bank at time "<<c.getArriveTime()<<std::endl;
  }
  void Bank::Depart()
  {
  	if(!(Line.empty()))
  	{	
  	Customers s=Line.front();
  		std::cout<<"Customer "<<s.getId()<<" has left the bank at time "<<globalTime<<std::endl<<"The Wait Time for customer "<<s.getId()<<" is: "<<globalTime-s.getArriveTime()-s.getServiceTime()<<" Units"<<std::endl;
  	 waitSum+=(globalTime-s.getArriveTime()-s.getServiceTime());
    Line.pop();
  	return;
  }
  std::cout<<"There is no one in Line"<<std::endl;

  }
  Customers::Customers(int t,int i,int st)
  {
  	arriveTime=t;
  	id=i;
    serviceTime=st;
  }
 
