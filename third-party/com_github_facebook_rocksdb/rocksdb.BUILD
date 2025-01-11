load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)

cmake(
    name = "rocksdb",
    cache_entries = {
        "CMAKE_CXX_FLAGS": "-fPIC -std=c++20",  # 添加 C++17 支持
        "WITH_TESTS": "OFF",
        "WITH_TOOLS": "OFF",
        "WITH_BENCHMARK_TOOLS": "OFF",
        "WITH_CORE_TOOLS": "OFF",
        "WITH_GFLAGS": "OFF",
    },
    lib_source = ":all_srcs",
    out_static_libs = ["librocksdb.a"],
    visibility = ["//visibility:public"],
)
