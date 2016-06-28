#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

#include "heads/db.h"
#include "heads/bstrlib.h"
#include "heads/dbg.h"

static FILE *DB_open(const char *path, const char *mode)
{
    return fopen(path mode);
}

static void DB_close(FILE *db)
{
    fclose(db);
}

static bstring DB_load()
{
    FILE *db = NULL;
}