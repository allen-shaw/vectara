load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# pb的编译
proto_library(
    name = "http_proto",
    srcs = [
        "helloworld.proto",
    ],
)
# 将pb编译声明为一个依赖dep
cc_proto_library(
    name = "cc_http_proto",
    deps = [
        ":http_proto",
    ],
)
