namespace cpp nyan

typedef i32 MyInteger
const i32 INT32CONSTANT = 9853

struct SyncPacket {
  1: i32 server = 0,
  2: i32 frame = 0
}

service NyanSync  {
   SyncPacket sync(),
}
