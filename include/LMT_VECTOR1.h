//----------------------------------------------------------------------------------
// FILENAME			: vector.h
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.06
// NOTES			:	vector structure and operations , inheritanted from matrix.h
//						some of functions share the same function object with matrix library
//						use function-pointer to rename these functions
//	loosen vector functions
//	neither rowVector nor colVector are treat as n-tuple vector
//-------------------------------------------------------------
#ifndef _VECTOR_H
#define _VECTOR_H

#include<LMT_MATRIX.h>

typedef struct	matrix_st	VECTOR						;

#define	_VECTOR(k)			struct{MATRIX_HEADER attr;ELEMTYPE body[k];}	// template macro to declare matrix object 	

int			vecInitialize		(VECTOR* v,const size_t length);
//-----------------
//	element accessing
//------------------
int			vecGetValue			(VECTOR* v,const size_t	index,double* value);
int			vecSetValue			(VECTOR* v,const size_t	index,const double value);
extern int	(&vecSetAll)(VECTOR*,const double);	// alias function , reuse
extern int	(&vecAssign)(VECTOR* lhs,VECTOR* rhs);		// alias function , reuse
														// operation: lhs = rhs;
														// lhs = left-hand side	 , so on for rhs
//-------------------
//	exclusive vector operations
//-------------------
extern int	(&vecLength)(VECTOR* v	,double*	length);
extern int	(&vecAdd)	(VECTOR* v1	,VECTOR* v2,VECTOR* vResult);	
extern int	(&vecMinus)	(VECTOR* vMinuend,VECTOR* vSubtrahend,VECTOR* vResult);	// vResult  = vMinuend - vSubtrahend
int		vecDotProduct		(VECTOR* v1,VECTOR* v2,double*	scalar);			//	scalar = v1 . v2
int		vecCrossProduct		(VECTOR* v1,VECTOR* v2,VECTOR*	vPerpendicular);	// dimension-3 vector valid only

extern int	(&vecScalarMultiply)(VECTOR* v,const double scalar,VECTOR* vResult);
int			vecUnit(VECTOR* v,VECTOR* vUnit);

#endif 