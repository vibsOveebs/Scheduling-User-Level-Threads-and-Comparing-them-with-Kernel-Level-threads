#include "p_func.h"
#include <string.h>
#define NUM_THREADS	5

int main(int argc, char const *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  int *arr;
  void *tab[] = {counter,sleeping};
  int flag = -1;

  arr = (int *)malloc(10 * sizeof(int));
  long long int sum = 0;

  for(int i=0 ; i<10 ; i++)
    arr[i] = 0;

  if(argc<2)
  {
    printf("Argument missing !!\n");
    return -1;
  }

  flag = !(strcmp(argv[1],"counter"))? 0 : 1;
    
  printf("Code under execution .. \n");
  for(t=0;t<NUM_THREADS;t++){
   
    rc = pthread_create(&threads[t], NULL, tab[flag], (void *)arr);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
      }
    }

  for (t=0 ; t<NUM_THREADS ; t++)
    pthread_join(threads[t],NULL);

  for(int i=0 ; i<10 ; i++)
  {
    sum += arr[i];
  }

  printf("Counter = %lld\n",sum);
  pthread_exit(NULL);
  return 0;
}
