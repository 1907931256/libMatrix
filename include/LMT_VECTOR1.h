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
typedef int (*fp_type0)(VECTOR*,const double)				;
typedef int (*fp_type1)(VECTOR*,double*)				;
typedef	int	(*fp_type2)(VECTOR*,VECTOR*)				;
typedef	int	(*fp_type3)(VECTOR*,VECTOR*,VECTOR*)		;

#define	_VECTOR(k)			struct{MATRIX_HEADER attr;ELEMTYPE body[k];}	// template macro to declare matrix object 	

int			vecInitialize		(VECTOR* v,const size_t length);
//-----------------
//	element accessing
//------------------
int			vecGetValue			(VECTOR* v,const size_t	index,double* value);
int			vecSetValue			(VECTOR* v,const size_t	index,const double value);
extern int	(&vecSetAll)(VECTOR*,const double);	// alias function
extern int	(&vecAssign)(VECTOR*,VECTOR*);
//-------------------
//	exclusive vector operations
//-------------------
extern int	(&vecLength)(VECTOR*,double*);
extern int	(&vecAdd)	(VECTOR*,VECTOR*,VECTOR*);	
int		vecDotProduct		(VECTOR* v1,VECTOR* v2,double*	scalar);			//	scalar = v1 . v2
int		vecCrossProduct		(VECTOR* v1,VECTOR* v2,VECTOR*	vPerpendicular);	// dimension-3 vector valid only

#endif 