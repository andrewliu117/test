#include <iostream>
#include <string.h>

using namespace std;

void init(char* buf){
    int i = 0;
    for(i=0; i<10000; i++){
        buf[i] = 'A' + i % 15;
    }
    buf[i] = 0; 
}

char tolower(char ch){
    if (ch >= 'A' and ch <='Z'){
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int main(void){
    char buf[10240];
    init(buf);
    int length = strlen(buf);
    for (int loop=0; loop<1000; loop++){
        for (int i=0; i < length; i++){
            buf[i] = tolower(buf[i]);
        }
    }
//    cout << buf << endl;
}
