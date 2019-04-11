/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "./gen-cpp2/ExampleServiceAsyncClient.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/gen/client_cpp.h>
#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace tamvm { namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>> ExampleService_get_number_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_I32, int32_t*>> ExampleService_get_number_presult;

template <typename Protocol_>
void ExampleServiceAsyncClient::get_numberT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t number) {
  auto headerAndReqContext = std::make_shared<apache::thrift::detail::ac::HeaderAndReqContext>();
  std::shared_ptr<apache::thrift::transport::THeader> header(headerAndReqContext, &headerAndReqContext->header);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  headerAndReqContext->reqContext.setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "ExampleService.get_number", &headerAndReqContext->reqContext);
  ExampleService_get_number_pargs args;
  args.get<0>().value = &number;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), std::move(header), channel_.get(), "get_number", writer, sizer, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, useSync);
  headerAndReqContext->reqContext.setRequestHeader(nullptr);
}



void ExampleServiceAsyncClient::get_number(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t number) {
  ::apache::thrift::RpcOptions rpcOptions;
  get_numberImpl(false, rpcOptions, std::move(callback), number);
}

void ExampleServiceAsyncClient::get_number(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t number) {
  get_numberImpl(false, rpcOptions, std::move(callback), number);
}

void ExampleServiceAsyncClient::get_numberImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t number) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      get_numberT(&writer, useSync, rpcOptions, std::move(callback), number);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      get_numberT(&writer, useSync, rpcOptions, std::move(callback), number);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

int32_t ExampleServiceAsyncClient::sync_get_number(int32_t number) {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_get_number(rpcOptions, number);
}

int32_t ExampleServiceAsyncClient::sync_get_number(apache::thrift::RpcOptions& rpcOptions, int32_t number) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(
      &_returnState, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE);
  get_numberImpl(true, rpcOptions, std::move(callback), number);
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  return recv_get_number(_returnState);
}

folly::Future<int32_t> ExampleServiceAsyncClient::future_get_number(int32_t number) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_get_number(rpcOptions, number);
}

folly::SemiFuture<int32_t> ExampleServiceAsyncClient::semifuture_get_number(int32_t number) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_get_number(rpcOptions, number);
}

folly::Future<int32_t> ExampleServiceAsyncClient::future_get_number(apache::thrift::RpcOptions& rpcOptions, int32_t number) {
  folly::Promise<int32_t> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<int32_t>>(std::move(_promise), recv_wrapped_get_number, channel_);
  get_number(rpcOptions, std::move(callback), number);
  return _future;
}

folly::SemiFuture<int32_t> ExampleServiceAsyncClient::semifuture_get_number(apache::thrift::RpcOptions& rpcOptions, int32_t number) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_get_number, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get_number(rpcOptions, std::move(callback), number);
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> ExampleServiceAsyncClient::header_future_get_number(apache::thrift::RpcOptions& rpcOptions, int32_t number) {
  folly::Promise<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<int32_t>>(std::move(_promise), recv_wrapped_get_number, channel_);
  get_number(rpcOptions, std::move(callback), number);
  return _future;
}

folly::SemiFuture<std::pair<int32_t, std::unique_ptr<apache::thrift::transport::THeader>>> ExampleServiceAsyncClient::header_semifuture_get_number(apache::thrift::RpcOptions& rpcOptions, int32_t number) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_get_number, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get_number(rpcOptions, std::move(callback), number);
  return std::move(callbackAndFuture.second);
}

void ExampleServiceAsyncClient::get_number(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t number) {
  get_number(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), number);
}

folly::exception_wrapper ExampleServiceAsyncClient::recv_wrapped_get_number(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ExampleService_get_number_presult;
  constexpr auto const fname = "get_number";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

int32_t ExampleServiceAsyncClient::recv_get_number(::apache::thrift::ClientReceiveState& state) {
  int32_t _return;
  auto ew = recv_wrapped_get_number(_return, state);
  if (ew) {
    ew.throw_exception();
  }
  return _return;
}

int32_t ExampleServiceAsyncClient::recv_instance_get_number(::apache::thrift::ClientReceiveState& state) {
  return recv_get_number(state);
}

folly::exception_wrapper ExampleServiceAsyncClient::recv_instance_wrapped_get_number(int32_t& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_get_number(_return, state);
}

}} // tamvm::cpp2
namespace apache { namespace thrift {

}} // apache::thrift