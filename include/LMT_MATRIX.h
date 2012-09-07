//----------------------------------------------------------------------------------
// FILENAME			: matrix.h
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.06
// NOTES			: 
//	0. generic matrix data-structure and operations
//	1. all function are passed-by-reference , to save memory and increase efficiency
//		for those arguments prefix by 'const' , means they'r input arguments
//	2. namespace: mat
//	3. lack of error prevent machanism , due to this library is mainly used by
//			us RDs , we should manuelly prevent coding-error.
//----------------------------------------------------------------------------------
#ifndef	_MATRIX_H
#define _MATRIX_H
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define ELEMTYPE	double			// possible to change type

typedef struct	matrixHeader_st	MATRIX_HEADER;
typedef	struct	matrix_st		MATRIX;			// the abstrct class of matrix/vector

#define _MATRIX( m , n )	struct{MATRIX_HEADER attr;ELEMTYPE body[m][n];}	// template macro to declare matrix object 

struct matrixHeader_st
{
	//---------------------------------------------------------------------
	//	COMMON ATTRIBUTE FOR BOTH STATIC/DYNAMIC/attribute dimension matrix
	//	for controlling dimension information
	//---------------------------------------------------------------------
	int	matId	;
	size_t	_m	;		//	dimension m	, number of rows	, beginning at ONE
	size_t	_n	;		//	dimension n	, number of columns	, beginning at ONE
	ELEMTYPE	*bodyAdr;	// used to recoding body's base address
};

struct matrix_st
{
	//---------------------------------
	//	generic type used to casting up
	//---------------------------------
	MATRIX_HEADER	attr;
	char			body;
};

//MATRIX*	matCreateInStack(const size_t row,const size_t cols);				// use void *_malloca() , to create matrix in stack
int		matInitialize	(MATRIX*,const size_t rows,const size_t columns);	// intializing matrix according to unique type-id
																			// no dynamic(heap) matrix avaliable
int		matIdentity		(MATRIX*);
int		matMarkId		(MATRIX*,const size_t	id);

//----------------------------------------------------------------------
//	Element Accessing, return values are error code for every functions
//----------------------------------------------------------------------
int		matGetElement	(MATRIX*	
						 ,const size_t	row
						 ,const size_t	column
						 ,double*	value);
int		matGetSubmatrix	(MATRIX*	
						 ,const size_t	fr
						 ,const size_t	lr
						 ,const size_t	fc
						 ,const size_t	lc
						 ,MATRIX*	submatrix);

int		matSetElement	(MATRIX*	,const size_t	row,const size_t	column,const double value);
int		matSetAll		(MATRIX*	,const double value);			// matrix magnitude
int		matAssign		(MATRIX*	rhs,MATRIX*	lhs);			// rhp = right-hand side , lhs = rhs

int		matScalarMultiply	(MATRIX* left,const double	scalar		,MATRIX*	result);	//	result = scalar*left
int		matMultiply			(MATRIX* left,MATRIX*	right,MATRIX*	result);	//	result = left*right
int		matAdd				(MATRIX* operand1,MATRIX*	operand2	,MATRIX*	result);	//	result = operand1 + operand2
int		matMinus			(MATRIX* minuend ,MATRIX*	subtrahend	,MATRIX*	result);
int		matNorm2			(MATRIX*,double*	norm2);										//	norm-2(normFrobenius) , such as vector	
																							//	squart(sigma(element^2))																							//	generic definition for all matrix
//---------------
//	Advenced operation
//---------------
int		matDeterminant		(MATRIX*,double*	det);	// not implemented
int		matInverse			(MATRIX*,MATRIX*);			// not implemented

#endif
																							