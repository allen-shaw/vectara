#pragma once

#include "rocksdb/db.h"

class Storage {
public:
  Storage(const std::string& db_path);
  ~Storage();

  void insert(uint64_t id, const std::string& value);

  std::string get(uint64_t id);
private:
  rocksdb::DB* db_;
};

