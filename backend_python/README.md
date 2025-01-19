# gRPC server
## install dependencies

```bash
sudo apt install python3 pip python3-venv
```

```bash
python3 -m venv env
pip3 install grpcio grpcio-tools
```

## Definition file

[dictionary.proto](./dictionary.proto)

## Generating stubs

```bash
python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. dictionary.proto
```
