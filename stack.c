#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);    
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr,"error: stack is full! \n");
        exit(1);
    }else{
        s->stack[++(s->top)] = item;
        return;
    }
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"error: stack is empty! \n");
        exit(1);
    }else{
        return s->stack[(s->top)--];
    }
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"error: stack is empty! \n");
        exit(1);
    }else{
        return s->stack[s->top];
    }
}

int main(void){
    StackType s;

    init(&s);
    for(int i=0; i<5; i++){
        printf("push: %d \n", i+1);
        push(&s,i+1);
    }
    
    for(int i=0; i<6; i++){
        printf("pop: %d \n", pop(&s));
    }
    
    return 0;
}