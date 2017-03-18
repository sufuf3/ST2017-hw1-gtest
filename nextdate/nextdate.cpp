#include <stdio.h>
#include "nextdate.hpp"

const int D_MAX[M_MAX + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int nextdate( int yy, int mm, int dd ) {
	//31days
	if( mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12 ){
		if(dd >= 1 && dd<31)
			dd++;
		else if(dd==31){
			dd=1;
			mm++;
			if(mm==13){
				mm=1;
				yy++;
			}
		}
		else
			return INVALID_DATE;
	}
	else if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
		if(dd >= 1 && dd<30)
			dd++;
		else if(dd==30){
			dd=1;
			mm++;
		}	
		else
			return INVALID_DATE;
	}
	else if(mm == 2){
		if(dd >= 1 && dd<28)
			dd++;
	}
	return (yy * 10000) + (mm * 100) + (dd);
}
