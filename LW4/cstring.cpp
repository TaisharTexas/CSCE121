#include <iostream>
#include "cstring.h"
#include <cstring>

unsigned int length(char str[])
{
  int length = 0;

  char *temp = str;
  length = strlen(temp);

  return length;
}


unsigned int find(char str[], char character)
{
  char *temp = str;
  for(int i = 0; i < strlen(temp); i++)
  {
    if(str[i] == character)
    {
      return i;
    }
  }

  return strlen(temp);
}


bool equalStr(char str1[], char str2[])
{
  char *temp1 = str1;
  char *temp2 = str2;
  bool stillEqual = false;
  if(strlen(temp1) == strlen(temp2))
  {
    for(int i = 0; i < strlen(temp1); i++)
    {
      if(str1[i] == str2[i])
      {
        stillEqual = true;
      }
      else
      {
        stillEqual = false;
      }
    }
  }
  else
  {
    return false;
  }

  return stillEqual;
  // returns true if they are equal and false if they are not
}
