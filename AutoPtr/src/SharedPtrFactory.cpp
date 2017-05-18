#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace boost;
int main()
{
    shared_ptr<std::string> str = make_shared<std::string>("this is a string");
    std::cout<<"make_create string is:"<<*str<<std::endl;
    shared_ptr<std::vector<int> > spv = make_shared<std::vector<int> >(10,20);
    for(int i=0; i<spv->size(); i++)
    {
        std::cout<<spv->at(i)<<std::endl;
    }
    std::cout<<spv->size()<<std::endl;
}
