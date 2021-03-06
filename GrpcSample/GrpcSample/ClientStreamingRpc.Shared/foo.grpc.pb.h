// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: foo.proto
#ifndef GRPC_foo_2eproto__INCLUDED
#define GRPC_foo_2eproto__INCLUDED

#include "foo.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace ClientStreamingRpc {

class FooService final {
 public:
  static constexpr char const* service_full_name() {
    return "ClientStreamingRpc.FooService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientWriterInterface< ::ClientStreamingRpc::FooRequest>> Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::ClientStreamingRpc::FooRequest>>(TotalRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>> AsyncTotal(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>>(AsyncTotalRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>> PrepareAsyncTotal(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>>(PrepareAsyncTotalRaw(context, response, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::ClientWriteReactor< ::ClientStreamingRpc::FooRequest>* reactor) = 0;
      #else
      virtual void Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::experimental::ClientWriteReactor< ::ClientStreamingRpc::FooRequest>* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientWriterInterface< ::ClientStreamingRpc::FooRequest>* TotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>* AsyncTotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::ClientStreamingRpc::FooRequest>* PrepareAsyncTotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientWriter< ::ClientStreamingRpc::FooRequest>> Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::ClientStreamingRpc::FooRequest>>(TotalRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>> AsyncTotal(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>>(AsyncTotalRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>> PrepareAsyncTotal(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>>(PrepareAsyncTotalRaw(context, response, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::ClientWriteReactor< ::ClientStreamingRpc::FooRequest>* reactor) override;
      #else
      void Total(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::experimental::ClientWriteReactor< ::ClientStreamingRpc::FooRequest>* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientWriter< ::ClientStreamingRpc::FooRequest>* TotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response) override;
    ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>* AsyncTotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::ClientStreamingRpc::FooRequest>* PrepareAsyncTotalRaw(::grpc::ClientContext* context, ::ClientStreamingRpc::FooResponse* response, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Total_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Total(::grpc::ServerContext* context, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* reader, ::ClientStreamingRpc::FooResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Total : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Total() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Total() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Total(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* /*reader*/, ::ClientStreamingRpc::FooResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestTotal(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::ClientStreamingRpc::FooResponse, ::ClientStreamingRpc::FooRequest>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Total<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Total : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Total() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::ClientStreamingRpc::FooRequest, ::ClientStreamingRpc::FooResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, ::ClientStreamingRpc::FooResponse* response) { return this->Total(context, response); }));
    }
    ~ExperimentalWithCallbackMethod_Total() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Total(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* /*reader*/, ::ClientStreamingRpc::FooResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerReadReactor< ::ClientStreamingRpc::FooRequest>* Total(
      ::grpc::CallbackServerContext* /*context*/, ::ClientStreamingRpc::FooResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerReadReactor< ::ClientStreamingRpc::FooRequest>* Total(
      ::grpc::experimental::CallbackServerContext* /*context*/, ::ClientStreamingRpc::FooResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Total<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Total<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Total : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Total() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Total() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Total(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* /*reader*/, ::ClientStreamingRpc::FooResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Total : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Total() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Total() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Total(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* /*reader*/, ::ClientStreamingRpc::FooResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestTotal(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Total : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Total() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, ::grpc::ByteBuffer* response) { return this->Total(context, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Total() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Total(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::ClientStreamingRpc::FooRequest>* /*reader*/, ::ClientStreamingRpc::FooResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* Total(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerReadReactor< ::grpc::ByteBuffer>* Total(
      ::grpc::experimental::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace ClientStreamingRpc


#endif  // GRPC_foo_2eproto__INCLUDED
