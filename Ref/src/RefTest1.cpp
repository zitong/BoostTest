#include <vector>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
using namespace boost::assign;
using namespace boost;
int main()
{
    struct square{
        typedef void reslut_of;
        void operator()(int &x){
            x=x*x;
        }
    };
    std::vector<int> v;
    v += 1,2,3,4,5;
    BOOST_FOREACH(int x, v){
        square();
        std::cout<<x<<std::endl;
    };
}
