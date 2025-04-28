import sys
import webbrowser
import os
from html.parser import HTMLParser

class QuarkHTMLParser(HTMLParser):
    def __init__(self):
        super().__init__()
        self.in_target = False
        self.current_tag = None
        self.entries = {}
        self.current_title = None
        self.current_content = []

    def handle_starttag(self, tag, attrs):
        if tag in ("h3", "h4"):
            self.in_target = True
            self.current_tag = tag
            self.current_content = []

    def handle_endtag(self, tag):
        if tag in ("h3", "h4") and self.in_target:
            title = ''.join(self.current_content).strip()
            self.entries[title] = ""
            self.current_title = title
            self.in_target = False
        elif self.current_title and tag in ("p", "div", "ul", "ol", "pre"):
            pass  # Continue collecting content if needed

    def handle_data(self, data):
        if self.in_target:
            self.current_content.append(data)
        elif self.current_title:
            # Collect content after heading
            self.entries[self.current_title] += data.strip() + " "

def quark_doc():
    html_path = os.path.join(os.getcwd(), 'index.html')
    if not os.path.isfile(html_path):
        print(f"Could not find {html_path}")
        exit(0)
    original_stderr = os.dup(2)
    devnull = os.open(os.devnull, os.O_WRONLY)
    try:
        os.dup2(devnull, 2)
        webbrowser.open(f'file://{html_path}')
    finally:
        os.dup2(original_stderr, 2)
        os.close(devnull)
    print("Opening docs in your browser")

def quark_help():
    print("Usage: qman [argument] ...\n")
    print("Options:")
    print("  doc\tOpen up a webpage with documentation.")
    print("  man\tGet specific information about a single element of quark. This takes one option of either a function name, type, or macro.")
    print("  help\tPrint this text and exit.")
    exit(0)

def g(src): return f"\n\n#include \"quarks.h\"\n{src}"

def quark_man(page):
    if page[:2] == "q_":
        page = page[2:]  # remove prefix 'q_'
    if page.endswith("()"):
        page = page[:-2]  # remove parens from function

    html_path = os.path.join(os.getcwd(), 'index.html')
    if not os.path.isfile(html_path):
        print(f"Could not find {html_path}")
        exit(1)

    with open(html_path, 'r', encoding='utf-8') as f:
        html_data = f.read()

    parser = QuarkHTMLParser()
    parser.feed(html_data)

    for heading, content in parser.entries.items():
        if heading.startswith("q_"):
            normalized = heading[2:].lower().replace("()", "").replace(" ", "").replace("_", "")
            target = page.lower().replace("()", "").replace(" ", "").replace("_", "")
            if normalized == target:
                print(f"QUARK\n\t{heading} - {' '.join(content.strip().split())}")
                return

    print(f"No manual entry for {page}")

if len(sys.argv) < 2:
    quark_help()
if sys.argv[1] == "doc":
    quark_doc()
elif sys.argv[1] == "man":
    if len(sys.argv) < 3:
        print("error: No page specified for man command.")
        exit(1)
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
