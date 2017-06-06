#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int n=5;

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

void inorder(node *x){
    if(x){
        inorder(x->left);
        printf("%d\n",x->key);
        inorder(x->right);
    }
    return ;
}

void preorder(node *x){
    if(x){
        printf("%d\n",x->key);
        preorder(x->left);
        preorder(x->right);
    }
    return;
}

void postorder(node *x){
    if(x){
        postorder(x->left);
        postorder(x->right);
        printf("%d\n",x->key);
    }
    return;
}

void inorder_nonrec(node *head){
    node *x=head;
    node *s[n];
    int stk=0;
    while(1){
        while(x){
            s[stk++]=x;
            x=x->left;
        }
        if(stk){
            x=s[--stk];
            printf("%d\n",x->key);
            x=x->right;
        }
        else break;
    }
    return ;
}

void preorder_nonrec(node *head){
    node *x=head;
    node *s[n];
    int stk=0;
    while(1){
        while(x){
            s[stk++]=x;
            printf("%d\n",x->key);
            x=x->left;
        }
        if(stk){
            x=s[--stk];
            x=x->right;
        }
        else break;
    }
    return ;
}


int main(){
    node *head=new(1);
    head->left=new(2);
    head->right=new(3);
    head->left->right=new(4);
    head->right->right=new(5);
    printf("Inoreder rec:\n");
    inorder(head);
    printf("preoreder rec:\n");
    preorder(head);
    printf("postoreder rec:\n");
    postorder(head);
    printf("Inoreder nonrec:\n");
    inorder_nonrec(head);
    printf("preoreder nonrec:\n");
    preorder_nonrec(head);
    return 0;
}
