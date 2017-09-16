#include "p_func.h"

void *counter(void *arr)
{
  long tid;
  pid_t id;
  int temp;
  id = syscall(SYS_gettid);
  int *ar = arr;

  struct timespec begin;
  struct timespec current;
  clock_gettime(CLOCK_MONOTONIC, &begin);
 
  long long int rf = 0;
  while (1)
  {
      rf++;

      clock_gettime(CLOCK_MONOTONIC, &current);
      if (((long long)current.tv_sec - (long long)begin.tv_sec) >= 10.0)
      {
       
        break;
      }
  }
  temp = (int)id%10;
  ar[temp] = rf;
   pthread_exit(NULL);
}

void *sleeping(void *arr)
{
  long tid;
  pid_t id;
  id = syscall(SYS_gettid);
  int *ar = arr;
  
  int temp;

  struct timespec begin;
  struct timespec current;
  clock_gettime(CLOCK_MONOTONIC, &begin);

  long long int rf = 0;
  while (1)
  {
      rf++;
      clock_gettime(CLOCK_MONOTONIC, &current);
      if (id%2 == 0)
      {
        if(((long long)current.tv_sec - (long long)begin.tv_sec) == 5.0)
         sleep(3);
      }

      if (((long long)current.tv_sec - (long long)begin.tv_sec) >= 10.0)
      {
        break;
      }
  }
  temp = id%10;
  ar[temp] = rf;
   pthread_exit(NULL);
}