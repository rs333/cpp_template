#include "Engine.h"
#include "gtest/gtest.h"
#include <iostream>
class TestEngine : public ::testing::Test {
protected:
	Engine a;
	
};

TEST_F(TestEngine, AInitializedToZero) {
	EXPECT_EQ(a.a(), 0, "a did not equal 0");
}

TEST_F(TestEngine, ASetterWorks) {
	a.a(3);
	EXPECT_EQ(a.a(), 3, "a did not equal 3 after set");
}