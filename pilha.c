#include <stdio.h>
void empilhar (int pilha[],int valor,int *posicao){
  if(*posicao == 100){
    printf("Pilha Cheia");
  }
  else{
     pilha[*posicao]= valor;
    (*posicao)++;
  }
}
void desempilhar (int *posicao){
  if(*posicao == 0){
    printf("Pilha Vazia");
  }
  else{
    (*posicao)--;
  }
}

void exibir(int pilha[],int *posicao){
    if(*posicao == 0){
      printf("Não existe valores empilhados");
    }
    else{
      for (int i = *posicao - 1; i>=0;i--){
        printf(" %d ",pilha[i]);
      }
    }
  
  
}
int main() {
int opcao=-1;
int pilha[100];
int posicao =0;
  while(opcao != 0){
    printf("\nEscolha uma das opcoes: \n1- empilhar\n2-desempilhar\n3-exibir\n0- sair\n");
      scanf("%d",&opcao);
    if (opcao ==1){
      int valor =0;
      printf("Digite o valor que será empilhado: ");
      scanf("%d",&valor);
      printf("\E[1;1H\E[2J");
      empilhar(pilha,valor,&posicao);
    }
    else if (opcao==2){
      printf("\E[1;1H\E[2J");
      desempilhar(&posicao);
    
    }
    else if (opcao==3){
      printf("\E[1;1H\E[2J");
      exibir(pilha,&posicao);
    }
  }

  
  return 0;
}