// 자료구조 과제 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

int sum_iterative(int num){
    int sum = 0;
    for(int i=1; i<=num; i++){
        sum += i;
    }
    return sum;
}

int sum_recursive(int num){
    if(!num) return 0;
    return num+sum_recursive(num-1);
}

int len_iterative(char *string){
    int len=0;
    while(1){
        if(string[len]=='\0') break;
        else len++;
    }
    return len;
}

int len_recursive(char *string, int idx){
    if(string[idx]=='\0') return 0;
    return 1+len_recursive(string,idx+1);
}

void reverse_iterative(char *string){
    for(int i=0; i<strlen(string); i++){
        printf("%c",string[strlen(string)-1-i]);
    }
    return;
}

void reverse_recursive(char *string, int idx){
    if(idx==strlen(string)) return;
    reverse_recursive(string,idx+1);
    printf("%c",string[idx]);
}

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void preorder(TreeNode *root){
    if(root){
        printf("%d -> ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        printf("%d -> ",root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ",root->data);
    }
}

void search(TreeNode *root, int num){
    if(root==NULL){
        printf("cannot found! \n");
        return;
    }
    printf("%d -> ",root->data);
    if(root->data == num){
        printf("found! \n");
        return;
    } else if(num < root->data){
        search(root->left,num);
    } else{
        search(root->right,num);
    }
}

int main(void){
    int select;
    int num;
    char string[MAX_SIZE];
    TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    TreeNode *p;

    /*
            18
            / \
           7   26
          /  \   \
         3   12   31 
                   \
                    37
    */
    n1 = (TreeNode*)malloc(sizeof(TreeNode)); n1->data = 18;
    n2 = (TreeNode*)malloc(sizeof(TreeNode)); n2->data = 7;
    n3 = (TreeNode*)malloc(sizeof(TreeNode)); n3->data = 26;
    n4 = (TreeNode*)malloc(sizeof(TreeNode)); n4->data = 3;
    n5 = (TreeNode*)malloc(sizeof(TreeNode)); n5->data = 12;
    n6 = (TreeNode*)malloc(sizeof(TreeNode)); n6->data = 31;
    n7 = (TreeNode*)malloc(sizeof(TreeNode)); n7->data = 37;

    n1->left = n2;   n1->right = n3;
    n2->left = n4;   n2->right = n5;
    n3->left = NULL; n3->right = n6;
    n4->left = NULL; n4->right = NULL;
    n5->left = NULL; n5->right = NULL;
    n6->left = NULL; n6->right = n7;
    n7->left = NULL; n7->right = NULL;
    

    while(1){
        printf("---------------- functions ---------------- \n");
        printf("1. 1부터 num까지 합을 구하는 반복/순환함수 \n2. 문자열의 길이를 구하는 반복/순환함수 \n3. 문자열 역순 출력 반복/순환함수 \n4. 이진탐색함수(순환), 특정값을 탐색하는 과정을 보여주는 함수 \n\n");
        printf("enter the number that you want(0 to quit): ");
        scanf("%d",&select);
        getchar(); // 입력버퍼 비우기
        printf("\n");
        if(!select) break;
        switch (select){
        case 1:
            printf("1부터 num까지 합을 구하는 반복/순환함수 \n");
            printf("enter the num: "); scanf("%d",&num);
            printf("> iterative function: %d \n",sum_iterative(num));
            printf("> recurvive function: %d \n",sum_recursive(num));
            printf("\n");
            break;
        case 2:
            printf("문자열의 길이를 구하는 반복/순환함수 \n");
            printf("enter the string: "); scanf("%[^\n]s",string);
            printf("> iterative function: %d \n",len_iterative(string));
            printf("> recurvive function: %d \n",len_recursive(string,0));
            printf("\n");
            break;
        case 3:
            printf("문자열 역순 출력 반복/순환함수 \n");
            printf("enter the string: "); scanf("%[^\n]s",string);
            printf("> iterative function: "); reverse_iterative(string);   printf("\n");
            printf("> recurvive function: "); reverse_recursive(string,0); printf("\n");
            printf("\n");
            break;
        case 4:
            printf("이진탐색함수(순환), 특정값을 탐색하는 과정을 보여주는 함수 \n");
            printf("> preorder: ");  preorder(n1);  printf("\n");
            printf("> inorder: ");   inorder(n1);   printf("\n");
            printf("> postorder: "); postorder(n1); printf("\n");
            printf("\n");
            
            printf("enter the number to search: "); scanf("%d",&num);
            search(n1,num);
            printf("\n");
            break;
        default:
            printf("wrong number, retry \n");
            break;
        }
    }
}