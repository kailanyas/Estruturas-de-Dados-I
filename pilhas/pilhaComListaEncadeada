#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
    float info;
    struct noLista *prox;
}NoLista;

typedef struct pilha{
    NoLista* prim;
}Pilha;

Pilha* criarPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int estaVazia(Pilha* p){
    return(p->prim == NULL);
}

void push(Pilha* p, float v){
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if(novo != NULL){
        novo->info = v;
        novo->prox = p->prim;
        p->prim = novo;
    }
    else{
        printf("Não foi possível alocar espaço!");
    }
}

void imprimePilha(Pilha *p){
    NoLista *l;
    if(!estaVazia(p)){
        for(l = p->prim; l != NULL; l = l->prox){
            printf("%2.f", l->info);
        }
    }
    else{
        printf("A pilha está vazia!");
    }
}

float pop(Pilha *p){
    if(!estaVazia(p)){
        NoLista* aux = p->prim;
        p->prim = aux->prox;
        float v = aux->info;
        free(aux);
        return v;
    }
    else{
        printf("Está Vazia!");
    }
}

void liberarPilha(Pilha *p){
    NoLista *aux, *temp;
    for(aux=p->prim; aux!=NULL; aux=temp){
        temp= aux->prox;
        free(aux);
    }
    free(p);
    p=NULL;
}

int main(int argc, char** argv) {
    Pilha *pilha = criarPilha();
    printf("%d\n", estaVazia(pilha));
    push(pilha, 1);
    push(pilha, 2);
    imprimePilha(pilha);
    return (EXIT_SUCCESS);
}
