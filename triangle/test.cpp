#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "triangle.hpp"


TEST( triangle_type, NormalBoundary ) {
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

}

//TEST( TriangleTest, RobustBoundary ) {

//}

//TEST( TriangleTest, Equivalence ) {

//}

//TEST( TriangleTest, DecisionTable ) {

//}


int main( int argc, char *argv[] ) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

