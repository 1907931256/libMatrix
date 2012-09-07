//----------------------------------------------------------------------------------
// FILENAME			: vector.h
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.06
// NOTES			:	vector structure and operations , inheritanted from matrix.h
//						some of functions share the same function object with matrix library
//						use function-pointer to rename these functions
//----------------------------------------------------------------------------------
#include<LMT_VECTOR1.h>

int	(&vecSetAll)(VECTOR*,const double)	 =	matSetAll;
int	(&vecAssign)(VECTOR*,VECTOR*)		 =	matAssign;
/*int*/ELEMTYPE	(&vecLength)(VECTOR*/*,double**/)		 =	matNorm2;
int	(&vecAdd)	(VECTOR*,VECTOR*,VECTOR*)=	matAdd;		// added by Hsien 
int	(&vecMinus)	(VECTOR*,VECTOR*,VECTOR*) = matMinus;
int	(&vecScalarMultiply)(VECTOR*,const double,VECTOR*) = matScalarMultiply;

int		vecInitialize(VECTOR* v,const size_t length)
{
	if(!matInitialize((MATRIX*)v,length,1))		// as column vector
		return 0;

	return 1;
}
int			vecSetValue			(VECTOR* v,const size_t	index,const double value)
{
	//-----------------------------------------------------
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//-----------------------------------------------------
	if(!matSetElement((MATRIX*)v,index,0,value))
		return 0;
	return 1;
}
/*int*/ELEMTYPE			vecGetValue			(VECTOR* v,const size_t	index/*,double* value*/)
{
	//-----------------------------------------------------
	//		All index are normalized to beginning from ZERO
	//		Hsien , 2012.09.07
	//	Function Prototype Changed , return required value
	//		Hsien , 2012.09.07 , recommented by Peter
	//----------------------------------------------------
	//if(!matGetElement((MATRIX*)v,index,0,value))
	//	return 0;
	//return 1;
	return matGetElement((MATRIX*)v,index,0);
}
int		vecCrossProduct		(VECTOR* v1,VECTOR* v2,VECTOR*	vPerpendicular)
{
	//-----------------
	//	Dimension-3 ONLY:
	//	In mathematics, the cross product, vector product, or Gibbs' vector product is a binary operation on two vectors 
	//	in three-dimensional space , definition from WIKI
	//-----------------

	//-----------------
	//	Dimension check
	//-----------------

	vPerpendicular->attr.bodyAdr[0] = 
		v1->attr.bodyAdr[1] * v2->attr.bodyAdr[2]
	-	v1->attr.bodyAdr[2]	* v2->attr.bodyAdr[1];

	vPerpendicular->attr.bodyAdr[1] = 
		v1->attr.bodyAdr[2] * v2->attr.bodyAdr[0]
	-	v1->attr.bodyAdr[0]	* v2->attr.bodyAdr[2];

	vPerpendicular->attr.bodyAdr[2] = 
		v1->attr.bodyAdr[0] * v2->attr.bodyAdr[1]
	-	v1->attr.bodyAdr[1]	* v2->attr.bodyAdr[0];

	return 1;
}

/*int*/ELEMTYPE		vecDotProduct		(VECTOR* v1,VECTOR* v2/*,double*	scalar*/)
{
	//--------------------------
	//	extension of matMultiply
	//		iterated by _m , Hsien , 2012.09.06
	//--------------------------
	/**scalar = 0;*/
	ELEMTYPE scalar = 0;
	for(size_t	elemIndex = 0;elemIndex < v1->attr._m ; elemIndex++)
		/***/scalar +=	
		v1->attr.bodyAdr[elemIndex] * v2->attr.bodyAdr[elemIndex];

	return scalar/*1*/;
}

int			vecUnit(VECTOR* v,VECTOR* vUnit)
{
	//-----------------
	//	implemented @ 7.Sep.2012
	//	Function Prototype Changed , return required value
	//		Hsien , 2012.09.07 , recommented by Peter
	//----------------------------------------------------
	//double length = 0;
	//vecLength(v,&length);					// calculate length of vector
	vecScalarMultiply(v,1/vecLength(v)/*length*/,vUnit);	// vUnit = v/||v||;

	return 1;
}

ELEMTYPE	vecCrossProduct2D	(VECTOR* v1,VECTOR* v2)
{
	//-----------------------------------------------------------------------------------
	// dimension-2 vector valid only , Hsien , 2012.09.07
	// return = v1[0]*v2[1] + v1[1]*v2[0] , single component of other two parts of vector
	//-----------------------------------------------------------------------------------
	return 		v1->attr.bodyAdr[0] * v2->attr.bodyAdr[1]-	v1->attr.bodyAdr[1]	* v2->attr.bodyAdr[0];
}