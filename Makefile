GEN_SRC := NyanSync.cpp nyan_constants.cpp nyan_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)

.PHONY: all clean

all: nyan_server nyan_client

%.o: %.cpp 
	$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -std=c++0x $(INC) -c $< -o $@ 

nyan_server: NyanSync_server.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift -lthriftnb -levent

nyan_client: NyanSync_client.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift -pthread  -lthriftnb -levent

clean:
	$(RM) *.o nyan_server nyan_client
