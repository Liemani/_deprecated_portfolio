#include "empty.h"

int main()
{
	Empty e1;
	Empty e2(e1);
	
	e1 = e2;
	
	Empty *e3;
	e3 = &e2;
	
	const Empty e4;
	&e4;
	
	return 0;
}
