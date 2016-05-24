main: EchoServer.o
	g++ -std=c++11 -o main main.cc EchoServer.o -lmuduo_net_cpp11 -lmuduo_base_cpp11 -lrt -lpthread

EchoServer.o :
	g++ -std=c++11 -c EchoServer.cc -lmuduo_net_cpp11 -lmuduo_base_cpp11 -lrt -lpthread

clean:
	rm *.o
	rm main
