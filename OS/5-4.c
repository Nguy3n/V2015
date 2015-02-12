#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *consumer(void *arg)
{ int i;
  for (i=0;i<5;i++){
    pthread_mutex_lock(&mutex);
    if (state == EMPTY)
      pthread_cond_wait(&signalS, &mutex);
-----
  pthread_cond_signal(&signalS);
 pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(void)
{
  return 0;
}
