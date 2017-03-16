#include <stdio.h>
#include "triangle.hpp"

int triangle_type( int a, int b, int c ) {
	if (a < 1 || b < 1 || c < 1 || a > 200 || b > 200 || c > 200)
		return TYPE_INVALID_INPUT;
	if( !(a + b > c && a + c > b && b + c > a) )
		return TYPE_NOTTRIANGLE;
	if( a==b || b==c || c==a){
		if (a==b && b==c && c==a)
			return TYPE_EQUILATERAL;
		else
			return TYPE_ISOSCELES;
	}
	return TYPE_SCALENE;
}
