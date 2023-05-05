typedef struct pessoa{
	char nome[50];
	int idade;
	char sexo;
}Pessoa;

typedef struct dado{
	Pessoa info;
	struct dado *proximo;
} Lista;

Pessoa Cria_Pessoa(){
	Pessoa pessoa;

	printf("\n      			Cadastrar Pessoa\n");
	
	fflush(stdin);
	printf("\n Digite o nome: ");
	fgets(pessoa.nome,50,stdin);
	printf("\n Digite a idade: ");
	scanf("%d", &pessoa.idade);
	do{
		fflush(stdin);
		printf("\n Digite o sexo M para Masculino e F para Feminino: ");
		scanf("%c", &pessoa.sexo);
	}while(pessoa.sexo != 'F' && pessoa.sexo != 'M');

	return pessoa;
}

int Menu(){
	system("cls");
	int opcao;

	printf("\n                          MENU\n");

	printf("\n  1 - Adicionar Pessoa\n");
	printf("\n  2 - Listar Pessoas idade maior que a primeira\n");
	printf("\n  3 - Listar Mulheres\n");
	printf("\n  4 - Listar Homens menores de 21 anos\n");
	printf("\n  5 - Excluir o ultimo registro\n");
	printf("\n  6 - Sair do programa\n");
	printf("\n  Digite sua opcao: ");
	scanf("%d", &opcao);

	return opcao;
}