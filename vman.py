import sys
import webbrowser
from pathlib import Path


def vlibc_help():
    print("Usage: vman [argument] ...\n")
    print("Options:")
    print("  doc\tOpen up a webpage with documentation.")
    print("  man\tGet specific information about a single element of vlibc. This takes one option of either a function name, type, or macro.")
    print("  help\tPrint this text and exit.")
    exit(0)


def vlibc_doc():
    fp = "README.md"
    webbrowser.open(Path(fp).resolve().as_uri())


def g(src): return f"\n\n#include \"vlibc.h\"\n{src}"


def vlibc_man(page):
    if page[:6] == "vlibc_":
        page = page[6:]  # remove prefix
    match page:
        case "string_t": print("string_t is a string used by the vlibc library. It has two fields `to_str` and `len`" + g("string_t src = new_string(\"Hello, World!\");"))
        case "logf": print("logf() is a function used for general purpose printing to the user. It takes at least two arguments. A level, see level_t, and a format. It can also have a variable ammount of extra arguemnts as long as format has format specifier. All output from logf() is sent to stderr" + g("logf(OK \"hello, World!\");"))
        case "level_t": print("level_t is a internal type used in vlibc. It is intented that the uses called it through the macros of OK, ERR, WARN, INFO, and FATAL." + g("logf(OK \"Hello, World!\"); "))
        case _: print(f"No manual entry for {page}")


if len(sys.argv) < 2:
    vlibc_help()
if sys.argv[1] == "doc":
    vlibc_doc()
elif sys.argv[1] == "man":
    vlibc_man(sys.argv[2])
elif sys.argv[1] == "help":
    vlibc_help()
else:
    print(f"error: Unreconized argument `{sys.argv[1]}`. ", end="")
    if sys.argv[1][0] in "doc sfipxv":
        print("Did you mean doc?")
    elif sys.argv[1][0] in "man n,sb":
        print("Did you mean man?")
    else:
        print("\nRun `vman help` for the help text.")
