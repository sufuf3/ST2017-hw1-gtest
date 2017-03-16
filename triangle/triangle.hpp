#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#define MIN	1
#define MAX	200

#define TYPE_INVALID_INPUT	0
#define TYPE_NOTTRIANGLE	1
#define TYPE_EQUILATERAL	2
#define TYPE_ISOSCELES		3
#define TYPE_SCALENE		4

int triangle_type( int a, int b, int c );

#endif
