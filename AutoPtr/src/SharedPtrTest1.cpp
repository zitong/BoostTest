#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;
using namespace boost;
int main()
{
    boost::shared_ptr<int> sp(new int(10));
    cout<<sp.unique()<<endl;
    boost::shared_ptr<int> ps2 = sp;
    cout<<"sp.uique:"<<sp.unique()<<endl;
    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    cout<<"*sp:"<<*sp<<endl;
    sp.reset();
    cout<<"sp.unique:"<<sp.unique()<<" sp.use_count:"<<sp.use_count()<<endl;
}
