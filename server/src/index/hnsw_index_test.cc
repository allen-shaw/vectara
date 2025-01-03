#include <gtest/gtest.h>
#include "hnsw_index.h"

TEST(TestHNSWIndex, InsertAndSearchVectors) {
  HNSWIndex* index = new HNSWIndex(1, 100, vectara::index::MetricType::METRIC_TYPE_L2, 16, 200);
  std::vector<float> data = {0.2};
  index->insert_vectors(data, 3); 

  std::vector<float> query = {0.5};
  std::pair<std::vector<long>, std::vector<float>> result = index->search_vectors(query, 2);

  EXPECT_EQ(3, result.first[0]);
  EXPECT_FLOAT_EQ(0.09, result.second[0]);
  // std::cout << "result vector_id: " << result.first[0] << std::endl;
  // std::cout << "result distance: " << result.second[0] << std::endl;
}