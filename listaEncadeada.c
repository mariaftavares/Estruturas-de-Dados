#include <stdio.h>
#include <stdlib.h>

//Estrutura do nó.
struct node
{
  int valor;
  struct node *prox;
};

typedef struct node node;

node* cabeca = NULL;
node* ultimo = NULL;

void adicionar(int valor, int* contador){
  if(*contador == 100){
    printf("Não é possível adicionar mais nenhum valor. Lista está cheia.");
  }

  else if(cabeca == NULL){
    node* no = malloc(sizeof(node));
    no-> valor = valor;
    no-> prox = NULL;
    cabeca = no;
    ultimo = no;

    *contador += 1;
  }

  else{
    node* no = malloc(sizeof(node));
    no -> valor = valor;
    no -> prox = NULL;
    ultimo -> prox = no;
    ultimo = no;

    *contador+= 1;
  }
};

void excluir(int* contador){
  node* p = cabeca;

  if(p == NULL){
    printf("A lista está vazia.");
  }

  else if(cabeca == ultimo){
    cabeca = NULL;
    ultimo = NULL;

    free(p);

    *contador = 0;
  }

  else{
    while(p->prox != ultimo){
      p = p->prox;
    }

    ultimo = p;
    p = p->prox;
    ultimo->prox = NULL;
    free(p);

    *contador -= 1;
  }
}

void imprimirLista(){
  node* p = cabeca;

  if(cabeca == ultimo){
      printf("%d", cabeca->valor);
  }

  else{
    while(p != NULL){
      printf("%d\n", p->valor);
      p = p->prox;
    }
  }
}


int main(void){
  int contador = 0;
  int opcao = 5;
  while(opcao!=0){
    printf("\nEscolha uma das opcoes \n 1-Adicionar \n 2-Remover \n 3-Exibir \n 0- Sair \n Digite a sua opcao: ");
    scanf("%d",&opcao);
    if(opcao == 1){
      int valor = 0;
      printf("Digite o valor que deseja ser adicionado: ");
      scanf("%d",&valor);
      printf("\E[1;1H\E[2J");
      adicionar(valor,&contador);
    }
    else if(opcao == 2){
       printf("\E[1;1H\E[2J");
      excluir(&contador);
    }
    else if(opcao == 3){
      printf("\E[1;1H\E[2J");
      imprimirLista();
    }
  }

  return 0;
}