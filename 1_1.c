/*
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures.
*/


#include <stdio.h>
#include <string.h>


/*
	假设字符集是ASCII字符, 用每一位表征相应位置字符的出现,需要256位，即一个长度为8的int 数组a即可.
	
	数组的第一个int，即a[0]
	假设ASCII为0的字符 ，那么 0/32 为数组下标， 0%32 为 bit位上的位置 32 那么第一个 字符存在的位置如下图所示：
	
	| 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0|
	   第一个字节	     第二个字节	     第三个字节         第四个字节
        | 1 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0|
      我在这儿	
      
      ASCII 为1的字符存储在
      | 0 1 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0|	
													 	   
*/
int isUnique(char* str)
{
	int a[8];
	memset(a,0,sizeof(a));
	int len = strlen(str);
	int i = 0;
	for(;i<len;i++)
	{
		int temp = str[i];
		int index = temp/32;
		int shift = temp%32;
		if(a[index]&(1<<shift)) return 0;
		a[index] |= (1<<shift);
	}
	
}

int main(){
	char * str = "abcdbf";
	if(isUnique(str))
		printf("true");
	else
		printf("false");
}
