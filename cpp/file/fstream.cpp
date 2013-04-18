#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void initfile() {
    fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
    if (fs.fail()){
        printf("fs fail\n");
        return;
    }
    int ptr[100] = {0};
    fs.write((char*)ptr, 4*100);
    fs.close();
}

void writecell() {
    //fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary);
    fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary);
    fs.seekp(18*4);
    int i = 28;
    fs.write((char*)&i, 4);
    fs.close();
}

void getcell() {
    fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary);
    fs.seekp(11*4);
    int i = 0;
    fs >> i;
    printf("the changed cell is: %d\n", i);
    fs.close();
}

void printblock() {
    fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary);
    int data[10];
    for (int i = 0; i < 10; i++) {
        fs.read((char*)data, 4 * 10);
        for(int j = 0; j< 10; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
    }
    fs.close();
}

void getlast() {
    fstream fs("b.txt", ios_base::in | ios_base::out | ios_base::binary);
    fs.seekp(18*4);
    int i = 0;
    fs.read((char*) & i, 4);
    printf("the last cell is: %d\n", i);
    if (fs.eof()){
        printf("eof is meet\n");
    }

    fs.close();
}

int main(void) {
    initfile();
    printblock();
    writecell();
    getcell();
    printblock();
    getlast();
    printf("atoi %d\n", atoi(" "));
    string str = " ";
    printf("atoi1 %d\n", atoi(str.c_str()));
}
