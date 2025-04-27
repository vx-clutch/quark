import sys
import webbrowser
import os


def quark_help():
    print("Usage: qman [argument] ...\n")
    print("Options:")
    print("  doc\tOpen up a webpage with documentation.")
    print("  man\tGet specific information about a single element of quark. This takes one option of either a function name, type, or macro.")
    print("  help\tPrint this text and exit.")
    exit(0)


def quark_doc():
    html_path = os.path.join(os.getcwd(), 'doc', 'std.html')

    if not os.path.isfile(html_path):
        print(html_path)
        exit(0)

    # Open the HTML file in the default web browser
    webbrowser.open(f'file://{html_path}')


def g(src): return f"\n\n#include \"quarks.h\"\n{src}"


def quark_man(page):
    if page[:2] == "q_":
        page = page[2:]  # remove prefix
    match page:
        case "string_t": print("string_t is a string used by the quark library. It has two fields `to_str` and `len`" + g("string_t src = new_string(\"Hello, World!\");"))
        case "logf": print("logf() is a function used for general purpose printing to the user. It takes at least two arguments. A level, see level_t, and a format. It can also have a variable ammount of extra arguemnts as long as format has format specifier. All output from logf() is sent to stderr" + g("logf(OK \"hello, World!\");"))
        case "level_t": print("level_t is a internal type used in quark. It is intented that the uses called it through the macros of OK, ERR, WARN, INFO, and FATAL." + g("logf(OK \"Hello, World!\"); "))
        case _: print(f"No manual entry for {page}")


if len(sys.argv) < 2:
    quark_help()
if sys.argv[1] == "doc":
    quark_doc()
elif sys.argv[1] == "man":
    quark_man(sys.argv[2])
elif sys.argv[1] == "help":
    quark_help()
else:
    print(f"error: Unreconized argument `{sys.argv[1]}`. ", end="")
    if sys.argv[1][0] in "doc sfipxv":
        print("Did you mean doc?")
    elif sys.argv[1][0] in "man n,sb":
        print("Did you mean man?")
    else:
        print("\nRun `qman help` for the help text.")
