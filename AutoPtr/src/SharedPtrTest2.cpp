#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace boost;
class shared{
    private:
        shared_ptr<int> p;
    public:
        shared(shared_ptr<int> p_):p(p_){};
        void print()
        {
            std::cout<<"p.use_count:"<<p.use_count()<<",p value:"<<*p<<std::endl;
        }
};
void print_func(shared_ptr<int> &p)
{
    std::cout<<"p.use_count:"<<p.use_count()<<",p value:"<<*p<<std::endl;
}
int main()
{
    shared_ptr<int> p(new int(100));
    shared s1(p), s2(p);
    s1.print();
    s2.print();
    *p=20;
    print_func(p);
    s1.print();
    s2.print();
}
