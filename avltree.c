#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int key;
    struct node *left,*right,*p;
    int height;
}node;

node *new(int key){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->left=ptr->right=ptr->p=NULL;
    ptr->key=key;
    ptr->height=0;
    return ptr;
}

void inorder(node *x){//worst case time complexity=O(n).
    if(x){
        inorder(x->left);
        printf("%d ",x->key,x->height);
        inorder(x->right);
    }
    return ;
}

node *search(node *x,int k){//worst case time complexity=O(log n).
    while(x){
        if(x->key==k)return x;
        if(x->key<k)x=x->right;
        else x=x->left;
    }
    return x;
}

node *minimum(node *x){//worst case time complexity=O(log n).
    while(x->left)x=x->left;
    return x;
}

int leftheight(node *z){//worst case time complexity=O(1).
    if(z->left)return z->left->height;
    return -1;
}
int rightheight(node *z){//worst case time complexity=O(1).
    if(z->right)return z->right->height;
    return -1;
}

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int height(node *z){//worst case time complexity=O(1).
    int left=leftheight(z),right=rightheight(z);
    return max(left,right)+1;
}

node *leftrotate(node *root,node *x){//worst case time complexity=O(1).
    if(!x||(x&&!x->right)){
        printf("Invalid operation\n");
        return root;
    }
    node *y=x->right;
    x->right=y->left;
    if(y->left)y->left->p=x;
    y->p=x->p;
    if(x->p){
        if(x->p->left==x)x->p->left=y;
        else x->p->right=y;
    }
    else root=y;
    x->p=y;
    y->left=x;
    return root;
}

node *rightrotate(node *root,node *y){//worst case time complexity=O(1).
    if(!y||(y&&!y->left)){
        printf("Invalid operation1\n");
        return root;
    }
    node *x=y->left;
    y->left=x->right;
    if(x->right)x->right->p=y;
    x->p=y->p;
    if(y->p){
        if(y->p->left==y)y->p->left=x;
        else y->p->right=x;
    }
    else root=x;
    y->p=x;
    x->right=y;
    return root;
}

node *balancetree(node *root,node *y,int key){//worst case time complexity=O(log n).
    while(y){
        y->height=height(y);
        int balance=leftheight(y)-rightheight(y);
        if(balance>1&&key<y->left->key)root=rightrotate(root,y);
        else if(balance>1&&key>=y->left->key){
            root=leftrotate(root,y->left);
            y->left->left->height=height(y->left->left);
            y->left->height=height(y->left);
            root=rightrotate(root,y);
        }
        else if(balance<-1&&key>=y->right->key)root=leftrotate(root,y);
        else if(balance<-1&&key<y->right->key){
            root=rightrotate(root,y->right);
            y->right->right->height=height(y->right->right);
            y->right->height=height(y->right);
            root=leftrotate(root,y);
        }
        if(balance<-1||balance>1){
            y->height=height(y);
            y=y->p;
            y->height=height(y);
        }
        y=y->p;
    }
    return root;
}

node *insert(node *root,int key){//worst case time complexity=O(log n).
    node *x=root,*y=NULL,*z=new(key);
    while(x){
        y=x;
        if(x->key>key)x=x->left;
        else x=x->right;
    }
    if(!y)root=z;
    else {
        if(y->key>key)y->left=z;
        else y->right=z;
    }
    z->p=y;
    root=balancetree(root,y,key);
    return root;
}

node *delete(node *root,node *z){//worst case time complexity=O(log n).
    node *y,*x;
    int key=z->key;
    if(!z->left||!z->right)y=z;
    else y=minimum(z->right);
    if(y!=z){
            key=y->key;
            z->key=y->key;
    }
    if(y->left)x=y->left;
    else x=y->right;
    if(!y->p)root=x;
    else {
        if(y->p->left==y)y->p->left=x;
        else y->p->right=x;
    }
    if(x)x->p=y->p;
    root=balancetree(root,y->p,key);
    return root;
}

int main() {
     node *root=NULL,*x;
    int op,val;
    while(1){
        scanf("%d",&op);
        if(op==1||op==2||op==3)scanf("%d",&val);
        if(op==1){
            root=insert(root,val);
        }
        else if(op==2){
            x=search(root,val);
            if(x)printf("Found\n");
            else printf("Not found\n");
        }
        else if(op==3){
            x=search(root,val);
            if(x){
                    root=delete(root,x);
                    printf("Deleted\n");
            }
            else printf("Not found in tree\n");
        }
        else if(op==4){
            inorder(root);
            printf("\n");
        }
        else break;
    }
    return 0;
}
