#ifndef __CRY_H__
#define __CRY_H__
#include <stdbool.h>
#include <stdlib.h>
#include "log.h"

typedef struct {
  int code;
  char *name;
  bool is_fatal;
  int ret_val;
} cry_t;



void
cry (void *type, char *msg);

cry_t
cry_new (int code, char *name);

cry_t
cry_fatal_new (int code, char *name, bool is_fatal, int ret_val);

cry_t
cry_new (int code, char *name) {
  cry_t err;
  err.code = code;
  err.name = name;
  err.is_fatal = false;
  err.ret_val = 0;
  return err;
}


cry_t
cry_fatal_new (int code, char *name, bool is_fatal, int ret_val) {
  cry_t err;
  err.code = code;
  err.name = name;
  err.is_fatal = is_fatal;
  err.ret_val = ret_val;
  return err;
}

void
cry (void *type, char *msg) {
  cry_t *err = (cry_t *) type;
  log_error("%s (%d): %s\n", err->name, err->code, msg);
  if(!err->is_fatal) return;
  exit(err->ret_val);
}

#endif
