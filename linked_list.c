#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if(*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    } else if(p == NULL){
        new_node->link = *phead;
        *phead = new_node;
    } else{
        new_node->link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
    if(p == NULL) *phead = (*phead)->link;
    else p->link = removed->link;
    free(removed);
}

void display(ListNode *head){
    ListNode *p = head;
    while(p!=NULL){
        printf("%d -> ",p->data);
        p = p->link;
    }
    printf("\n");
}

ListNode *search(ListNode *head, int x){
    ListNode *p = head;
    while(p != NULL){
        if(p->data == x) return p;
        else p = p->link;
    }
    return p;
}

ListNode *create(element data, ListNode *link){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node == NULL) error("error: unable to allocate memory \n");
    new_node->data = data;
    new_node->link = link;
    return new_node;
}

int main(void){
    ListNode *list1 = NULL;
    ListNode *p;
    int input;

    for(int i=0; i<10; i++){
        printf("insert: %d \n",i+1);
        insert_node(&list1,NULL,create(i+1,NULL));
    }
    display(list1);

    for(int i=0; i<5; i++){
        p = list1;
        printf("remove: %d \n",p->data);
        remove_node(&list1,NULL,list1);
    }
    display(list1);

    printf("input data to search: ");
    scanf("%d",&input);
    p = search(list1,input);
    if(p!=NULL){
        printf("found: %d \n",p->data);
    }else{
        printf("can not found! \n");
    }

    return 0;
}