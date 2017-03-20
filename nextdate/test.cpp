/*
C1: 1 ≤ month ≤ 12 
C2: 1 ≤ day ≤ 31
C3: 1812 ≤ year ≤ 2012.
*/

#include <stdio.h>
#include "gtest/gtest.h"
#include "nextdate.hpp"

TEST( NextDateTest, BoundaryDate ) {
	//year
	ASSERT_EQ( 18120616 , nextdate(1812, 06, 15) ); // year min
	ASSERT_EQ( 18130616 , nextdate(1813, 06, 15) ); // year min+1
	ASSERT_EQ( 19120616 , nextdate(1912, 06, 15) ); // year middle
	ASSERT_EQ( 20110616 , nextdate(2011, 06, 15) ); // year max-1
	ASSERT_EQ( 20120616 , nextdate(2012, 06, 15) ); // year max
	//day
	ASSERT_EQ( 19120602 , nextdate(1912, 06, 01) ); // day min
	ASSERT_EQ( 19120603 , nextdate(1912, 06, 02) ); // day min+1
	ASSERT_EQ( 19120701 , nextdate(1912, 06, 30) ); // day max-1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, 06, 31) ); // day max
	//month
	ASSERT_EQ( 19120116 , nextdate(1912, 01, 15) ); // month min
	ASSERT_EQ( 19120216 , nextdate(1912, 02, 15) ); // month min+1
	ASSERT_EQ( 19121116 , nextdate(1912, 11, 15) ); // month max-1
	ASSERT_EQ( 19121216 , nextdate(1912, 12, 15) ); // month max
}

TEST( NextDateTest, Equivalence ) {
	//Weak Normal & Strong Normal Equivalence Class
	ASSERT_EQ( 19120616 , nextdate(1912, 06, 15) ); 
	//Weak Robust Equivalence Class
	ASSERT_EQ( INVALID_DATE , nextdate(1912, -1, 15) ); // month min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, 13, 15) ); // month max+1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, 6, -1) ); // day min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, 6, 32) ); // day max+1
	ASSERT_EQ( INVALID_DATE , nextdate(1811, 6, 15) ); // year min-1
	ASSERT_EQ( INVALID_DATE , nextdate(2013, 6, 15) ); // year max+1
	//Strong Robust Equivalence Class
	ASSERT_EQ( INVALID_DATE , nextdate(1912, -1, 15) ); // month min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, 6, -1) ); // day min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1811, 6, 15) ); // year min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1912, -1, -1) ); // month and day min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1811, 6, -1) ); //day and year min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1811, -1, 15) ); // month and year min-1
	ASSERT_EQ( INVALID_DATE , nextdate(1811, -1, -1) ); // year, month and day min-1
	//Weak Normal Equivalence Class
	ASSERT_EQ( 20000615 , nextdate(2000, 06, 14) ); //same with SN1
	ASSERT_EQ( 19960730 , nextdate(1996, 07, 29) ); //same with SN18
 
	ASSERT_EQ( INVALID_DATE , nextdate(2002, 2, 30) ); // day max-1
	ASSERT_EQ( INVALID_DATE , nextdate(2000, 6, 31) ); // day max,same with SN10

	//Strong Normal Equivalence Class	
	ASSERT_EQ( 19960615 , nextdate(1996, 06, 14) ); // SN2
	ASSERT_EQ( 20020615 , nextdate(2002, 06, 14) ); // SN3
	ASSERT_EQ( 20000630 , nextdate(2000, 06, 29) ); // SN4
	ASSERT_EQ( 19960630 , nextdate(1996, 06, 29) ); // SN5
	ASSERT_EQ( 20020630 , nextdate(2002, 06, 29) ); // SN6
	ASSERT_EQ( 20000701 , nextdate(2000, 6, 30) ); // SN7
	ASSERT_EQ( 19960701 , nextdate(1996, 6, 30) ); // SN8
	ASSERT_EQ( 20020701 , nextdate(2002, 6, 30) ); // SN9
	ASSERT_EQ( INVALID_DATE , nextdate(1996, 6, 31) ); // SN11
	ASSERT_EQ( INVALID_DATE , nextdate(2002, 6, 31) ); // SN12
	ASSERT_EQ( 20000715 , nextdate(2000, 07, 14) ); // SN13
	ASSERT_EQ( 19960715 , nextdate(1996, 07, 14) ); // SN14
	ASSERT_EQ( 20020715 , nextdate(2002, 07, 14) ); // SN15
	ASSERT_EQ( 20000730 , nextdate(2000, 07, 29) ); // SN16
	ASSERT_EQ( 19960730 , nextdate(1996, 07, 29) ); // SN17
	ASSERT_EQ( 20020730 , nextdate(2002, 07, 29) ); // SN18
	ASSERT_EQ( 20000731 , nextdate(2000, 07, 30) ); // SN19
	ASSERT_EQ( 19960731 , nextdate(1996, 07, 30) ); // SN20
	//http://www.softwaretestinggenius.com/tutorial-7-to-generate-equivalence-class-test-cases-for-the-next-date-function
}

TEST( NextDateTest, DecisionTable ) {
	ASSERT_EQ( 20010416 , nextdate(2001, 04, 15) ); 
	ASSERT_EQ( 20010501 , nextdate(2001, 04, 30) ); 
	ASSERT_EQ( INVALID_DATE , nextdate(2001, 04, 31) ); 
	ASSERT_EQ( 20010116 , nextdate(2001, 01, 15) ); 
	ASSERT_EQ( 20010201 , nextdate(2001, 01, 31) ); 
	ASSERT_EQ( 20011216 , nextdate(2001, 12, 15) ); 
	ASSERT_EQ( 20020101 , nextdate(2001, 12, 31) ); 
	ASSERT_EQ( 20010216 , nextdate(2001, 02, 15) ); 
	ASSERT_EQ( 20040229 , nextdate(2004, 02, 28) ); 
	ASSERT_EQ( 20010301 , nextdate(2001, 02, 28) ); 
	ASSERT_EQ( 20040301 , nextdate(2004, 02, 29) ); 
	ASSERT_EQ( INVALID_DATE , nextdate(2001, 02, 29) ); 
	ASSERT_EQ( INVALID_DATE , nextdate(2001, 02, 30) ); 
	
}

int main( int argc, char *argv[] ) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

