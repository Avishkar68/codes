#include <stdio.h>

void quickSort(int a[],int low, int high){
	int i, j, pivot, temp;
	if(low<high){
		pivot = low;
		i=low;
		j=high;
		while(i<j){
			while(a[i]<=a[pivot] && i<high){
				i++;
			}	
			while(a[j]>a[pivot]){
				j--;
			}
			if(i<j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[pivot];
		a[pivot]=a[j];
		a[j] = temp;

		quickSort(a,low,j-1);
		quickSort(a,j+1,high);
	} 
}

int main(){
	int a[100],n,i;
	
	printf("enter number of elements: \n");
	scanf("%d",&n);

	printf("enter elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quickSort(a,0,n-1);
	printf("sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	
    return 0;
}