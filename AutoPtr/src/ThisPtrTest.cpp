/**
 * 当类A被share_ptr管理，且在类A的成员函数里需要把当前类对象作为参数传给其他函数时，就需要传递一个指向自身的share_ptr
 */
#include <iostream>
#include <boost/enable_shared_from_this.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;
class self_shared;
void test_func(shared_ptr<self_shared> p);
class self_shared:public enable_shared_from_this<self_shared>
{
public:
	int x;
	self_shared(int n):x(n){}
	void print(){
		test_func(shared_from_this());
	}
};
void test_func(shared_ptr<self_shared> p){
	std::cout<<p->x<<std::endl;
}
int main()
{
	shared_ptr<self_shared> sp = make_shared<self_shared>(314);
	sp->print();
	shared_ptr<self_shared> p = sp->shared_from_this();
	p->x = 1000;
	p->print();
}