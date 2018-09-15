#include <stdio.h>
#include <stdlib.h>

int ind=0;

typedef struct node{
    int dest;
    struct node * next;
}node ;

typedef struct list{
    struct node * head;
}list;

typedef struct Graph{
    int V;
    struct list * array;
}Graph;

Graph * creategraph(int V){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;
    g->array = (list *)malloc(sizeof(list)*V);
    while(V--){
        g->array[V].head = NULL;
    }
    return g;
}

node * newnode(int dest){
    node *p = (node *)malloc(sizeof(node));
    p->next  = NULL;
    p->dest = dest;
    return p;
}

void addedge(Graph * g,int src,int dest){
    node *p = newnode(dest);
    p->next = g->array[src].head;
    g->array[src].head = p;
    return;
}

void DFS(Graph * g,int *visited,int *stack,int v){
  if(visited[v])return;
  printf("%d\n",v);
  visited[v] = 1;
  node * temp = g->array[v].head;
  while(temp){
    DFS(g,visited,stack,temp->dest);
    temp = temp->next;
  }
  stack[ind++] = v;
  return;
}

int main()
{
    int i;
    Graph * g = creategraph(5);
    int *visited = (int *)calloc(g->V,sizeof(int));
    int *stack = (int *)malloc(sizeof(int)*g->V);
    addedge(g,0,1);
    addedge(g,0,4);
    addedge(g,0,2);
    addedge(g,1,2);
    addedge(g,2,3);
    printf("DFS :\n");
    DFS(g,visited,stack,0);
    printf("Topological Sorting :\n");
    for(i=ind-1;i>=0;i--)printf("%d\n",stack[i]);
    return 0;
}