// $ gcc -o prodcon_omp.exe prodcon_omp.c -fopenmp
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 5
#define NITER 10

void *producer();
void *consumer();

// Shared by the producer and consumer thread
int buffer[BUFFER_SIZE];
int in = 0;    // next free position 
int out = 0;   // first full position

int main(){
   srand(time(NULL));
   #pragma omp parallel sections
   {
      #pragma omp section
      producer();
      
      #pragma omp section
      consumer();
   }

   return 0;
}

void *producer(){
   int next_produced; 

   for (int i=0; i< NITER; i++) { 
      next_produced = rand() % 100 + 1;

      // Do nothing if the buffer is full
      while (((in + 1) % BUFFER_SIZE) == out) ; 
   
      buffer[in] = next_produced; 
      printf("Producer produced [%d].(Placed in index:in=%d,out=%d)\n",next_produced,in,out);     
      in = (in + 1) % BUFFER_SIZE; 
   }
}

void *consumer(){
   int next_consumed; 

   for (int i=0; i< NITER; i++) { 
      
      // Do nothing if the buffer is empty
      while (in == out) ; 

      next_consumed = buffer[out]; 
      printf("\tConsumer consumed [%d].(in=%d,Consumed from index: out=%d)\n",next_consumed,in,out);     
      out = (out + 1) % BUFFER_SIZE;
   } 
}