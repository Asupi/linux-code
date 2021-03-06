#include"tcp_thread_server.hpp"
#include<jsoncpp/json/json.h>


// 请求
// "10 20 +"
// 响应
// "30"

//使用 Json 的方式进行序列化和反序列化
//{
//    "nums":[10,20,30....],
//    "op": "+"
//}

//{
//  "result": 30
//}
//如何解析 JSON 格式？借助第三方库，直接完成解析和操作
//jsoncpp
//Json：：Value 用来表示一个Json数据
//Json：：Reader 把字符串转成 Json：：Value
//Json：；Writer 把Json：：Value转成字符串
int main(){
    TcpThreadServer server;
    server.Start("0.0.0.0",9090,[](const std::string& req,std::string* resp){
            //1. 先将req先进行反序列化
            Json::Reader reader;
            Json::Value req_json;
            reader.parse(req,req_json);
            //2.根据反序列化的结果进行计算
            Json::Value& nums = req_json["nums"];
            std::string op=req_json["op"].asString();
            int result= 0;
            for(size_t i=0; i<nums.size();++i){
            if(op == "+"){
            result += nums[(int)i].asInt();
            }else if(op == "-"){
            result -= nums[(int)i].asInt();
            }
            }
            //3. 需要把结果在序列化会一个字符串
            Json::FastWriter writer;
            Json::Value resp_json;
            resp_json["result"] = result;
            *resp = writer.write(resp_json);
        });
    return 0;
}
