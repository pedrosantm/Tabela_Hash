#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 7


typedef struct no{
    int val;
    struct no* prox;
}no;

int main(){

    no vet[TAM];
    inicializa_tabela(vet, TAM);

    for(int i=0; i<TAM; i++){
        int numero;
        printf("Digite o %d valor a ser inserido: \n", i+1);
        scanf("%d", &numero);
        adicionar_na_tabela(vet, numero, TAM);
    }

    imprime(vet, TAM);
    return 0;
}

void inicializa_tabela(no tab[], int t){
    for(int i=0; i<t; i++){
         tab[i].val = -1;
         tab[i].prox = NULL;
    }
    return;
}

void adicionar_na_tabela(no tab[], int numero, int t){
    int posicao;
    posicao = funcao_hash(numero);


    if(tab[posicao].val == -1){
        tab[posicao].val = numero;
    }else{
        no* novo = malloc(sizeof(no));
        novo->val = numero;
        novo->prox = NULL;

        no* atual = &tab[posicao];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return;
}

int funcao_hash(int x){
    int h;
    h = x%TAM;
    return h;
}

void imprime(no tab[], int t){
   for (int i = 0; i < t; i++) {
        printf("Indice %d: ", i);
        no* atual = &tab[i];
        while (atual != NULL && atual->val != -1) {
            printf("%d -> ", atual->val);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
    return;
}
