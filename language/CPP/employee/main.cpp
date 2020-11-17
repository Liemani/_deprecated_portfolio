#include <iostream>
#include "employee.h"

int main()
{
	Employee* ems[5];
	ems[0] = new Employee(1, "Park Jung Seok", NULL);
	ems[1] = new Employee(2, "Sung Young Ho", ems[0]);
	ems[2] = new Employee(3, "Yun Jung Soo", ems[0]);
	ems[3] = new Employee(4, "Kim Tae Hyun", ems[1]);
	ems[4] = new Employee(5, "Ha Sung Ho", ems[1]);
	
	Employee e6;
	
	// Employee e1;		X
	// Employee e2(e1);	X
	// e2 = e1			X
	
	std::cout << "id: " << ems[0]->getId() << ", name: " << ems[0]->getName() <<std::endl;
	
	if (ems[0]->isDirector())
		std::cout << ems[0]->getName() << " is a manager" << std::endl;
	else
		std::cout << ems[0]->getName() << " is not a manager" << std::endl;
	
	for (int i = 0; i < 5; ++i)
		delete ems[i];

	return 0;
}
