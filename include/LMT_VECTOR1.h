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
ELEMTYPE			vecGetValue			(VECTOR* v,const size_t	index);		// index beginning from ZERO
int					vecSetValue			(VECTOR* v,const size_t	index,const double value);		// index beginning from ZERO
extern int	(&vecSetAll)(VECTOR*,const double);			// alias function , reuse
extern int	(&vecAssign)(VECTOR* lhs,VECTOR* rhs);		// alias function , reuse
														// operation: lhs = rhs;
														// lhs = left-hand side	 , so on for rhs
//-------------------
//	exclusive vector operations
//-------------------
extern ELEMTYPE	(&vecLength)(VECTOR* v);			//	Function Prototype Changed , return required value
extern int	(&vecAdd)	(VECTOR* v1	,VECTOR* v2,VECTOR* vResult);	
extern int	(&vecMinus)	(VECTOR* vMinuend,VECTOR* vSubtrahend,VECTOR* vResult);	// vResult  = vMinuend - vSubtrahend
ELEMTYPE		vecDotProduct		(VECTOR* v1,VECTOR* v2);			//	scalar = v1 . v2
int			vecCrossProduct		(VECTOR* v1,VECTOR* v2,VECTOR*	vPerpendicular);	// dimension-3 vector valid only
ELEMTYPE	vecCrossProduct2D	(VECTOR* v1,VECTOR* v2);							// dimension-2 vector valid only , Hsien , 2012.09.07
																					// return = v1[0]*v2[1] + v1[1]*v2[0] , single component of other two parts of vector
extern int	(&vecScalarMultiply)(VECTOR* v,const double scalar,VECTOR* vResult);
int			vecUnit(VECTOR* v,VECTOR* vUnit);

#endif 