#include "faiss_index.h"
#include <butil/logging.h>
#include <vector>

FaissIndex::FaissIndex(faiss::Index* index) : index(index) {}

void FaissIndex::insert_vectors(const std::vector<float>& data, uint64_t label) {
    long id = static_cast<long>(label);
    index->add_with_ids(1, data.data(), &id);
}   

std::pair<std::vector<long>, std::vector<float>> 
FaissIndex::search_vectors(const std::vector<float>& query, int k) {
    int dim = index->d;
    int num_queries = query.size() / dim;
    std::vector<long> indices(num_queries * k);
    std::vector<float> distances(num_queries * k);

    index->search(num_queries, query.data(), k, distances.data(), indices.data());
    DLOG(INFO) << "Retrieved values:";
    for (size_t i = 0; i < indices.size(); ++i) {
        if (indices[i] != -1) {
            DLOG(INFO) << "ID: " << indices[i] << ", Distance: " << distances[i];
        } else {
            DLOG(INFO) << "No specific value found";
        }
    }
    return {indices, distances};
}