import grpc
import dictionary_pb2
import dictionary_pb2_grpc

def run():
    channel = grpc.insecure_channel('localhost:50051')
    stub = dictionary_pb2_grpc.DictionaryServiceStub(channel)

    # Add words
    response = stub.AddWord(dictionary_pb2.WordRequest(word="hello"))
    print(response.message)

    response = stub.AddWord(dictionary_pb2.WordRequest(word="world"))
    print(response.message)

    response = stub.AddWord(dictionary_pb2.WordRequest(word="hello"))
    print(response.message)

    response = stub.AddWord(dictionary_pb2.WordRequest(word="kty"))
    print(response.message)

    # Get all words
    word_list = stub.GetAllWords(dictionary_pb2.Empty())
    print("All words:")
    for word in word_list.words:
        print(f"Word: {word.word}, Count: {word.count}")

if __name__ == '__main__':
    run()
