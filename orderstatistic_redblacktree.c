#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int key;
    char color;
    struct node *left,*right,*p;
    int size;
}node;

node *newnode(int key){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->key=key;
    ptr->color='r';
    ptr->left=ptr->right=ptr->p=NULL;
    ptr->size=1;
    return ptr;
}

node *search(node *x,int k){//worst case time complexity=O(log n).
    while(x){
        if(x->key==k)return x;
        if(x->key<k)x=x->right;
        else x=x->left;
    }
    return x;
}

void inorder(node *x){//worst case time complexity=O(n).
    if(x){
        inorder(x->left);
        printf("%d ",x->key);
        inorder(x->right);
    }
    return;
}

int size(node *x){
    int r;
    if(x->left)r=x->left->size+1;
    else r=1;
    if(x->right)r+=x->right->size;
    return r;
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
    x->size=size(x);
    y->size=size(y);
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
    y->size=size(y);
    x->size=size(x);
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



node *insert(node *root,int key){//worst case time complexity=O(log n).
    node *z=newnode(key);
    if(!root){
            z->color='b';
            return z;
    }
    node *x=root,*y=NULL;
    while(x){
        y=x;
        x->size++;
        if(key<x->key)x=x->left;
        else x=x->right;
    }
    if(key<y->key)y->left=z;
    else y->right=z;
    z->p=y;
    if(y->color=='r')root=insertfix(root,z);
    return root;
}

node * select(node *x,int i){//worst case time complexity=O(log n).
    int r;
    if(x->left)r=x->left->size+1;
    else r=1;
    if(i==r)return x;
    if(i<r)return select(x->left,i);
    else return select(x->right,i-r);
}

node * select_nonrec(node *x,int i){//worst case time complexity=O(log n).
    int temp,r=0;
    while(x){
        if(x->left)temp=x->left->size+1;
        else temp=1;
        if(r+temp==i)return x;
        if(r+temp<i){
            r+=temp;
            x=x->right;
        }
        else x=x->left;
    }
    return x;
}

int rank(node *root,node *x){//worst case time complexity=O(log n).
    int r;
    if(x->left)r=x->left->size+1;
    else r=1;
    while(x!=root){
        if(x->p->right==x)r+=(x->p->size-x->size);
        x=x->p;
    }
    return r;
}

node *delete(node *root,int i){
    return root;
}

int main() {
    node *root=NULL;
    int op,i;
    node *x,*y;
    while(1){
        scanf("%d",&op);
        if(op==1||op==2||op==3||op==4||op==5)scanf("%d",&i);
        if(op==1)root=insert(root,i);
        else if(op==2){
            x=search(root,i);
            if(x){
                printf("Found :key=%d,color=%c,size=%d\n",x->key,x->color,x->size);
            }
            else printf("Not found in tree\n");
        }
        else if(op==3){
            if(root){
                    if(i>root->size||i<=0)printf("Invalid input\n");
                    else {
                            x=select(root,i);
                            y=select_nonrec(root,i);
                            printf("rec : %dth order statistic =%d\nnonrec : %dth order statistic =%d\n",i,x->key,i,y->key);
                    }
            }
            else printf("Sorry,tree is empty\n");
        }
        else if(op==4){
                x=search(root,i);
                if(x)root=delete(root,i);
                else printf("Error :key not found\n");
        }
        else if(op==5){
            x=search(root,i);
            if(x)printf("Rank of %d is %d\n",i,rank(root,x));
            else printf("Not found in tree\n");
        }
        else if(op==6){
                inorder(root);
                printf("\n");
        }
        else break;
    }
    return 0;
}
