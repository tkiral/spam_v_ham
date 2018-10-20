#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
  FILE* stream = fopen("test.txt", "r");

    int i = 0;
    char line[1024];
    char messages[6000];
    while (fgets(line, 1024, stream))
    {
        strcpy(&messages[i++],line);
        printf("inserted this: %s\n", line);
    }
  return 0;
}
