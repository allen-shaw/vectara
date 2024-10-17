#include <gtest/gtest.h>
#include "faiss_index.h"
#include <faiss/IndexFlat.h>
#include <faiss/IndexIDMap.h>

TEST(TestNewFaissIndex, NewFaissIndex) {
    FaissIndex* index = new FaissIndex(new faiss::IndexIDMap(new faiss::IndexFlat(dim, faiss_metric)));
    EXPECT_TRUE(index != nullptr);
}