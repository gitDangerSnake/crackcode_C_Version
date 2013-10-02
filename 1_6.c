//Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image 90 degree. Can you do this in place?
//第一步交换主对角线两侧的对称元素，第二步交换第i行和第n-1-i行，即得到结果。
#include<stdio.h>

void swap(int *a,int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void rotate90Degree(int s[][4],int n){
	
	int i,j;
	for (i=0;i<n;i++)	
		for(j=i+1;j<n;j++)
			swap(&s[i][j],&s[j][i]);
	for(i=0;i<n/2;i++)
		for(j=0;j<n;j++)
			swap(&s[i][j],&s[n-i-1][j]);
}

void main(){
	int i,j;
	int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotate90Degree(a,4);

    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j)
           printf("%d ",a[i][j]);
      putchar('\n');
    }
}
