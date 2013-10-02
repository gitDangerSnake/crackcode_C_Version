/*
	write code to reverse a C-Style string.
	C-Style means that "abcd" is represented as five characters, including the null character.
*/
#include<stdio.h>
#include<string.h>

/*
	前后交换顺序即可，i<len/2
*/
void swap(char* a,char *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}


void reverse(char *str){	
	int i=0,j=strlen(str)-1;
	while(i<j)
	{		
		swap(&str[i++],&str[j--]);		
	}
	
}

int main()
{
	char s[] = "abcdefgtjt"; // This is 
	// char *s = "djjdkf"; something really bad will happen usually is segment fault because char *s is imutiable
	reverse(s);
	printf("%s\n",s);
	
}

