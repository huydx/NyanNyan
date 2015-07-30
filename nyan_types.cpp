/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "nyan_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace nyan {


SyncPacket::~SyncPacket() throw() {
}


void SyncPacket::__set_server(const int32_t val) {
  this->server = val;
}

void SyncPacket::__set_frame(const int32_t val) {
  this->frame = val;
}

const char* SyncPacket::ascii_fingerprint = "989D1F1AE8D148D5E2119FFEC4BBBEE3";
const uint8_t SyncPacket::binary_fingerprint[16] = {0x98,0x9D,0x1F,0x1A,0xE8,0xD1,0x48,0xD5,0xE2,0x11,0x9F,0xFE,0xC4,0xBB,0xBE,0xE3};

uint32_t SyncPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->server);
          this->__isset.server = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->frame);
          this->__isset.frame = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SyncPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SyncPacket");

  xfer += oprot->writeFieldBegin("server", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->server);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("frame", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->frame);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SyncPacket &a, SyncPacket &b) {
  using ::std::swap;
  swap(a.server, b.server);
  swap(a.frame, b.frame);
  swap(a.__isset, b.__isset);
}

SyncPacket::SyncPacket(const SyncPacket& other0) {
  server = other0.server;
  frame = other0.frame;
  __isset = other0.__isset;
}
SyncPacket& SyncPacket::operator=(const SyncPacket& other1) {
  server = other1.server;
  frame = other1.frame;
  __isset = other1.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const SyncPacket& obj) {
  using apache::thrift::to_string;
  out << "SyncPacket(";
  out << "server=" << to_string(obj.server);
  out << ", " << "frame=" << to_string(obj.frame);
  out << ")";
  return out;
}

} // namespace