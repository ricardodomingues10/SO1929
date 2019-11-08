
CC=clang
#CC=gcc
CC_FLAGS=-Wall -g -std=c99
APP_VERIFICADOR=verificador
APP_GESTOR=gestor
APP_CLIENTE=cliente

all: gestor cliente verificador

gestor: gestor.c
	$(CC) -o $(APP_GESTOR) gestor.c $(CC_FLAGS)

cliente: cliente.c
	$(CC) -o $(APP_CLIENTE) cliente.c $(CC_FLAGS)

verificador: verificador.c
	$(CC) -o $(APP_VERIFICADOR) verificador.c $(CC_FLAGS)

clean:
	test -f $(APP_VERIFICADOR) && rm $(APP_VERIFICADOR)
	test -f $(APP_GESTOR) && rm $(APP_GESTOR)
	test -f $(APP_CLIENTE) && rm $(APP_CLIENTE)