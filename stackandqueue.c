#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
following stack is to hold max of n elements
and following queue is to hold max of n-1 elements
*/

int n,top=0,head=0,tail=0;

void push(int *s,int x){//worstcase time = O(1)
    if(top==n){
        printf("overflow\n");
        return;
    }
    s[top++]=x;
    return;
}

int pop(int *s){//worstcase time = O(1)
    if(top==0){
        printf("underflow\n");
        return -1;
    }
    return s[--top];
}

void enqueue(int *q,int x){//worstcase time = O(1)
    if(head==tail+1||(head==0&&tail==n-1)){
        printf("overflow\n");
        return;
    }
    q[tail]=x;
    if(tail==n-1)tail=0;
    else tail++;
    return;
}

int dequeue(int *q){//worstcase time = O(1)
    if(head==tail){
        printf("underflow\n");
        return -1;
    }
    int temp=q[head];
    head++;
    if(head==n)head=0;
    return temp;
}

void printstack(int *s){//worstcase time = O(n)
    int i;
    if(top==0){
        printf("empty stack\n");
        return;
    }
    for(i=0;i<top;i++)printf("%d ",s[i]);
    printf("\n");
    return;
}

void printqueue(int *q){//worst case time = O(n)
    int i;
    if(head==tail){
        printf("empty queue\n");
        return;
    }
    if(tail>head)for(i=head;i<tail;i++)printf("%d ",q[i]);
    else {
        for(i=head;i<n;i++)printf("%d ",q[i]);
        for(i=0;i<tail;i++)printf("%d ",q[i]);
    }
    printf("\n");
    return;
}

int main() {
 int x,op;
 scanf("%d",&n);
 int *s=(int *)malloc(n*sizeof(int));
 int *q=(int *)malloc(n*sizeof(int));
 while(1){
    scanf("%d",&op);
    if(op==0)break;
    if(op==1||op==4)scanf("%d",&x);
    if(op==1)push(s,x);
    if(op==2)pop(s);
    if(op==4)enqueue(q,x);
    if(op==5)dequeue(q);
    if(op==3)printstack(s);
    if(op==6)printqueue(q);
 }
 return 0;
}
