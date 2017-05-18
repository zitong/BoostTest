#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/pool/object_pool.hpp>
class demo_class
{
public:
	int a,b,c;
	demo_class(int x=1, int y=2, int z=3):a(x),b(y),c(z){};
	~demo_class();
};
int main()
{
	object_pool<demo_class> pl;
	demo_class *p = pl.malloc();
	assert(pl.is_from(p));
	assert(p->a != 1 || p->b != 2 || p->c != 3);
	p = pl.construct(7, 8, 9);
	std::cout<<p->a<<p->b<<p->c<<std::endl;

	object_pool<string> pls;
	for(int i=0; i<10; i++)
	{
		string *s = pls.construct("hello ahaa");
	}
}