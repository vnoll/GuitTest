#include <stdio.h>

#define MAX_SIZE 100
#define FAIL 0
#define SUCCESS 1

unsigned char FIFO[MAX_SIZE];
unsigned char start = 0;
unsigned char end = 0;

/* essa FIFO eh mais simples, e sempre o dado é colocado na na posição end e retirado na posição start, exceto na ultima posição. Isso elimina uma posição. Na matriz de 100 elementos estao disponiveis 99 elementos
*/
unsigned char enqueue(unsigned char data) {
    if ((end+1) % MAX_SIZE == start)
    {
        printf("Queue is full\n");
        return FAIL;
    }
    else {
        FIFO[end] = data;
        end = (end + 1) % MAX_SIZE;
        return SUCCESS;      
    }
}

unsigned char dequeue(unsigned char *data)
{
    if (start == end){
        printf("Queue is empty\n");
        return FAIL;
    }
    else {
        *data = FIFO[start];
        start = (start + 1) % MAX_SIZE;
        return SUCCESS;
  }
}

unsigned char enqueue_adicionado_branch_new(unsigned char data) {
    if ((end+1) % MAX_SIZE == started)
    {
        printf("Queue is full\n");
        return FAIL;
    }
    else {
        FIFO[end] = data;
        end = (end + 1) % MAX_SIZE;
        return SUCCESS;      
    }
}


int main(void) {
  
  unsigned char undata;
  unsigned idx = 0;
  
  printf("Inserindo dados na FIFO\n");  
  for (idx=0 ; idx<MAX_SIZE; idx++) {
    enqueue(idx);
  }

  printf("Retirando dados na FIFO\n");  
  for (idx =0 ; idx<MAX_SIZE; idx++) {
    if(dequeue(&undata)==SUCCESS) printf("%d\n",undata);  
  }

  printf("Inserindo mais dados na FIFO\n");  
  for (idx=0 ; idx<MAX_SIZE/2; idx++) {
    enqueue(idx);
  }

  printf("Retirando dados na FIFO\n");  
  for (idx =0 ; idx<MAX_SIZE; idx++) {
    if(dequeue(&undata)==SUCCESS) printf("%d\n",undata);  
  }
  
  return 0;
}
