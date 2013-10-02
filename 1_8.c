//Assume you have a method is isSubstring which checks if one word is a substring of another.Given two strings, S1 and S2 , write code to check if S2 is a rotaion of S1 using only one call to isSubstring. for example, "waterbottle" is a rotation of "erbottlewat"


// first, we need a isSubstring method becase there is no such a method in the C language 
// So I have to write it first 

// Then consider the rotation string 
// "waterbottle" & "erbottlewat" 
// we have only one chance to use the  isSubstring 
//so S1 = "waterbottle" and S2 = "erbottlewat"
//consider this S1+S1 = "waterbottlewaterbottle"  isSubstring(S1+S1,S2) will return true

#include<stdio.h>
#include<string.h>

//isSubstring

int isSubstring(const char* S1,const char* S2){
	//strstr
	return (int)strstr(S1,S2);
}

int isRotation(char S1[],char S2[]){
	if(strlen(S1) != strlen(S2) || S1=="" ) return 0;
	return isSubstring(strcat(S1,S1),S2);
}

void main(){
	char s1[] = "apple";
	char s2[] = "pleap";

	isRotation(s1,s2) != 0 ? printf("true\n") : printf("false\n");
}