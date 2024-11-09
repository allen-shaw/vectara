#include <gtest/gtest.h>
#include "faiss_index.h"
#include <faiss/IndexFlat.h>
#include <faiss/IndexIDMap.h>

TEST(TestNewFaissIndex, NewFaissIndex) {
    int dim = 1;
    faiss::MetricType faiss_metric = faiss::METRIC_L2;
    FaissIndex* index = new FaissIndex(new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric)));
    EXPECT_TRUE(index != nullptr);
}