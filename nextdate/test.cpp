/*
C1: 1 ≤ month ≤ 12 
C2: 1 ≤ day ≤ 31
C3: 1900 ≤ year ≤ 2025.
*/

#include <stdio.h>
#include "gtest/gtest.h"
#include "nextdate.hpp"

TEST( NextDateTest, BoundaryDate ) {
	//year
	ASSERT_EQ( 19000616 , nextdate(1900, 06, 15) ); // year min
	ASSERT_EQ( 19010616 , nextdate(1901, 06, 15) ); // year min+1
	ASSERT_EQ( 19620616 , nextdate(1962, 06, 15) ); // year middle
	ASSERT_EQ( 20240616 , nextdate(2024, 06, 15) ); // year max-1
	ASSERT_EQ( 20250616 , nextdate(2025, 06, 15) ); // year max
	//day
	ASSERT_EQ( 19620602 , nextdate(1962, 06, 01) ); // day min
	ASSERT_EQ( 19620603 , nextdate(1962, 06, 02) ); // day min+1
	ASSERT_EQ( 19620701 , nextdate(1962, 06, 30) ); // day max-1
	ASSERT_EQ( INVALID_DATE , nextdate(1962, 06, 31) ); // day max
	//month
	ASSERT_EQ( 19620116 , nextdate(1962, 01, 15) ); // month min
	ASSERT_EQ( 19620216 , nextdate(1962, 02, 15) ); // month min+1
	ASSERT_EQ( 19621116 , nextdate(1962, 11, 15) ); // month max-1
	ASSERT_EQ( 20241216 , nextdate(2024, 12, 15) ); // month max
}
