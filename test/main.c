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
  // FILE * has to have read permissions
  FILE * mime = fopen("mime.types", "r");
  printf("Loaded %d MIME-types\n\n", mime_load(mime));
  fclose(mime);

  // If no MIME-type for the extention was found, `mime_get()` returns NULL
  for(const char **e = extentions; *e; e++)
    printf("MIME-Type for %s: %s\n", *e, mime_get(*e));

  // Free Memory
  mime_unload();
  return 0;
}

