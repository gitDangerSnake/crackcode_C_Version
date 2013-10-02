// design an algorithm and write code to remove the duplicate characters in a string without using any addtional buffer. Note : One or Two addtional variables are fine. An extra copy of the array is not allowed.

#include<stdio.h>
#include<string.h>

/*
	no addtional buffer
*/
void removeDuplicate(char* s){

	int len = strlen(s);
	if(len<2) return;
	int i,j,p=0;

	for(i=0;i<len;i++){
		if(s[i]!='\0'){
			s[p++] = s[i];
			for (j = i+1; j < len; ++j)
			{
				if(s[j]==s[i])
					s[j]='\0';
			}
		}

		
	}

	s[p]='\0';
	printf("%s\n", s);
}

/*
	addtional fixed array
*/

void fastRemoveDuplicate(char* s){
	int len = strlen(s);
	if(len<2) return;
	char c[256];
	memset(c,0,sizeof(c));

	int p=0,i;

	for(i=0;i<len;i++){
		if(!c[s[i]]){
			s[p++]=s[i];
			c[s[i]] = 1;
		}
	}

	s[p] = '\0';
}

main(){
	char s[]="abbcad";
	fastRemoveDuplicate(s);
	printf("%s\n", s);
	int i;
	for(i=0;i<sizeof(s);i++){
		putchar(s[i]);
	}

}