#include <stdio.h>

struct Item
{
	int profit , weight;
	float ratio;
};

void sort(struct Item item[],int n){
	int i,j;
	struct Item temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(item[i].ratio < item[j].ratio){
				temp = item[i];
				item[i] = item[j];
				item[j] = temp;
			}
		}
	}
}

int main(){

	int i,n,capacity;
	float totalProfit = 0;
	struct Item item[50];

	printf("enter number of items: \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("enter profit and weight: \n");
		scanf("%d%d",&item[i].profit, &item[i].weight);
		
		item[i].ratio = (float)item[i].profit / item[i].weight;
	}
	printf("enter capacity: \n");
	scanf("%d",&capacity);	
	
	sort(item , n);

	for(i=0;i<n;i++){
		if(capacity >= item[i].weight){
			totalProfit += item[i].profit;
			capacity -= item[i].weight;
		}else{
			totalProfit += capacity * item[i].ratio;
		}
	}
		
	printf("the total profit that can be achived is: %f \n",totalProfit);

	return 0;
}



