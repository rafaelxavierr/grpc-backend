const express = require('express');
const grpc = require('@grpc/grpc-js');
const protoLoader = require('@grpc/proto-loader');

const PROTO_PATH = './dictionary.proto';
const packageDefinition = protoLoader.loadSync(PROTO_PATH);
const dictionaryProto = grpc.loadPackageDefinition(packageDefinition).Dictionary;

const client = new dictionaryProto('grpc-server:50051', grpc.credentials.createInsecure());
const app = express();
app.use(express.json());

app.post('/add-word', (req, res) => {
  client.UpdateWord({ word: req.body.word }, (err, response) => {
    if (err) res.status(500).send(err.message);
    else res.send(response);
  });
});

app.get('/get-dictionary', (req, res) => {
  client.GetDictionary({}, (err, response) => {
    if (err) res.status(500).send(err.message);
    else res.send(response);
  });
});

app.listen(3000, () => console.log('API Gateway running on port 3000'));
