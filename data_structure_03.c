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
// P1(x) = 5x^4-3x^3-9x+18
// P2(x) = -10x^3+7x^2+5;
struct{
    float coef;    
    int expon;
} terms[MAX_TERMS] = {{4,7},{-3,4},{2,3},{-1,0},
                    {5,4},{-3,3},{-9,1},{18,0},
                    {-10,3},{7,2},{5,0} };
int avail = 11;


void print_poly(polynomial P){
    int degree = P.degree;
    for(int i=0; i<=degree; i++){
        if(P.coef[i]!=0){
            if(i==degree){
                if(P.coef[i]>0)
                    printf("+%1.f",P.coef[degree]);
                else
                    printf("%1.f",P.coef[degree]);
            } else{
                if(P.coef[i]<0 || i==0 ){
                    printf("%1.fx^%d",P.coef[i],degree-i);
                } else if(P.coef[i]>0){
                    printf("+%1.fx^%d",P.coef[i],degree-i);
                } else{
                    continue;
                }
            }
        }
    }
    return;
}

void print_terms(int Ps, int Pe){
    for(int i=Ps; i<=Pe; i++){
        if(terms[i].coef!=0){
            if(terms[i].expon==0){
                if(terms[i].coef>0) printf("%+1.f",terms[i].coef);
                else printf("%1.f",terms[i].coef);
            } else{
                if(terms[i].coef<0 || i==Ps){
                    printf("%1.fx^%d",terms[i].coef,terms[i].expon);
                } else if(terms[i].coef>0){
                    printf("+%1.fx^%d",terms[i].coef,terms[i].expon);
                } else{
                    continue;
                }
            }
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

polynomial sub_poly(polynomial A, polynomial B){
    polynomial C;
    int Apos=0, Bpos=0, Cpos=0;
    int A_degree = A.degree;
    int B_degree = B.degree;

    while(Apos<=A.degree && Bpos<=B.degree){
        if(A_degree>B_degree){
            C.coef[Cpos++] = A.coef[Apos++];
            A_degree--;
        }else if(A_degree<B_degree){
            C.coef[Cpos++] = (-1)*B.coef[Bpos++];
            B_degree--;
        }else{
            C.coef[Cpos++] = A.coef[Apos++]-B.coef[Bpos++];
            A_degree--;
            B_degree--;
        }
    }
    C.degree = A.degree>B.degree? A.degree:B.degree;
    return C;
}

void sub_terms(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
    float tempcoef;
    *Cs = avail;
    while(As<=Ae && Bs<=Be){
        if(terms[As].expon>terms[Bs].expon){
            terms[*Cs].coef = terms[As].coef;
            terms[*Cs].expon = terms[As].expon;
            *Cs += 1;
            As++;
        } else if(terms[As].expon<terms[Bs].expon){
            terms[*Cs].coef = (-1)*terms[Bs].coef;
            terms[*Cs].expon = terms[Bs].expon;
            *Cs += 1;
            Bs++;
        } else{
            if(terms[As].coef==terms[Bs].coef) break;
            terms[*Cs].coef = terms[As].coef-terms[Bs].coef;
            terms[*Cs].expon = terms[As].expon;
            *Cs += 1;
            As++; Bs++;
        }
    }
    *Ce = *Cs-1;
    *Cs = avail;
    return;
}


int main(void){
    // P(x) = 4x^7-3x^4+2x^3-1
    // P1(x) = 5x^4-3x^3-9x+18
    // P2(x) = -10x^3+7x^2+5;
    polynomial P = {7, {4,0,0,-3,2,0,0,-1}};
    polynomial P1 = {4, {5,-3,0,-9,18}};
    polynomial P2 = {3, {-10,7,0,5}};
    int x;
    int Cs,Ce;

    printf("(1) polynomial printing program \n");
    printf("> P(x) = "); print_poly(P); printf("(poly) \n");
    printf("> P(x) = "); print_terms(0,3); printf("(terms) \n");
    printf("\n");
    printf("(2) evaluate function \n");
    printf("enter the x: "); scanf("%d",&x);
    printf("> P(%d) = %d(poly) \n",x,eval_poly(P,x)); 
    printf("> P(%d) = %d(terms) \n",x,eval_terms(0,3,x));
    printf("\n");
    printf("(3) polynomial subtract \n"); 
    print_poly(P1); printf(" subtract "); print_poly(P2); printf("\n");
    printf("> "); print_poly(sub_poly(P1,P2)); printf("(poly) \n");
    printf("> "); sub_terms(4,7,8,10,&Cs,&Ce); print_terms(Cs,Ce); printf("(terms) \n");
 
    printf("\n");

}