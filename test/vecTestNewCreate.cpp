#include<stdlib.h>
#include<time.h>
#include<LMT_VECTOR1.h>

int main()
{
	//-------------------------------------------------------------
	//	going to test: matMallocInStack
	//-------------------------------------------------------------
	double		buffer = 256.512;
	VECTOR* v1 = (VECTOR*)matMallocInStack(3,1);
	VECTOR* v2 = (VECTOR*)matMallocInStack(3,1);
	v1 = vecMallocInStack(3);
	//_VECTOR(3)	v1,v2;
	////vecInitialize((VECTOR*)&v1,3);
	////vecInitialize((VECTOR*)&v2,3);

	vecSetValue(v1,0,buffer);
	if(vecGetValue(v1,0) != buffer)	// test if index 0 consistent with buffer
		return 0;

	buffer  = vecGetValue(v1,3);	// test if over-index accessing

	buffer = vecLength(v1);

	for(int i=0;i<3;i++){
		vecSetValue(v1,i,(double)(rand()%10));
		vecSetValue(v2,i,(double)(rand()%10));
	}

	buffer = vecDotProduct		(v1,v2);
	buffer = vecCrossProduct2D	(v1,v2);
	//	done  , worked , Hsien , 2012.09.17
	//	no need to do cast-back , when using vector manipulator

	//	all test done
	return 1;
}