clean()
{
  rm -rf output
  rm -rf *.o
}

clean;
gcc -c *.c
gcc -o output *.o && ./output
clean;