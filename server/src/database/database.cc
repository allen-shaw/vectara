#include "database.h"

VectorDatabase::VectorDatabase(const std::string &db_path) : storage_(db_path) {
}

void VectorDatabase::upsert(uint64_t id, const rapidjson::Document &data, vectara::index::IndexType index_type) {
  
}


rapidjson::Document VectorDatabase::query(uint64_t id) {
  return rapidjson::Document();
}