#pragma once

#include "proto/rpc_service.pb.h"
#include "server/src/index/faiss_index.h"

class VectaraServer : public vectara::rpc::RpcService {
public:
  VectaraServer();
  virtual ~VectaraServer();

  void Insert(google::protobuf::RpcController* controller,
              const ::vectara::rpc::InsertRequest* request,
              ::vectara::rpc::InsertReply* reply,
              ::google::protobuf::Closure* done);

  void Search(google::protobuf::RpcController* controller,
                       const ::vectara::rpc::SearchRequest* request,
                       ::vectara::rpc::SearchReply* response,
                       ::google::protobuf::Closure* done);  

private:
  std::unique_ptr<FaissIndex> index;
};