#include <iostream>
#include "json/json.h"
#include <string>

using namespace std;
using namespace Json;

void testjson(void) {
    Value obj;
    Value obj1;
    Reader reader;

    obj["list"].append(1);
    obj["list"].append(2);
    //obj["dict"] = new Value;
    obj["dict"]["key1"] = "a";
    obj["dict"]["key2"] = "B";
    obj["num"] = 1;
    obj["num"] = obj["num"].asInt() + 3;
    //obj["num"].asInt() += 3;

    reader.parse("{\"a\":1,\"b\":[2,3,4,5], \"c\":[], \"d\":\"haha\"}", obj1);
    string js = "json";
    obj[js] =  obj1;

    if (Value::null == obj["abcd3fa"]){
        cout << "can't find key\n" << endl;
    }

    StyledWriter writer;
    cout << "--- in function testjson() ---" << endl; 
    cout << writer.write(obj) << endl; 
    obj.clear();
    // core
    //cout << writer.write(obj) << endl; 
    //obj.append("a");
    //obj.append("b");
    cout << writer.write(obj) << endl; 
}

int main(void)
{
	string a = "{\"a\":1,\"b\":[2,3,4,5], \"c\":[], \"d\":\"haha\",\"e\":{}}";
	Reader reader;	
	Value obj;
	reader.parse(a, obj);
    cout << "obj[e].size =" << obj["e"].size() << endl; 

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

    testjson();
}
