# Build Command

## install gcc or clang and config cc

```bash
sudo apt install build-essential
```

## install openssl

```bash
 sudo apt-get install libssl-dev
```

## install bazel

follow [bazelisk](https://github.com/bazelbuild/bazelisk)

## build vectara

```bash
bazel build //server/src/main:vectara
```

## gen compile_commands.json

```bash
bazel run @hedron_compile_commands//:refresh_all
```

## run bazel test

```bash
cd ${sub_module} # e.g. cd server/src/index
# run all testcases
bazel test --test_output=all :xxx_test # e.g.bazel test --test_output=all :index_tes

# test one testcase
bazel test --test_output=all --test_arg=--gtest_filter=TestSuite.test :xxx_test

# e.g.
#bazel test --test_output=all --test_arg=--gtest_filter=TestFaissIndex.InsertAndSearchVectors :index_test
```
