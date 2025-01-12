load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "database",
    srcs = [
        "database.cc",
    ],
    hdrs = [
        "database.h",
    ],
    copts = ["-std=c++20"],  # 为您的代码启用 C++17
    deps = [
        "@apache_brpc//:butil",
        "@com_github_tencent_rapidjson//:rapidjson",
        "//proto:cc_vectara_proto",
        "//server/src/storage:storage",
        "//server/src/index:index",
    ],
)

cc_test(
    name = "database_test",
    srcs = [
        "database_test.cc",
    ],
    copts = ["-std=c++20"],  # 为您的代码启用 C++17
    deps = [
        ":database",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
