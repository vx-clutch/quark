# vlibc
any entries with an '*' are require for the library to function.
## Defines
### VLIBC_PACKAGE*
The name of the program
### VLIBC_SHORT
Enables short names. It does this by removeing the preifx of 'vlibc_'
## Functions
### vlibc_logf(__level_t, _vlibc_string_t, ...)
Takes in the levels of OK, ERR, WARN, INFO, FATAL

Ex: `vlibc_logf(OK "Hello, VLIBC!");`
