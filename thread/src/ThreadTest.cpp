#include <iostream>
#include <boost/thread/thread.hpp>
#include <iostream>

void hello()
{
    while(true){
    	sleep(1);
    	std::cout << "Hello world, I''m new thread!" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    boost::thread thrd(&hello);
    thrd.join();
    std::cout << "Hello world, I''m main thread!" << std::endl;
    while(true){
    	sleep(1);
    	std::cout << "Hello world, I''m main thread!" << std::endl;
    }
    return 0;
}
