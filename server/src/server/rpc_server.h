#pragma once

#include "vectara_server.h"
#include <brpc/server.h>
#include <butil/logging.h>

class RpcServer {
public:
    RpcServer(int port);
    virtual ~RpcServer();

    int start();
private:
    int init();
private:
    int port;

    brpc::Server rpc_server;
    VectaraServer* server;
};


