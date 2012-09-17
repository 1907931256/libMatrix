//----------------------------------------------------------------------------------
// FILENAME			: matrix.h
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.06
// NOTES			: 
//	0. type-defined vector data-structure and operations
//	1. namespace: mat , xxxVec
//	strict vector functions	
//	, vectors are further categroried into rowVector and colVector
//----------------------------------------------------------------
#ifndef _MATRIX_VEC_H
#define _MATRIX_VEC_H
#include<LMT_VECTOR1.h>

typedef	struct	matrix_st	ROW_VECTOR;
typedef struct	matrix_st	COL_VECTOR;

#define _ROW_VECTOR( i )	struct{MATRIX_HEADER attr;ELEMTYPE body[i];}	// template macro to declare matrix object 
#define _COL_VECTOR( j )	struct{MATRIX_HEADER attr;ELEMTYPE body[j];}	// template macro to declare matrix object 

#define	rowMallocInStack(n)	(ROW_VECTOR*)matMallocInStack(1,n)	
#define	colMallocInStack(m)	(COL_VECTOR*)matMallocInStack(m,1)	


//----------------------------------------------------------------
//	strict vector functions	
//	, vectors are further categrories into rowVector and colVector
//----------------------------------------------------------------
/*int*/VECTOR*			rowVecInitialize(ROW_VECTOR*,const size_t cols);
extern /*int*/VECTOR*	(&colVecInitialize)(VECTOR*,const size_t);


/*int*/VECTOR*	matGetRowVector	(MATRIX*,const size_t	row,ROW_VECTOR*);
/*int*/VECTOR*		matGetColVector	(MATRIX*,const size_t	col,COL_VECTOR*);

#endif