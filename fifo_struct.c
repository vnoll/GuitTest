#include <stdio.h>
#include <string.h>

#define FAIL 0
#define SUCCESS 1
#define MAX_ELEMENTS 100

typedef struct dados_t {
    char nome[20];
    unsigned char contador;
} dados_t;

dados_t Fifo_Structs[MAX_ELEMENTS];


unsigned char start = 0;
unsigned char end = 0;

/* essa FIFO eh mais simples, e sempre o dado é colocado na na posição end e retirado na posição start, exceto na ultima posição. Isso elimina uma posição. Na matriz de 100 elementos estao disponiveis 99 elementos
*/
unsigned char enqueue(dados_t *self) {
    
    if ((end+1) % MAX_ELEMENTS == start)
    {
        printf("Queue is full\n");
        return FAIL;
    }
    else {
        Fifo_Structs[end] = *self;
        end = (end + 1) % MAX_ELEMENTS;
        return SUCCESS;      
    }
}

unsigned char dequeue(dados_t *self)
{
    if (start == end){
        printf("Queue is empty\n");
        return FAIL;
    }
    else {
        *self = Fifo_Structs[start];
        start = (start + 1) % MAX_ELEMENTS;
        return SUCCESS;
  }
}


int main(void) {
  
  unsigned char undata;
  unsigned int idx = 0;

  dados_t meusDados = {.nome="VALDIR", .contador=0};

  printf("Inserindo dados na FIFO\n");  
  for (idx=0 ; idx<MAX_ELEMENTS; idx++) {
    meusDados.contador=idx;
    enqueue(&meusDados);
  }


  printf("Retirando dados na FIFO\n");  
  for (idx =0 ; idx<MAX_ELEMENTS; idx++) {
    if(dequeue(&meusDados)==SUCCESS) 
        {
            printf("%s\n",meusDados.nome); 
            printf("%d\n",meusDados.contador);
        }
  }

  printf("Inserindo mais dados na FIFO\n");  
  for (idx=0 ; idx<10; idx++) {
    meusDados.contador=idx;
    enqueue(&meusDados);
  }
 
  printf("Retirando mais dados na FIFO\n");  
  for (idx =0 ; idx<20; idx++) {
        if(dequeue(&meusDados)==SUCCESS) 
        {
            printf("%s\n",meusDados.nome); 
            printf("%d\n",meusDados.contador);
        };  
  }
  return 0;
}
