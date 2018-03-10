#include <string.h>
#include <stdio.h>
#define TAM_ANO 4

int main() {
	char ano[TAM_ANO + 1];
	memset(ano, '\0', TAM_ANO + 1);
	printf("Qual ano nascimento(4 digitos):");
	scanf("%s", ano);
	printf("ano=%s, com tamanho=%d\n", ano, strlen(ano));
	return 0;
}