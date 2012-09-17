//----------------------------------------------------------------------------------
// FILENAME			: coord.cpp
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.17
// NOTES			:	
//		function including:
//					1. scaling function(09/17)
//					2. vector building(09/17)
//					3. array conversion(09/17)
//----------------------------------------------------------------------------------
#include<LMT_COORD.h>

COORD*	(&coordBuildVector)(COORD*	end,COORD* start,VECTOR* vec)	= vecMinus;
void	(&coordFwrite)(COORD*,FILE* fp)								= vecFwrite;

COORD*	array2Coord			(COORD*	coord,ELEMTYPE	a[])			// convert array form of coordinate into type COORD
{
	//----------------------------
	//	directly assignment
	//		3d,4d coordinate exclusively
	//----------------------------
	coord->attr.bodyAdr[0] = a[0];
	coord->attr.bodyAdr[1] = a[1];
	coord->attr.bodyAdr[2] = a[2];

	return coord;
}

void	coord2Array			(COORD*	coord,ELEMTYPE	a[])
{
	//----------------------------
	//	directly assignment
	//		3d,4d coordinate exclusively
	//----------------------------
	a[0] = coord->attr.bodyAdr[0];
	a[1] = coord->attr.bodyAdr[1];
	a[2] = coord->attr.bodyAdr[2];
}

COORD* coordScale(COORD* givenPoint
				  ,COORD* scalePivot
				  ,double i
				  ,double j
				  ,double k
				  ,COORD* scaledPoint)
{
	//----------------------------------------------------------------------
	//	mathmatical model:
	//		scaledPoint = scaleMatrix(givenPoint - scalePivot) + scalePivot
	//			which i,j,k would affect scaleMatrix
	//		Hsien , 2012.09.14
	//----------------------------------------------------------------------
	_MATRIX(_DIM,_DIM)		scaleMatrix;
	_VECTOR(_DIM)			vecBuffer;

	matInitialize((MATRIX*)&scaleMatrix,_DIM,_DIM);
	vecInitialize((VECTOR*)&vecBuffer,_DIM);

	matIdentity((MATRIX*)&scaleMatrix);

	matSetElement((MATRIX*)&scaleMatrix,0,0,i);	// set-up scaling matrix , factor as diagonals
	matSetElement((MATRIX*)&scaleMatrix,1,1,j);
	matSetElement((MATRIX*)&scaleMatrix,2,2,k);

	vecMinus((VECTOR*)givenPoint,(VECTOR*)scalePivot,(VECTOR*)&vecBuffer);
	matMultiply((MATRIX*)&scaleMatrix,(MATRIX*)&vecBuffer,(VECTOR*)&vecBuffer);
	vecAdd((VECTOR*)&vecBuffer,(VECTOR*)scalePivot,(VECTOR*)scaledPoint);

	return scaledPoint;
}