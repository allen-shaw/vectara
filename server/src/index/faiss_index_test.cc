#include <gtest/gtest.h>
#include "faiss_index.h"
#include <faiss/IndexFlat.h>
#include <faiss/IndexIDMap.h>

TEST(TestFaissIndex, NewFaissIndex) {
    int dim = 1;
    faiss::MetricType faiss_metric = faiss::METRIC_L2;
    FaissIndex* index = new FaissIndex(new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric)));
    EXPECT_TRUE(index != nullptr);
}

TEST(TestFaissIndex, InsertAndSearchVectors) {
    int dim = 1;
    faiss::MetricType faiss_metric = faiss::METRIC_L2;
    FaissIndex* index = new FaissIndex(new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric)));
    std::vector<float> data = {1.0};
    index->insert_vectors(data, 0);

    std::pair<std::vector<long>, std::vector<float>> result = index->search_vectors(data, 1);
    EXPECT_EQ(result.first[0], 0);
}