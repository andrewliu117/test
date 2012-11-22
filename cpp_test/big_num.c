#include <stdio.h>


int max1(int x,int y){//符号相同，返回x，y中的大值  
  unsigned int z;  
  z=((x-y)>>31)&1;  
  
  return (1-z)*x+z*y;//这种写法很巧妙  
}  
  
int max2(int x,int y){//符号不同，直接判断x的正负即可，返回最大值  
  unsigned int z;  
  z=(x>>31)&1;  
  
  return (1-z)*x+z*y;  
}  
  
int max(int x,int y){  
  unsigned int z;  
  z=((x^y)>>31)&1;//异或操作，判断符号位是否相同  
    
  return (1-z)*max1(x,y)+z*max2(x,y);  
} 

int main(void) {
	int a = 25;
	int b = 13;
	int max_num = max(a,b);
	int sig = ((a-b)>>31) & 1;
	printf("sig=%d\n", sig);
	printf("a=%d, b=%d, max=%d\n", a, b, max_num);
}
