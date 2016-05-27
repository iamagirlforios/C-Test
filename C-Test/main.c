//
//  main.c
//  C-Test
//
//  Created by PZDF on 16/5/19.
//  Copyright © 2016年 PZDF. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define HASESIZE 101
#define MAXSIZE  10
typedef struct _node{
    char *name;
    char *desc;
    struct _node *next;
}node;

//线性表
typedef struct _node_{
    int data;
    struct _node_ *next;
}LNode, *LinkList;

//队列
typedef struct queue{
    int array[1024];
    int rear, front;
}Queue;

//带标识的队列
typedef struct{
    int data[MAXSIZE];
    int rear, front;
    int num;
}c_SeQueue;

typedef struct{
    LNode *front, *rear;
}c_LQueue;

c_LQueue *init_cLQueue(){
    c_LQueue *p;
    LNode *H;
    p = malloc(sizeof(c_LQueue));
    H = malloc(sizeof(LNode));
    H->next = NULL;
    p->front = p->rear = H;
    return p;
}

void In_LQueue(c_LQueue *queue, int data){
    LNode *p = malloc(sizeof(LNode));
    p->next = NULL;
    p->data = data;
    queue->rear->next = p;
    queue->rear = p;
}

int Empty_LQueue(c_LQueue *queue){
    if (queue->front == queue->rear) {
        return 1;
    }
    return 0;
}

void Out_LQueue(c_LQueue *queue, int data){
    if (queue->front == queue->rear) {
        return;
    }
    //出队是按顺序来的
    LNode *p = queue->front->next;  //需要删除的元素
    queue->front->next = p->next;
    data = p->data;
    if (queue->front->next == NULL) {
        queue->rear = queue->front;
    }
}

