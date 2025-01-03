#include "hnsw_index.h"
#include <memory>

HNSWIndex::HNSWIndex(int dim, int num_data, vectara::index::MetricType metric,
                     int M, int ef_construction)
    : dim(dim) {
  if (metric == vectara::index::MetricType::METRIC_TYPE_L2) {
    space_ptr = std::make_unique<hnswlib::L2Space>(dim);
  } else {
    throw std::runtime_error("Invalid metric type.");
  }
  index_ptr = std::make_unique<hnswlib::HierarchicalNSW<float>>(
    space_ptr.get(), num_data, M, ef_construction
  );
}

HNSWIndex::~HNSWIndex() {
}

void HNSWIndex::insert_vectors(const std::vector<float>& data, uint64_t label) {
  index_ptr->addPoint(data.data(), label);
}

std::pair<std::vector<long>, std::vector<float>> HNSWIndex::search_vectors(const std::vector<float>& query, int k, int ef_search) {
  index_ptr->setEf(ef_search);
  auto result = index_ptr->searchKnn(query.data(), k);
  std::vector<long> indices(k);
  std::vector<float> distances(k);
  for (int j = 0; j < k; j++) {
    auto item = result.top();
    indices[j] = item.second;
    distances[j] = item.first;
    result.pop();
  }
  return {indices, distances};
}