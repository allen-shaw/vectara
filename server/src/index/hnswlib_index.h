#pragma once

#include "hnswlib/hnswlib.h"

class HNSWIndex {
 public:
  HNSWIndex(int dim, int num_data);
  virtual ~HNSWIndex();

  void insert_vectors(const std::vector<float>& data, uint64_t label);
  std::pair<std::vector<long>, std::vector<float>> search_vectors(
      const std::vector<float>& query, int k);

 private:
  int dim;
  hnswlib::SpaceInterface<float>* space;
  hnswlib::HierarchicalNSW<float>* index;
};