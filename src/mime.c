#include "mime.h"

#define INDEX(i)	(i-1)
#define	EQUALS(x,y)	(strcmp(x, y) == 0)

typedef struct
{
  char * mimetype;
  char * extention;
}
mimetype_t;

static mimetype_t * types = NULL;
static size_t types_len = 0;

int fpeek(FILE * file)
{
  int c = fgetc(file);
  ungetc(c, file);
  return c;
}

int mime_load(FILE * file)
{
  while(!feof(file))
  {
    if(fpeek(file) == '#') // Comment
    {
      while(fgetc(file) != '\n');
      continue;
    }

    types = (mimetype_t *) realloc(types, sizeof(*types) * ++types_len);
    if(fscanf(file, "%ms %m[^\r\n] ", &types[INDEX(types_len)].mimetype, &types[INDEX(types_len)].extention) == EOF)
      return -1;
  }

  return types_len;
}

const char * mime_get(const char * extention)
{
  if(types == NULL || extention == NULL)
    return NULL;

  if(*extention == '.')
    extention++;

  for(size_t i = 0; i < types_len; i++)
  {
    if(types[i].extention == NULL)
      continue;

    char *buffer, *token;
    char *cpy = strdup(types[i].extention);
    for(char * str = cpy;; str = NULL)
    {
      if((token = strtok_r(str, " \t\n\r", &buffer)) == NULL)
      {
	free(cpy);
        break;
      }

      if(EQUALS(extention, token)) {
	free(cpy);
        return types[i].mimetype;
      }
    }
  }
  return NULL;
}

void mime_unload()
{
  for(size_t i = 0; i < types_len; i++)
  {
    free(types[i].mimetype);
    free(types[i].extention);
  }
  free(types);
}

