#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    float info;
    struct no* prox;
}NoLista;

typedef struct fila{
    NoLista* ini;
    NoLista* fim;
}Fila;

Fila* criarFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    
    return f;
}

int estaVazia(Fila* f){
    return(f->ini == NULL);
}

void inserir(Fila* f, float v){
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    
    if(novo != NULL){
        novo->info = v;
        novo->prox = NULL;
        
        if(f->fim == NULL){ //posso usar f->ini tb
            f->ini = f->fim = novo;
        }
        else{
            f->fim->prox = novo;
            f->fim = novo;
        }
    }
    else{
        printf("Nao foi possivel alocar espaco!\n");
    }
}

void imprimeFila(Fila* f){
    NoLista* aux;
    
    if(!estaVazia(f)){ 
        for(aux = f->ini; aux != NULL; aux = aux->prox){
            printf("%.2f ", aux->info);
        }
        printf("\n");
    }
    else{
        printf("A fila esta vazia!\n");
    }
}

float remover(Fila *f){
    if(!estaVazia(f)){
        NoLista* aux = f->ini;
        float v = aux->info;
        f->ini = aux->prox;
        
        if(f->ini == NULL){
            f->fim = NULL;
        }
        
        free(aux);
        return v;
    }
    else{
        printf("Vazia!\n");
    }
}

void liberarFila(Fila *f){
    if(!estaVazia(f)){
        NoLista* aux, *temp;
        for(aux = f->ini; aux != NULL; aux = temp){
            temp = aux->prox;
            free(aux);
        }
        free(f);
        f = NULL;
    }
}

void furaFila(Fila* f, float v){
    NoLista* aux, *ant = NULL;

    if(!estaVazia(f)){
        for(aux = f->ini; aux != NULL && aux->info != v; aux = aux->prox){
            ant = aux;
        }
        
        if(p == NULL){
            printf("Elemento n encotrado!\n");
        }
        else{
            if(ant!= NULL){
                ant->prox = aux->prox;
                aux->prox = f->ini;
                f->ini = aux;
            }
        }
    }   
}


int main(int argc, char** argv){
    
    Fila* fila = criarFila();
    
    inserir(fila, 4);
    inserir(fila, 5);
    inserir(fila, 8);
    inserir(fila, 3);
    
    imprimeFila(fila);
    
    float prim = remover(fila);
    printf("%f\n", prim);
    imprimeFila(fila);

    return 0;
}
