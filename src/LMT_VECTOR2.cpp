//----------------------------------------------------------------
//	strict vector functions	
//	, vectors are further categrories into rowVector and colVector
//----------------------------------------------------------------
#include<LMT_VECTOR2.h>

/*int*/COL_VECTOR*	(&colVecInitialize)(VECTOR*,const size_t) = vecInitialize;


/*int*/ROW_VECTOR* rowVecInitialize(ROW_VECTOR* rv,const size_t cols)
{
	//---------------
	//	Repack matrix intialize function
	//---------------
	if(!matInitialize((MATRIX*)rv,1,cols))
		return NULL;

	return rv;
}

/*int*/ROW_VECTOR*		matGetRowVector	(MATRIX* mat,const size_t	row,ROW_VECTOR* rv)
{
	//------
	//	extension usage of matGetSubmatrix
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//-----------------------------------------------------
	matGetSubmatrix(mat
		,row
		,row
		,/*1*/0
		,/*(rv->attr._n)*/(rv->attr._n)-1
		,(MATRIX*)&rv);
	return rv;
}
/*int*/COL_VECTOR*		matGetColVector	(MATRIX* mat,const size_t	col,COL_VECTOR* cv)
{
	//-----------------------------------------------------
	//	extension usage of matGetSubmatrix
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//-----------------------------------------------------
	matGetSubmatrix(mat
		,0
		,/*mat->attr._m*/(mat->attr._m)-1
		,col
		,col
		,(MATRIX*)&cv);
	return cv;
}