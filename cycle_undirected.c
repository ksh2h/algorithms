#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Using DFS


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
    if(src==dest)return;
    p = newnode(src);
    p->next = g->array[dest].head;
    g->array[dest].head = p;
    return;
}

bool detect_cycle(Graph * g,bool *visited,int p,int v){
  printf("p : %d , v : %d\n",p,v);
  visited[v] = true;
  node * temp = g->array[v].head;
  while(temp){
    if((temp->dest != p && visited[temp->dest]))return true;
    if(temp->dest != p && detect_cycle(g,visited,v,temp->dest))return true;
    temp = temp->next;
  }
  return false;
}

int main()
{
    Graph * g = creategraph(5);
    bool *visited = (bool *)calloc(g->V,sizeof(int));
    addedge(g,0,1);
    addedge(g,0,4);
    addedge(g,0,2);
    addedge(g,1,2);
    addedge(g,2,3);
    //addedge(g,3,3);
    printf("%s\n",detect_cycle(g,visited,-1,0)? "True":"False");
    return 0;
}