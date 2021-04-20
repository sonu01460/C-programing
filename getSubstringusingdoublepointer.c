/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getsubstr (char **Inoutstr,char *str)
{

  int len = strlen (str);
  if (len > 6)
    {
      *Inoutstr=&str[len - 6];
    }
  else
    {
      *Inoutstr=str;
    }
     printf ("%s", *Inoutstr);
}

int
main ()
{
  char *finalstr;
  printf ("get only 6 char\n");
  getsubstr(&finalstr,"123456abcdef");
  return 0;
}
