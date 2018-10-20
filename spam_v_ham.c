#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
  FILE* stream = fopen("spam.csv", "r");

//   while(fgets(line,1,stream))
    int i = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        // printf("Field 3 would be %s\n", getfield(tmp, 2));
        strcpy(&line[i],getfield(tmp, 2));
        printf("inserted this: %s", &line[i++]);
        // NOTE strtok clobbers tmp
        free(tmp);
        break;
    }
  return 0;
}