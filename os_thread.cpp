#include "os_thread.h"
#include "Particle.h"

// Function to create a new thread
os_thread_id_t os_add_thread(thread_func_t p, void * arg, int stack_size, void *stack){
  os_thread_id_t thread_id;
  thread_id.handle = new Thread("", p, 0, stack_size);
  return thread_id;
}
