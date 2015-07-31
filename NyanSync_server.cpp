#include "NyanSync.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thread>
#include "Nyancat.cpp"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::concurrency;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::nyan;

const int FIX_FRAME = 22;

int server_counter = 0;
int frame_counter = 0;
int initialized = 0;

class NyanSyncHandler : virtual public NyanSyncIf {
 public:
  NyanSyncHandler() {
    // Your initialization goes here
  }

  void sync(SyncPacket& _return) {
    if (initialized == 0) {
      //init counter
      server_counter = 1;
      frame_counter = 0;

      initialized = 1;  
    }

    _return.server = server_counter;
    _return.frame = frame_counter;
    printf("%d\n", server_counter);
    printf("%d\n", frame_counter);
    printf("sync\n");
  }

};

int counterThread() {
  while (1) {
    frame_counter++;
    if (frame_counter > FIX_FRAME) {
      server_counter++;
      frame_counter = 0;
    }

    usleep(FRAMESPEED);
  }
  return 0;
}

int serverThread(int port) {
  printf("creating server with port: %d", port);

  shared_ptr<NyanSyncHandler> handler(new NyanSyncHandler());
  shared_ptr<TProcessor> processor(new NyanSyncProcessor(handler));
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();

  TNonblockingServer server(processor, protocolFactory, port, threadManager);
  server.serve();
  return 0;
}

int main(int argc, char **argv) {
  std::thread cnt(counterThread);    

  std::thread svr1(serverThread, 9090);

  svr1.join();
  cnt.join();

  return 0;
}

