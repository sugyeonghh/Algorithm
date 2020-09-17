// 자료구조 과제 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

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

ListNode *search_node(ListNode *head, char *title){
    ListNode *p = head;
    while(p!=NULL){
        if(strcmp(p->title,title)==0) return p;
        else p = p->link;
    }
    return p;
}

ListNode *recently_search_node(ListNode *head){
    ListNode *p = head;
    ListNode *recent;
    recent->date = 0;
    while(p!=NULL){
        if(p->date > recent->date) recent = p;
        p = p->link;
    }
    return recent;
}

void remove_node(ListNode **phead, ListNode *removed){
    ListNode *p = *phead;
    ListNode *f;
    while(p!=NULL){
        if(strcmp(p->title,removed->title)==0){
            f = NULL;
            break;
        }else if(strcmp(p->link->title,removed->title)==0){
            f = p;
            break;
        }else {
            p = p->link;
        }
    }
    f = p;

    if(f == NULL) *phead = (*phead)->link;
    else f->link = removed->link;
    free(removed);
}

void display(ListNode *head){
    ListNode *p = head;
    for(int i=1; p!=NULL; i++){
        printf("%d) %s(%c,%d) \n",i,p->title,p->genre,p->date);
        p = p->link;
    }
    printf("\n\n");
}

void display_genre(ListNode *head, char genre){
    ListNode *p = head;
    int i=1;
    while(p!=NULL){
        if(p->genre==genre)
            printf("%d) %s(%c,%d) \n",i++,p->title,p->genre,p->date);
        p = p->link;
    }
    printf("\n\n");
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
    ListNode *removed;
    int select,menu;
    char movie[MAX_SIZE];
    char title[MAX_SIZE], genre;
    int date;

    insert_node(&list,NULL,create_node("Mammamia",'R',2018));
    insert_node(&list,NULL,create_node("Interstella",'S',2014));
    insert_node(&list,NULL,create_node("Mars",'S',2016));
    insert_node(&list,NULL,create_node("Inception",'A',2010));
    insert_node(&list,NULL,create_node("Harry Potter",'F',2001));

    while(1){
        printf("---------------- Options ---------------- \n");
        printf("1. Search movie \n2. Insert movie \n3. Remove movie \n4. Search recently released movie \n");
        printf("5. Display the genre of movie you want \n6. Display \n7. Print number of nodes \n");
        printf("\nselect(0 to quit): "); scanf("%d",&menu);
        if(menu==0) break;
        switch (menu){
        case 1:
            printf("> Search movie \n");
            printf("> enter the movie to search: "); scanf("%s",movie);
            p = search_node(list,movie);
            if(p!=NULL) printf("%s(%c,%d) \n\n",p->title,p->genre,p->date);
            else printf("can not found \n\n");
            break;
            
        case 2:
            printf("> Insert movie \n");
            printf("> enter the movie info \n");
            getchar();
            printf("> title: "); scanf("%[^\n]s",title); 
            getchar();
            printf("> genre: "); scanf("%c",&genre);
            getchar();
            printf("> release date: "); scanf("%d",&date);
            new_node = create_node(title,genre,date);
            getchar();
            printf("> enter the movie(insert in the next order of the entered movie): "); scanf("%[^\n]s",movie);
            p = search_node(list,movie);
            if(p==NULL) printf("error: can not found \n");
            else{
                insert_node(&list,p,new_node);
                printf("success \n");
            }
            printf("\n");
            break;

        case 3:
            printf("> Remove movie \n");
            printf("> enter the movie: "); scanf("%s",movie);
            removed = search_node(list,movie);
            if(removed==NULL) printf("error: can not found \n");
            else{
                remove_node(&list,removed);
                printf("success \n");
            }
            printf("\n");
            break;

        case 4:
            printf("> Search recently released movie \n");
            p = recently_search_node(list);
            printf("%s(%c,%d) \n\n",p->title,p->genre,p->date);
            break;

        case 5:
            printf("> Display the genre of movie you want \n");
            getchar();
            printf("> enter the genre: "); scanf("%c",&genre);
            display_genre(list,genre);
            break;
        
        case 6:
            printf("> Display \n");
            display(list);
            break;
        
        case 7:
            printf("> Print number of nodes \n");
            printf("> Length of list: %d \n\n",get_length(list));
            break;
        
        default:
            printf("error: wrong number \n");
            break;
        }
    }

    

}