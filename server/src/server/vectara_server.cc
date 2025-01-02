#include "vectara_server.h"

#include <brpc/server.h>
#include <butil/logging.h>
#include <faiss/IndexFlat.h>
#include <faiss/IndexIDMap.h>

#include <cstdint>
#include <vector>

VectaraServer::VectaraServer() {
  int dim = 1;
  faiss::MetricType faiss_metric = faiss::METRIC_L2;
  index = std::make_unique<FaissIndex>(
      new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric)));
}

VectaraServer::~VectaraServer() {}

void VectaraServer::Insert(google::protobuf::RpcController* controller,
                           const ::vectara::rpc::InsertRequest* request,
                           ::vectara::rpc::InsertReply* reply,
                           ::google::protobuf::Closure* done) {
  LOG(INFO) << "Received Insert Request:" << request->DebugString();
  brpc::ClosureGuard done_guard(done);

  uint64_t label = request->id();
  std::vector<float> data;
  for (const auto& value : request->vectors()) {
    data.push_back(value);
  }

  index->insert_vectors(data, label);
}

void VectaraServer::Search(google::protobuf::RpcController* controller,
                           const ::vectara::rpc::SearchRequest* request,
                           ::vectara::rpc::SearchReply* reply,
                           ::google::protobuf::Closure* done) {
  LOG(INFO) << "Received Search Request" << request->DebugString();
  brpc::ClosureGuard done_guard(done);

  int k = request->k();
  std::vector<float> query;
  for (const auto& value : request->vectors()) {
    query.push_back(value);
  }

  auto results = index->search_vectors(query, k);

  for (size_t i = 0; i < results.first.size(); i++) {
    reply->add_vectors(results.first[i]);
    reply->add_distances(results.second[i]);
  }
}