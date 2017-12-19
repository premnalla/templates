
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "ax_string.hpp"


#define max_threads     5
#define max_assign_loop 1000
// #define max_assign_loop 10000000

static void
copy_constructor_test_func(ax_string s)
{
  printf("inside copy constructor: %s\n", s.c_str());
}


static void *
worker_routine(void * arg)
{
  for (int i=0; i<max_assign_loop; i++) {
    ax_string foo = "fooooooooooooooooooooooooo";
    ax_string bar = foo;
    // printf("%s\n", bar.c_str());
    copy_constructor_test_func(bar);
    printf("out of copy constructor: %s\n", bar.c_str());
  }
}


int main(int argc, char * argv[])
{
  ax_string       tmp;
  pthread_t       workerId[max_threads];
  pthread_attr_t  workerProperties;

  pthread_attr_init(&workerProperties);

  for (int i=0; i<max_threads; i++) {
    pthread_create(&workerId[i], &workerProperties, worker_routine, NULL);
  }

#if 0
  while (1) {
    sleep(60);
  }
#endif

  for (int i=0; i<max_threads; i++) {
    pthread_join(workerId[i], (void **)NULL);
  }

  ax_string * strPtr = new ax_string("foo");
  *strPtr = "bar";
  printf("%s\n", strPtr->c_str());

  tmp = "testing copy constructor...";
  copy_constructor_test_func(tmp);
  printf("out of copy constructor: %s\n", tmp.c_str());

  tmp = "done...";
  printf("%s\n", tmp.c_str());

  return (0);
}
