#include "aula.h"

int main(){
	Lista l;
	char resposta, arquivo[80];
	int opcao;
	printf("Arquivo pronto? (S/N)");
	scanf("%c", &resposta);
	FLVazia(&l);
	if (resposta=='S')
	{
		fgets(arquivo,80,stdin);
        printf("Qual o nome do arquivo? (Max 80)\n");
        fgets(arquivo,80,stdin);
        arquivo[strlen(arquivo)-1]='\0';
		preencheLista(&l,arquivo,false);
	}
	else{
		strcpy(arquivo,"ArquivoNomes.txt");
		preencheLista(&l,arquivo,true);
	}
	do
	{
		printf("O que deseja fazer?\n\t1-Inserir nome\n\t2-Remover\n\t3-Remover iguais\n\t4-Printar lista\n\t5-Mostrar repetições\n\t8-Atualizar arquivo\n\t9-Sair (Arquivo atualizado)\n\t0-Sair (Não atualizar arquivo)\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			insertLista(&l);
			break;
		case 2:
			removeListaItem(&l);
			break;
		case 3:
			removeRepet(&l);
			break;
		case 4:
			printLista(&l);
			break;
		case 5:
			showRepet(&l);
			break;
		case 8:
			printf("Atualizando arquivo...\n");
			atualizaArquivo(&l,arquivo);
			break;
		case 9:
			printf("Atualizando arquivo...\n");
			atualizaArquivo(&l,arquivo);
			printf("Saindo.\n");
			opcao=0;
			break;
		case 0:
			printf("Saindo.\n");
			break;
		default:
			break;
		}
	}while (opcao!=0);
	return 0;
}
