#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    bool end;
    struct node *t[26];
    struct node *p;
    int count;
}node;

node *new(){
    int i;
    node *ptr=(node *)malloc(sizeof(node));
    ptr->end=false;
    ptr->count=0;
    ptr->p=NULL;
    for(i=0;i<26;i++)ptr->t[i]=NULL;
    return ptr;
}

void add(node *root,char *s){//time complexity = O(n),n is length of string.
    int i,n=strlen(s),temp;
    node *x=root;
    for(i=0;i<n;i++){
        temp=(int)(s[i])-97;
        if(!x->t[temp]){
            x->t[temp]=new();
            x->t[temp]->p=x;
        }
        x->count++;
        x=x->t[temp];
    }
    x->end=true;
    return;
}

int find(node *root,char *s){//finds no of strings with string s as prefix.
    int i,n=strlen(s),temp;//time complexity=O(n),n is length of string.
    node *x=root;
    for(i=0;i<n;i++){
            temp=(int)(s[i])-97;
            if(!x)return 0;
            x=x->t[temp];
    }
    if(!x)return 0;
    if(x->end)return 1+x->count;
    return x->count;
}

int main() {
    int n;
    node *root=new();
    char s1[10],s2[100];
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",s1,s2);
        if(s1[0]=='a'){
                add(root,s2);
        }
        else printf("%d\n",find(root,s2));
    }
    return 0;
}
