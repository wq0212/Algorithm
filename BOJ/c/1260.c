#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **arr;
int *visit;
int *queue;
int n,m,v;

void dfs(int v){
	visit[v] = 1;
	printf("%d ",v);
	for (int i=1;i<n+1;i++){
		if (arr[v][i]==1 && visit[i]==0){
			dfs(i);
		}
	}
}

void bfs(int v){
	int front=0,top=0;
	queue[top] = v;
	printf("%d ",v);
	top++;
	visit[v] = 1;
	int get;
	while(front<top){
		get = queue[front];
		front++;
		for (int i=1;i<n+1;i++){
			if (arr[get][i]==1 && visit[i]==0){
				queue[top] = i;
				top++;
				printf("%d ",i);
				visit[i] = 1;
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&v);

	arr = (int**)calloc(n+1,sizeof(int*));
	for (int i=0;i<n+1;i++){
		arr[i] = (int*) calloc (n+1,sizeof(int));
	}
	
	int a,b;
	for (int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	visit = (int*)calloc(n+1,sizeof(int));
	dfs(v);
	printf("\n");
	free(visit);
	visit = (int*)calloc(n+1,sizeof(int));
	queue = (int*)calloc(n+1,sizeof(int));
	bfs(v);
	printf("\n");
	
}
