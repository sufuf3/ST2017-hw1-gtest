#include "commission.hpp"

//const double SALE_THRESHOLD[SALE_INPUT] = { 0.0, 1000.0, 1800.0 };
//const double COMMISSION_PERCENT[SALE_INPUT] = { 0.1, 0.15, 0.2 };

double count_commission( int lock, int stock, int barrel ) {
	
	int i, rank = 0;
	double sale = 0.0, commission = 0.0;
	
	// validate the input sale
	if( lock < LOCK_MIN || stock < STOCK_MIN || barrel < BARREL_MIN || lock > LOCK_MAX || stock > STOCK_MAX || barrel > BARREL_MAX ) 
		return INVALID_SALE;
	
	sale = LOCK_PRICE * lock + STOCK_PRICE * stock + BARREL_PRICE * barrel;
	return sale;		
/*	if(sale < 1000 ){
		return sale*0.1;
	}
	else if(sale < 1800){
		return 100+(sale-1000)*0.15;
	}
	else{
		return 220+(sale-1800)*0.2;
	}*/
}
