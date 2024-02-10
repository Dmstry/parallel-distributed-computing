#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Додавання цього заголовочного файлу

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
  intptr_t tid; // Зміна типу на intptr_t
  tid = (intptr_t)threadid;
  printf("Hello World! It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for (t = 0; t < NUM_THREADS; t++)
  {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)(intptr_t)t);
    if (rc)
    {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
