import grpc
from concurrent import futures
import dictionary_pb2
import dictionary_pb2_grpc

class DictionaryServicer(dictionary_pb2_grpc.DictionaryService):
    def __init__(self):
        self.words = {}

    def AddWord(self, request, context):
        word = request.word
        if word in self.words:
            self.words[word] += 1
        else:
            self.words[word] = 1
        return dictionary_pb2.WordResponse(message=f"Word '{word}' added successfully.")

    def GetAllWords(self, request, context):
        word_list = dictionary_pb2.WordList()
        for word, count in self.words.items():
            word_list.words.append(dictionary_pb2.Word(word=word, count=count))
        return word_list

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    dictionary_pb2_grpc.add_DictionaryServiceServicer_to_server(DictionaryServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server started, listening on 50051")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
