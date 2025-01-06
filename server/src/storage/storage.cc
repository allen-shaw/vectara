#include "storage.h"
#include "rocksdb/db.h"
#include <butil/logging.h>
#include <string>

Storage::Storage(const std::string& db_path) {
  rocksdb::Options options;
  options.create_if_missing = true;
  rocksdb::Status status = rocksdb::DB::Open(options, db_path, &db_);
  if (!status.ok()) {
    throw std::runtime_error("Failed to open RocksDB: " + status.ToString());
  }
}

Storage::~Storage() {
  rocksdb::Status status = db_->Close();
  if (!status.ok()) {
    LOG(ERROR) << "Failed to close RocksDB: " << status.ToString(); 
  }
  delete db_;
}

void Storage::insert(uint64_t id, const std::string& value) {
  std::string key = std::to_string(id);
  rocksdb::Status status = db_->Put(rocksdb::WriteOptions(), key, value);
  if (!status.ok()) {
    LOG(ERROR) << "Failed to insert key-value pair: " << status.ToString();
  }
}

std::string Storage::get(uint64_t id) {
  std::string key = std::to_string(id);
  std::string value;
  rocksdb::Status status = db_->Get(rocksdb::ReadOptions(), key, &value);
  if (!status.ok()) {
    LOG(ERROR) << "Failed to get value for key " << key << ": " << status.ToString();
    return "";
  }
  return value; 
}