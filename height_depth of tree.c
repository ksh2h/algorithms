#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct node{
    int key;
    struct node *left,*right,*p;
}node;

node *new(int key){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->left=ptr->right=ptr->p=NULL;
    ptr->key=key;
    return ptr;
}

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int height(node *x){//time complexity=O(n).
    if(!x)return -1;
    return 1+max(height(x->left),height(x->right));
}

int depth(node *x){//time complexity = O(n).
    if(!x)return -1;
    return 1+depth(x->p);
}

int main() {
    node *root=new(1);
    root->left=new(2);
    root->right=new(3);
    root->left->p=root->right->p=root;
    root->left->right=new(4);
    root->left->right->p=root->left;
    printf("%d\n%d\n",height(root),depth(root->left->right));
    return 0;
}
