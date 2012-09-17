#include<stdlib.h>
#include<time.h>
#include<LMT_VECTOR1.h>

int main()
{
	//----------------
	//	going to test: vecUnit , vMinus , vecScalarMultiply
	//----------------	
	double		buffer;
	_VECTOR(3)	v1,v2,v3,vUnit;
	vecInitialize((VECTOR*)&v1,3);
	vecInitialize((VECTOR*)&v2,3);
	vecInitialize((VECTOR*)&v3,3);
	vecInitialize((VECTOR*)&vUnit,3);

	matMarkId((MATRIX*)&v1,1);
	matMarkId((MATRIX*)&v2,2);
	matMarkId((MATRIX*)&v3,3);
	matMarkId((MATRIX*)&vUnit,1024);


	srand(time(NULL));
	vecSetAll((VECTOR*)&v1,(double)(rand()%10));
	vecSetValue((VECTOR*)&v1,1,(double)(rand()%10));
	vecSetValue((VECTOR*)&v1,2,(double)(rand()%10));
	vecFwrite((VECTOR*)&v1,stdout);

	vecSetAll((VECTOR*)&v2,(double)(rand()%10));
	vecFwrite((VECTOR*)&v2,stdout);

	vecScalarMultiply((VECTOR*)&v1,3,(VECTOR*)&v1);	// x3
	vecFwrite((VECTOR*)&v1,stdout);

	vecMinus((VECTOR*)&v1,(VECTOR*)&v2,(VECTOR*)&v3); // v3 = v1-v2
	vecFwrite((VECTOR*)&v3,stdout);

	vecUnit((VECTOR*)&v1,(VECTOR*)&vUnit);		// vUnit = unit(v1)
	vecFwrite((VECTOR*)&vUnit,stdout);

	// all done , Hsien , 2012.09.07
	return 1;
}