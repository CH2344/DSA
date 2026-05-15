#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct StrStack
{
    char arr[MAX];
    int top;
}StrStack;
//StrStack
void initStrStack(StrStack* s){
    s->top = -1;
}
int isEmptyStrStack(StrStack* s){
    return (s->top == -1);
}
void pushStrStack(StrStack* s, char val){
    if(s->top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}
void popStrStack(StrStack* s){
    if(isEmptyStrStack(s)){
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}
char peekStrStack(StrStack* s){
    if(isEmptyStrStack(s)){
        return '\0';
    }
    return s->arr[s->top];
}
// Valid Parenthesis function
int isOpening(char c){
    return (c=='(' || c=='{' || c=='[');
}
int isCorrectPair(char c1, char c2){
    if( (c1=='(' && c2==')') ||
        (c1=='{' && c2=='}') ||
        (c1=='[' && c2==']') )
        return 1;
    return 0;
}
int validParanthesis(char* s){
    StrStack stack;
    initStrStack(&stack);  

    int n = strlen(s);
    for(int i = 0; i < n; i++){
        // If opening bracket → push
        if(isOpening(s[i])){
            pushStrStack(&stack, s[i]);   
        }
        else{
            // If stack empty → invalid (no opening bracket)
            if(isEmptyStrStack(&stack)){
                return 0;
            }

            // Check matching
            if(isCorrectPair(peekStrStack(&stack), s[i])){
                popStrStack(&stack);   // ✅ correct pop
            }
            else{
                return 0;
            }
        }
    }

    // If stack empty → valid
    return isEmptyStrStack(&stack);
}
//Stock span
/*
max no. of consecutive days from today price <= today's price
prevHigh = immediate greater value for any day
span[n];
span[0] = 1;
span[i] = i - prevHigh
*/
typedef struct Stack
{
    int top;
    int arr[MAX];
}Stack;

void initStack(Stack* s){
    s->top=-1;
}
int isEmpty(Stack* s){
    return s->top==-1;
}
int isFull(Stack* s){
    return s->top == MAX - 1;
}
void push(Stack* s,int val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}
void pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return;
    }
    s->top--;
}
int peek(Stack* s){
    if(isEmpty(s)){
        return -1;
    }
    return s->arr[s->top];
}
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}

