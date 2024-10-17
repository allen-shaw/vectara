licenses(["notice"])  

package(default_visibility = ["//visibility:public"])


genrule(
    name = "build",
    srcs = glob(["**/*"]),
    outs = ["include/cblas.h"] + 
        ["lib/libopenblas.a"],
    cmd = "\n".join([
        "blas=\"external/com_github_xianyi_OpenBLAS\"",
        "outs=($(OUTS))",
        "cp -r $${blas} build ",
        "(cd build " + 
        "&& make --silent -j4 && make install PREFIX=.)",
        "cp build/include/*.h $$(dirname $(location include/cblas.h))",
        "cp build/lib/libopenblas.a $(location lib/libopenblas.a)",
    ]),
)

cc_library(
    name = "openblas",
    srcs = ["lib/libopenblas.a"],
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    linkstatic = True,
    visibility = ["//visibility:public"],
)