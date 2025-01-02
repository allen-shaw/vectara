#include "rpc_server.h"

#include <brpc/channel.h>
#include <brpc/server.h>
#include <bthread/bthread.h>
#include <butil/logging.h>
#include <gtest/gtest.h>

#include "proto/rpc_service.pb.h"

TEST(TestRpcServer, NewRpcServer) {
  RpcServer* server = new RpcServer(50051);
  EXPECT_TRUE(server != nullptr);
}

TEST(TestRpcServer, StartRpcServer) {
  RpcServer* server = new RpcServer(50051);
  EXPECT_EQ(server->start(), 0);
}

void* StartService(void* args) {
  RpcServer* server = new RpcServer(50051);
  EXPECT_EQ(server->start(), 0);
  return nullptr;
}

void SendRequest() {
  brpc::Channel channel;
  brpc::ChannelOptions options;
  options.protocol = "h2:grpc";
  options.timeout_ms = 5000;
  options.max_retry = 3;

  std::string server_addr = "127.0.0.1";
  int ret = channel.Init(server_addr.c_str(), 50051, &options);
  EXPECT_EQ(ret, 0);

  vectara::rpc::RpcService_Stub stub(&channel);
  vectara::rpc::InsertRequest request;
  vectara::rpc::InsertReply reply;
  brpc::Controller cntl;
  stub.Insert(&cntl, &request, &reply, nullptr);
  EXPECT_TRUE(!cntl.Failed());

  if (cntl.Failed()) {
    LOG(WARNING) << cntl.ErrorText();
  }

  
}

TEST(TestRpcServer, RpcRequest) {
  bthread_t service_thread;
  bthread_start_background(&service_thread, nullptr, StartService, nullptr);
  LOG(INFO) << "=============== Start RpcServer ================";
  usleep(3000000);
  SendRequest();
}
