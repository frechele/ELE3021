#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char** argv)
{
  int pid = fork();

  if (pid < 0)
  {
    printf(1, "Fork failed.\n");
    exit();
  }

  while (1)
  {
    if (pid > 0)
    {
      write(1, "Parent\n", 8);
    }
    else if (pid == 0)
    {
      write(1, "Child\n", 7);
    }

    yield();
  }

	exit();
}
