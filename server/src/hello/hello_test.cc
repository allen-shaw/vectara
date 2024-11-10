#include <gtest/gtest.h>
#include "hello.h"


TEST(TestHello, HelloMethod) {
    std::string empty_name;

    EXPECT_EQ(false, Hello(empty_name));

    std::string name("allen");

    std::cout << "Test Hello: " << name << std::endl;

    EXPECT_EQ(true, Hello(name));
}