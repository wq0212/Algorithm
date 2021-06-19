#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[501][501];
int n;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		for (int j=0;j<i+1;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<i+1;j++){
			if (j==0){
				arr[i][j] = arr[i-1][j] + arr[i][j];
			}
			else if(j==i){
				arr[i][j] = arr[i-1][j-1] + arr[i][j];
			}
			else{
				if (arr[i-1][j]>=arr[i-1][j-1]){
					arr[i][j] = arr[i-1][j] + arr[i][j];
				}
				else{
					arr[i][j] = arr[i-1][j-1] + arr[i][j];
				}
			}
		}
	}
	int max = 0;
	for (int i=0;i<n;i++){
		if (arr[n-1][i]>max){
			max = arr[n-1][i];
		}
	}
	printf("%d\n",max);
}
