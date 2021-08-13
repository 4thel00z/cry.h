#include "cry.h"
#include <sysexits.h>

#define CRY_SIMPLE (-1337)
#define CRY_FATAL (1337)

int main(){


  cry_t simple_cry = cry_new(CRY_SIMPLE, "CRY_SIMPLE");
  cry_t fatal_cry = cry_fatal_new(CRY_FATAL, "CRY_FATAL", true, EX_USAGE);

  cry(&simple_cry, "Crying simply");
  cry(&fatal_cry, "Crying for last time boi");

  // This will get ignored lel
  return 0;
}
