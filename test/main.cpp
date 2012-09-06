#include<vector.h>
//#define MATRIX(m,n)	struct{int matId;static const size_t _m = m;/*static const*/ size_t _n/*=n*/;double body[m][n];}
//#define ROW_VECTOR
//#define COL_VECTOR

int main()
{
	//struct	{static const int i;} var(1);

	_MATRIX(64,64)	mat;
	_MATRIX(64,64)	mat2;
	_MATRIX(3,3)	mat3;
	_MATRIX(3,3)	mat4;
	_ROW_VECTOR(3)	rv;
	_COL_VECTOR(3)	cv;
	_COL_VECTOR(3)	cv2;
	
	double	buffer;
	matInitialize((MATRIX*)&mat,64,64);	// result is fine , Hsien ,  2012.09.04
	matInitialize((MATRIX*)&mat2,64,64);
	matInitialize((MATRIX*)&mat3,3,3);
	matInitialize((MATRIX*)&mat4,3,3);

	matInitialize((MATRIX*)&rv,1,3);
	matInitialize((MATRIX*)&cv,3,1);
	matInitialize((MATRIX*)&cv2,3,1);
	//struct	st{int a;static const int i=3;}	m;

	matGetElement	((MATRIX*)&mat,1,1,&buffer);
	matGetElement	((MATRIX*)&mat,2,2,&buffer);
	matGetElement	((MATRIX*)&mat,64,64,&buffer);
	matGetElement	((MATRIX*)&mat,25,40,&buffer);
	// successed

	matSetElement	((MATRIX*)&mat,3,2,89.98);	// fine
	matSetAll		((MATRIX*)&mat,32767);		// fine
	matAssign		((MATRIX*)&mat2,(MATRIX*)&mat);	// fine

	matScalarMultiply((MATRIX*)&mat,0.1,(MATRIX*)&mat);//fine

	matSetAll((MATRIX*)&rv,3);
	matSetAll((MATRIX*)&cv,3);
	vecDotProduct((ROW_VECTOR*)&rv,(COL_VECTOR*)&cv,&buffer);	//fine

	matSetAll((MATRIX*)&mat3,32);
	matSetElement((MATRIX*)&mat3,1,3,0);
	matSetElement((MATRIX*)&mat3,2,3,1);
	matSetElement((MATRIX*)&mat3,3,3,2);
	matGetSubmatrix((MATRIX*)&mat3,1,3,3,3,(MATRIX*)&cv2);
	matGetSubmatrix((MATRIX*)&mat3,1,3,2,2,(MATRIX*)&cv2);	//fine

	matSetAll((MATRIX*)&mat4,1);
	matMultiply((MATRIX*)&mat4,(MATRIX*)&mat3,(MATRIX*)&mat3);

	matIdentity((MATRIX*)&mat3);
	matIdentity((MATRIX*)&mat4);
	matMultiply((MATRIX*)&mat4,(MATRIX*)&mat3,(MATRIX*)&mat3);	// fine

	matAdd((MATRIX*)&mat3,(MATRIX*)&mat4,(MATRIX*)&mat3);	// fine

	matNorm2((MATRIX*)&mat3,&buffer);			// fine

	return 0;
}