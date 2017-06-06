#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int n=5;
int head=0,tail=0;

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node;

node *new(int x){
    node *p=(node *)malloc(sizeof(node));
    p->left=p->right=NULL;
    p->key=x;
    return p;
}

void enqueue(node **q,node *x){
    if(head==tail+1||(head==0&&tail==n)){
        //printf("overflow\n");
        return;
    }
    q[tail]=x;
    if(tail==n)tail=0;
    else tail++;
    return;
}

node * dequeue(node **q){
    if(head==tail){
        //printf("underflow\n");
        return NULL;
    }
    node * temp=q[head];
    head++;
    if(head==n+1)head=0;
    return temp;
}

void levelorder(node * x) {//time complexity=O(n)..space complexity=O(n)
    if(!x)return ;
    node *q[n+1];
    enqueue(q,x);
    while(x=dequeue(q)){
        printf("%d ",x->key);
        if(x->left)enqueue(q,x->left);
        if(x->right)enqueue(q,x->right);
    }
    return;
}


int main(){
    node *head=new(1);
    head->left=new(2);
    head->right=new(3);
    head->left->right=new(4);
    head->right->right=new(5);
    printf("level order:\n");
    levelorder(head);
    return 0;
}
