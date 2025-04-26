# Quark
Entries marked with a '*' are require for compelation.
## Defines
### QUARK_PACKAGE*
The name of the program
### QUARK_SHORT
Enables short names. It does this by removeing the preifx of 'quark_'
## Types
### quark_string_t
Custom string type that improves saftey, and makes them easier to work with.
## Functions
### quark_logf(__level_t, _quark_string_t, ...)
Takes in the levels of:
* OK
* ERR
* WARN
* INFO
* FATAL

Ex: `quark_logf(OK "Hello, QUARK!");`
