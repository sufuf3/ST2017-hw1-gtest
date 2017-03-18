#ifndef __NEXTDATE_H__
#define __NEXTDATE_H__

#define INVALID_DATE 0

#define Y_MIN 1812
#define Y_MAX 2012

#define M_MIN 1
#define M_MAX 12

#define D_MIN 1
extern const int D_MAX[M_MAX + 1];

int nextdate( int yy, int mm, int dd );

#endif
