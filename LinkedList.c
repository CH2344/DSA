#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int data;
    Node* next;
}Node;

typedef struct 
{
    Node* head;
}LinkedList;

Node* createNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed");
        return;
    }
    newNode->data = val;
    return newNode;
}

void makeList(LinkedList* l){
    l->head = NULL;
}

void pushFront(LinkedList* l,int val){
    Node* newNode = createNode(val);
    if(l->head==NULL){
        l->head = newNode;
        return;
    }
    newNode->next = l->head;
    l->head = newNode;
}

void pushBack(LinkedList* l, int val){
    if(l->head == NULL){
        l->head = createNode(val);
        return;
    }
    Node* temp = l->head;
    Node* newNode = createNode(val);
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void popFront(LinkedList* l){
    if(l->head==NULL){
        printf("Empty Linked List");
        return;
    }
    Node* temp = l->head;
    l->head = l->head->next;
    free(temp);
}

void popBack(LinkedList* l){
    if(l->head==NULL){
        printf("List is empty");
        return;
    }
    Node* temp = l->head;
    //Go to second last
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    //Acces the last to delete it
    Node* temp2 = temp->next;
    //Make last second's next NULL
    temp->next = NULL;
    free(temp2);

}

void insert(LinkedList* l,int pos,int val){
    if(pos<0){
        printf("Invalid position.\n");
        return;
    }
    if(pos==0){
        pushFront(l,val);
        return;
    }
    Node* temp = l->head;
    Node* newNode = createNode(val);
    //At i=0 temp will be at 1 --> 
    for (int i = 0; i < pos-1; i++)
    {
        if(temp==NULL){
            printf("Invalid position");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}

int search(LinkedList* l, int target){
    Node* temp = l->head;
    int i = 0;
    while (temp!=NULL && temp->data!=target)
    {
        temp = temp->next;
        i++;
    }
    if(temp==NULL){
        return -1;
    }
    else{
        return i;
    }
}

void revLL(LinkedList* l){
    Node* prev = NULL;
    Node* curr = l->head;
    Node* next = NULL;
    while (curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

Node* detectCycle(LinkedList* l){
    Node* slow = l->head;
    Node* fast = l->head;
    //If fast at NULL then even sized if next is NUll then odd sized
    while (fast!=NULL && fast->next!=NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return fast;
        }
    }
    return NULL;
}

void removeCycle(LinkedList* l){
    Node* fast = detectCycle(l);
    if(fast==NULL){return;} //Means no cycle
    Node* slow = l->head;
    Node* prev = NULL;
    while (slow!=fast)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = NULL;
}

Node* rmergeTwoLists(Node* h1,Node* h2){ //See the recursion tree in notes
    if(h1 == NULL || h2 == NULL){
        return (h1==NULL)?h2:h1;
    }
    if(h1->data<=h2->data){
        h1->next = rmergeTwoLists(h1->next,h2);
        return h1;
    }
    else{
        h2->next = rmergeTwoLists(h1,h2->next);
        return h2;
    }
}

Node* mergeTwolist(LinkedList* l1,LinkedList* l2){
    Node* h1 = l1->head;
    Node* h2 = l2->head;
    if(!h1){return h2;}
    if(!h2){return h1;}
    Node* tail;
    Node* head;
    if(h1->data <= h2->data){
        head = tail = h1;
        h1 = h1->next;
    }
    else{
        head = tail = h2;
        h2 = h2->next;
    }
    while (h1!=NULL && h2!=NULL)
    {
        if(h1->data <= h2->data){
            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        }
        else{
            tail->next = h2;
            tail=tail->next;
            h2 = h2->next;
        }
    }
    tail->next = (h1)?h1:h2;
    return head;
}

void printLinkedList(LinkedList* l){
    Node* temp = l->head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
