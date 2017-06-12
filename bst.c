#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
All the below operations run in O(h) time in worst case.
*/

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

void inorder(node *x){
    if(x){
        inorder(x->left);
        printf("%d ",x->key);
        inorder(x->right);
    }
    return ;
}

node *maximum(node *x){
    while(x->right)x=x->right;
    return x;
}

node *maximum_rec(node *x){
    if(x->right)return maximum_rec(x->right);
    return x;
}

node *minimum(node *x){
    while(x->left)x=x->left;
    return x;
}

node *minimum_rec(node *x){
    if(x->left)return minimum_rec(x->left);
    return x;
}

node *successor(node *x){
    if(x->right)return minimum(x->right);
    node *y=x->p;
    while(y){
        if(y->left==x)return y;
        x=y;
        y=y->p;
    }
    return y;
}

node *predecessor(node *x){
    if(x->left)return maximum(x->left);
    node *y=x->p;
    while(y){
        if(y->right==x)return y;
        x=y;
        y=y->p;
    }
    return y;
}

node *search(node *x,int k){
    while(x){
        if(x->key==k)return x;
        if(x->key<k)x=x->right;
        else x=x->left;
    }
    return x;
}

node *search_rec(node *x,int k){
    if(x==NULL||(x&&x->key==k))return x;
    if(x->key<k)return search_rec(x->right,k);
    return search_rec(x->left,k);
}

node *insert(node *root,int key){
    node *ptr=new(key),*x=root,*y=NULL;
    if(!root)return ptr;
    while(x){
        y=x;
        if(x->key>key)x=x->left;
        else x=x->right;
    }
    if(y->key>key)y->left=ptr;
    else y->right=ptr;
    ptr->p=y;
    return  root;
}

node *delete(node *root,node *z){
    node *x,*y;
    if(!z->left||!z->right)y=z;
    else y=minimum(z->right);
    if(y->left)x=y->left;
    else x=y->right;
    if(x)x->p=y->p;
    if(!y->p)root=x;
    else {
        if(y==y->p->left)y->p->left=x;
        else y->p->right=x;
    }
    if(y!=z)z->key=y->key;
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
