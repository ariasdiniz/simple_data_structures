#include "test_list.h"
#include "test_stack.h"
#include "test_queue.h"
#include <stdio.h>

int main() {
  printf("Starting execution of tests\n");
  runlisttests();
  runstacktests();
  runqueuetests();
  printf("All tests passed.\n");
  return 0;
}