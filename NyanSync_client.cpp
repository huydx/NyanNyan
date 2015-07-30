#include "NyanSync.h"

#include <iostream>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include "thread"
#include "Nyancat.cpp"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace nyan;

int serverId = 0;
int drawFrame = 0;

int clientThread() {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  SyncPacket packet;

  NyanSyncClient client(protocol);

  transport->open();

  while (1) {
    client.sync(packet);
    if (packet.server == serverId) {
      drawFrame = packet.frame;      
    }

    sleep(1);
  }

  transport->close();
  return 0;

}

int drawThread() {
  run_nyan(0); 
  return 0;
}

int main(int argc, char **argv) {
  //check serverId
  if (argc < 2) {
    printf("need serverId to work\n");
    return 1;
  }

  serverId = atoi(argv[1]);

  std::thread clt(clientThread);
  std::thread drw(drawThread);

  clt.join();
  drw.join();

  return 0;
}
