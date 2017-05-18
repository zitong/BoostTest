#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;
void any_func(void *p)
{
    cout<<"delete this point"<<endl;
}
int main()
{
    shared_ptr<void> p((void*)0, any_func);
}
