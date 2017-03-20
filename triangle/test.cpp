/*
Take 200 as an upper bound
Normal boundary are {1,2,199,200}
Robust values {0,201}
*/
#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "triangle.hpp"


TEST( TriangleTest, NormalBoundary ) {
	//one at min bound
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(MIN, 100, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, MIN, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, 100, MIN) );
	//one at min+1 bound
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(MIN+1, 100, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, MIN+1, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, 100, MIN+1) );
	//all same
	ASSERT_EQ( TYPE_EQUILATERAL, triangle_type(100, 100, 100) );
	//one at max-1 bound
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(MAX-1, 100, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, MAX-1, 100) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(100, 100, MAX-1) );
	//one at max bound
	ASSERT_EQ( TYPE_NOTTRIANGLE, triangle_type(MAX, 100, 100) );
	ASSERT_EQ( TYPE_NOTTRIANGLE, triangle_type(100, MAX, 100) );
	ASSERT_EQ( TYPE_NOTTRIANGLE, triangle_type(100, 100, MAX) );
	//ref: http://www.softwaretestinggenius.com/tutorial-2-to-generate-bva-test-cases-for-the-triangle-problem
}

TEST( TriangleTest, Equivalence ) {
	//  Weak Normal Equivalence Class
	ASSERT_EQ( TYPE_EQUILATERAL, triangle_type(5, 5, 5) );
	ASSERT_EQ( TYPE_ISOSCELES, triangle_type(2, 2, 3) );
	ASSERT_EQ( TYPE_SCALENE, triangle_type(3, 4, 5) );
	ASSERT_EQ( TYPE_NOTTRIANGLE, triangle_type(4, 1, 2) );
	// Weak Robust Equivalence Class 
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(-1, 5, 5) ); //strong Robust single invaled
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(5, -1, 5) );//strong Robust single invaled
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(5, 5, -1) );//strong Robust single invaled
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(201, 5, 5) );
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(5, 201, 5) );
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(5, 5, 201) );
	// Strong Robust Equivalence Class two invaled
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(-1, -1, 5) );
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(5, -1, -1) );
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(-1, 5, -1) );
	ASSERT_EQ( TYPE_INVALID_INPUT, triangle_type(-1, -1, -1) );
	//ref: http://www.softwaretestinggenius.com/tutorial-6-to-generate-equivalence-class-test-cases-for-the-triangle-problem
}

//TEST( TriangleTest, DecisionTable ) {

//}


int main( int argc, char *argv[] ) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

