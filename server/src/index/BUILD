load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "index",
    srcs = [
      "faiss_index.cc",
      "hnsw_index.cc", 
    ],
    hdrs = [
        "faiss_index.h",
        "hnsw_index.h",
    ],
    deps = [
        "//proto:cc_vectara_proto",
        "@apache_brpc//:butil",
        "@com_github_facebookresearch_faiss//:faiss",
        "@com_github_nmslib_hnswlib//:hnswlib",
    ],
)

cc_test(
    name = "index_test",
    srcs = [
      "faiss_index_test.cc",
      "hnsw_index_test.cc",
    ],
    deps = [
        ":index",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
