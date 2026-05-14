#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Vec{
    int* arr;
    int size;
    int capacity;
} Vec;

typedef struct vecVec{
    int size;
    int capacity;
    Vec** vecs;
} vecVec;

// ---------------- Vec ----------------

void initVec(Vec* v,int capacity){
    v->capacity = capacity;
    v->size = 0;

    if(capacity > 0){
        v->arr = (int*) calloc(capacity, sizeof(int));
    } else {
        v->arr = NULL;
    }
}

void ensureCapacityVec(Vec* v){
    if(v->size < v->capacity){
        return;
    }

    int oldCap = v->capacity;   // ❌ duplicate removed
    v->capacity = (v->capacity==0)?2:v->capacity*2;

    v->arr = (int*) realloc(v->arr,sizeof(int)*v->capacity);

    for (int i = oldCap; i < v->capacity; i++){
        v->arr[i] = 0;
    }
}

void pushBackVec(Vec* v,int val){
    ensureCapacityVec(v);
    v->arr[v->size++] = val;
}

void popBackVec(Vec* v){
    if(v->size==0){
        printf("Empty vector\n");
        return;
    }
    v->size--;
}

void printVec(Vec* v){
    printf("[ ");
    for(int i=0;i<v->size;i++){
        printf("%d ", v->arr[i]);
    }
    printf("]\n");
}

// ---------------- vecVec ----------------

void initvecVec(vecVec* v,int capacity){
    v->capacity = capacity;
    v->size = 0;

    if(capacity>0){
        v->vecs = (Vec**) calloc(v->capacity,sizeof(Vec*));
    } else {
        v->vecs = NULL;
    }
}

void ensureCapacityVecVec(vecVec* v){
    if(v->size < v->capacity){
        return;
    }

    int oldCap = v->capacity;
    v->capacity = (v->capacity==0)?2:v->capacity*2;

    v->vecs = (Vec**) realloc(v->vecs,sizeof(Vec*)*v->capacity);

    for (int i = oldCap; i < v->capacity; i++){
        v->vecs[i] = NULL;
    }
}

void pushBackVecVec(vecVec* v,Vec* vec){
    ensureCapacityVecVec(v);
    v->vecs[v->size++] = vec;   // pointer copy (correct)
}

void popBackVecVec(vecVec* v){
    if(v->size==0){
        printf("Empty vector\n");
        return;
    }

    Vec* temp = v->vecs[v->size - 1];

    free(temp->arr);
    free(temp);

    v->size--;
}

void printVecVec(vecVec* v){
    printf("[\n");
    for(int i=0;i<v->size;i++){
        printf("  ");
        printVec(v->vecs[i]);
    }
    printf("]\n");
}

int cmp(void* vec1,void* vec2){
    Vec* v1 = *(Vec**)vec1;
    Vec* v2 = *(Vec**)vec2;
    int n1 = v1->size;
    int n2 = v2->size;
    int minSize = (n1<=n2)?n1:n2;
    for (int i = 0; i < minSize; i++)
    {
        if(v1->arr[i]!=v2->arr[i]){
            return (v1->arr[i]>v2->arr[i])-(v1->arr[i]<v2->arr[i]);
        }
    }
    return n1-n2;
}

int main(){

    // -------- Vec testing --------
    Vec v;
    initVec(&v, 2);

    pushBackVec(&v, 10);
    pushBackVec(&v, 20);
    pushBackVec(&v, 30); // resize

    printf("Vec after push:\n");
    printVec(&v);

    popBackVec(&v);
    printf("After pop:\n");
    printVec(&v);


    // -------- vecVec testing --------
    vecVec vv;
    initvecVec(&vv, 2);

    // create Vec 1
    Vec* v1 = (Vec*) malloc(sizeof(Vec));
    initVec(v1, 2);
    pushBackVec(v1, 1);
    pushBackVec(v1, 2);

    // create Vec 2
    Vec* v2 = (Vec*) malloc(sizeof(Vec));
    initVec(v2, 2);
    pushBackVec(v2, 3);
    pushBackVec(v2, 4);

    // push into vecVec
    pushBackVecVec(&vv, v1);
    pushBackVecVec(&vv, v2);

    printf("\nvecVec:\n");
    printVecVec(&vv);

    // pop one Vec
    popBackVecVec(&vv);

    printf("\nAfter popping one Vec:\n");
    printVecVec(&vv);

    return 0;
}