// write a method to decide if two strings are anagrams or not

#include <stdio.h>
#include <string.h>

int isAnagrams(char* s1,char *s2){
	if(s1=="" || s2 == "") return 0;
	if(strlen(s1) != strlen(s2)) return 0;

	int len = strlen(s1);

	int c[256],i; //in case the length of the string is too long. if the length is limited in 256,then char c[256] is just fine.
	memset(c,0,sizeof(c));

	for(i=0;i<len;i++){
		++c[s1[i]];
		--c[s2[i]];
	}

	for(i=0;i<256;i++){
		if(c[i] != 0)
			return 0;
	}

	return 1;
}


/*
	another way to solve this problem is sort the string at first then check whether the two strings is the same or not. 
*/

void main(){
	char s1[] = "abbacd";
	char s2[] = "acdabb";

	isAnagrams(s1,s2) == 1? printf("true\n") : printf("false\n");
}
