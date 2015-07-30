#include "NyanSync.h"

#include <iostream>
#include <fstream>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include "thread"
#include "Nyancat.cpp"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace nyan;

int clientId = 0;
int drawFrame = 0;

std::ofstream myfile;

int clientThread(char* server) {
  boost::shared_ptr<TSocket> socket(new TSocket(server, 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  SyncPacket packet;

  NyanSyncClient client(protocol);

  transport->open();

  while (1) {
    client.sync(packet);
    if (packet.server == clientId) {
      drawFrame = packet.frame;      
    }

    usleep(FRAMESPEED);
  }

  transport->close();
  return 0;

}

int drawThread() {
  while(1) {
    run_nyan(drawFrame); 
    usleep(FRAMESPEED);
  }
  return 0;
}

int main(int argc, char **argv) {
  //check clientId
  if (argc < 3) {
    printf("need clientId to work\n");
    return 1;
  }

  clientId = atoi(argv[1]);
  char* serverHost = argv[2];
  myfile.open ("log.o");

  std::thread clt(clientThread, serverHost);
  std::thread drw(drawThread);

  clt.join();
  drw.join();

  myfile.close();
  return 0;
}
