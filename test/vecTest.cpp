#include<stdlib.h>
#include<time.h>
#include<LMT_VECTOR1.h>

int main()
{
	double		buffer;
	_VECTOR(3)	v1,v2,v3;
	vecInitialize((VECTOR*)&v1,3);
	vecInitialize((VECTOR*)&v2,3);
	vecInitialize((VECTOR*)&v3,3);

	srand(time(NULL));
	vecSetAll	((VECTOR*)&v1,(const double)(rand()%10));
	vecGetValue	((VECTOR*)&v1,1/*(const size_t)(rand()%3)*/,&buffer);
	vecSetValue	((VECTOR*)&v2,2/*(const size_t)(rand()%3)*/,(const double)(rand()%10));
	vecAssign	((VECTOR*)&v1,(VECTOR*)&v2);		// v1=v2

	vecLength	((VECTOR*)&v1,&buffer);
	vecAdd		((VECTOR*)&v2,(VECTOR*)&v1,(VECTOR*)&v1);

	vecDotProduct((VECTOR*)&v1,(VECTOR*)&v2,&buffer);

	vecSetAll	((VECTOR*)&v1,0);
	vecSetAll	((VECTOR*)&v2,0);
	vecSetValue	((VECTOR*)&v1,1,1);
	vecSetValue	((VECTOR*)&v2,2,1);

	vecCrossProduct((VECTOR*)&v1,(VECTOR*)&v2,(VECTOR*)&v3);	// done , all func worked well
																// Hsien , 2012.09.06

	return 1;
}