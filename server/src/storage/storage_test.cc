#include <gtest/gtest.h>
#include <iostream>

#include "storage.h"

TEST(TestStorage, PutAndGet) {
  std::cout << __VERSION__ << std::endl;

  std::string test_db_path = "./tmp/testdb";
  Storage storage(test_db_path);
  storage.insert(1, "hello");
  std::string value = storage.get(1);
  ASSERT_EQ(value, "hello");
}
