#include <iostream>
#include <vector>
#include <boost/assign.hpp>
using namespace boost::assign;
int main()
{
	std::vector<int> v;
	v+=1,2,3,4,5,6;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		std::cout<<*i<<std::endl;
	}
	std::vector<std::string> vs;
	vs = list_of("abc")("def")("hiz");
	for (std::vector<std::string>::iterator i = vs.begin(); i != vs.end(); ++i)
	{
		std::cout<<*i<<std::endl;
	}
}