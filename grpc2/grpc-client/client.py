import grpc
import dictionary_pb2
import dictionary_pb2_grpc

def add_word(word):
    with grpc.insecure_channel('grpc-server:50051') as channel:
        stub = dictionary_pb2_grpc.DictionaryStub(channel)
        response = stub.UpdateWord(dictionary_pb2.WordRequest(word=word))
        print(response.message)

def get_dictionary():
    with grpc.insecure_channel('grpc-server:50051') as channel:
        stub = dictionary_pb2_grpc.DictionaryStub(channel)
        response = stub.GetDictionary(dictionary_pb2.Empty())
        print("Dictionary contents:")
        for word, count in response.dictionary.items():
            print(f"{word}: {count}")

if __name__ == "__main__":
    while True:
        print("1. Add word")
        print("2. Get dictionary")
        print("3. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            word = input("Enter a word: ")
            add_word(word)
        elif choice == '2':
            get_dictionary()
        elif choice == '3':
            break
        else:
            print("Invalid option. Try again.")
