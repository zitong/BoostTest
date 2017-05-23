#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::asio;
using namespace boost::posix_time;
using namespace boost;

class a_timer
{
private:
	int count, count_max;
	std::function<void()> f;
	deadline_timer *t;
public:
	template<typename F> a_timer(io_service &ios, int x, F func)
	{
		this->t = new deadline_timer(ios, posix_time::millisec(500));
		this->f = func;
		this->count_max = x;
		this->count = 0;
		this->t->async_wait(boost::bind(&a_timer::call_func, this, boost::asio::placeholders::error));
	}

	void call_func(const system::error_code&)
	{
		if(count >= count_max)
		{
			return;
		}
		++count;
		f();
		t->expires_at(t->expires_at() + posix_time::millisec(500));
		t->async_wait(boost::bind(&a_timer::call_func, this, boost::asio::placeholders::error));
	}
};

void print1()
{
	std::cout<<"hello asio"<<std::endl;
}

void print2()
{
	std::cout<<"hello boost"<<std::endl;
}

int main()
{
	io_service ios;
	a_timer at1(ios, 5, print1);
	a_timer at2(ios, 5, print2);
	ios.run();
}
