#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    struct Node* next;
    int data; 
}Node;

Node* createNode(int val){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

typedef struct Stack
{
    Node* top;
    int size;
}Stack;

void initStack(Stack* s){
    s->size = 0;
    s->top = NULL;    
}

void push(Stack* s,int val){
    Node* newNode = createNode(val);
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}
void pop(Stack* s){
    if(s->top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
}
int peek(Stack* s){
    if(s->top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int isEmpty(Stack* s){
    return (s->top==NULL);
}

void printStack(Stack* s){
    Node* temp = s->top;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
