//----------------------------------------------------------------------------------
// FILENAME			: coord.h
// ORIGIN AUTHOR	: Hsien
// EDITOR			: Hsien, 2012.09.17
// NOTES			: typedef system , inheritant from VECTOR	
//-------------------------------------------------------------
#ifndef _COORD_H
#define _COORD_H
#include<LMT_VECTOR1.h>		// inheritant from vector

#define	_DIM	3			// if in HTM form , DIM should be 4 , to utilize all coordinate/vector

typedef VECTOR COORD;
#define coordCreate()		(COORD*)vecMallocInStack(_DIM)			//

extern	void	(&coordFwrite)(COORD*,FILE* fp);					// to showing-up the values of COORD

COORD*	array2Coord			(COORD*	coord,ELEMTYPE	a[]);			// convert array form of coordinate into type COORD
void	coord2Array			(COORD*	coord,ELEMTYPE	a[]);			// inconversion of array

extern	COORD*		(&coordBuildVector)(COORD*	end,COORD* start,VECTOR* vec);	// vec = start - end
COORD*	coordScale	(COORD* givenPoint
					 ,COORD* scalePivot
					 ,double i
					 ,double j
					 ,double k
					 ,COORD* scaledPoint);		// scaling 

#endif	_COORD_H