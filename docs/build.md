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
