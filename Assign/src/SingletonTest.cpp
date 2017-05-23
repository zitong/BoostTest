#include <iostream>
#include <boost/container/detail/singleton.hpp>
using namespace boost::container::container_detail;
using namespace std;
class SqlDB_t
{
public:
	void connect(){
		cout<<"connect database..."<<endl;
	}
	void execut(const char *sqlstr){
		cout<<"execut sql:"<<sqlstr<<endl;
	}
};
typedef singleton_default<SqlDB_t> SqlDB;
int main(){
	SqlDB::instance().connect();
	SqlDB::instance().execut("select * from mytable");
}