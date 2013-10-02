//write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

#include<stdio.h>

void set0(int **a,int m,int n){
	char row[m],column[n];
	memset(row,0,sizeof(row));
	memset(column,0,sizeof(column));

	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if(a[i][j]==0) {
				row[i] = 1;
				column[j] = 1;
			}
		}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)	
			if(row[i] || column[j])
				a[i][j]=0;

}