c_SeQueue *init_SqQueue(){
    c_SeQueue *queue = malloc(sizeof(c_SeQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->num = 0;
    return queue;
}

int In_SqQueue(c_SeQueue *queue, int data){
    if (queue->num == MAXSIZE) return -1;
    queue->rear = (queue->rear+1)%MAXSIZE;
    queue->data[queue->rear] = data;
    queue->num++;
    return 1;
}

int Out_SqQueue(c_SeQueue *queue){
    if (queue->num == 0) return -1;
    queue->front = (queue->front+1)%MAXSIZE;
    queue->data[queue->front] = -1;
    queue->num--;
    return 1;
}

int Empty_SqQueue(c_SeQueue *queue){
    if (queue->num == 0) return 1;
    return 0;
}

static node* hashtab[HASESIZE];

int main(int argc, const char * argv[]) {
//    int count = 5;
//    int array[count];
//    int i = 0, j = 0;
//    printf("put %d int :\n", count);
//    for (i = 0; i < count; i ++) {
//        scanf("%d", &array[i]);
//    }
//    for (i = 0; i < count; i ++) {
//        for (j = i + 1; j < count; j ++) {
//            int temp;
//            if (array[i] > array[j]) {
//                temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//            }
//        }
//    }
//    for (i = 0; i < count; i ++) {
//        printf("%d, ", array[i]);
//    }
    
    
//    char *str;
//    int subLen = 0;
//    printf("输入字符串:\n");
//    str = "abcdefghuijrkabsevfhdf";
//    int tempLen = 0;
//    char modeArray[256];
//    int maxLenFrom = 0;
//    char maxArray[256];
//    char tempMaxArray[256];
//    for (int i = 0; i < 256; i ++) {
//        modeArray[i] = -1;
//        maxArray[i] = -1;
//        tempMaxArray[i] = -1;
//    }
//    
//    for (int i = 0; i < strlen(str); i ++) {
//        if (modeArray[str[i]] == -1) {
//            modeArray[str[i]] = i;
//            maxArray[maxLenFrom] = str[i];
//            maxLenFrom ++;
//            tempLen ++;
//        }else{
//            if (tempLen > subLen) {
//                subLen = tempLen;
//                maxLenFrom = 0;
//                for (int i = 0; i < 256; i ++) {
//                    tempMaxArray[i] = maxArray[i];
//                    maxArray[i] = -1;
//                }
//                tempLen = 1;
//            }
//            modeArray[str[i]] = i;
//            maxArray[maxLenFrom] = str[i];
//            maxLenFrom ++;
//        }
//    }
//    if (tempLen > subLen) {
//        subLen = tempLen;
//        for (int i = 0; i < 256; i ++) {
//            tempMaxArray[i] = maxArray[i];
//        }
//    }
//    printf("subLen = %d\n", subLen);
//    for (int i = 0; i < 256; i ++) {
//        if (tempMaxArray[i] != -1) {
//            printf("%c", tempMaxArray[i]);
//        }
//    }
    
//    FILE *fp;
//    char *array[10000];
//    int i = 0;
//    while ((fp=fopen("demo.txt", "r")) != NULL) {
//        char *str = "";
//        fgets(str, 100, fp);
//        array[i] = str;
//        i++;
//    }

//    printf("输入一个整数:\n");
//    int num;
//    scanf("%d", &num);
//    printf("%d", f(num));
//    
//    printf("\n");
    
//    LinkList L = NULL;
//    LNode *s;
//    LNode *r;   //r永远代表最后一个节点
//    r = L;
//    int x;
//    scanf("%d", &x);
//    while (x!=-1) {
//        s = (LNode *)malloc(sizeof(LNode));
//        s->data = x;
//        s->next = r;
//        if (L == NULL) {
//            L = s;
//        }else{
//            r->next = s;
//        }
//        r = s;
//    }
    LinkList L = NULL;
    LNode *p = L;
    int i = 0;
    while (p->next) {
        p = p->next;
        i ++;
    }
    return 0;
}

LNode *Get_Linklist(LinkList L, int i){
    LNode *p = L;
    int j = 0;
    while (p->next && j<i) {
        p = p->next;
        if (j == i) {
            return p;
        }
        j++;
    }
    return NULL;
}

LNode *Locate_LinkList(LinkList L, int data){
    LNode *p = L;
    while (p->next) {
        p = p->next;
        if (p->data && p->data == data) {
            return p;
        }
    }
    return NULL;
}

void revertList(LinkList L){
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    LNode *p = L->next;
    L = NULL;
    while (p) {
        newNode = p;
        p = p->next;
        newNode->next = L->next;
        L->next = newNode;
    }
}

//删除重复节点
void deleteDuplicate(LinkList L){
    LNode *p, *q, *r;
    p = L->next;
    if (p==NULL) return;
    while (p->next) {
        q = p;
        while (q->next) {
            if (q->next->data == p->data) {
                r = q->next;
                q->next = r->next;
            }
        }
    }
}

void compare(LinkList A, LinkList B){
    LNode *p, *q, *s;
    LinkList C;
    C = A;
    C->next = NULL;
    p = A->next;
    q = B->next;
    if(p == NULL || q == NULL) return;
    while (p && q) {
        if (p->data < q->data) {
            if (C->next == NULL) {
                C->next = q;
            }
            q = q->next;
        }else{
            if (C->next == NULL) {
                C->next = p;
            }
            p = p->next;
        }
    }
    if (p==NULL) p=q;
    while (p) {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
        
}

//对两个递增有序的顺序表进行集合的交运算，选择相同的元素组成新的顺序表
void con(){
    int a[12] = {1, 3, 4, 5, 7, 8, 9, 11, 15, 17, 18, 19};
    int b[10] = {2, 3, 6, 7, 8, 12, 16, 17, 18, 19};
    int c[10];
    int i = 0, j = 0, k = 0;
    while (i != 12 && j != 10) {
        if (a[i] > b[j]) {
            j ++;
        }else if(a[i] < b[j]){
            i ++;
        }else{
            c[k] = a[i];
            i ++;
            j ++;
            k ++;
        }
    }
    for (int e = 0; e < k; e++) {
        if (c[e] != -1) {
            printf("%d\n", c[e]);
        }
    }
    printf("\n");
}

int f(int n){
    if (n > 4) {
       return 3*f(n-3);
    }else if(n == 4){
        return 2*2;
    }else if(n == 3){
        return  3;
    }else if(n == 2){
        return 2;
    }
    return 1;
}

void initHashTab(){
    int i = 0;
    for (i = 0; i < HASESIZE; i ++) {
        hashtab[i] = NULL;
    }
}

unsigned int hash(char *s){
    unsigned int h = 0;
    for (; *s; s++) {
        h = *s+h*31;
    }
    return h%HASESIZE;
}

node *lookup(char *n){
    unsigned int hi = hash(n);
    node *np = hashtab[hi];
    for (; np!=NULL; np=np->next) {
        if (!strcmp(np->name, n)) {
            return np;
        }
    }
    return NULL;
}

char *m_strdup(char *o){
    long l = strlen(o)+1;
    char *ns = (char *)malloc(l*sizeof(char));
    strcpy(ns, o);
    return ns==NULL?NULL:ns;
}

char *get(char *name){
    node *n = lookup(name);
    return n==NULL?NULL:n->desc;
}

int install(char *name, char *des){
    unsigned int hi;
    node *np;
    if ((np=lookup(name))==NULL) {
        hi = hash(name);
        np = (node *)malloc(sizeof(node));
        if (np==NULL) {
            return 0;
        }
        np->name = m_strdup(name);
        if (name==NULL) {
            return 0;
        }
        np->next=hashtab[hi];
        hashtab[hi]=np;
        
    }else{
//        free(np->desc);
    }
    np->desc=m_strdup(des);
    if(np->desc==NULL) return 0;
    return 1;
}

#define MAX_STRING_SIZE 256
typedef struct{
    char data[MAX_STRING_SIZE];
    int curlen;
}SeqString;

int StrConcat1(SeqString *s1, SeqString *s2, SeqString *s){
    int len = s1->curlen + s2->curlen;
    if (len > MAX_STRING_SIZE) {
        return -1;
    }
    int i = 0, j = 0;
    while (s1->data[i] != '\0') {
        s->data[j] = s1->data[i];
        j++;
        i++;
    }
    i = 0;
    while (s2->data[i] != '\0') {
        s->data[j] = s2->data[i];
        j++;
        i++;
    }
    s->data[j] = '\0';
    return 1;
}

int StrSub(char *t, char *s, int index, int len){
    if (len > MAX_STRING_SIZE || index > strlen(s) || index+len>strlen(s)) {
        return -1;
    }
//    int i = 0;
//    while (s[i] != '\0' && i != index) {
//        i ++;
//    }
    int j = 0;
    while (s[index] != '\0' && j < len) {
        t[j] = s[index];
        index++;
    }
    return 1;
}

//----------**二叉树------------
typedef struct BiTNode{
    int data;
    struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

//建立空二叉树
int Initiate(BiTree *bt){
    *bt = malloc(sizeof(BiTNode));
    (*bt)->lChild = NULL;
    (*bt)->rChild = NULL;
    return 1;
}

//建立一棵树
BiTNode * Create(int data, BiTNode *lbt, BiTNode *rbt){
    BiTree *bt;
    Initiate(bt);
    BiTNode *firstNode = malloc(sizeof(BiTNode));
    firstNode->data = data;
    (*bt)->lChild = (*bt)->rChild = firstNode;
    (firstNode)->lChild = lbt;
    (firstNode)->rChild = rbt;
    return firstNode;
}

BiTree InsertL(BiTree bt, int data, BiTree parent){
    BiTNode *newNode;
    if (parent == NULL) {
        printf("插入错误");
        return bt;
    }
    if (malloc(sizeof(BiTNode)) == NULL) return bt;
    newNode->data = data;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    if (parent->lChild == NULL) {
        parent->lChild = newNode;
    }else{
        newNode->lChild = parent->lChild;
        parent->lChild = newNode;
    }
    return bt;
}
//删除parent的左子树
BiTree DeleteL(BiTree bt, BiTree parent){
    if (parent == NULL || parent->lChild == NULL) {
        printf("删除错误");
        return bt;
    }
    BiTree p = parent->lChild;
    parent->lChild = NULL;
//    free(p);
    return bt;
}
