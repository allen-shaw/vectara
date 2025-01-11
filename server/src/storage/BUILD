load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "storage",
    srcs = [
        "storage.cc",
    ],
    hdrs = [
        "storage.h",
    ],
    copts = ["-std=c++20"],  # 为您的代码启用 C++17
    deps = [
        "@apache_brpc//:butil",
        "@com_github_facebook_rocksdb//:rocksdb",
        "@zstd",
    ],
)

cc_test(
    name = "storage_test",
    srcs = [
        "storage_test.cc",
    ],
    copts = ["-std=c++20"],  # 为您的代码启用 C++17
    deps = [
        ":storage",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
