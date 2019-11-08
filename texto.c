#include <stdio.h>
#include "typedefs.h"
#include "constantes.h"

pTexto_t adicionarTexto(char titulo, char artigo, int data_expiracao, int id, pTexto_t lista, pTopico_t topic)
{
    pTexto_t novo, aux;
    
    novo = malloc(sizeof(texto_t));
    if(novo == NULL){
        fprintf(stderr,"Erro ao reservar memoria\n");
        return lista;
    }
    
    printf("Indique o titulo:\n");
    scanf(" %49[^\n]",novo->titulo);
    printf("Indique o texto:\n");
    scanf(" %49[^\n]",novo->artigo);

    novo->prox = NULL;
  
    
    if(lista == NULL){
        lista = novo;
    }
    else {
        aux = lista;
    }
    return lista;
}

void mostrarTexto(pTexto_t lista){
    if(!lista){
        puts("Não existem textos.\n");
        return;
    }
    
    puts("Lista de textos:\n");
    while(lista != NULL){
        printf("\t- %s %s %d %d \n",lista->titulo,lista->artigo, lista->data_expiracao, lista->id);
        lista = lista->texto;
    }
}

pTopico_t eliminarTexto(pTopico_t lista){
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