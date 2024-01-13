#include "test_list.h"
#include "test_stack.h"
#include "test_queue.h"

int main() {
  runlisttests();
  runstacktests();
  runqueuetests();
  return 0;
}