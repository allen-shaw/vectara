#include <brpc/channel.h>
#include <brpc/server.h>
#include <bthread/bthread.h>
#include <butil/logging.h>
#include "proto/rpc_service.pb.h"

int main(int argc, char* argv[]) {
 brpc::Channel channel;
  brpc::ChannelOptions options;
  options.protocol = "h2:grpc";
  options.timeout_ms = 5000;
  options.max_retry = 3;

  std::string server_addr = "127.0.0.1";
  int ret = channel.Init(server_addr.c_str(), 50051, &options);
  if (ret != 0) {
    LOG(ERROR) << "Fail to init channel";
    return -1;
  }

  vectara::rpc::RpcService_Stub stub(&channel);
  vectara::rpc::InsertRequest request;
  vectara::rpc::InsertReply reply;
  brpc::Controller cntl;
  stub.Insert(&cntl, &request, &reply, nullptr);
  if (cntl.Failed()) {
    LOG(WARNING) << cntl.ErrorText();
    return -1;
  }

  return 0;
}