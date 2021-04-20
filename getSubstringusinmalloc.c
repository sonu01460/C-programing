/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
getsubstr (char *str)
{

  int len = strlen (str);
  char *subbuff = malloc (6);
  if (len > 6)
    {
      memcpy (subbuff, &str[len - 6], 6);
      return subbuff;
    }
  else
    {
      memcpy (subbuff, str, len);
      return subbuff;
    }
  //*finalstr=subbuff;
  // free(subbuff);
}

int
main ()
{
  //char *finalstr;
  printf ("get only 6 char\n");
  char *finalstr = getsubstr ("12345abcdefg");
  //getsubstr(&finalstr,"12345abcdefg");
  printf ("%s", finalstr);
  free (finalstr);
  return 0;
}
