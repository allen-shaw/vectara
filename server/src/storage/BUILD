load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "storage",
    srcs = [
      "storage.cc",
    ],
    hdrs = [
      "storage.h"
    ],
    deps = [
        "@apache_brpc//:butil",
        "@com_github_facebook_rocksdb//:rocksdb",
    ],
)

cc_test(
  name = "storage_test",
  deps = [
    ":storage",
    "@gtest",
    "@gtest//:gtest_main",
  ],
  srcs = [
    "storage_test.cc",
  ],
)