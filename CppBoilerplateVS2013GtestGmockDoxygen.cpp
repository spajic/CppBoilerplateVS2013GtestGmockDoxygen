// CppBoilerplateVS2013GtestGmockDoxygen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(FirstTest, Fail) {
	EXPECT_EQ(1, 2);
}

int runAllTests(int argc, char* argv[]) {
	std::cout << "\nRunning tests...\n\n";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

int _tmain(int argc, char* argv[])
{
	std::cout << "Hello, CppBoilerplateVS2013GtestGmockDoxygen!\n";

	::runAllTests(argc, argv);

	std::cout << "\nPress enter to exit.";
	std::cin.get();
	return 0;
}

