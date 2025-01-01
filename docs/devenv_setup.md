# Dev Env Setup

## Q&A

Q: How to fix VSCode Error: `In included file: 'stdlib.h' file not found`

A: 
1. Installing the libstdc++ library, by running `sudo apt install libstdc++-14-dev`

2. Adding config `~/.config/clangd/config.yaml` file
```yaml
CompileFlags:
    Add: [
          -I/usr/include/c++/13,
          -I/usr/include/x86_64-linux-gnu/c++/13,
          -I/usr/include/c++/13/backward,
          -I/usr/lib/gcc/x86_64-linux-gnu/13/include,
          -I/usr/local/include,
          -I/usr/include/x86_64-linux-gnu,
          -I/usr/include,
          -isystem,
          -std=c++23,
    ]
```