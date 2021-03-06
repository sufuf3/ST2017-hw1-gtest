#include "gtest/gtest.h"
#include "commission.hpp"

TEST( CommissionTest, NormalBoundary ) {
	//Barrel
	ASSERT_EQ( 2800 , count_commission(35, 40, 1) ); //min
	ASSERT_EQ( 2825 , count_commission(35, 40, 2) ); //min+1
	ASSERT_EQ( 5000 , count_commission(35, 40, 89) ); //max-1
	ASSERT_EQ( 5025 , count_commission(35, 40, 90) ); //max
	//Stock
	ASSERT_EQ( 2730 , count_commission(35, 1, 45) ); //min
	ASSERT_EQ( 2760 , count_commission(35, 2, 45) ); //min+1
	ASSERT_EQ( 5070 , count_commission(35, 79, 45) ); //max-1
	ASSERT_EQ( 5100 , count_commission(35, 80, 45) ); //max
	//Lock
	ASSERT_EQ( 2370 , count_commission(1, 40, 45) ); //min
	ASSERT_EQ( 2415 , count_commission(2, 40, 45) ); //min+1
	ASSERT_EQ( 5430 , count_commission(69, 40, 45) ); //max-1
	ASSERT_EQ( 5475 , count_commission(70, 40, 45) ); //max
	//all middle
	ASSERT_EQ( 3900 , count_commission(35, 40, 45) ); 
	//ref: http://www.softwaretestinggenius.com/tutorial-4-to-generate-bva-test-cases-for-the-salesman-commision-calculation-program
}

TEST( CommissionTest, Equivalence ) {
	// Weak Normal & Strong Normal Equivalence Class
	ASSERT_EQ( 3900 , count_commission(35, 40, 45) ); 
	//Weak Robust Equivalence Class
	ASSERT_EQ( INVALID_SALE , count_commission(0, 40, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(71, 40, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, 0, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, 81, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, 40, 0) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, 40, 91) ); 
	//Strong Robust Equivalence Class
	ASSERT_EQ( INVALID_SALE , count_commission(-1, 40, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, -1, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, 40, -1) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(-1, -1, 45) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(-1, 40, -1) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(35, -1, -1) ); 
	ASSERT_EQ( INVALID_SALE , count_commission(-1, -1, -1) ); 
	//http://www.softwaretestinggenius.com/tutorial-8-to-generate-equivalence-class-test-cases-for-the-salesman-commission-calculation-program
}
