load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "server",
    hdrs = [
        "rpc_server.h",
        "vectara_server.h"
    ],
    srcs = [
        "rpc_server.cc",
        "vectara_server.cc"
    ],
    deps = [
        "//proto:cc_vectara_proto",
        "//server/src/index:index",
        "@apache_brpc//:brpc",
        "@apache_brpc//:bthread",
        "@apache_brpc//:bvar",
        "@apache_brpc//:butil"
    ]
)

cc_test(
    name = "rpc_server_test",
    deps = [
        ":server",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
    srcs = ["rpc_server_test.cc"]
)

cc_test(
    name = "vectara_server_test",
    deps = [
        ":server",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
    srcs = ["vectara_server_test.cc"]
)