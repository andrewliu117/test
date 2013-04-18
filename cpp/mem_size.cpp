#include <iostream>

using namespace std;

void foo(void){
    int buf[1000000000];
    buf[0] = 1;
    buf[1000000000 - 1] = 9;
}

int main(void){
	//foo();

    int i;
    cout << "not new" << endl;
    cin >> i;
    int* a = new(int[100000000]);
    cout << "have new" << endl;
    cin >> i;
   
    for (int c=0; c < 100000000;c++){
        a[c]=c;
    }
    cout << "used" << endl;
    cin >> i;

    delete a;
    cout << "delete" << endl;
    cin >> i;
}
