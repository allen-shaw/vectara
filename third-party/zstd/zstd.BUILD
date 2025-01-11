cc_library(
    name = "zstd",
    srcs = glob([
        "lib/common/*.c",
        "lib/compress/*.c",
        "lib/decompress/*.c",
    ]),
    hdrs = glob([
        "lib/common/*.h",
        "lib/compress/*.h",
        "lib/decompress/*.h",
        "lib/*.h",
    ]),
    copts = [
        "-O2",
        "-DZSTD_MULTITHREAD",
        "-DZSTD_NO_UNUSED_FUNCTIONS",  # 避免未使用的函数
        "-DZSTD_DISABLE_ASM",  # 禁用汇编优化
    ],
    includes = ["lib"],
    visibility = ["//visibility:public"],
)
