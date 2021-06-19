#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,m;
int visit[9] = {0,};
int ans[9] = {0,};

void BT(int x){
	if (x==m+1){
		for (int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	else{
		for (int i=1;i<=n;i++){
			if (visit[i]==0){
				visit[i] = 1;
				ans[x] = i;
				BT(x+1);
				visit[i] = 0;
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	BT(1);	
}
