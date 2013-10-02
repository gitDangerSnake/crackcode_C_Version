// write a method to replace all spaces in a string with '%20'

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* replace(char *s){
	if(s== "") return;
	int len = strlen(s);
	if(len==0) return ;

	int csp = 0,i,p=0;
	for(i=0;i<len;i++){
		if(s[i]==' ')
			csp++;
	}
	 char *tmp =(char*) malloc(sizeof(char)*(len+2*csp+1));
	 for(i=0;i<len;i++){
	 	if(s[i]==' '){
	 		tmp[p] = '%';
	 		tmp[p+1]='2';
	 		tmp[p+2]='0';
	 		 p += 3;
	 	}else{
	 		tmp[p++]=s[i];
	 		
	 	}
	 }
	 tmp[p]='\0';
	 return tmp;

}

/*
	Q:what if there are enough space for the substitution in the array.
*/

void main(){
	char s[] = "I am a student";
	char* res=replace(s);
	printf("%s\n", res);
}