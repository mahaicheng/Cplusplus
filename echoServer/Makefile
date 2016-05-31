link_library = -lmuduo_net_cpp11 -lmuduo_base_cpp11 -lrt -lpthread
CC_FLAG = -std=c++11
CC = g++
EXECUABLE = EchoServer
OBJECT = EchoServer.o EchoServerImpl.o

default: $(OBJECT)
	$(CC) $(CC_FLAG) -o EchoServer main.cc $(OBJECT) $(link_library)
	rm $(OBJECT)

EchoServer.o : EchoServerImpl.o
	$(CC) $(CC_FLAG) -c EchoServer.cc EchoServerImpl.o $(link_library)

EchoServerImpl.o :
	$(CC) $(CC_FLAG) -c EchoServerImpl.cc $(link_library)

clean:
	rm $(EXECUABLE)
