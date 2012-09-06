//----------------------------------------------------------------
//	strict vector functions	
//	, vectors are further categrories into rowVector and colVector
//----------------------------------------------------------------
#include<LMT_VECTOR2.h>

int rowVecInitialize(ROW_VECTOR* rv,const size_t cols)
{
	//---------------
	//	Repack matrix intialize function
	//---------------
	if(!matInitialize((MATRIX*)rv,1,cols))
		return 0;

	return 1;
}

int		matGetRowVector	(MATRIX* mat,const size_t	row,ROW_VECTOR* rv)
{
	//------
	//	extension usage of matGetSubmatrix
	//------
	matGetSubmatrix(mat
		,row
		,row
		,1
		,rv->attr._n
		,(MATRIX*)&rv);
	return 1;
}
int		matGetColVector	(MATRIX* mat,const size_t	col,COL_VECTOR* cv)
{
	//------
	//	extension usage of matGetSubmatrix
	//------
	matGetSubmatrix(mat
		,1
		,mat->attr._m
		,col
		,col
		,(MATRIX*)&cv);
	return 1;
}