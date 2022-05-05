#include "aula.h"
void FLVazia(Lista *l){
    // diz que a cabeça da lista é um espaço de memória que armazena um BLOCO
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    // diz que o ultimo termo da lista é o primeiro
    l->cauda=l->cabeca;
    // diz que o proximo item depois do ultimo é nulo
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l,char arquivo[80],bool novo){
    FILE *f;
    char nome[100];
    Item aux;
    if(!novo){
        if(!(f=fopen(arquivo,"r"))){
            printf("Erro ao abrir arquivo.\n");
            exit(1);
        }
        fseek(f,0,SEEK_END);
        fseek(f, -9, SEEK_CUR);
        fscanf(f,"%s",nome);
        if(strcmp(nome,"---------") !=0){
            fclose(f);
            f=fopen(arquivo,"a");
            fputs("\n---------",f);
        }
        fclose(f);
        f=fopen(arquivo,"r");
    }
    else{
        f= fopen("ArquivoNomes.txt","w");
		preencheArquivo(f);
		fclose(f);
		f=fopen("ArquivoNomes.txt","r");
    }
    fscanf(f,"%s ",nome);
    while(strcmp(nome,"---------") !=0){
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        strcpy(aux.value,nome);
        aux.removido=false;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
        fscanf(f,"%s ",nome);
    }
    fclose(f);
}
void preencheArquivo(FILE* arq){
    char nome[100];
    fgets(nome, 100, stdin);
    do
    {
        printf("Insira o nome: (Max 100, 0 para sair)\n");
        fgets(nome, 100, stdin);
        if (nome[0]!='0')
            fputs(nome, arq);
    } while (nome[0]!='0');
    fputs("-----------", arq);
}
bool insertLista(Lista *l){
    Bloco *aux;
    Item item;
    char nome[100];
    fgets(nome, 100, stdin);
    printf("Qual nome deseja inserir? \n");
	fgets(nome,100,stdin);
    nome[strlen(nome)-1]='\0';
    strcpy(item.value,nome);
    item.removido=false;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.removido==true){
            aux->prox->dado=item;
            return 1;
        }
        else
            aux=aux->prox;
    }
    l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cauda->prox;
    l->cauda->dado=item;
    l->cauda->prox=NULL;
    return 1;
}
void removeListaItem(Lista *l){
    Bloco* aux;
    char nome[100];
    aux=l->cabeca;
    fgets(nome, 100, stdin);
    printf("Qual nome deseja remover? (Remove todas as aparicoes)\n");
	fgets(nome,100,stdin);
    nome[strlen(nome)-1]='\0';
    while (aux->prox!=NULL){
        if (strcmp(aux->prox->dado.value,nome)==0)
           aux->prox->dado.removido=true;
        aux=aux->prox;
    }
}
void removeRepet(Lista *l){
    Bloco *percorre, *remove;
    percorre=l->cabeca;
    while (percorre->prox!=NULL){
        remove=percorre->prox;
        while (remove->prox!=NULL)
        {
            if (strcmp(remove->prox->dado.value,percorre->prox->dado.value)==0)
                remove->prox->dado.removido=true;
            remove=remove->prox;
        }
        percorre=percorre->prox;
    }
}

void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.removido==false)
            printf("%s, ",aux->prox->dado.value);
        aux=aux->prox;
    }
    printf("\n");
}
void printListaV(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf("%s, ",aux->prox->dado.value);
        aux=aux->prox;
    }
    printf("\n");
}
void atualizaArquivo(Lista *l,char nomearquvio[80]){
    FILE *f;
    f=fopen(nomearquvio, "w");
    Bloco* aux;
    aux=l->cabeca;
    while(aux->prox!=NULL)
    {
        strcat(aux->prox->dado.value,"\n");
        fputs(aux->prox->dado.value, f);
        aux=aux->prox;
    }
    fputs("---------", f);
    fclose(f);
}