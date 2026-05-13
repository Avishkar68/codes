#include <stdio.h>
#include <limits.h>

int m[10][10];

int matrixChain(int p[],int n){
	int i,j,k,L,q;
	for(i=0;i<n;i++){
		m[i][i] = 0;
	}
	for(L=2;L<=n;L++){
		for(i=1;i<n-L+1;i++){
			j = i+L-1;
			m[i][j] = INT_MAX;

			for(k=i;k<j;k++){
				q = m[i][k] + m[k+1][j] + p[i-1] * p[j] * p[k];
				if(q < m[i][j]){
					m[i][j] = q;
				}
			}
		}
	}
	return m[1][n-1];
}

int main(){
	int p[10],n,i;
	printf("enter number of metrices: \n");
	scanf("%d",&n);
	printf("enter dimensions: \n");
	for(i=0;i<=n;i++){
		scanf("%d",&p[i]);
	}
	int result = matrixChain(p,n);
	printf("minimum multiplications cost is : %d \n",result);
	return 0;	
}