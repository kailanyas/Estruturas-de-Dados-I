#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct pilha{
    float info[N];
    int n;
}Pilha;

Pilha* criarPilha(){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->n=0;
    return p;
}

int estaVazia(Pilha *p){
    return(p->n==0);
}

int estaCheia(Pilha *p){
    return(p->n==N);
}

void push(Pilha *p, float v){
    if(!estaCheia(p)){
        p->info[p->n] = v;
        p->n++;
    }
    else{
        printf("A pilha está cheia!");
        exit(1);
    }
}

void imprimePilha(Pilha *p){
    if(!estaVazia(p)){
        for(int i = p->n-1; i>=0; i--){
            printf("%.2f ", p->info[i]);
        }
        printf("\n");
    }
    else{
        printf("A pilha está vazia!");
    }
}

float pop(Pilha *p){
    if(!estaVazia(p)){
        float v = p->info[p->n-1];
        p->n--;
        return v;
    }
    else{
        printf("PIlha Vazia!");
        exit(1);
    }
}

void liberarPilha(Pilha *p){
    free(p);
}

int main(int argc, char** argv) {
    Pilha *pilha;
    pilha = criarPilha();
    push(pilha, 2.5);
    push(pilha, 3.5);
    imprimePilha(pilha);
    pop(pilha);
    imprimePilha(pilha);
    liberarPilha(pilha);
    imprimePilha(pilha);


        
    return (EXIT_SUCCESS);
}
