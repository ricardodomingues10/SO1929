#include <stdio.h>
#include "typedefs.h"
#include "constantes.h"

pTopico_t adicionarTopico(char nome, pTopico_t lista)
{
    pTopico_t novo, aux;
    
    novo = malloc(sizeof(topico_t));
    if(novo == NULL){
        fprintf(stderr,"Erro ao reservar memoria\n");
        return lista;
    }
    
    printf("Indique o topico:\n");
    scanf(" %49[^\n]",novo->nome);

    novo->prox = NULL;
  
    
    if(lista == NULL){
        lista = novo;
    }
    else {
        aux = lista;
    }
    return lista;
}

void mostrarTopicos(pTopico_t lista){
    if(!lista){
        puts("Não existem topicos.\n");
        return;
    }
    
    puts("Lista de topicos:\n");
    while(lista != NULL){
        printf("\t- %s \n",lista->nome);
        lista = lista->topico;
    }
}

pTopico_t eliminarTopico(pTopico_t lista){
    pTopico_t aux,anterior=NULL;
    char nome[MAX_TEXTO];
    
    if(!lista){
        puts("Nao existem pacientes em espera.");
        return NULL;
    }
    printf("Indique o topico que quer eliminar:\n");
    if(scanf(" %49[^\n]",nome) != 1) {
        puts("Erro na introducao do topico.");
        return lista;
    }
    
    aux = lista;
    while(aux!=NULL && strcmp(aux->nome,nome)!=0){
        anterior = aux;
        aux=aux->prox;
    }
    if(aux==NULL){
        printf("O topico [%s] nao existe na lista de pacientes.\n",nome);
        return lista;
    }
    if(anterior==NULL){
        lista = aux->prox;
    }
    else{
        anterior->prox = aux->prox;
    }
    free(aux);
    
    return lista;
}