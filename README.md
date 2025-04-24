# vlibc
Entries marked with a '*' are require for compelation.
## Defines
### VLIBC_PACKAGE*
The name of the program
### VLIBC_SHORT
Enables short names. It does this by removeing the preifx of 'vlibc_'
## Types
### vlibc_string_t
Custom string type that improves saftey, and makes them easier to work with.
## Functions
### vlibc_logf(__level_t, _vlibc_string_t, ...)
Takes in the levels of OK, ERR, WARN, INFO, FATAL
Ex: `vlibc_logf(OK "Hello, VLIBC!");`
