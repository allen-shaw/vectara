# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

BAZEL_SKYLIB_VERSION = "1.1.1"  # 2021-09-27T17:33:49Z

BAZEL_SKYLIB_SHA256 = "c6966ec828da198c5d9adbaa94c05e3a1c7f21bd012a0b29ba8ddbccb2c93b0d"

def brpc_workspace():
    http_archive(
        name = "bazel_skylib",
        sha256 = BAZEL_SKYLIB_SHA256,
        urls = [
            "https://github.com/bazelbuild/bazel-skylib/releases/download/{version}/bazel-skylib-{version}.tar.gz".format(version = BAZEL_SKYLIB_VERSION),
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/{version}/bazel-skylib-{version}.tar.gz".format(version = BAZEL_SKYLIB_VERSION),
        ],
    )

    http_archive(
        name = "com_google_protobuf",  # 2021-10-29T00:04:02Z
        build_file = "//third-party/com_google_protobuf:protobuf.BUILD",
        patch_cmds = [
            "sed -i protobuf.bzl -re '4,4d;417,508d'",
        ],
        patch_cmds_win = [
            """$content = Get-Content 'protobuf.bzl' | Where-Object {
            -not ($_.ReadCount -ne 4) -and
            -not ($_.ReadCount -ge 418 -and $_.ReadCount -le 509)
        }
        Set-Content protobuf.bzl -Value $content -Encoding UTF8
        """,
        ],
        sha256 = "87407cd28e7a9c95d9f61a098a53cf031109d451a7763e7dd1253abf8b4df422",
        strip_prefix = "protobuf-3.19.1",
        urls = ["https://github.com/protocolbuffers/protobuf/archive/refs/tags/v3.19.1.tar.gz"],
    )

    http_archive(
        name = "com_github_google_leveldb",
        build_file = "//third-party/com_github_google_leveldb:leveldb.BUILD",
        strip_prefix = "leveldb-a53934a3ae1244679f812d998a4f16f2c7f309a6",
        url = "https://github.com/google/leveldb/archive/a53934a3ae1244679f812d998a4f16f2c7f309a6.tar.gz",
    )

    http_archive(
        name = "com_github_madler_zlib",  # 2017-01-15T17:57:23Z
        build_file = "//third-party/com_github_madler_zlib:zlib.BUILD",
        sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        strip_prefix = "zlib-1.2.11",
        urls = [
            "https://downloads.sourceforge.net/project/libpng/zlib/1.2.11/zlib-1.2.11.tar.gz",
            "https://zlib.net/fossils/zlib-1.2.11.tar.gz",
        ],
    )

    native.new_local_repository(
        name = "openssl",
        path = "/usr",
        build_file = "//third-party/openssl:openssl.BUILD",
    )

    http_archive(
        name = "com_github_gflags_gflags",
        strip_prefix = "gflags-46f73f88b18aee341538c0dfc22b1710a6abedef",
        url = "https://github.com/gflags/gflags/archive/46f73f88b18aee341538c0dfc22b1710a6abedef.tar.gz",
    )

    http_archive(
        name = "apache_brpc",
        strip_prefix = "brpc-1.11.0",
        url = "https://github.com/apache/brpc/archive/refs/tags/1.11.0.tar.gz",
    )

    git_repository(
        name = "gtest",
        remote = "https://github.com/google/googletest",
        branch = "v1.15.2",
    )

    http_archive(
        name = "com_github_xianyi_OpenBLAS",
        build_file = "//third-party/com_github_xianyi_OpenBLAS:openblas.BUILD",
        strip_prefix = "OpenBLAS-0.3.24",
        url = "https://github.com/xianyi/OpenBLAS/archive/refs/tags/v0.3.24.tar.gz",
    )

    http_archive(
        name = "com_github_facebookresearch_faiss",
        build_file = "//third-party/com_github_facebookresearch_faiss:faiss.BUILD",
        strip_prefix = "faiss-1.7.4",
        url = "https://github.com/facebookresearch/faiss/archive/refs/tags/v1.7.4.tar.gz",
    )

    http_archive(
        name = "com_github_nmslib_hnswlib",
        build_file = "//third-party/com_github_nmslib_hnswlib:hnswlib.BUILD",
        strip_prefix = "hnswlib-0.8.0",
        url = "https://github.com/nmslib/hnswlib/archive/refs/tags/v0.8.0.tar.gz",
    )

    http_archive(
        name = "com_github_facebook_rocksdb",
        url = "https://github.com/facebook/rocksdb/archive/refs/tags/v6.29.5.tar.gz",
        strip_prefix = "rocksdb-6.29.5",
        build_file = "//third-party/com_github_facebook_rocksdb:rocksdb.BUILD",
    )

    git_repository(
        name = "com_github_brpc_braft",
        remote = "https://github.com/baidu/braft.git",
        tag = "v1.1.2",
    )
