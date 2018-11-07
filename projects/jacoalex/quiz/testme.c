#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  char char_list[20] = "[({ ax})]";
  unsigned int random_number = rand() % strlen(char_list);

  return char_list[random_number];
}

char *inputString()
{
  char char_list[20] = "rest";
  char * return_string = malloc(6); // put the string on the heap so it can be returned
  unsigned int random_number;

  // generate random string from a set of chars
  int i;
  for (i = 0; i < 5; i++)
  {
    random_number = rand() % strlen(char_list);
    return_string[i] = char_list[random_number];
  }

  // add a null char to make it a valid string
  return_string[5] = '\0';

  return return_string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {

      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
