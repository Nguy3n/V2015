#include <stdio.h>     /* printf */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* fork */
#include <pthread.h>
#include <semaphore.h>
#define SHARED 1

sem_t sem[6];   /* one semaphore for each thread */

struct threadargs {
  int id;        /* thread number */
  int sec;       /* how many seconds to sleep */
  int signal[6]; /* which threads to signal when done */
};

/* thread function: start by waiting on my own semaphore if it has been
 * initialized to 0; do my work (sleeping); signal the threads that
 * should start when I finish; exit
 */

void* tfunc(void *arg) {
  struct threadargs *targs=arg;
  // VENT PÅ DIN EGEN SEMAFOR
  printf("Tråd %d kjører\n", targs->id);
  sleep(targs->sec);
  printf("Tråd %d er ferdig og vekker kanskje andre...\n", targs->id);
  // ITERERER OVER signal-ARRAYET OG VEKK TRÅD nr i HVIS signal[i] er 1
  return 0;
}

int main(void) {
  int i,j;
  pthread_t tid[6];
  struct threadargs *targs[6];
  /* allocate memory for threadargs and zero out semaphore signals */
  for(i=0;i<6;i++) {
    targs[i] = (struct threadargs*) malloc(sizeof(struct threadargs));
    for(j=0;j<6;j++) {
      targs[i]->signal[j]=0;
    }
}

  targs[0]->id=0;        /* thread number 0 */
  targs[0]->sec=1;       /* how long to sleep */
  targs[0]->signal[1]=1; /* which threads to wake up when done */
  targs[0]->signal[1]=0;

  // INITIALISERER TRÅDENS SEMAFOR TIL 1 ELLER 0
  // START TRÅDEN

  // GJENTA KODELINJENE OVER FOR DE FEM NESTE TRÅDENE, BARE ENDRE PARAMETRE

  // for(i=0;i<6;i++) pthread_join(tid[i], NULL);

  targs[0]->id=2;        /* thread number 0 */
  targs[0]->sec=3;       /* how long to sleep */
  targs[0]->signal[3]=1; /* which threads to wake up when done */
  targs[0]->signal[3]=1;

  return 0;
}
