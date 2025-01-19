#include <grpcpp/grpcpp.h>
#include "dictionary.grpc.pb.h"
#include <unordered_map>
#include <mutex>
#include <string>
#include <iostream>

class DictionaryServiceImpl final : public Dictionary::Service {
private:
    std::unordered_map<std::string, int> dictionary_;
    std::mutex mutex_;

public:
    grpc::Status UpdateWord(grpc::ServerContext* context, const WordRequest* request, WordResponse* response) override {
        std::lock_guard<std::mutex> lock(mutex_);
        const std::string& word = request->word();

        if (dictionary_.find(word) != dictionary_.end()) {
            dictionary_[word]++;
        } else {
            dictionary_[word] = 1;
        }

        response->set_message("Word '" + word + "' updated.");
        return grpc::Status::OK;
    }

    grpc::Status GetDictionary(grpc::ServerContext* context, const Empty* request, DictionaryResponse* response) override {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& entry : dictionary_) {
            (*response->mutable_dictionary())[entry.first] = entry.second;
        }
        return grpc::Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    DictionaryServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
