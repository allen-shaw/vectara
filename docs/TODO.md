# TODO

## 项目结构调整

1. 参考tensorflow: 移除src目录
2. bazel包含go代码的编译，相当于使用bazel管理整个项目
3. grpc server应该独立为一个目录

## 系统设计

系统架构分为4个模块

### dbServer

使用c++编写

grpc server，提供基础的存储和读取能力

### metaServer

使用go语言编写

元数据服务，提供元数据比如分片位置查询，服务注册发现等能力

可以分为两个版本。第一个版本通过etcd抢锁保证唯一，后续可以集成etcd的raft库，实现自举，避免过多的依赖

### client

sdk，提供多种语言的sdk(python, go等)

### coordinator

使用go语言编写

负责非核心链路的处理，比如负载均衡调整

### adminServer

非核心链路

使用nodejs或者gin框架编写

管理端服务，提供api管理系统，包含web端，API也宫cli调用

### CLI

go语言编写的命令行客户端

## 语言规范

1. 按照google c++ guide修改
2. 移除中文注释
3. 将裸指针替换成std::uniq_ptr<?>
4. 返回错误类型，而不是直接返回int
