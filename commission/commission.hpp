#ifndef __COMMISSION_H__
#define __COMMISSION_H__

#define LOCK_PRICE	45
#define STOCK_PRICE	30
#define BARREL_PRICE	25

#define LOCK_MIN	1
#define LOCK_MAX	70

#define STOCK_MIN	1
#define STOCK_MAX	80

#define BARREL_MIN	1
#define BARREL_MAX	90

#define SALE_INPUT	3

#define INVALID_SALE	0.0

//const double	SALE_THRESHOLD[SALE_INPUT];
//const double	COMMISSION_PERCENT[SALE_INPUT];
const double SALE_THRESHOLD[SALE_INPUT] = { 0.0, 1000.0, 1800.0 };
const double COMMISSION_PERCENT[SALE_INPUT] = { 0.1, 0.15, 0.2 };

double count_commission( int lock, int stock, int barrel );
#endif
