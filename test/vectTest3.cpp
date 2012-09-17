#include<stdlib.h>
#include<time.h>
#include<LMT_VECTOR1.h>

int main()
{
	//-------------------------------------------------------------
	//	going to test: vecGetValue,vecSetValue , index start from 0
	//				   vecLength , return double
	//					vecDotProduct , return double
	//					vecCrossProduct2D , return double
	//-------------------------------------------------------------
	double		buffer = 256.512;
	_VECTOR(3)	v1,v2;
	vecInitialize((VECTOR*)&v1,3);
	vecInitialize((VECTOR*)&v2,3);

	vecSetValue((VECTOR*)&v1,0,buffer);
	if(vecGetValue((VECTOR*)&v1,0) != buffer)	// test if index 0 consistent with buffer
		return 0;

	buffer  = vecGetValue((VECTOR*)&v1,3);	// test if over-index accessing


	buffer = vecLength((VECTOR*)&v1);
	vecFwrite((VECTOR*)&v1,stdout);
	printf("length : %f\n",buffer);

	for(int i=0;i<3;i++){
		vecSetValue((VECTOR*)&v1,i,(double)(rand()%10));
		vecSetValue((VECTOR*)&v2,i,(double)(rand()%10));
	}

	vecFwrite((VECTOR*)&v1,stdout);
	vecFwrite((VECTOR*)&v2,stdout);

	buffer = vecDotProduct		((VECTOR*)&v1,(VECTOR*)&v2);
	printf("dot product : %f\n",buffer);
	buffer = vecCrossProduct2D	((VECTOR*)&v1,(VECTOR*)&v2);
	printf("cross product : %f\n",buffer);

	//	all test done
	return 1;
}
