#pragma once

#include <cstdint>
#include <string>
#include "proto/index.pb.h"
#include "server/src/index/hnsw_index.h"
#include "server/src/storage/storage.h"
#include <rapidjson/document.h>
class VectorDatabase {
public:
  VectorDatabase(const std::string &db_path);
  virtual ~VectorDatabase() = default;

  void upsert(uint64_t id, const rapidjson::Document &data, vectara::index::IndexType index_type);
  rapidjson::Document query(uint64_t id);
private:
  Storage storage_;
  HNSWIndex index_;
};