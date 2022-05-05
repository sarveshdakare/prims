#include<stdio.h>
void prims();

void main(){
    int n,cost[10][10];
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("Enter cost of the %d %d edges: ",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    prims(n,cost);
}
void prims(int n, int cost[10][10]){
    int mincost=0,min,e=1,u,v,visited[10];
    for(int i=1; i<=n; i++){
        visited[i]=0;
    }
    visited[1]=1;
    while(e<n){
        for(int i=1,min=999; i<=n; i++){
            for(int j=1; j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]==0){
                        continue;
                    }
                    else{
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            if(visited[u]==0||visited[v]==0){
                mincost=mincost+min;
                printf("\n%d edge (%d,%d) & Cost=%d",++e,u,v,min);
                visited[v]=1;
            }
            cost[v][u]=cost[u][v]=999;
        }
    }
    printf("\nTotal cost: %d \n", mincost);
}
