import sys

if len(sys.argv) < 2: vlibc_help()
    
def vlibc_help():
    print("Usage: python3 vman.py [argument] ...\n\n")
    print("Options:")
    print("  doc\tOpen up a webpage with documentation.")
    print("  man\tGet specific information about a single element of vlibc. This takes one option of either a function name, type, or macro")
    print("  help\tPrint this text and exit")
    exit(0)
    
def vlibc_doc():
    print("impl")
    
def vlibc_man(page):
    match page:
        case _: print("Unknown feature.")
    
if sys.argv[1] == "doc": vlibc_doc()
elif sys.argv[1] == "man": vlibc_man(sys.argv[2])
elif sys.argv[1] == "help": vlibc_help()
else:
    print(f"error: Unreconized argument `{sys.argv[1]}`. ", end="")
    if sys.argv[1][0] in "doc sfipxv": print("Did you mean doc?")
    elif sys.argv[1][0] in "man n,sb": print("Did you mean man?")
    else: print("\nRun `python3 vman.py help` for the help text.")
