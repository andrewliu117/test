#include <stdio.h>
#include <iostream>

using namespace std;

void init(void){
   // throw exception("what the fuck");
    throw exception();
}

int main(void) {
    try {
        init();
    }
    catch (exception & e) {
        printf("catch exception %s \n", e.what());
    }
}
