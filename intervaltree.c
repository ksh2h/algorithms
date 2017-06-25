#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
//All intervals are assumed to be closed intervals.

typedef struct interval{
    int low;
    int high;
}interval;

typedef struct node {
    int max;
    char color;
    struct node *left,*right,*p;
    interval *i;
}node;

node *newnode(int low,int high){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->i=(interval *)malloc(sizeof(interval));
    ptr->i->low=low;
    ptr->i->high=high;
    ptr->color='r';
    ptr->max=high;
    ptr->left=ptr->right=ptr->p=NULL;
    return ptr;
}

int max(node *x){//worst case time complexity=O(1).
    int l,r,m;
    if(x->left)l=x->left->max;
    else l=INT_MIN;
    if(x->right)r=x->right->max;
    else r=INT_MIN;
    m=l;
    if(r>l)m=r;
    if(x->i->high>max)m=x->i->high;
    return m;
}

node *search(node *x,int low,int high){//worst case time complexity=O(log n).
    while(x){
        printf("x:[%d,%d]\n",x->i->low,x->i->high);
        if(x->i->low<=high&&low<=x->i->high)return x;
        if(x->left&&x->left->max>=low){
                x=x->left;
        }
        else x=x->right;
    }
    return x;
}

void inorder(node *x){//worst case time complexity=O(n).
    if(x){
        inorder(x->left);
        printf("[%d,%d] ",x->i->low,x->i->high);
        inorder(x->right);
    }
    return;
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
    if(!x->p)root=y;
    else {
        if(x->p->left==x)x->p->left=y;
        else x->p->right=y;
    }
    x->p=y;
    y->left=x;
    x->max=max(x);
    y->max=max(y);
    return root;
}

node *rightrotate(node *root,node *y){//worst case time complexity=O(1).
    if(!y||(y&&!y->left)){
        printf("Invalid operation\n");
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
    y->max=max(y);
    x->max=max(x);
    return root;
}

node *insertfix(node *root,node *z){//worst case time complexity=O(log n).
    node *y;
    while(z&&z->p&&z->p->p&&z->p->color=='r'){
        if(z->p==z->p->p->left){
            y=z->p->p->right;
            if(y&&y->color=='r'){
                y->color='b';
                z->p->color='b';
                z->p->p->color='r';
                z=z->p->p;
            }
            else {
                if(z==z->p->right){
                        z=z->p;
                        root=leftrotate(root,z);
                }
                z->p->color='b';
                z->p->p->color='r';
                root=rightrotate(root,z->p->p);
            }
        }
        else {
            y=z->p->p->left;
            if(y&&y->color=='r'){
                y->color='b';
                z->p->color='b';
                z->p->p->color='r';
                z=z->p->p;
            }
            else {
                if(z==z->p->left){
                    z=z->p;
                    root=rightrotate(root,z);
                }
                z->p->color='b';
                z->p->p->color='r';
                root=leftrotate(root,z->p->p);
            }
        }
    }
    root->color='b';
    return root;
}



node *insert(node *root,int low,int high){//worst case time complexity=O(log n).
    node *z=newnode(low,high);
    if(!root){
            z->color='b';
            z->max=high;
            return z;
    }
    node *x=root,*y=NULL;
    while(x){
        y=x;
        if(x->max<high)x->max=high;
        if(low<x->i->low)x=x->left;
        else x=x->right;
    }
    if(low<y->i->low)y->left=z;
    else y->right=z;
    z->p=y;
    root=insertfix(root,z);
    return root;
}



node *delete(node *root,node *x){
    return root;
}



int main() {
    node *root=NULL;
    int op,low,high;
    node *x,*y;
    while(1){
        scanf("%d",&op);
        if(op==1||op==2||op==3)scanf("%d%d",&low,&high);
        if(op==1){
                root=insert(root,low,high);
        }
        else if(op==2){
            x=search(root,low,high);
            if(x){
                printf("Found interval : [%d,%d]\n",x->i->low,x->i->high);
            }
            else printf("Not found in tree\n");
        }
        else if(op==3){
                x=search(root,low,high);
                if(x)root=delete(root,x);
                else printf("Error :key not found\n");
        }
        else if(op==4){
                inorder(root);
                printf("\n");
        }
        else break;
    }
    return 0;
}
