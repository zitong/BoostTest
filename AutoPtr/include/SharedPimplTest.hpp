#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;
class sample
{
    private:
        class impl;
        shared_ptr<impl> p;
    public:
        sample();
        void print();
};

