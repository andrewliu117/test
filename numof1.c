#include <stdio.h>
// 计算从0到n中的数，包含多少个1，例如13包含了6个1

int getlen(int num)
{
	int result = 1;
	while(num>0)
	{
		num=num/10;
		result = result*10;
	}
	result = result/10;
	return result;
}

int get_num_of1(int num)
{
	int minnum = getlen(num);
	printf("minnum %d\n", minnum);
	if(minnum==0)
		return 0;
	if(minnum==1)
		return 1;
	int litnum = num%minnum;
	if(num/minnum==1)
	{
		return litnum+1+get_num_of1(minnum-1)+get_num_of1(litnum);
	}
	else
	{
		return minnum+get_num_of1(minnum-1)*(num/minnum)+get_num_of1(litnum);
	}
}

int main()
{
	int num=0;
	scanf("%d",&num);
	printf("%d\n", get_num_of1(num));
	return 0;
}
