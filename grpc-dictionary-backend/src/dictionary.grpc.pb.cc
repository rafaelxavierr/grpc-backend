// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: dictionary.proto

#include "dictionary.pb.h"
#include "dictionary.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* DictionaryService_method_names[] = {
  "/DictionaryService/AddWord",
  "/DictionaryService/GetAllWords",
};

std::unique_ptr< DictionaryService::Stub> DictionaryService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< DictionaryService::Stub> stub(new DictionaryService::Stub(channel, options));
  return stub;
}

DictionaryService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_AddWord_(DictionaryService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetAllWords_(DictionaryService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DictionaryService::Stub::AddWord(::grpc::ClientContext* context, const ::WordRequest& request, ::WordResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::WordRequest, ::WordResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddWord_, context, request, response);
}

void DictionaryService::Stub::async::AddWord(::grpc::ClientContext* context, const ::WordRequest* request, ::WordResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::WordRequest, ::WordResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddWord_, context, request, response, std::move(f));
}

void DictionaryService::Stub::async::AddWord(::grpc::ClientContext* context, const ::WordRequest* request, ::WordResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddWord_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::WordResponse>* DictionaryService::Stub::PrepareAsyncAddWordRaw(::grpc::ClientContext* context, const ::WordRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::WordResponse, ::WordRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddWord_, context, request);
}

::grpc::ClientAsyncResponseReader< ::WordResponse>* DictionaryService::Stub::AsyncAddWordRaw(::grpc::ClientContext* context, const ::WordRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddWordRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DictionaryService::Stub::GetAllWords(::grpc::ClientContext* context, const ::Empty& request, ::WordList* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Empty, ::WordList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetAllWords_, context, request, response);
}

void DictionaryService::Stub::async::GetAllWords(::grpc::ClientContext* context, const ::Empty* request, ::WordList* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Empty, ::WordList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllWords_, context, request, response, std::move(f));
}

void DictionaryService::Stub::async::GetAllWords(::grpc::ClientContext* context, const ::Empty* request, ::WordList* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllWords_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::WordList>* DictionaryService::Stub::PrepareAsyncGetAllWordsRaw(::grpc::ClientContext* context, const ::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::WordList, ::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetAllWords_, context, request);
}

::grpc::ClientAsyncResponseReader< ::WordList>* DictionaryService::Stub::AsyncGetAllWordsRaw(::grpc::ClientContext* context, const ::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetAllWordsRaw(context, request, cq);
  result->StartCall();
  return result;
}

DictionaryService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DictionaryService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DictionaryService::Service, ::WordRequest, ::WordResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DictionaryService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::WordRequest* req,
             ::WordResponse* resp) {
               return service->AddWord(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DictionaryService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DictionaryService::Service, ::Empty, ::WordList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DictionaryService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Empty* req,
             ::WordList* resp) {
               return service->GetAllWords(ctx, req, resp);
             }, this)));
}

DictionaryService::Service::~Service() {
}

::grpc::Status DictionaryService::Service::AddWord(::grpc::ServerContext* context, const ::WordRequest* request, ::WordResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DictionaryService::Service::GetAllWords(::grpc::ServerContext* context, const ::Empty* request, ::WordList* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


