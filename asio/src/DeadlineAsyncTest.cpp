#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::asio;
using namespace boost::posix_time;
using namespace boost;

void print(const system::error_code &e ){
	std::cout<<"hello asio"<<std::endl;
}

int main()
{
    io_service ios;
    deadline_timer t(ios, posix_time::seconds(2));
    std::cout<<t.expires_at()<<std::endl;
    t.async_wait(print);
    ios.run();
    std::cout<<"hello asio"<<std::endl;
}
