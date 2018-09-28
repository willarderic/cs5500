#!/usr/bin/env python2s
from antlr4 import *
from miplLexer import miplLexer
from miplListener import miplListener
from miplParser import miplParser
import sys

class miplPrintListener(miplListener):
    def enterHi(self, ctx):
        print("Hello: %s" % ctx.ID())

def main():
    lexer = miplLexer(StdinStream())
    stream = CommonTokenStream(lexer)
    parser = miplParser(stream)
    tree = parser.prog()
    printer = miplPrintListener()
    walker = ParseTreeWalker()
    walker.walk(printer, tree)

if __name__ == '__main__':
    main()