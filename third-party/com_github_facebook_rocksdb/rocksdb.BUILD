cc_library(
    name = "rocksdb",
    srcs = glob(
        [
            "db/**/*.cc",
            "db/**/*.h",
            "env/**/*.cc",
            "env/**/*.h",
            "memtable/**/*.cc",
            "memtable/**/*.h",
            "monitoring/**/*.cc",
            "monitoring/**/*.h",
            "options/**/*.cc",
            "options/**/*.h",
            "port/**/*.cc",
            "port/**/*.h",
            "table/**/*.cc",
            "table/**/*.h",
            "util/**/*.cc",
            "util/**/*.h",
            "util/*.cc",
            "include/rocksdb/*.h",
            "**/*.cc",
            "**/*.h",
            "utilities/**/*.cc",  # 添加 utilities 目录
            "utilities/**/*.h",
            "tools/*.cc",  # 添加 tools 目录，可能包含版本相关代码
        ],
        exclude = [
            "**/tests/**",
            "**/*_test.cc",
            # "**/mock_*.cc",
            "**/benchmarks/**",
            "**/tools/**",
            "**/java/**",  # 排除与 Java 相关的所有文件
            "**/rocksjni.cc",  # 排除 JNI 相关的文件
            "**/rocksjni.h",
            "**/multi_processes_example.cc",  # 排除多进程示例
            "**/fuzz/**",
            "**/microbench/**",
            "third-party/gtest-1.8.1/**",
            "**/cache_bench.cc",  # 排除特定基准文件
            "**/forward_iterator_bench.cc",  # 排除特定基准文件
            "**/db_test2.cc",  # 排除特定测试文件
            "**/range_del_aggregator_bench.cc",
            "**/db_stress.cc",
            "**/examples/**",  # 排除所有示例文件夹
            "**/*example*.cc",
            "**/*bench*/**",
            "**/*_bench.cc",
        ],
    ),
    hdrs = glob([
        "include/rocksdb/*.h",
        "include/rocksdb/utilities/*.h",
        "util/*.h",
    ]),
    copts = [
        "--std=c++20",
        "-DROCKSDB_PLATFORM_POSIX",
        "-DROCKSDB_LIB_IO_POSIX",
        "-DROCKSDB_SUPPORT_THREAD_LOCAL",
        "-DOS_LINUX",
        "-fno-builtin-memcmp",
        "-DROCKSDB_MALLOC_USABLE_SIZE",
        "-Iexternal/rocksdb",
        "-Iexternal/rocksdb/include",
        "-DROCKSDB_LITE=0",  # 启用完整功能
        "-D_GLIBCXX_USE_CXX11_ABI=0",  # 确保使用正确的 C++ ABI
        "-DVERSION_BUILD_ID=v9.9.3",  # 添加版本信息
    ],
    includes = [
        ".",
        "include",
    ],
    linkstatic = 1,  # 添加静态链接
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_gflags_gflags//:gflags",
        "@com_github_madler_zlib//:zlib",
        "@gtest",
        "@gtest//:gtest_main",
        "@lz4",
        "@snappy",
        "@zstd",
    ],
)
