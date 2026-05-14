#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int size;
    int capacity;
    char** data;
} strVec;

void init(strVec* v, int capacity){
    v->size = 0;
    v->capacity = capacity;
    v->data = (char**) calloc(capacity, sizeof(char*));
}

void ensureCapacity(strVec* v){
    if(v->size < v->capacity){
        return;
    }
    int oldCapacity = v->capacity;
    //Handle the capacity 0 condition
    v->capacity = (v->capacity == 0) ? 2 : v->capacity * 2;
    v->data = (char**) realloc(v->data, v->capacity * sizeof(char*));

    for (int i = oldCapacity; i < v->capacity; i++){
        v->data[i] = NULL;
    }
}

void pushBack(strVec* v, char* str){
    ensureCapacity(v);
    //Don't directly do strcpy first allocate memory as per str's length. +1 for '\0'
    v->data[v->size] = (char*) calloc(strlen(str) + 1, sizeof(char));
    strcpy(v->data[v->size], str);
    v->size++;
}

void popBack(strVec* v){
    if(v->size == 0){
        printf("Empty vector\n");
        return;
    }
    //Don't just decr the size also free that memory
    free(v->data[v->size - 1]);
    v->size--;
}

void insertAt(strVec* v, int pos, char* str){
    if(pos < 0 || pos > v->size){
        printf("Invalid position\n");
        return;
    }

    ensureCapacity(v);

    if(pos == v->size){
        v->data[pos] = (char*) calloc(strlen(str) + 1, sizeof(char));
        strcpy(v->data[v->size], str);
        v->size++;
        return;
    }

    for (int i = v->size - 1; i >= pos; i--){
        v->data[i + 1] = v->data[i];
    }

    v->data[pos] = (char*) calloc(strlen(str) + 1, sizeof(char));
    strcpy(v->data[pos], str);
    v->size++;
}

void deleteAtIndex(strVec* v, int pos){
    if(pos < 0 || pos >= v->size){
        printf("Invalid Position\n");
        return;
    }

    free(v->data[pos]);

    for (int i = pos; i < v->size - 1; i++){
        v->data[i] = v->data[i + 1];
    }

    v->size--;
}

char* get(strVec* v, int index){
    if(index < 0 || index >= v->size){
        printf("Invalid position\n");
        return NULL;
    }
    return v->data[index];
}

void set(strVec* v, int index, char* str){
    if(index < 0 || index >= v->size){
        printf("Invalid position\n");
        return;
    }

    free(v->data[index]);
    v->data[index] = (char*) calloc(strlen(str) + 1, sizeof(char));
    strcpy(v->data[index], str);
}

void printVec(strVec *v){
    for (int i = 0; i < v->size; i++){
        printf("%s ", v->data[i]);
    }
    printf("\n");
}

void freeVector(strVec* v){
    for (int i = 0; i < v->size; i++){
        free(v->data[i]);
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main() {
    strVec v;

    // Initialize
    init(&v, 2);

    // Push back
    pushBack(&v, "hello");
    pushBack(&v, "world");
    pushBack(&v, "vector");
    printVec(&v);   // hello world vector

    // Insert at position
    insertAt(&v, 1, "C");
    printVec(&v);   // hello C world vector

    // Get element
    char* val = get(&v, 2);
    if(val != NULL){
        printf("Element at index 2: %s\n", val);
    }

    // Set element
    set(&v, 2, "programming");
    printVec(&v);   // hello C programming vector

    // Delete at index
    deleteAtIndex(&v, 1);
    printVec(&v);   // hello programming vector

    // Pop back
    popBack(&v);
    printVec(&v);   // hello programming

    // Pop until empty (to test edge case)
    popBack(&v);
    popBack(&v);
    popBack(&v);    // should print "Empty vector"

    // Final cleanup
    freeVector(&v);

    return 0;
}
