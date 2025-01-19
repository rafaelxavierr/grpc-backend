const express = require("express");
const cors = require("cors");
const grpc = require("@grpc/grpc-js");
const protoLoader = require("@grpc/proto-loader");

const app = express();
app.use(cors()); // Permite requisições de qualquer origem por padrão
app.use(express.json()); // Para interpretar JSON no corpo das requisições

const PROTO_PATH = "./dictionary.proto"; // Caminho para o arquivo .proto
const GRPC_BACKEND_ADDRESS = "backend:50051"; // Endereço do serviço gRPC

// Carrega o arquivo .proto
const packageDefinition = protoLoader.loadSync(PROTO_PATH, {
    keepCase: true,
    longs: String,
    enums: String,
    defaults: true,
    oneofs: true,
});
const dictionaryProto = grpc.loadPackageDefinition(packageDefinition);

console.log({dictionaryProto});
// Configura o cliente gRPC
const grpcClient = new dictionaryProto.DictionaryService(
    GRPC_BACKEND_ADDRESS,
    grpc.credentials.createInsecure()
);

// Rota para adicionar uma palavra
app.post("/add_word", (req, res) => {
    const word = req.body.word;
    if (!word) {
        return res.status(400).json({ error: "Word is required" });
    }

    grpcClient.AddWord({ word }, (err, response) => {
        if (err) {
            return res.status(500).json({ error: err.message });
        }
        res.json({ message: response.message });
    });
});

// Rota para listar todas as palavras
app.get("/get_words", (req, res) => {
    grpcClient.GetAllWords({}, (err, response) => {
        if (err) {
            return res.status(500).json({ error: err.message });
        }
        const words = response.words.map((word) => ({
            word: word.word,
            count: word.count,
        }));
        res.json({ words });
    });
});

// Inicia o servidor
const PORT = 8080;
app.listen(PORT, () => {
    console.log(`API Gateway running on http://0.0.0.0:${PORT}`);
});
