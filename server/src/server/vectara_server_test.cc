#include <gtest/gtest.h>
#include "vectara_server.h"


TEST(VectaraServerTest, InsertAndSearchVectors) {
    VectaraServer server;
    vectara::rpc::InsertRequest insert_request;
    vectara::rpc::InsertReply insert_reply;
    vectara::rpc::SearchRequest search_request;
    vectara::rpc::SearchReply search_reply; 

    google::protobuf::Closure* done = nullptr;  
    server.Insert(nullptr, &insert_request, &insert_reply, done);
    server.Search(nullptr, &search_request, &search_reply, done);
}