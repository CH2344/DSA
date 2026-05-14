#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct intVec
{
    int size;
    int capacity;
    int* arr;
}intVec;

void init(intVec* v, int capacity){
    v->size = NULL;
    v->arr = (int*)calloc(capacity,sizeof(int));
    v->capacity = capacity;
}

void ensureCapacity(intVec* v){
    if(v->size<v->capacity){
        return;
    }
    int oldCap = v->capacity;
    v->capacity *= 2;
    v->arr = realloc(v->arr,v->capacity*sizeof(int));
    for (int i = oldCap; i < v->capacity; i++)
    {
        v->arr[i] = 0;
    }
}

void pushBack(intVec* v,int val){
    ensureCapacity(v);
    v->arr[v->size] = val;
    v->size++;
}

void popBack(intVec* v){
    if(v->size==0){printf("Empty vector");}
    v->size--;
}

typedef struct Stack{
    int top;
    intVec* v;
}Stack;

void push(Stack* s,int val){
    pushBack(s->v,val);
}

void pop(Stack* s){
    popBack(s->v);
}

int top(Stack* s){
    return s->v->arr[s->v->size-1];
}

bool isEmpty(Stack* s){
    return s->v->size==0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
