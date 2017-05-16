#include<boost/smart_ptr.hpp>
#include<iostream>
using namespace boost;
using namespace std;
struct posix_file
{
    explicit posix_file(const char * file_name)
    {
        cout<<"open file:"<<file_name<<endl;
    }
    
    ~posix_file()
    {
        cout<<"close file:"<<endl;
    }
};
int main()
{
    scoped_ptr<int> p(new int);
    if(p){
        *p=100;
        cout<<*p<<endl;
    }
    p.reset();
    assert(p==0);
    if(!p){
        cout<<"scoped_ptr == null"<<endl;
        scoped_ptr<posix_file> fp(new posix_file("/Users/lichenyang/Desktop/Test-1.cpp"));
    }
}
