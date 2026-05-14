#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    Node* next;
    Node* random;
    int data;
}Node;

typedef struct{ //Key value pair, map will be array of key-value pairs
    Node* key;
    Node* value;
}Pair;

Node* createNode(int val){ //Dynamically creating node: In C++ Node* node = new Node(val);
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = node->random = NULL;
    node->data = val;
    return node; 
}
int sizeOfLL(Node* head){ //For calculating size of linked list
    Node* temp = head;
    int size=0;
    while(temp!=NULL){
        temp = temp->next;
        size++;
    }
    return size;
}
Node* val(Pair* pairs,Node* key,int size){ //m[key] = val; in C++
    for (int i = 0; i < size; i++)
    {
        if(pairs[i].key == key){
            return pairs[i].value;
        }
    }
    return NULL;
}
Node* copyList(Node* head){
    if(head==NULL){
        return head;
    }
    int size = sizeOfLL(head);
    Pair* keyVals = (Pair*) malloc(size*sizeof(Pair)); //unordered_map<Node*,Node*> m; in C++
    Node* newHead = createNode(head->data); //Node* newHead = new Node(head->val)
    int i=0;
    keyVals[i].key = head;
    keyVals[i].value = newHead; //m[head] = newHead
    i++;
    Node* oldTemp = head->next; 
    Node* newTemp = newHead;
    while(oldTemp != NULL){
        Node* copyNode = createNode(oldTemp->data);
        keyVals[i].key = oldTemp; 
        keyVals[i].value = copyNode; 
        i++;
        newTemp->next = copyNode;
        newTemp = newTemp->next;
        oldTemp = oldTemp->next;
    }
    oldTemp = head;
    newTemp = newHead;
    while (oldTemp!=NULL)
    {
        newTemp->random = val(keyVals,oldTemp->random,size);
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
    return newHead;
}
int main()
{
    
    return 0;
}