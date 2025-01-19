# Usa a imagem base do GCC
FROM gcc:latest

# Atualiza pacotes e instala dependências necessárias
RUN apt-get update && apt-get install -y \
    cmake \
    protobuf-compiler \
    libprotobuf-dev \
    libgrpc++-dev \
    git \
    build-essential \
    autoconf \
    libtool \
    pkg-config

# Define o diretório de trabalho
WORKDIR /app

# Baixa e compila o gRPC para incluir o plugin `grpc_cpp_plugin`
RUN git clone --recurse-submodules -b v1.57.0 https://github.com/grpc/grpc.git && \
    cd grpc && \
    mkdir -p cmake/build && cd cmake/build && \
    cmake ../.. -DBUILD_SHARED_LIBS=ON && \
    make -j$(nproc) && make install && \
    ldconfig

# Baixa e compila o Abseil
RUN git clone --recurse-submodules https://github.com/abseil/abseil-cpp.git && \
    cd abseil-cpp && \
    cmake . && \
    make && make install

# Configura o caminho das bibliotecas compartilhadas
ENV LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# Copia os arquivos do projeto para o contêiner
COPY . .

# Compila os arquivos protobuf
RUN protoc --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin dictionary.proto

# Compila o servidor com as bibliotecas corretas
RUN g++ -std=c++17 server.cpp dictionary.grpc.pb.cc dictionary.pb.cc -o server \
    -lgrpc++ -lgrpc -lgrpc++_reflection -lprotobuf -lgpr -labsl -ldl -lpthread

# Comando para executar o servidor
CMD ["./server"]
