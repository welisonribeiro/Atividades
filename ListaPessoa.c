#include <stdio.h>


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

int main(int argc, char const *argv[])
{
	int menu;
	Pessoa pessoa;
	Lista *li = NULL;
	Lista *no, *aux, *ultimo,*penultimo;

	do{
		system("cls");

		menu = Menu();

		switch(menu){
			case 1:
				pessoa = Cria_Pessoa();

				no = malloc (sizeof (Lista));

				if (!no)
				{
					printf("\n Nao ha espaco na memoria!! \n");
				}else{

					no->info = pessoa;
					no->proximo = li;
					li = no;
					printf("\n Registro realizado com sucesso!! \n");
				}
				break;
			case 2:
				system("cls");
				aux = malloc (sizeof (Lista));

				aux ? aux = li : printf("\nMemoria nao alocada!!\n");

				if (!aux)
				{
					printf("\n                       Lista Vazia !!\n");
				}else{

					int idadePrimeiraPessoa = aux->info.idade;
					int cont = 1;

					printf("\n      Lista Pessoas cuja idade seja maior que a primeira       \n");
					printf("\n(%d)",cont);
					printf("\n nome: %s", aux->info.nome);
					printf("\n idade: %d", aux->info.idade);
					aux->info.sexo == 'M'? printf("\n sexo: Masculino") : printf("\n sexo: Feminino");
					cont++;
					while(aux){
						if(aux->info.idade > idadePrimeiraPessoa){
							printf("\n(%d)\n",cont);
							printf("\n nome: %s", aux->info.nome);
							printf("\n idade: %d", aux->info.idade);
							aux->info.sexo == 'M'? printf("\n sexo: Masculino") : printf("\n sexo: Feminino");

							cont++;
						}

						aux = aux->proximo;
					}
					printf("\n                          Fim da Lista                         \n");
				}
				system("pause");
				system("cls");

				break;
			case 3:
				system("cls");

				aux = malloc (sizeof (Lista));

				aux ? aux = li : printf("\nMemoria nao alocada!!\n");

				if (!aux)
				{
					printf("\n                       Lista Vazia !!\n");
				}else{

					int cont = 0;

					printf("\n                       Lista sexo Feminino\n");
					while(aux){
						cont++;
						if(aux->info.sexo == 'F'){
							printf("\n(%d)\n",cont);
							printf("\n nome: %s", aux->info.nome);
							printf("\n idade: %d\n\n", aux->info.idade);
						}

						aux = aux->proximo;
					}
					printf("\n                          Fim da Lista\n");
				}
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");

				aux = malloc (sizeof (Lista));

				aux ? aux = li : printf("\nMemoria nao alocada!!\n");

				if (!aux)
				{
					printf("\n                       Lista Vazia !!\n");
				}else{

					int cont = 0;

					printf("\n                       Lista homens menores de 21 anos\n");
					while(aux){
						cont++;
						if(aux->info.idade < 21 && aux->info.sexo == 'M'){
							printf("\n(%d)",cont);
							printf("\n nome: %s", aux->info.nome);
							printf("\n idade: %d\n\n", aux->info.idade);
						}

						aux = aux->proximo;
					}
					printf("\n                          Fim da Lista\n");
				}
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");

				if (!li)
				{

					printf("\n                       Lista Vazia !!\n");
					system("pause");
					system("cls");
				}else{

					ultimo;
					penultimo = li;

					if (penultimo->proximo)
					{
						ultimo = li->proximo;
						while(ultimo->proximo != NULL){
							penultimo = ultimo;
							ultimo = ultimo->proximo;
						}

						penultimo->proximo = NULL;
						free(ultimo);

					}else{
						li = NULL;
					}

					printf("\n         O ultimo registro foi excluido com sucesso!!\n");
					system("pause");
					system("cls");
				}
				break;
			case 6:
				printf("\n Saiu do programa!!!\n");
				break;
			default:
				printf("\nOpcao Invaauxda!!!\n");
		}

		system("cls");

    
	}  while(menu != 6);

	free(li);
	free(no);
	free(aux);

	return 0;

}