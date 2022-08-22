#include <stdio.h>

#include "mime.h"

const char *extentions[] = {
  ".html",
  ".htl",
  ".css",
  ".csv",

  NULL
};

int main()
{
  FILE * mime = fopen("mime.types", "r");
  printf("Loaded %d MIME-types\n\n", mime_load(mime));
  fclose(mime);

  for(const char **e = extentions; *e; e++)
    printf("MIME-Type for %s: %s\n", *e, mime_get(*e));

  mime_unload();
  return 0;
}

