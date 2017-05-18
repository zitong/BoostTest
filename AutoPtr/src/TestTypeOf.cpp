#include <iostream>
using namespace std;
int main()
{
	int var = 666;
	int *pvar = NULL;
	typeof(int *)pvar=&var;
	cout<<pvar<<endl;
}