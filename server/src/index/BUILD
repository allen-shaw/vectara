load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "index",
    hdrs = ["faiss_index.h"],
    srcs = ["faiss_index.cc"],
    deps = [
        "@com_github_facebookresearch_faiss//:faiss",
        "@com_github_nmslib_hnswlib//:hnswlib",
        "@apache_brpc//:butil",
    ]
)

cc_test(
    name = "index_test",
    srcs = ["faiss_index_test.cc"],
    deps = [
        ":index",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ]
)