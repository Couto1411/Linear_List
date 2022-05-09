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
    }
    else{
        f= fopen("ArquivoNomes.txt","w");
		preencheArquivo(f);
		fclose(f);
		f=fopen("ArquivoNomes.txt","r");
    }
    while(!feof (f)&&tamanhoLista<MAXTAM){
        fscanf(f,"%s ",nome);
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        strcpy(aux.value,nome);
        aux.cont=0;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
        tamanhoLista++;
    }
    if (tamanhoLista>=MAXTAM)
        printf("Arquivo e igual ou excedeu a quantidade maxima de 100 nomes, lista fica com os 100 primeiros\n");
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
}
void insertLista(Lista *l){
    Item item;
    char nome[100];
    if (tamanhoLista<MAXTAM)
    {
        fgets(nome, 100, stdin);
        printf("Qual nome deseja inserir no final? \n");
        fgets(nome,100,stdin);
        nome[strlen(nome)-1]='\0';
        strcpy(item.value,nome);
        item.cont=0;
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        l->cauda->dado=item;
        l->cauda->prox=NULL;
        tamanhoLista++;
    }
    else
        printf("Arquivo e igual ou excedeu a quantidade maxima de 100 nomes, lista fica com os 100 primeiros\n");
}
void removeListaItem(Lista *l){
    Bloco* aux, *freeBloco;
    char nome[100];
    aux=l->cabeca;
    fgets(nome, 100, stdin);
    printf("Qual nome deseja remover? (Remove todas as aparicoes)\n");
	fgets(nome,100,stdin);
    nome[strlen(nome)-1]='\0';
    while (aux->prox!=NULL){
        if (strcmp(aux->prox->dado.value,nome)==0){
            if (aux->prox==l->cauda){
                free(aux->prox);
                aux->prox=NULL;
                l->cauda=aux;
                tamanhoLista--;
            }
            else{
                freeBloco=aux->prox;
                aux->prox=aux->prox->prox;
                free(freeBloco);
                tamanhoLista--;
            }
        }
        else{
            aux=aux->prox;
        }
    }
}
void removeRepet(Lista *l){
    Bloco *percorre, *remove, *freeBloco;
    percorre=l->cabeca;
    while (percorre->prox!=NULL){
        remove=percorre->prox;
        while (remove->prox!=NULL)
        {
            if (strcmp(remove->prox->dado.value,percorre->prox->dado.value)==0){
                if (remove->prox==l->cauda){
                    free(remove->prox);
                    remove->prox=NULL;
                    l->cauda=remove;
                    tamanhoLista--;
                }
                else{
                    freeBloco=remove->prox;
                    remove->prox=remove->prox->prox;
                    free(freeBloco);
                    tamanhoLista--;
                }
            }
            else
                remove=remove->prox;
        }
        percorre=percorre->prox;
    }
}
void showRepet(Lista *l){
    Bloco *percorre, *repet,*aux;
    percorre=l->cabeca;
    aux=l->cabeca;
    while (percorre->prox!=NULL){
        if (percorre->prox->dado.cont!= -1)
            percorre->prox->dado.cont+=1;
        repet=percorre->prox;
        while (repet->prox!=NULL&&percorre->prox->dado.cont!=-1)
        {
            if (strcmp(repet->prox->dado.value,percorre->prox->dado.value)==0){
                percorre->prox->dado.cont+=1;
                repet->prox->dado.cont= -1;
            }
            repet=repet->prox;
        }
        percorre=percorre->prox;
    }
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.cont>0)
            printf("%s\t repetições: %d\n",aux->prox->dado.value,aux->prox->dado.cont);
        aux->prox->dado.cont=0;
        aux=aux->prox;
    }
    printf("\n");
}
void printLista(Lista *l){
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
        aux->prox->dado.value[strlen(aux->prox->dado.value)-1]='\0';
        aux=aux->prox;
    }
    fclose(f);
}