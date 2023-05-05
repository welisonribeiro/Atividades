typedef struct pessoa{
	char nome[50];
	int idade;
	char sexo;
}Pessoa;

typedef struct dado{
	Pessoa info;
	struct dado *proximo;
} Lista;