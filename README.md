# Quark
Entries marked with a '*' are require for compelation.
## Defines
### QUARK_PACKAGE*
The name of the program. Used in q_logf()
## Types
### q_string_t
Custom string type that improves saftey, and makes them easier to work with.
## Functions
### q_logf(__level_t, q_string_t, ...)
Takes in the levels of:
* OK
* ERR
* WARN
* INFO
* FATAL

Ex: `q_logf(OK "Hello, QUARK!");`
