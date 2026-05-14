#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int* arr;
    int n;
}Node;

typedef struct 
{
    int size;
    int capacity;
    Node* data;
}arrVec;

void init(arrVec* v,int capacity){
    v->size = 0;
    v->capacity = capacity;
    Node* temp = (Node*) calloc(capacity,sizeof(Node));
    if(temp==NULL){
        printf("Memory allocation failed");
        exit(1);
    } 
    v->data = temp;
}

void ensureCapacity(arrVec* v){
    if(v->size<v->capacity){return;}
    int oldCapacity = v->capacity;
    v->capacity = (v->capacity==0)?1:v->capacity*2;
    Node* temp = (Node*) realloc(v->data,v->capacity*sizeof(Node));
    if(temp==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    v->data = temp;
    for (int i = oldCapacity; i < v->capacity; i++)
    {
        v->data[i].arr = NULL;
        v->data[i].n = 0;
    }
}

Node createNode(int* arr,int n){
    Node newNode;
    newNode.n = n;
    int* temp = (int*) calloc(n,sizeof(int));
    if(temp==NULL){
        printf("Memory allocation failed");
        Node node;
        node.n = 0;
        node.arr = NULL;
        return node;
    }
    newNode.arr = temp;
    memcpy(newNode.arr,arr,n*sizeof(int));
    return newNode;
}

void pushBack(arrVec* v,int* arr,int n){
    ensureCapacity(v);
    v->data[v->size] = createNode(arr,n);
    v->size++; 
}

void popBack(arrVec* v){
    if (v->size==0)
    {
        printf("Empty Vector\n");
        return;
    }
    free(v->data[v->size-1].arr);
    v->size--;
}

void insertAt(arrVec* v, int pos,int* arr,int n){
    if(pos<0 || pos>v->size)
    {
        printf("Invalid position\n");
        return;
    }
    ensureCapacity(v);
    for (int i = v->size-1; i >= pos; i--)
    {
        v->data[i+1] = v->data[i];
    }
    v->data[pos] = createNode(arr,n);
    v->size++;
}

void deleteAt(arrVec* v,int pos){
    if(pos<0 || pos>=v->size)
    {
        printf("Invalid position\n");
        return;
    }
    free(v->data[pos].arr);
    for (int i = pos; i < v->size-1; i++)
    {
        v->data[i] = v->data[i+1];
    }
    v->size--;
}

Node get(arrVec* v,int pos){
    if(pos<0 || pos>=v->size)
    {
        printf("Invalid position\n");
        Node node;
        node.n = 0;
        node.arr = NULL;
        return node;
    }
    return v->data[pos];
}

void set(arrVec* v,int pos,int* arr,int n){
    if(pos<0 || pos>=v->size)
    {
        printf("Invalid position\n");
        return;
    }
    free(v->data[pos].arr);
    Node node = createNode(arr,n);
    v->data[pos] = node;
}

void printArrVec(arrVec* v){
    for (int i = 0; i < v->size; i++)
    {
        printf("[");
        for (int j = 0; j < v->data[i].n; j++)
        {
            printf("%d ",v->data[i].arr[j]);
        }
        printf("] ");
    }
    printf("\n");
}

void freeArrVec(arrVec* v){
    for(int i = 0; i < v->size; i++){
        free(v->data[i].arr);
    }
    free(v->data);
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
