

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


static void * thread_func(void * arg);

int main(int argc, char * argv[])
{
  // sem_t        * my_sem;
  sem_t          my_sem;
  int            th_rc;
  int            sem_rc;
  pthread_attr_t th_props;
  pthread_t      th_id;
  unsigned int   sem_init_value = 10;

  /* open semaphore */
  // my_sem = sem_open("Prem", O_CREAT);
  sem_rc = sem_init(&my_sem, 0, sem_init_value);

  /* create thread/worker */
  memset(&th_id, 0, sizeof(th_id));
  pthread_attr_init(&th_props);
	// th_rc = pthread_create(&th_id, &th_props, thread_func, (void *) my_sem);
  th_rc = pthread_create(&th_id, &th_props, thread_func, (void *) &my_sem);

  /* main thread */
  while (1) {
    sleep(5);
    printf("main thread: signalling worker\n");
    // sem_post(my_sem);
    sem_post(&my_sem);
  }

  return (0);
}


static void * thread_func(void * arg)
{
  sem_t * my_sem = (sem_t *) arg;

  while (!sem_wait(my_sem)) {
  // while (sem_wait(my_sem)) {
    printf("worker thread: got signalled \n");
  }

  printf("worker thread: exiting ... \n");
}


