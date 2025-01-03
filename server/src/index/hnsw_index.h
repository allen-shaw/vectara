#pragma once

#include "hnswlib/hnswlib.h"
#include "proto/index.pb.h"

class HNSWIndex {
 public:
  HNSWIndex(int dim, int num_data, vectara::index::MetricType metric,
            int M = 16, int ef_construction = 200);
  virtual ~HNSWIndex();

  void insert_vectors(const std::vector<float>& data, uint64_t label);
  std::pair<std::vector<long>, std::vector<float>> search_vectors(
      const std::vector<float>& query, int k, int ef_search=50);

 private:
  int dim;
  std::unique_ptr<hnswlib::L2Space> space_ptr;
  std::unique_ptr<hnswlib::HierarchicalNSW<float>> index_ptr;
};