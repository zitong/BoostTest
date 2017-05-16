#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;
using namespace boost;
int main()
{
    int *arr = new int[30];
    scoped_array<int> sa(arr);
    fill_n(&sa[0], 30, 5);
    sa[20] = sa[4]+sa[3];
    cout<<"sa[20]:"<<sa[20]<<endl;
}
