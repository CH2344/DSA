#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next; 
    struct Node* prev;
    //struct Node* a, b; Incorrect
    //struct Node *a, *b; Correct
}Node;

typedef struct{
    Node* head;
}DLL;

Node* createNode(int val){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = node->prev = NULL;
    node->data = val;
    return node;
}

void pushFront(DLL* l, int val){
    Node* newNode = createNode(val);
    if(l->head == NULL){
        l->head = newNode;
        return;
    }
    newNode->next = l->head;
    l->head->prev = newNode;
    l->head = newNode;
}

void pushBack(DLL* l, int val){
    Node* newNode = createNode(val);
    if(l->head == NULL){
        l->head = newNode;
        return;
    }
    Node* tail = l->head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

void popFront(DLL* l){
    if(l->head==NULL){
        printf("List empty\n");
        return;
    }

    Node* temp = l->head;
    l->head = l->head->next;
    if(l->head != NULL){   //No prev for NULL in case of single element 
        l->head->prev = NULL;
    }
    free(temp);
}

void popBack(DLL* l){
    if(l->head==NULL){
        printf("List empty\n");
        return;
    }
    if(l->head->next==NULL){ //Handle single element case 
        free(l->head);
        l->head->next = NULL;
        return;
    }
    Node* temp = l->head;
    while(temp->next!=NULL && temp->next->next!=NULL){ //Before accessing next of next check if it is not NULL
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = NULL;
    Node* temp1 = tail; //You can directly free tail instead
    tail->next = tail->prev = NULL;
    free(temp1);
}

void insertAt(DLL* l,int pos,int val){
    if(pos<0){
        printf("Invalid position\n");
        return; 
    }

    //Case 1: If insert at head means pos = 0
    if(pos==0){
        pushFront(l,val);
        return;
    }
    Node* temp = l->head;

    // ❌ ORIGINAL MISTAKE: If list is empty and pos > 0,
    // temp is NULL and temp->next would crash later
    if(temp == NULL){
        return;
        printf("Invalid position\n");
    }
    //if i=0 temp at 1 --> i=pos-2 temp at pos-1
    for(int i=0; i<pos-1; i++){
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    
    // ❌ ORIGINAL MISTAKE: No check after loop
    // temp could become NULL → temp->next would crash
    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    // ❌ ORIGINAL MISTAKE:
    // You wrote: if(newNode != NULL && newNode->next != NULL)
    // newNode is ALWAYS non-NULL → redundant check
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp; 
    if(newNode->next!=NULL){
       newNode->next->prev = newNode;
    }
    /*
    Whenever you write insertion in DLL, always think:
    Head case
    Invalid position
    Pointer safety (NULL checks)
    4 pointer updates
    */
}

void deleteAt(DLL* l,int pos){
    if(l->head==NULL){
        printf("Empty list\n");
    }
    if(pos<0){
        printf("Invalid position\n");
        return; 
    }

    // ✅ FIX: Handle deletion at head (pos == 0)
    // ❌ ORIGINAL MISTAKE: You did not handle pos == 0 separately
    if(pos==0){
        popFront(l);
        return;
    }
    Node* temp = l->head;
    //if i=0 temp at 1 --> i=pos-2 temp at pos-1
    for(int i=0; i<pos-1; i++){
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Invalid position\n");
        return;
    }
    Node* temp2 = temp->next; //Getting the node at given position
    temp->next = temp->next->next;

    // ✅ FIX: update backward link 
    // temp <-> temp2 <-> nextNode
    if(temp2->next != NULL){
        temp2->next->prev = temp;
    }

    temp2->prev = temp2->next = NULL;
    free(temp2);
}

void reverseDLL(DLL* l){
    if(l->head==NULL){
        printf("Empty list");
        return;
    }
    Node* prev = NULL;
    Node* curr = l->head;
    Node* next = NULL;
    Node* tail;
    while(curr!=NULL){
        next = curr->next;
        if(next==NULL){
            tail = curr; //You wrote tail = next earlier
        }
        curr->next = prev;
        prev = curr; 
        curr = next;
        // You wrote: curr = curr->next; curr = next already does the task.
    }
    prev = NULL;
    curr = tail;
    l->head = curr;
    next = NULL;
    while(curr!=NULL){
        next = curr->prev;
        curr->prev = prev;
        curr = next;
    }
}

void reverseDLLTwo(DLL* l){
    if(l==NULL || l->head==NULL){
        printf("Empty list\n");
        return;
    }
    Node* prev = NULL;
    Node* curr = l->head;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr; 
        curr = next;
        // You wrote: curr = curr->next; curr = next already does the task.
    }
    l->head = prev;
}

void printDLL(DLL* l){
    if(l==NULL || l->head==NULL){
        printf("List is empty");
        return;
    }
    Node* temp = l->head;
    Node* head2 = NULL;
    printf("From front: ");
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        if(temp->next==NULL){
            head2 = temp;
        }
        temp = temp->next;
    }
    printf("NULL\n");
    printf("From back: ");
    temp = head2;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int get(DLL* l, int index){
    // ❌ Mistake to avoid: not checking NULL → may cause crash
    if(l == NULL || l->head == NULL){
        printf("List is empty\n");
        return -1; // return error value
    }

    Node* temp = l->head;
    int i = 0;

    // Traverse till desired index
    while(temp != NULL && i < index){
        temp = temp->next;
        i++;
    }

    // ❌ Mistake to avoid: index out of bounds not handled
    if(temp == NULL){
        printf("Index out of bounds\n");
        return -1;
    }

    return temp->data;  // return value at index
}

void set(DLL* l, int index, int value){
    // ❌ Mistake to avoid: not checking NULL
    if(l == NULL || l->head == NULL){
        printf("List is empty\n");
        return;
    }

    Node* temp = l->head;
    int i = 0;

    // Traverse till desired index
    while(temp != NULL && i < index){
        temp = temp->next;
        i++;
    }

    // ❌ Mistake to avoid: not checking index validity
    if(temp == NULL){
        printf("Index out of bounds\n");
        return;
    }

    // Update value
    temp->data = value;
}

typedef struct CNode
{
    int data;
    struct CNode* next;
    struct CNode* prev;
    struct CNode* child;
}CNode;

CNode* flatten(CNode* head){ //TC: O(n) if there are n nodes
    if(head==NULL){
        return head;
    }
    CNode* curr = head;
    while (curr!=NULL)
    {
        if(curr->child!=NULL){
            CNode* next = curr->next;
            //Flatten the child node
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            //Find the tail
            while (curr->next!=NULL)    
            {
                curr = curr->next;
            }
            
            //Attach tail to next ptr
            if(next!=NULL){
                curr->next = next;
                next->prev = curr;
            } 
        }
        curr=curr->next;
    }
    return head;
}
int main(){
    return 0;
}
