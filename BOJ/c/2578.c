#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int L[5][5];
int call[5][5];
int visit[5][5];

void bingo(int target){
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			if (L[i][j]==target){
				visit[i][j] = 1;
				return;
			}
		}
	}
}

int check(){
	int cnt=0;
	int tmp;
	for (int i=0;i<5;i++){
		tmp = 0;
		for (int j=0;j<5;j++){
			tmp+=visit[i][j];
		}
		if (tmp==5){
			cnt+=1;
		}
	}
	for (int i=0;i<5;i++){
		int tmp = 0;
		for (int j=0;j<5;j++){
			tmp+=visit[j][i];
		}
		if (tmp==5){
			cnt+=1;
		}
	}
	tmp = 0;
	for (int i=0;i<5;i++){
		tmp+=visit[i][i];
	}
	if (tmp==5){
		cnt+=1;
	}
	tmp = 0;
	for (int i=0;i<5;i++){
		tmp+=visit[i][4-i];
	}
	if (tmp==5){
		cnt+=1;
	}
	return cnt;
}

int main(){
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			scanf("%d",&L[i][j]);
		}
	}
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			scanf("%d",&call[i][j]);
		}
	}
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			visit[i][j] = 0;
		}
	}
	int target;
	int count = 0;
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			target = call[i][j];
			count++;
			bingo(target);
			if(check()>2){
				printf("%d\n",count);
				return 0;
			}
		}
	}
}
