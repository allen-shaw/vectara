cc_library(
    name = "bzip2",
    srcs = [
        "blocksort.c",
        "bzlib.c",
        "compress.c",
        "crctable.c",
        "decompress.c",
        "huffman.c",
        "randtable.c",
    ],
    hdrs = [
        "bzlib.h",
        "bzlib_private.h",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    copts = [
        "-DBZ_NO_STDIO",
    ],
)