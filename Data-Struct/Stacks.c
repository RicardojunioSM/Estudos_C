#include<stdio.h> 
#include<stdlib.h> 
   
struct stack{ 
      int value; 
      struct stack* node; 
  }; 
   
typedef struct stack* No; 
 
void push(No* SP, int num){ 
    No newnod = malloc(sizeof(No)); 

    newnod->value = num; 
    newnod->node = NULL; 
     
    if(*SP == NULL){ 
      *SP = newnod; 
      newnod = *SP; 
    }else{ 
        newnod->node = *SP; 
        *SP = newnod; 
    }  
  } 
   
  void pop(No* SP){ 
    No aux = *SP; 
     
    if(*SP == NULL){ 
      printf("      Lista vazia..\n"); 
    }else{ 
      *SP = (*SP)->node; 
      free(aux);  
    } 
  } 
   
  void printStack(No* SP){ 
    No aux = *SP; 
    while(aux != NULL){ 
      printf("           %d\n",aux->value);  
      aux = aux->node; 
    } 
    printf("\n"); 
  } 
   
  void show(){ 
    printf("Selecione sua opção \n(1) Inserir item na pilha \n(2) Remover item na pilha \n(3) Sair\n\nDigite:"); 
  } 
   
   
  int main(int argc , char* argv[]){ 
    No stack = NULL; 
    int chose,num; 
     
    show(); 
    scanf("%d",&chose); 
     
    while(chose != 3){ 
       
      switch(chose){ 
        case 1:  
            printf("\nDigite um numero para colocar na pilha.."); 
            scanf("%d",&num); 
            push(&stack,num); 
            printf("\n Inserindo item na pilha\n"); 
            printStack(&stack); 
        break; 
           
        case 2: 
            printf("\n Removendo item na pilha \n"); 
            pop(&stack); 
            printStack(&stack); 
        break; 
          
        default: 
            printf("\nEscolha invalida\n"); 
            show(); 
        break;  
      } 
      show(); 
      scanf("%d",&chose); 
    }
    printf("\nfim do programa...");
    return 0; 
  } 

