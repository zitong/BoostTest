#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace boost;
int main()
{
    shared_ptr<int> sp(new int(200));
    std::cout<<sp.use_count()<<std::endl;

    weak_ptr<int> wp(sp);
    std::cout<<wp.use_count()<<std::endl;
    sp.reset();    
    if(wp.expired()){
        std::cout<<"wp is expired"<<std::endl;             
    }else{
        std::cout<<wp.use_count()<<std::endl;
    }
}


