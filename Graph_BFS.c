#include <stdio.h>
#include <stdlib.h>
//Breadth first search of a graph
int head=0,tail=0;

typedef struct node{
    int dest;
    struct node * next;
}node ;

typedef struct list{
    int src;
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
        g->array[V].src = V;
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

void enqueue(int *q,int v,int n){
    if(head==tail+1||(head ==0 && tail==n)){
        printf("Queue overflow\n");
        return;
    }
    q[tail++] = v;
    if(tail==n+1)tail = 0;
    return;
}

int dequeue(int *q,int n){
    if(head == tail)return -1;
    int temp = q[head++];
    if(head==n+1)head = 0;
    return temp;
}

void BFS(Graph * g){
    int *visited = (int *)calloc(g->V,sizeof(int));
    int n = g->V+1,v;
    int *q[n];
    enqueue(q,0,n);
    while((v=dequeue(q,n))!=-1){
        printf("%d ",v);
        visited[v] = 1;
        node * temp = g->array[v].head;
        while(temp){
            if(!visited[temp->dest])enqueue(q,temp->dest,n);
            temp = temp->next;
        }
    }
}

int main()
{
    Graph * g = creategraph(5);
    addedge(g,0,1);
    addedge(g,0,4);
    addedge(g,0,2);
    addedge(g,1,2);
    addedge(g,2,0);
    addedge(g,2,3);
    addedge(g,3,3);
    BFS(g);
    return 0;
}
