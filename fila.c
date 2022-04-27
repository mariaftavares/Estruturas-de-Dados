#include <stdio.h>
void enfileirar(int item,int fila[],int *p){
  if(*p==100){
    printf("Não é possivel fila cheia\n");
  }

  else{
    fila[*p] = item;
    (*p)++;
  }
}
void desenfilerar (int fila[],int *p){
  if( *p == 0){
    printf("Não é possivel fila vazia\n");
    
    } 

  else{
    (*p)--; 
    for(int i=0; i<*p;i++){
       fila[i]=fila[i+1];
    }
 }
}

void exibir (int fila[],int *p){
  if( *p == 0){
    printf("Não possui itens enfileirados para ser exibidos\n");
    
  } 
  else{
    for (int i=0;i<*p;i++){
    printf(" %d ",fila[i]);
    }
  }
}
int main(void) {
 
  int vetor [100];
  int posicao =0;
  int opcao = 5;
  while(opcao != 0){
    printf("\nEscolha uma das opcoes \n 1-Enfileirar \n 2-Desenfileirar \n 3-Exibir \n 0- Sair \n Digite a sua opcao: ");
    scanf("%d",&opcao);
    if(opcao == 1){
      int valor = 0;
      printf("Digite o valor que deseja ser enfileirado: ");
      scanf("%d",&valor);
      printf("\E[1;1H\E[2J");
      enfileirar(valor,vetor,&posicao);
    }
    else if(opcao == 2){
       printf("\E[1;1H\E[2J");
      desenfilerar(vetor,&posicao);
    }
    else if(opcao == 3){
      printf("\E[1;1H\E[2J");
      exibir(vetor,&posicao);
    }
    
  }
  
 



  
  


  

  return 0;
  }
