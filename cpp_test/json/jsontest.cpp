#include <iostream>
#include "../../../snda_repository/search/code/public/third_part/jsoncpp/include/json/json.h"
#include <string>

using namespace std;
using namespace Json;

int main(void)
{
	string a = "{\"a\":1,\"b\":[2,3,4,5], \"c\":[], \"d\":\"haha\"}";
	Reader reader;	
	Value obj;
	reader.parse(a, obj);
	cout << obj["a"].asInt() << endl;
	Value b = obj["b"];
	cout << "---b---" << endl;
	for(unsigned i = 0; i<b.size(); i++){
		cout << b[i].asInt() << endl;
	}
	cout << "this is it" << "\4" << "haha" << endl;
	cout << obj["c"].size() << endl;
	Value c = obj["c"];
	//unsigned i = 0;
	//cout << c[unsigned(0)].asString() << endl;
	cout << c[0u].asString() << endl;
	obj["a"] = "change";
	cout << obj["a"].asString() << endl;
	//cout << obj["a"].asInt() << endl;
	
	cout << obj["d"].asString() << endl;
	if(obj.isMember("d") && obj["d"].asString() == "haha"){
	//if(obj.isMember("d") ){
		cout << "equal" << endl;
	}
}
