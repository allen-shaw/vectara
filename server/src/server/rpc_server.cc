#include "rpc_server.h"
#include <brpc/server.h>
#include <brpc/restful.h>
#include <butil/logging.h>


RpcServer::RpcServer(int port) : port(port) {
    server = new VectaraServer();
}

RpcServer::~RpcServer() {
    delete server;
}

int RpcServer::start() {
    init();

    brpc::ServerOptions options;
    options.idle_timeout_sec = 60; // TODO: from config 
    if(rpc_server.Start(port, &options) != 0) {
        LOG(ERROR) << "Fail to start RpcServer";
        return -1;
    }
    rpc_server.RunUntilAskedToQuit();

    return 0;
}

int RpcServer::init() {
    if(rpc_server.AddService(server, 
                            brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add service";
        return -1;
    }
    return 0;
}