#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	time_t time_s;
	time(&time_s);
	struct timeval tv;
	gettimeofday(&tv, NULL);
	time_s = tv.tv_sec;
	cout << time_s << endl;
	time_t time1 = time_s - time_s % 3600;
	struct tm * ptm = gmtime(&time1);
	printf("%04d%02d%02d-%02d%02d%02d\n", ptm->tm_year+1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

	ptm = localtime(&time1);
	printf("%04d%02d%02d-%02d%02d%02d\n", ptm->tm_year+1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

	bool retry = false;
	bool ret = retry?false:true;
	if (ret)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
