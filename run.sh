clean()
{
  rm -rf output
  rm -rf *.o
}

clean;
gcc -c -w *.c
gcc -o output *.o && ./output
clean;