#include <fcntl.h>
#include <iostream>
#include <semaphore.h>

int main() {
  auto sem_handle =
      sem_open("/instinet_md_adapter", O_CREAT, S_IRUSR | S_IWUSR, 1);
  if (sem_handle == SEM_FAILED) {
    std::cout << "semaphore creation failed" << std::endl;
    exit(EXIT_FAILURE);
  }
  auto val = sem_trywait(sem_handle);
  if (val < 0) {
    std::cout << "max num of processes already present" << std::endl;
    exit(EXIT_FAILURE);
  }

  int value_of_semaphore{-3};
  int x = sem_getvalue(sem_handle, &value_of_semaphore);
  std::cout << "value_of_semaphore = " << x << std::endl;
  while (true) {
  };
  sem_close(sem_handle);
  return 0;
}
