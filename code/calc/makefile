.PHONY:all
all:calc_client calc_server calc_2_client calc_2_server

calc_server:calc_server.cc tcp_thread_server.hpp tcp_socket.hpp 
	g++ calc_server.cc -o calc_server -std=c++11 -lpthread

calc_client: calc_client.cc tcp_client.hpp tcp_socket.hpp 
	g++ calc_client.cc -o calc_client -std=c++11 -lpthread
calc_2_server:calc_2_server.cc tcp_thread_server.hpp tcp_socket.hpp 
	g++ calc_2_server.cc -o calc_2_server -std=c++11 -lpthread -ljsoncpp

calc_2_client: calc_2_client.cc tcp_client.hpp tcp_socket.hpp 
	g++ calc_2_client.cc -o calc_2_client -std=c++11 -lpthread -ljsoncpp


.PHONY:clean
clean:
	rm  calc_client calc_server calc_2_client calc_2_server
	

