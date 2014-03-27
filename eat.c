#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
eat_mem ()
{
  size_t megs = 0;

  while (1)
    {
      void *mem = calloc(1, 1024*1024);
      if (mem == NULL)
        {
          printf ("Failed.\n");
          return 1;
        }
      megs += 1;
      printf ("Allocated %uMB.\n", megs);
      memset (mem, 0xFF, 1024*1024);
      printf ("Used %uMB.\n", megs);
      usleep(500000);
    }
}

void
eat_cpu ()
{
  while (1)
    ;
}

void
main (int argc, char **argv)
{
  if (argv[1] && strcmp (argv[1], "mem") == 0)
    eat_mem ();
  else
    eat_cpu ();
}
