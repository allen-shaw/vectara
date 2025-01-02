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

  brpc::Controller cntl;

  vectara::rpc::RpcService_Stub stub(&channel);
  vectara::rpc::InsertRequest request;
  vectara::rpc::InsertReply reply;

  request.add_vectors(0.8);
  request.add_vectors(9.9);
  request.set_id(2);
  request.set_index_type(vectara::index::IndexType::IndexType_Flat);

  stub.Insert(&cntl, &request, &reply, nullptr);
  EXPECT_TRUE(!cntl.Failed());

  if (cntl.Failed()) {
    LOG(WARNING) << cntl.ErrorText();
  } else {
    LOG(INFO) << "Insert success";
  }

  cntl.Reset();
  
  vectara::rpc::SearchRequest search_request;
  vectara::rpc::SearchReply search_reply;
  search_request.add_vectors(0.5);
  search_request.set_k(2);
  search_request.set_index_type(vectara::index::IndexType::IndexType_Flat);

  stub.Search(&cntl, &search_request, &search_reply, nullptr);
  EXPECT_TRUE(!cntl.Failed());

  if (cntl.Failed()) {
    LOG(WARNING) << cntl.ErrorText();
  } else {
    LOG(INFO) << "Search success";
    LOG(INFO) << search_reply.DebugString();
  }
}

TEST(TestRpcServer, RpcRequest) {
  bthread_t service_thread;
  bthread_start_background(&service_thread, nullptr, StartService, nullptr);
  LOG(INFO) << "=============== Start RpcServer ================";
  usleep(3000000);
  SendRequest();
}
