#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <time.h>
#include "constantes.h"

typedef struct texto texto_t, *pTexto_t;
typedef struct topico topico_t, *pTopico_t;

typedef struct no_texto no_texto_t, *pNo_texto_t;
typedef struct no_topico no_topico_t, *pNo_topico_t;


struct texto
{
    char titulo[MAX_TEXTO];
    char artigo[MAX_TEXTO_ARTIGO];

    time_t data_expiracao;
    unsigned int id;

    pTopico_t topico;
};

struct topico
{
    char nome[MAX_TEXTO];

    pNo_texto_t textos;
};

struct no_texto
{
    pTexto_t texto;
    pNo_texto_t next;
};

struct no_topico {
    pTopico_t topico;
    pNo_topico_t next;
};

#endif