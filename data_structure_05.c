// 자료구조 과제 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char *title;
    char genre;
    int date;
    struct ListNode *link;
} ListNode;

ListNode *create_node(char *title, char genre, int date){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node == NULL){
        printf("error: unable to allocate memory \n");
        exit(1);
    }
    new_node->title = title;
    new_node->genre = genre;
    new_node->date = date;
    new_node->link = NULL;
    return new_node;
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

void display(ListNode *head){
    ListNode *p = head;
    while(p!=NULL){
        printf("%s(%c,%d) -> ",p->title,p->genre,p->date);
        p = p->link;
    }
    printf("\n");
}

int get_length(ListNode *head){
    ListNode *p = head;
    int length = 0;
    while(p!=NULL){
        length++;
        p = p->link;
    }
    return length;
}

int main(void){
    ListNode *list = NULL;
    ListNode *p;
    ListNode *new_node;
    int select;

    typedef struct{
        char *title;
        char genre;
        int date;
    }Movie;
    
    Movie movie[] = {
        "Mammamia",'R',2018,
        "Interstella",'S',2014,
        "Mars",'S',2016,
        "Inception",'A',2010,
        "Harry Potter",'F',2001
    };


    printf("Insert: \n");
    printf("1. in ascending order of title \n2. at front \n3. at last \n");
    printf("select(0 to quit): "); scanf("%d",&select);
    printf("\n");
    switch (select){
    case 1:
        printf("> Insert in ascending order of title \n");
        for(int i=0; i<5; i++){
            p = list;
            new_node = create_node(movie[i].title,movie[i].genre,movie[i].date);
            if(p==NULL) insert_node(&list,p,new_node);
            else{
                while(p!=NULL){
                    if(strcmp(new_node->title,p->title)>0 && p->link!=NULL){
                        p = p->link;
                    }else if(strcmp(new_node->title,p->title)<0 && p==list){
                        insert_node(&list,NULL,new_node);
                        break;
                    }else{
                        insert_node(&list,p,new_node);
                        break;
                    }
                }
            }
        }
        break;

    case 2:
        printf("> Insert at front \n");
        for(int i=0; i<5; i++)
            insert_node(&list,NULL,create_node(movie[i].title,movie[i].genre,movie[i].date));
        break;

    case 3:
        printf("> Insert at last \n");
        for(int i=0; i<5; i++){
            new_node = create_node(movie[i].title,movie[i].genre,movie[i].date);
            insert_node(&list,p,new_node);
            p = new_node;
        }
        break;

    default:
        printf("error: wrong number \n");
        printf("\n");
        break;
    }
    
    display(list);
    printf("\n");
    printf("> Length of list: %d \n",get_length(list));
}