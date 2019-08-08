#include<stdio.h>
#include<stdlib.h>

void dfs(int graph[9][9],int s);
void bfs(int graph[9][9],int s);
void push(int j);
void pop();
bool visited[9];
bool visitedbfs[9];
struct bfsqueue{
    int value;
    struct bfsqueue* pointer;
};
struct bfsqueue* frnt=NULL;
struct bfsqueue* rear=NULL;

void push(int j)
{
    struct bfsqueue* temp = (struct bfsqueue*)malloc(sizeof(struct bfsqueue));
    temp->value = j;
    temp->pointer = NULL;
    printf("push:%d\n",temp->value);
    if(frnt==NULL)
    {
   // printf("push:%d",temp->value);
    //printf("temp:%d",temp);
        frnt=temp;
        rear=temp;
    }
    else
    {
        //printf("epush:%d",temp->value);
        rear->pointer=temp;
        rear=temp;
    }
}
void pop()
{
    if(frnt==NULL&&rear==NULL)
    {
        printf("queue is empty");
    }
    else{
        printf("pop:%d\n",frnt->value);
        frnt=frnt->pointer;
    }

}


void dfs(int graph[9][9],int s)
{
    int j;
    printf("%d  ",s);
    visited[s]=true;

	for(j=0;j<9;j++)
       if(!visited[j]&&graph[s][j]==true)
        dfs(graph,j);
}
void bfs(int graph[9][9],int s)
{
    int x,start;
    printf("%d  ",s);
    visitedbfs[s]=true;

    for(x=0;x<9;x++)
    {
        if(!visitedbfs[x]&&graph[s][x]==true)
            push(x);
    }
        pop();
        start=frnt->value;
      bfs(graph,start);
}
int main()
{
    // push(5);
    // push(7);
    // push(9);
    // pop();
    // push(78);
    // pop();
    // pop();
    // pop();
    // pop();

    int graph[9][9]={
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,0},
        {0,1,0,0,0,0,1,0,0},
        {0,0,1,0,0,1,0,0,0},
        {0,0,1,0,1,0,1,0,0},
        {0,0,0,1,0,1,0,1,1},
        {0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,0}
    };
    int i,s;
    for(i=0;i<9;i++)
    {
        visited[i]=false;
    }
for(i=0;i<9;i++)
    {
        visitedbfs[i]=false;
    }
    printf("enter the starting vertex from 1-8\n");
    scanf("%d",&s);
    printf("DFS:");
    dfs(graph,s);
    printf("\nBFS:");
    push(s);
    bfs(graph,s);
    return 0;
}