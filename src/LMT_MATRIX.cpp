//----------------------------------------------------------------------------------
// FILENAME			: matrix.cpp
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.06
// NOTES			: 
//	0. generic matrix data-structure and operations
//	1. all function are passed-by-reference , to save memory and increase efficiency
//		for those arguments prefix by 'const' , means they'r input arguments
//	2. namespace: mat
//	rowIndex		= runningIndex/_n + 1 , cause beginning at one
//	colIndex		= reminder(runningIndex/_n) + 1 , 
//	runningIndex	= (rowIndex-1)*_n + (columnIndex-1)
//	totalLength		= _m*_n;
//----------------------------------------------------------------------------------
#include<string.h>
#include<math.h>	
#include<malloc.h>		// for void *_alloca(  size_t size ) , memory-allocating in stack
#include<stdio.h>
#include<LMT_MATRIX.h>

#define	IS_SQUARE	1
#define	NOT_SQUARE	0


static	char	isMatSquare		(MATRIX* mat)
{
	//-----------
	//	check if object matrix is square
	//-----------
	if(mat->attr._m == mat->attr._n)
		return	IS_SQUARE;
	else
		return	NOT_SQUARE;
}

MATRIX* matMarkId		(MATRIX* mat,const size_t	id)
{
	mat->attr.matId = id;
	return mat;
}

/*int*/MATRIX*		matInitialize2	(void* mat,void* body,const size_t rows,const size_t columns)		// intializing matrix according to unique type-id
{
	//mat = _malloca(sizeof(MATRIX));
	((MATRIX*)mat)->attr.bodyAdr = (ELEMTYPE*)body;
	matInitialize((MATRIX*)mat,rows,columns);

	return (MATRIX*)mat;
}

/*int*/MATRIX*		matInitialize	(MATRIX* mat,const size_t rows,const size_t columns)		// intializing matrix according to unique type-id
{
	//--------------------
	//	do error prevent before	attribute setting
	//	return Matrix* for cascade usage.
	//	Hsien , 2012.09.17
	//--------------------
	if(rows == 0 || columns == 0)
		return 0;	// null matrix is not allowed

	mat->attr._m = rows;
	mat->attr._n = columns;
	mat->attr.bodyAdr = (ELEMTYPE*)&mat->body;

	memset(mat->attr.bodyAdr,0,sizeof(ELEMTYPE)* mat->attr._m * mat->attr._n);		// reset internal buffer

	return mat;
}

/*int*/MATRIX*		matIdentity		(MATRIX*	mat)
{
	size_t rowIndex,colIndex;

	if(isMatSquare(mat) == NOT_SQUARE)
		return NULL;

	memset(mat->attr.bodyAdr,0,sizeof(ELEMTYPE)* mat->attr._m * mat->attr._n);		// reset internal buffer
	//---------------------------
	//	make diagonal are one's
	//---------------------------
	for(size_t i=0;i<(mat->attr._m * mat->attr._n );i++){
		rowIndex	= (i/mat->attr._n) + 1;
		colIndex	= (i%mat->attr._n) + 1;
		if( rowIndex == colIndex)
			mat->attr.bodyAdr[i]		= 1;
	}

	return /*1*/mat;		// return reference to do cascade using
}

