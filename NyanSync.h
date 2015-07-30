/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef NyanSync_H
#define NyanSync_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "nyan_types.h"

namespace nyan {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class NyanSyncIf {
 public:
  virtual ~NyanSyncIf() {}
  virtual void sync(SyncPacket& _return) = 0;
};

class NyanSyncIfFactory {
 public:
  typedef NyanSyncIf Handler;

  virtual ~NyanSyncIfFactory() {}

  virtual NyanSyncIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(NyanSyncIf* /* handler */) = 0;
};

class NyanSyncIfSingletonFactory : virtual public NyanSyncIfFactory {
 public:
  NyanSyncIfSingletonFactory(const boost::shared_ptr<NyanSyncIf>& iface) : iface_(iface) {}
  virtual ~NyanSyncIfSingletonFactory() {}

  virtual NyanSyncIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(NyanSyncIf* /* handler */) {}

 protected:
  boost::shared_ptr<NyanSyncIf> iface_;
};

class NyanSyncNull : virtual public NyanSyncIf {
 public:
  virtual ~NyanSyncNull() {}
  void sync(SyncPacket& /* _return */) {
    return;
  }
};


class NyanSync_sync_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  NyanSync_sync_args(const NyanSync_sync_args&);
  NyanSync_sync_args& operator=(const NyanSync_sync_args&);
  NyanSync_sync_args() {
  }

  virtual ~NyanSync_sync_args() throw();

  bool operator == (const NyanSync_sync_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const NyanSync_sync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NyanSync_sync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const NyanSync_sync_args& obj);

};


class NyanSync_sync_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~NyanSync_sync_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const NyanSync_sync_pargs& obj);

};

typedef struct _NyanSync_sync_result__isset {
  _NyanSync_sync_result__isset() : success(false) {}
  bool success :1;
} _NyanSync_sync_result__isset;

class NyanSync_sync_result {
 public:

  static const char* ascii_fingerprint; // = "2608B2248A20695720752F369582E1E6";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0x08,0xB2,0x24,0x8A,0x20,0x69,0x57,0x20,0x75,0x2F,0x36,0x95,0x82,0xE1,0xE6};

  NyanSync_sync_result(const NyanSync_sync_result&);
  NyanSync_sync_result& operator=(const NyanSync_sync_result&);
  NyanSync_sync_result() {
  }

  virtual ~NyanSync_sync_result() throw();
  SyncPacket success;

  _NyanSync_sync_result__isset __isset;

  void __set_success(const SyncPacket& val);

  bool operator == (const NyanSync_sync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const NyanSync_sync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NyanSync_sync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const NyanSync_sync_result& obj);

};

typedef struct _NyanSync_sync_presult__isset {
  _NyanSync_sync_presult__isset() : success(false) {}
  bool success :1;
} _NyanSync_sync_presult__isset;

class NyanSync_sync_presult {
 public:

  static const char* ascii_fingerprint; // = "2608B2248A20695720752F369582E1E6";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0x08,0xB2,0x24,0x8A,0x20,0x69,0x57,0x20,0x75,0x2F,0x36,0x95,0x82,0xE1,0xE6};


  virtual ~NyanSync_sync_presult() throw();
  SyncPacket* success;

  _NyanSync_sync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const NyanSync_sync_presult& obj);

};

class NyanSyncClient : virtual public NyanSyncIf {
 public:
  NyanSyncClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NyanSyncClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sync(SyncPacket& _return);
  void send_sync();
  void recv_sync(SyncPacket& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class NyanSyncProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<NyanSyncIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (NyanSyncProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_sync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  NyanSyncProcessor(boost::shared_ptr<NyanSyncIf> iface) :
    iface_(iface) {
    processMap_["sync"] = &NyanSyncProcessor::process_sync;
  }

  virtual ~NyanSyncProcessor() {}
};

class NyanSyncProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  NyanSyncProcessorFactory(const ::boost::shared_ptr< NyanSyncIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< NyanSyncIfFactory > handlerFactory_;
};

class NyanSyncMultiface : virtual public NyanSyncIf {
 public:
  NyanSyncMultiface(std::vector<boost::shared_ptr<NyanSyncIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~NyanSyncMultiface() {}
 protected:
  std::vector<boost::shared_ptr<NyanSyncIf> > ifaces_;
  NyanSyncMultiface() {}
  void add(boost::shared_ptr<NyanSyncIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void sync(SyncPacket& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sync(_return);
    }
    ifaces_[i]->sync(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class NyanSyncConcurrentClient : virtual public NyanSyncIf {
 public:
  NyanSyncConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NyanSyncConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sync(SyncPacket& _return);
  int32_t send_sync();
  void recv_sync(SyncPacket& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif