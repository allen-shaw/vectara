COPTS = [
    "-DGFLAGS_NS=google",
]

cc_binary(
    name = "vectara_client",
    srcs = ["main.cc"],
    copts = COPTS,
    deps = [
        "//proto:cc_vectara_proto",
        "@apache_brpc//:brpc",
        "@apache_brpc//:bthread",
        "@apache_brpc//:butil",
        "@apache_brpc//:bvar",
    ],
)
