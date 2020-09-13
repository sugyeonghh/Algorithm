// 자료구조 과제 3
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_DEGREE 100
#define MAX_TERMS 100

typedef struct{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// P(x) = 4x^7-3x^4+2x^3-1
struct{
    float coef;    
    int expon;
} terms[MAX_TERMS] = {{4,7},{-3,4},{2,3},{-1,0}};


void print_poly(polynomial P){
    int degree = P.degree;
    for(int i=0; i<degree; i++){
        if(P.coef[i]!=0){
            if(P.coef[i]<0 || i==0){
                printf("%1.fx^%d",P.coef[i],degree-i);
            } else if(P.coef[i]>0){
                printf("+%1.fx^%d",P.coef[i],degree-i);
            } else{
                continue;
            }
        }
    }
    printf("%1.f",P.coef[degree]);
    return;
}

void print_terms(){
    for(int i=0; terms[i].coef; i++){
        if(terms[i].coef<0 || i==0){
            if(terms[i].expon==0) printf("%1.f",terms[i].coef);
            else printf("%1.fx^%d",terms[i].coef,terms[i].expon);
        } else if(terms[i].coef>0 && i!=0){
            printf("+%1.fx^%d",terms[i].coef,terms[i].expon);
        } else{
            continue;
        }
    }
    return;
}

int eval_poly(polynomial P, int x){
    int result = 0;
    int degree = P.degree;
    for(int i=0; i<=degree; i++){
        if(P.coef[i]!=0){
            result += P.coef[i]*pow(x,degree-i);
        }
    }
    return result;
}

int eval_terms(int Ps, int Pe, int x){
    int result = 0;
    for(int i=Ps; i<=Pe; i++){
        if(terms[i].coef!=0)
            result += terms[i].coef*pow(x,terms[i].expon);
    }
    return result;
}

int main(void){
    // P(x) = 4x^7-3x^4+2x^3-1
    polynomial P = {7, {4,0,0,-3,2,0,0,-1}};
    int x;

    printf("(1) polynomial printing program \n");
    printf("> P(x) = "); print_poly(P); printf("(poly)");  printf("\n");
    printf("> P(x) = "); print_terms(); printf("(terms)"); printf("\n");
    printf("\n");
    printf("(2) evaluate function \n");
    printf("enter the x: "); scanf("%d",&x);
    printf("> P(%d) = %d(poly) \n",x,eval_poly(P,x)); 
    printf("> P(%d) = %d(terms) \n",x,eval_terms(0,3,x));
}