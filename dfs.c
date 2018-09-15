#include <stdio.h>
#include <stdlib.h>
//Depth first search of a graph


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

void DFS(Graph * g,int *visited,int v){
  if(visited[v])return;
  printf("%d ",v);
  visited[v] = 1;
  node * temp = g->array[v].head;
  while(temp){
    DFS(g,visited,temp->dest);
    temp = temp->next;
  }
  return;
}

int main()
{
    Graph * g = creategraph(5);
    int *visited = (int *)calloc(g->V,sizeof(int));
    addedge(g,0,1);
    addedge(g,0,4);
    addedge(g,0,2);
    addedge(g,1,2);
    addedge(g,2,0);
    addedge(g,2,3);
    addedge(g,3,3);
    DFS(g,visited,0);
    return 0;
}