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
//	4. accessing index beginning from ZERO
//----------------------------------------------------------------------------------
#ifndef	_MATRIX_H
#define _MATRIX_H
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define ELEMTYPE	double			// possible to change type

typedef struct	matrixHeader_st	MATRIX_HEADER;
typedef	struct	matrix_st		MATRIX;			// the abstrct class of matrix/vector

#define _MATRIX( m , n )		struct{MATRIX_HEADER attr;ELEMTYPE body[m][n];}	// template macro to declare matrix object 
//#define	matMallocInStack(m,n)	(MATRIX*)matInitialize2(_alloca(sizeof(MATRIX)),_alloca(sizeof(ELEMTYPE) * m * n),m,n)
																				// macro to allocating in stack  , would be do garbage-collation automatically
																				// facility added by Hsien , 2012.09.17
																				// expremental function , stack is need to deallocating as well
																				// otherwise , would cause stack-overflow for thread.
																				

struct matrixHeader_st
{
	//---------------------------------------------------------------------
	//	COMMON ATTRIBUTE FOR BOTH STATIC/DYNAMIC/attribute dimension matrix
	//	for controlling dimension information
	//---------------------------------------------------------------------
	int	matId	;
	size_t	_m	;		//	dimension m	, number of rows	
	size_t	_n	;		//	dimension n	, number of columns	
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

MATRIX*		matInitialize2	(void* mat,void* body,const size_t rows,const size_t columns);
MATRIX*		matInitialize	(MATRIX*,const size_t rows,const size_t columns);	// intializing matrix according to unique type-id
																			// no dynamic(heap) matrix avaliable
																			// return intialized/input reference of matrix
MATRIX*		matIdentity		(MATRIX*);
MATRIX*		matMarkId		(MATRIX*,const size_t	id);

void matFwrite(MATRIX*	mat,FILE*	fp);		// debuggin usage , do stream output

//----------------------------------------------------------------------
//	Element Accessing, return values are error code for every functions
//----------------------------------------------------------------------
ELEMTYPE		matGetElement	(MATRIX*	
						 ,const size_t	rowIndex
						 ,const size_t	colIndex);			// index beginning from ZERO
MATRIX*		matGetSubmatrix	(MATRIX*	mainmatrix
						 ,const size_t	fr
						 ,const size_t	lr
						 ,const size_t	fc
						 ,const size_t	lc
						 ,MATRIX*	submatrix);			// index beginning from ZERO , return submatrix

MATRIX*		matSetElement	(MATRIX*	
						 ,const size_t	rowIndex
						 ,const size_t	colIndex
						 ,const double value);			// index beginning from ZERO
MATRIX*		matSetAll		(MATRIX*	,const double value);			// matrix magnitude
MATRIX*		matAssign		(MATRIX*	rhs,MATRIX*	lhs);				// rhp = right-hand side , lhs = rhs , return lhs

MATRIX*		matScalarMultiply	(MATRIX* left,const double	scalar		,MATRIX*	result);	//	result = scalar*left , return result
MATRIX*		matMultiply			(MATRIX* left,MATRIX*	right,MATRIX*	result);				//	result = left*right , return result
MATRIX*		matAdd				(MATRIX* operand1,MATRIX*	operand2	,MATRIX*	result);	//	result = operand1 + operand2
MATRIX*		matMinus			(MATRIX* minuend ,MATRIX*	subtrahend	,MATRIX*	result);	//  return result
ELEMTYPE		matNorm2(MATRIX* mat);					//	norm-2(normFrobenius) , such as vector	
														//	squart(sigma(element^2))																							
														//	generic definition for all matrix
														//	Function Prototype Changed , return required value
//---------------
//	Advenced operation
//---------------
ELEMTYPE		matDeterminant		(MATRIX*);	// not implemented
MATRIX*					matInverse		(MATRIX* mat,MATRIX* matAfterInverse);			// not implemented

#endif
																							