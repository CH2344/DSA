#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Vector of ints
typedef struct{
    int size;
    int capacity;
    int* arr;
}intVec;
void init(intVec* v,int capacity){
    v->size = 0;
    v->capacity = capacity;
    v->arr=(int*) calloc(capacity,sizeof(int));
}
void ensureCapacity(intVec* v){
    if(v->size<v->capacity){
        return;
    }
    v->capacity = (v->capacity == 0) ? 2 : v->capacity * 2;
    v->arr = (int*) realloc(v->arr,v->capacity*sizeof(int));
}
void pushBack(intVec* v,int val){
    ensureCapacity(v);
    v->arr[v->size] = val;
    v->size++;
}
void popBack(intVec* v){
    if(v->size==0){printf("Empty vector\n"); return;}
    v->size--;
}
void insertAt(intVec* v,int pos,int val){
    if(pos<0 || pos>v->size){
        printf("Invalid position\n");
        return;
    }
    ensureCapacity(v);
    if(pos==v->size){
        v->arr[v->size] = val;
        v->size++;
        return;
    }
    for (int i = v->size-1; i >= pos; i--)
    {
        v->arr[i+1] = v->arr[i];
    }
    v->arr[pos] = val;
    v->size++;
}
void deleteAtIndex(intVec* v, int pos){
    if(pos<0 || pos>=v->size){
        printf("Invalid Position\n");
    }
    ensureCapacity(v);
    for (int i = pos; i < v->size-1; i++)
    {
        v->arr[i] = v->arr[i+1];
    }
    v->size--;
}
int get(intVec* v,int index){
    if(index<0 || index>=v->size){
        printf("Invalid position\n");
        return -1;
    }
    return v->arr[index];
}
void set(intVec* v,int index,int val){
    if(index<0 || index>=v->size){
        printf("Invalid position\n");
        return;
    }
    v->arr[index]=val;
}
int cmp(const void*a,const void* b){
    int num1 = *((int*) a);
    int num2 = *((int*) b);
    return (num1>num2)-(num1<num2);
}

void sortVec(intVec* v){
    qsort(v->arr,v->size,sizeof(int),cmp);
}

void printVec(intVec *v){
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ",v->arr[i]);
    }
    printf("\n");
}
void freeVector(intVec* v){
    free(v->arr);
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;
}


int main(){
    //Vector of ints
    intVec v;
    init(&v, 2);

    printf("PushBack:\n");
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 30); // triggers resize
    printVec(&v);

    printf("PopBack:\n");
    popBack(&v);
    printVec(&v);

    printf("InsertAt:\n");
    insertAt(&v, 1, 15);
    printVec(&v);

    printf("DeleteAtIndex:\n");
    deleteAtIndex(&v, 1);
    printVec(&v);

    printf("Get index 1:\n");
    printf("%d\n", get(&v, 1));

    printf("Set index 1 to 99:\n");
    set(&v, 1, 99);
    printVec(&v);

    printf("Edge cases:\n");
    deleteAtIndex(&v, 10); // invalid
    get(&v, -1);           // invalid

    pushBack(&v,20);
    pushBack(&v,50);
    pushBack(&v,10);
    pushBack(&v,40);
    
    printf("Before sorting: \n");
    printVec(&v);
    sortVec(&v);
    printf("After sorting: \n");
    printVec(&v);
    
    freeVector(&v);
    return 0;
}
