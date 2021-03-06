#include"tcp_thread_server.hpp"


void HttpProcess(const std::string& req,std::string* resp){
  // 不管用户输入的是啥请求，都返回hello world
  (void) req;
  std::string first_line = "HTTP/1.1 200 OK\n"; 
  std::string body = "<html><div>hello world</div></html>";
  std::string header = "Content-Type:text/html\nContent-Length: "+std::to_string(body.size()) + "\n";
  *resp = first_line + header + "\n" + body;
}
int main(){
     TcpThreadServer server;
     server.Start("0.0.0.0",9090,HttpProcess);
     return 0;
}
