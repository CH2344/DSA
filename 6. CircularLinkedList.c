#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    Node* next;
}Node;

typedef struct{
    Node* head;
}CLL;
Node* createNode(int val){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = node; 
    node->data = val;
    return node;
}

void pushFront(CLL* l,int val){
    if(l == NULL){
      printf("List not initialized\n");
      return;
    }
    Node* newNode = createNode(val);
    if(l->head == NULL){
        l->head = newNode;
        return;
    }
    Node* tail = l->head;
    while (tail->next!=l->head)
    {
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = l->head;
    l->head->next = newNode;
    l->head = newNode;
}
void pushBack(CLL* l,int val){
    if(l == NULL){
      printf("List not initialized\n");
      return;
    }
    Node* newNode = createNode(val);
    if(l->head == NULL){
      l->head = newNode;
      return;
    }
    Node* tail = l->head;
    while(tail->next != l->head){
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = l->head;
}

void popFront(CLL* l){
  if(l==NULL || l->head == NULL){
    printf("List is empty \n");
    return;
  }

  Node* temp = l->head;
  // In CLL, if only one node exists, head->next == head
  if(l->head->next == l->head){
        free(temp);
        l->head = NULL;   // ✅ List becomes empty
        return;
    }
  
  Node* tail = l->head;
  while(tail->next != l->head){
    tail = tail->next;
  }
  l->head = l->head->next;
  tail->next = l->head;
  free(temp);
}

void popBack(CLL* l){
    if(l == NULL || l->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* tail = l->head;
    Node* prev = NULL;

    if(l->head->next == l->head){
        free(l->head);
        l->head = NULL;   
        return;
    }

    while(tail->next != l->head){
        prev = tail;
        tail = tail->next;
    }
    prev->next = l->head;   // ✅ second last points to head

    free(tail);             // delete last node
}
void insertAt(CLL* l, int pos, int val){
    if(l == NULL){
        printf("List not initialized\n");
        return;
    }
    if(pos < 0){
        printf("Invalid position\n");
        return;
    }
    Node* newNode = createNode(val);
    // ✅ Case 1: Empty list
    if(l->head == NULL){
        if(pos != 0){
            printf("Index out of bounds\n");
            free(newNode);
            return;
        }
        l->head = newNode;
        return;
    }
    // ✅ Case 2: Insert at front
    if(pos == 0){
        pushFront(l,val);
        return;
    }

    // ✅ Case 3: Insert at middle or end
    Node* temp = l->head;
    int i = 0;

    while(i < pos - 1 && temp->next != l->head){
        temp = temp->next;
        i++;
    }
    if(i != pos - 1){
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int get(CLL* l, int index){
    if(l == NULL || l->head == NULL){
        printf("List is empty\n");
        return -1;
    }
    if(index < 0){
        printf("Invalid index\n");
        return -1;
    }
    Node* temp = l->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
        if(temp == l->head){
            printf("Index out of bounds\n");
            return -1;
        }
    }
    return temp->data;
}

void set(CLL* l, int index, int value){
    if(l == NULL || l->head == NULL){
        printf("List is empty\n");
        return;
    }
    if(index < 0){
        printf("Invalid index\n");
        return;
    }
    Node* temp = l->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
        if(temp == l->head){
            printf("Index out of bounds\n");
            return;
        }
    }
    temp->data = value;
}

void reverseCll(CLL* l){
  if(l==NULL || l->head == NULL){
    printf("List is empty\n");
    return;
  }
  Node* prev = NULL;
  Node* curr = l->head;
  Node* next = NULL;
  //Handling the first node
  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr=next;
  while (curr!=l->head)
  {
    next=curr->next;
    curr->next=prev;
    prev = curr;
    curr = next;
  }
  l->head=prev;
  curr->next = l->head;
}
int main(){
    
}
