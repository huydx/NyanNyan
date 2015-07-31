# NyanNyan (my personal project to explore thrift)
- Client-server model terminal nyancat, use to display moving nyancat in multiple display, and multiple computers.
- The original art/nyancat display logic is borrowed from @klange in : https://github.com/klange/nyancat
- The program use thrift as protocol to sync between client and server

# Install

#### Install thrift
Follow instruction from homepage
https://thrift.apache.org/docs/install/centos

#### Install libevent
I built libevent from source using follow url
https://github.com/libevent/libevent

#### Linking
My program use tnonblocking server from thrift, so libevent.so and libthirftnb must be linked.
When using instruction from homepage, it install to /usr/local/lib instead of /usr/lib, so just need to symlink the so files:

```
ln -s /usr/local/lib/libthrift-1.0.0-dev.so /usr/lib64/libthrift-1.0.0-dev.so
ln -s /usr/local/lib/libthriftnb-1.0.0-dev.so /usr/lib64/libthriftnb-1.0.0-dev.so
ln -s /usr/local/lib/libevent-2.1.so.5 /usr/lib64/libevent-2.1.so.5

//finally ldconfig to update dynamic link file to OS
ldconfig
```

#### make
Just make

```
make
```

#### Running
- Server

```
./nyan_server
```

- Client

```
./nyan_client id host port
```


#### Result
![nyannyan](https://cloud.githubusercontent.com/assets/535718/8999404/e0595d94-3774-11e5-9730-27d3449adf26.png)
