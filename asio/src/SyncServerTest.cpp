#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;
using namespace boost;

int main()
{
    try{
        std::cout<<"start server .."<<std::endl;
        io_service ios;
        ip::tcp::acceptor acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 9999));
        std::cout<<"server ip:"<<acceptor.local_endpoint().address()<<std::endl;
        while(true)
        {
            ip::tcp::socket sock(ios);
            acceptor.accept(sock);
            std::cout<<"clint:";
            std::cout<<sock.remote_endpoint().address()<<std::endl;
            sock.write_some(buffer("hello asio!\n"));
        }
    }catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
}
