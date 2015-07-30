#include "NyanSync.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::nyan;

class NyanSyncHandler : virtual public NyanSyncIf {
 public:
  NyanSyncHandler() {
    // Your initialization goes here
  }

  void sync(SyncPacket& _return) {
    // Your implementation goes here
    _return.server = 0;
    _return.frame = 10;
    printf("sync\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<NyanSyncHandler> handler(new NyanSyncHandler());
  shared_ptr<TProcessor> processor(new NyanSyncProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

