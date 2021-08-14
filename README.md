# cry.h

![cry-h.png](https://raw.githubusercontent.com/4thel00z/logos/master/cry-h.png)
<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [cry.h](#cryh)
  - [Motivation](#motivation)
  - [Installation](#installation)
  - [Usage](#usage)
  - [License](#license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->



## Motivation

I want errors and fatal errors with fancy colors.

## Installation

```
clib install 4thel00z/cry.h
```

## Usage

```c
#include "cry.h"
#include <sysexits.h>

#define CRY_SIMPLE (-1337)
#define CRY_FATAL (1337)

int main(){

  // If you set CRY_TO var to another FILE * the output get's redirected there

  cry_t simple_cry = cry_new(CRY_SIMPLE, "CRY_SIMPLE");
  cry_t fatal_cry = cry_fatal_new(CRY_FATAL, "CRY_FATAL", true, EX_USAGE);

  cry(&simple_cry, "Crying simply");
  cry(&fatal_cry, "Crying for last time boi");

  // This will get ignored lel
  return 0;
}
```

## License

This project is licensed under the GPL-3 license.
