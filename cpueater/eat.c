int
main (int argc, char **argv)
{
  int i;
  int delay = 0;

  if (argc > 1)
    delay = atoi (argv[1]);

  while (1)
    {
      for (i = 0; i < 10000000; i++)
        ;
      if (delay > 0)
        usleep(delay);
    }
}
