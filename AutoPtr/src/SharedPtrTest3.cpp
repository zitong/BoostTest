#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace boost;
int main()
{
    typedef std::vector<shared_ptr<int> > vs;
    vs v(10);
    int i=0;
    for( vs::iterator pos = v.begin(); pos != v.end(); ++pos)
    {
        *pos = make_shared<int>(++i);
        std::cout<<*(*pos)<<std::endl;
    }
}
