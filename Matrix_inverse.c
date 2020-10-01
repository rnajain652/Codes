#include<stdio.h>
#define N 3

void printmat(float mat[N][N*2]){
	int row, col;
	for(row=0;row<N;row++){
		for(col=0;col<N*2;col++){
			printf("%4.1f ", mat[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}


int main(){

	float mat[N][N*2] = {{1,1,2,1,0,0},{1,3,-6,0,1,0},{2,-1,2,0,0,1}}, ratio;
	//float mat[N][N+1] = {{1,1,1,1},{3,4,-1,13},{2,2,0,6}}, ratio;
	int row, col, k;

	printmat(mat);

	for(col=0;col<N;col++){
		for(row=0;row<N;row++){
			if(!(col==row)){
				ratio = mat[row][col]/mat[col][col];
				for(k=0;k<N*2;k++){
					mat[row][k] = mat[row][k] - ratio*mat[col][k];
				}

			}		
		}
		
			printmat(mat);
	}

}
