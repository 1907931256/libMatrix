//#include"windows.h"
//#undef COORD
#include<stdlib.h>
#include<time.h>
#include<LMT_COORD.h>

int main()
{
	//-------------------------------------------------------------
	//	going to test: array2Coord , coordCreate , coordBuildVector , 
	//					coordScale
	//-------------------------------------------------------------
	double	b;
	double  a[3];
	VECTOR*		vecBuffer	= vecMallocInStack(_DIM);
	for(int i=0;i<3;i++)
		a[i] = (double)(rand()%10);
	COORD*	p1 = coordCreate();
	COORD*	p2 = coordCreate();
	VECTOR*	v1 = vecMallocInStack(3);

	array2Coord(p1,a);
	v1 = coordBuildVector(p2,p1,v1);
	vecFwrite(v1,stdout);
	coordScale(p1,p2,0.1,2,3.2,p1);
	coordFwrite(p1,stdout);

	b = vecGetValue((VECTOR*)p1,0);
	b = vecGetValue((VECTOR*)p1,1);
	b = vecGetValue((VECTOR*)p1,2);
	// done , but allocating in stack is not really stable
	//	need to check it much more
	//	Hsien , 2012.09.17

	return 1;
}