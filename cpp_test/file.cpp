#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	FILE* fp = fopen("rw.txt", "a+");
	fseek(fp, 5, SEEK_SET);	
	fwrite("haha", 1, 4, fp); 
	cout << "finished" << endl;

	fp = fopen("w.txt", "r+");
	fwrite("0123456789", 1, 10, fp); 
	fseek(fp, 5, SEEK_SET);	
	fwrite("haha", 1, 4, fp); 
	cout << "finished" << endl;
	fseek(fp, -1, SEEK_END);	
	cout << ftell(fp) << endl;

	return 0;
}

