#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_PESSOA 50

typedef unsigned short int idade;
typedef double salario;
enum sexo { M, F };

struct pessoa {
	char m_nome[TAM_PESSOA + 1];
	idade m_idade;
	enum sexo m_sexo;
	salario m_salario;
};


int inicializa_pessoa(struct pessoa *p, char * p_nome, idade p_idade, enum sexo p_sexo, salario p_salario) {

	if (p == NULL) {
		return -1;
	}

	if (p_nome == NULL) {
		return -2;
	}


	strcpy(p->m_nome, p_nome);
	p->m_idade = p_idade;
	p->m_sexo = p_sexo;
	p->m_salario = p_salario;

	return 1;
}

int imprime_pessoa(const struct pessoa *p) {

	if (p == NULL) {
		return -1;
	}

	printf("nome = %s, idade = %d, sexo = %s,  salario = %lf\n"
		, p->m_nome
		, p->m_idade
		, (p->m_sexo == M ? "masculino" : "feminino")
		, p->m_salario);

	return 1;
}

int copia_pessoa(struct pessoa *p1, const struct pessoa *p2) {

	if (p1 == NULL) {
		return -3;
	}
	if (p2 == NULL) {
		return -4;
	}
	strcpy(p1->m_nome,p2->m_nome);
	p1->m_idade = p2->m_idade;
	p1->m_sexo = p2->m_sexo;
	p1->m_salario = p2->m_salario;
	return 1;
}

void teste0() {
	struct pessoa grupo;
	int rc = 1;

	rc = inicializa_pessoa(&grupo, "joao da silva", 34, M, 5678.12);

	if (rc != 1) {
		printf("ERRO 'inicializa_pessoa' %d\n", rc);
	}

	rc = imprime_pessoa(&grupo);

	if (rc != 1) {
		printf("ERRO 'imprime_pessoa' %d\n", rc);
	}
}

void test1() {
	struct pessoa grupo[2];
	int rc = 1;

	rc = inicializa_pessoa(&grupo[0], "joao da silva", 34, M, 5678.12);

	if (rc != 1) {
		printf("ERRO 'inicializa_pessoa' %d\n", rc);
	}

	rc = imprime_pessoa(&grupo[0]);

	if (rc != 1) {
		printf("ERRO 'imprime_pessoa' 0 %d\n", rc);
	}

	rc = copia_pessoa(&grupo[1],&grupo[0]);
	if (rc != 1) {
		printf("ERRO 'copia pessoa' %d\n", rc);
	}

	rc = imprime_pessoa(&grupo[1]);

	if (rc != 1) {
		printf("ERRO 'imprime_pessoa' 1 %d\n", rc);
	}
}

int main() {
	test1();
	return 1;
}





//
	//struct pessoa grupo[2];
	//char nome[TAM_PESSOA];
	//idade idade;
	//enum sexo sexo;
	//salario salario;
	//int l;// resultado de procura por pessoa
	//char nome1[TAM_PESSOA][2];
	//int i; // contador

	//for (i = 0; i <= 2; i++) {
	//	assimila_pessoa(&grupo[i],&i);

	//}
	//
	//printf("Informe o nome de quem vc gostaria de localizar");
	//scanf("%s", &nome);

	//for (i = 0; i <= 2; i++) {
	//	nome1[TAM_PESSOA][i] == grupo[i].m_nome;
	//}
	//l = localiza_pessoa(&nome1[TAM_PESSOA][2], &nome);
	//printf("Os dados completos da pessoa procurada são:");
	//imprime_pessoa(&grupo[l]);


//int localiza_pessoa(char *nome1[TAM_PESSOA][2], char *procurado[TAM_PESSOA]) {
//	int i;
//	for (i = 0; i <= 2; i++) {
//		if (nome1[TAM_PESSOA][i] == procurado[TAM_PESSOA])
//		{
//			return i;
//		}
//	}
//
//}
//void assimila_pessoa(struct pessoa *p, int *i) {
//	printf("insira o nome da pessoa.%d",i);
//	scanf("%s", &p->m_nome);
//	printf("insira a idade da pessoa.%d", i);
//	scanf("%d", &p->m_idade);
//	printf("insira o sexo da da pessoa.%d, responda com M ou F.f\n", i);
//	scanf("%s", &p->m_sexo);
//	printf("insira o salario da pessoa.%d",i);
//	scanf("%l", &p->m_salario);
//}



/*
void inicializa_pessoa(struct pessoa *p, char p_nome, idade p_idade, enum sexo p_sexo, salario p_salario) {
strcpy(p->m_nome, p_nome);
p->m_idade = p_idade;
p->m_sexo = p_sexo;
p->m_salario = p_salario;
}
inicializa_pessoa(&grupo[0], nome, idade, sexo, salario);

printf("insira o nome da segunda pessoa.");
scanf("%s", &nome);
printf("insira a idade da segunda pessoa.");
scanf("%d", &idade);
printf("insira o sexo da segunda pessoa, responda com M ou F.");
scanf("%s", &sexo);
printf("insira o salario da segunda pessoa.");
scanf("%l", &salario);

inicializa_pessoa(&grupo[1], nome, idade, sexo, salario);

printf("insira o nome da terceira pessoa.");
scanf("%s", &nome);
printf("insira a idade da terceira pessoa.");
scanf("%d", &idade);
printf("insira o sexo da terceira pessoa, responda com M ou F.");
scanf("%s", &sexo);
printf("insira o salario da terceira pessoa.");
scanf("%l", &salario);

inicializa_pessoa(&grupo[2], nome, idade, sexo, salario);

printf("Os dados da pessoa 1 são:");
imprime_pessoa(&grupo[0]);
printf("Os dados da pessoa 2  são:");
imprime_pessoa(&grupo[1]);
printf("Os dados da pessoa 3  são:");
imprime_pessoa(&grupo[2]);
*/
