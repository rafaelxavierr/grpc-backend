cmake_minimum_required(VERSION 3.10)
project(grpc_dictionary_backend)

# Definir padrão de C++
set(CMAKE_CXX_STANDARD 17)

# Encontrar pacotes necessários
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(absl REQUIRED)

# Diretórios
set(SRC_DIR src)
set(PROTO_DIR proto)

# Arquivos Protobuf e gRPC gerados
set(PROTO_SRCS ${SRC_DIR}/dictionary.pb.cc ${SRC_DIR}/dictionary.grpc.pb.cc)

# Arquivos de código fonte do projeto
set(SRC_SRCS ${SRC_DIR}/main.cpp ${SRC_DIR}/dictionary_service.cpp)

# Adicionar Executável
add_executable(dictionary_server ${PROTO_SRCS} ${SRC_SRCS})

# Vincular as bibliotecas necessárias
target_link_libraries(dictionary_server
    gRPC::grpc++
    protobuf::libprotobuf
    absl::base
    absl::strings
    absl::synchronization
    absl::time
    absl::memory
    absl::log_severity
)