ELEMTYPE		matGetElement	(MATRIX*	mat,const size_t	row,const size_t	col/*,double*	value*/)
{
	//---------------
	//	Over-index checking
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//	Function Prototype Changed , return required value
	//		Hsien , 2012.09.07 , recommented by Peter
	//---------------
	if(row >= mat->attr._m
		|| col >= mat->attr._n) // over-index condition , index greater/equal to length
		return 0;

	/*value =*/ return mat->attr.bodyAdr[row/*(row-1)*/ * mat->attr._n + col/*(col-1)*/];

	/*return 1;*/
}
/*int*/MATRIX*		matGetSubmatrix	(MATRIX*	mainMat
						 ,const size_t	fr
						 ,const size_t	lr
						 ,const size_t	fc
						 ,const size_t	lc
						 ,MATRIX*	subMat)
{
	//------------------------------------------------------------
	//	dimension checking , fr,lr,fc,lc should be consistent with 
	//		dimension of submatrix and mainmatrix
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//------------------------------------------------------------
	size_t	sm,sn,elemShift;		// dimension of required submatrix
	sm = lr - fr + 1;
	sn = lc - fc + 1;
	elemShift = /*(fr -1)*/fr * mainMat->attr._n + /*(fc -1)*/fc;

	if(sm > subMat->attr._m
		|| sn > subMat->attr._n)
		return 0;

	for(size_t	rowIndex = 0;	rowIndex<sm;	rowIndex++){
		for(size_t	colIndex = 0;	colIndex<sn;	colIndex++){
			subMat->attr.bodyAdr[rowIndex*sn + colIndex]
			= mainMat->attr.bodyAdr[elemShift + colIndex];	// shifting
		}
		elemShift += mainMat->attr._n;		// row shifting
	}

	return /*1*/subMat;
}
/*int*/MATRIX*		matSetElement	(MATRIX*	mat,const size_t	row,const size_t	col,const double value)
{
	//---------------------
	//	Over-index checking
	//	row : beginning at 1
	//	col : as well
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//---------------------
	if(row >= mat->attr._m
		|| col >= mat->attr._n)		// over-index condition , index greater/equal to length
		return 0;

	mat->attr.bodyAdr[row/*(row-1)*/ * mat->attr._n + col/*(col-1)*/] = value;

	return /*1*/mat;
}
/*int*/MATRIX*		matSetAll		(MATRIX*	mat,const double value)
{
	for(size_t i=0;i<(mat->attr._m * mat->attr._n);i++)
		mat->attr.bodyAdr[i] = value;
	return /*1*/mat;
}
/*int*/MATRIX*		matAssign		(MATRIX*	rhs,MATRIX*	lhs)
{
	//------------
	//	if Dimension checking passed , directly
	//	doing array assignment 
	//------------
	for(size_t i=0;i<(rhs->attr._m * rhs->attr._n);i++)
		rhs->attr.bodyAdr[i] = lhs->attr.bodyAdr[i];
	return /*1*/lhs;
}
/*int*/MATRIX*	matScalarMultiply	(MATRIX* origin,const double	scalar		,MATRIX*	result)
{
	//-------
	//
	//-------
	for(size_t i=0;i<(origin->attr._m * origin->attr._n);i++)
		result->attr.bodyAdr[i] 
	= origin->attr.bodyAdr[i] * scalar;

	return /*1*/result;
}
/*int*/MATRIX*		matMultiply			(MATRIX* left,MATRIX*	right		,MATRIX*	result)
{
	//-------------
	//	rowIndex : result-matrix's rowIndex
	//	colIndex : result-matrix's colIndex
	//	k		 : running index for left's column and right's row
	//-------------
	ELEMTYPE	buffer = 0;

	for(size_t rowIndex = 0;rowIndex < result->attr._m; rowIndex++)
		for(size_t colIndex = 0;colIndex < result->attr._n;colIndex++){
			buffer = 0;
			for(size_t	k = 0; k < left->attr._n ; k++){
				buffer
					+=	(left->attr.bodyAdr	[rowIndex	*left->attr._n	+ k]
					*	right->attr.bodyAdr	[k			*right->attr._n	+ colIndex]);
			}
			result->attr.bodyAdr[rowIndex	*result->attr._n + colIndex] 
			= buffer;		// assign accumulation result into element
		}

		return /*1*/result;
}
/*int*/MATRIX*	matAdd				(MATRIX* operand1,MATRIX*	operand2,MATRIX*	result)
{
	//-------------------
	//
	//-------------------
	for(size_t	i=0;i < (operand1->attr._m * operand1->attr._n) ; i++)
		result->attr.bodyAdr[i] = 
		operand1->attr.bodyAdr[i] + operand2->attr.bodyAdr[i];

	return /*1*/result;
}

/*int*/MATRIX*		matMinus			(MATRIX* minuend ,MATRIX*	subtrahend	,MATRIX*	result)
{
	//---------------------
	//	similiar to mat add
	//	Hsien , 2012.09.07
	//---------------------
	for(size_t	i=0;i < (minuend->attr._m * minuend->attr._n) ; i++)
		result->attr.bodyAdr[i] = 
		minuend->attr.bodyAdr[i] - subtrahend->attr.bodyAdr[i];

	return /*1*/result;
}

/*int*/ELEMTYPE		matNorm2			(MATRIX* mat/*,double*	norm2*/)
{
	//-----------------------------------------------------
	//	Function Prototype Changed , return required value
	//		Hsien , 2012.09.07 , recommented by Peter
	//----------------------------------------------------
	ELEMTYPE	buffer = 0;

	for(size_t i=0;i< (mat->attr._m * mat->attr._n); i++)
		buffer += pow(mat->attr.bodyAdr[i],2);
	/**norm2*/buffer = sqrt(buffer);

	/*return 1;*/
	return buffer;
}

void matFwrite(MATRIX*	mat,FILE*	fp)
{
	//----------------
	//	regular output
	//		print out : 1. ID
	//				  : 2. values
	//----------------
	fprintf(fp,"mid:%d\n",mat->attr.matId);

	for(size_t i=0;i<mat->attr._m;i++){
		for(size_t j=0;j<mat->attr._n;j++){
			fprintf(fp,"%.4f\t",mat->attr.bodyAdr[i*mat->attr._n + j]);
		}
		fprintf(fp,"\n");
	}
}