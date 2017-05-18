#include "../include/SharedPimplTest.hpp"
#include <iostream>
class sample::impl
{
    public:
        void print()
        {
            cout<<"impl print"<<endl;
        }
};
sample::sample():p(new impl()){}
void sample::print()
{
    p->print();
}

int main()
{
    sample s;
    s.print();
}
