#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct fila{
    float info[N];
    int n;
    int inicio;
}Fila;

Fila* criarFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    f->inicio;
    return f;
}

int estaVazia(Fila* f){
    return(f->n == 0);
}

int estaCheia(Fila* f){
    return(f->n == N);
}

void inserir(Fila* f, float v){
    if(!estaVazia(f)){
        int fim = (f->inicio + f->n) % N;
        f->info[fim] = v;
        f->n++;
    }
    else{
        printf("Fila cheia!\n");
    }
}

void imprime(Fila* f){
    if(!estaVazia(f)){
        int t = f->inicio;
        
        for(int i = 0; i < f->n; i++){
            printf("%f", f->info[t]);
            t = (t+1) % N;
        }
    }
    else{
        printf("Fila Vazia!\n");
    }
}

float remover(Fila* f){
    if(!estaVazia(f)){
        float v = f->info[f->inicio];
        f->inicio = (f->inicio + 1) % N;
        f->n--;
        return v;
    }
    else{
        printf("Fila Vazia!\n");
    }
}

void liberarFila(Fila* f){
    free(f);
}

int main(int argc, char** argv) {
    Fila* fila = criarFila();
    
    return 0;
}
