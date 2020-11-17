#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
	int id;
	char name[20];
} Employee;
	
typedef struct Employee2 {
	int id;
	char *name;
} Employee2;

void assignEmployee(Employee2 *des, const Employee2 *src)
{
	des->id = src->id;
	free(des->name);
	des->name = (char *)malloc(sizeof(char) * 20);		//strlen(src->name) + 1
	strcpy(des->name, src->name);
}

int compareEmployee(const Employee2 *lhs, const Employee2 *rhs) {
	return lhs->id == rhs->id && !strcmp(lhs->name, rhs->name);
}

int main(void)
{
	Employee e1;
	e1.id = 1;
	strcpy(e1.name, "park jung seok");
	
	Employee2 e2, e3;
	
	e2.id = 2;
	e2.name = (char *)malloc(sizeof(char) * 20); 
	strcpy(e2.name, "lim you han");
	
	e3.id = 3;
	e3.name = (char *)malloc(sizeof(char) * 20);
	strcpy(e3.name, "lee yun yeol");
	
	assignEmployee(&e2, &e3);
	
	if (compareEmployee(&e2, &e3)) {
		printf("e2 and e3 are equal \n");
	} else {
		printf("e2 and 23 are not equal \n");
	}
	
	free(e2.name);
	free(e3.name);
	return 0;
}

