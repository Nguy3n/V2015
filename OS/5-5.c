#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

int g_ant = 0; /* global declaration */

pthread_once_t foo_once = PTHREAD_ONCE_INIT;
pthread_mutex_t mutex;

void  foo_init()
{
  pthread_mutex_init(&mutex, NULL);
}

void *writeloop(void *arg) {
  while (g_ant < 10) {

    pthread_once(&foo_once, foo_init);
    pthread_mutex_lock(&mutex);

    g_ant++;
    usleep(rand()%10);
    printf("%d\n", g_ant);

    pthread_mutex_unlock(&mutex);
  }
  exit(0);
}

int main(void)
{
  pthread_t tid;
  pthread_create(&tid, NULL, writeloop, NULL);
  writeloop(NULL);
  pthread_join(tid, NULL);
  return 0;
}
