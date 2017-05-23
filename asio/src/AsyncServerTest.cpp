#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;
using namespace boost::asio;
class Server
{
private:
	io_service &ios;
	ip::tcp::acceptor acceptor;
	typedef shared_ptr<ip::tcp::socket> sock_pt;
public:
	Server(io_service &io):ios(io),acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 9900))
	{
		start();
	}

	void start()
	{
		sock_pt sock(new ip::tcp::socket(ios));
		acceptor.async_accept(*sock, bind(&Server::accept_handler, this, asio::placeholders::error, sock));
	}

	void accept_handler(const boost::system::error_code &ec, sock_pt sock)
	{
		if(ec){
			return;
		}
		std::cout<<"clint:";
		sock->async_write_some(buffer("hello asio"), bind(&Server::write_handler,this, asio::placeholders::error));
		start();
	}

	void write_handler(const boost::system::error_code &ec)
	{
		std::cout<<"send msg complate."<<std::endl;
	}
};

int main()
{
	try
	{
		std::cout<<"Server start."<<std::endl;
		io_service ios;
		Server sev(ios);
		ios.run();
	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}