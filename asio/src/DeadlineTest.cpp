#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::asio;
using namespace boost::posix_time;
using namespace boost;
int main()
{
    io_service ios;
    deadline_timer t(ios, posix_time::seconds(2));
    std::cout<<t.expires_at()<<std::endl;
    t.wait();
    std::cout<<"hello asio"<<std::endl;
}
