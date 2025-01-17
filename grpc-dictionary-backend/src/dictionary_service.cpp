#include "dictionary.pb.h"
#include "dictionary.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <map>
#include <string>

class DictionaryServiceImpl final : public DictionaryService::Service {
    std::map<std::string, int> dictionary;

    grpc::Status AddWord(grpc::ServerContext* context, const WordRequest* request, WordResponse* response) override {
        const std::string& word = request->word();
        dictionary[word]++;
        response->set_message("Word '" + word + "' added!");
        return grpc::Status::OK;
    }

    grpc::Status GetAllWords(grpc::ServerContext* context, const Empty* request, WordList* response) override {
        for (const auto& [word, count] : dictionary) {
            Word* word_entry = response->add_words();
            word_entry->set_word(word);
            word_entry->set_count(count);
        }
        return grpc::Status::OK;
    }
};
