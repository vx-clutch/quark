# Quark
A simple library that adds little features.
## Build
### Linux
`make`

then

`make install`
## Usage
See [docs](https://vx-clutch.github.io/quark/) for specific information on how to use Quark
### Linking
Compile with `-lq` and include `quark.h` in your project
## Examples
### Logging
```
#include "quarks.h"

int
main(void)
{
    q_logf(OK "Hello, World!");
    q_string_t qstr = new_string("Hello, Quark!");
    qlogf(OK qstr);
    return 0;
}
```