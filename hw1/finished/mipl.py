#!/usr/bin/env python2
from antlr4 import *
from miplLexer import miplLexer
from miplListener import miplListener
from miplParser import miplParser
from antlr4.error.ErrorListener import ErrorListener
import codecs
import sys

# class miplPrintListener(miplListener):
#     ruleNames = []

#     def __init__(self, ruleNames):
#         self.ruleNames = ruleNames

#     # Enter a parse tree produced by miplParser#prog.
#     def enterProg(self, ctx:miplParser.ProgContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#proglbl.
#     def enterProglbl(self, ctx:miplParser.ProglblContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#block.
#     def enterBlock(self, ctx:miplParser.BlockContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#vardecpart.
#     def enterVardecpart(self, ctx:miplParser.VardecpartContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#vardeclist.
#     def enterVardeclist(self, ctx:miplParser.VardeclistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#vardec.
#     def enterVardec(self, ctx:miplParser.VardecContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#ident.
#     def enterIdent(self, ctx:miplParser.IdentContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#identlist.
#     def enterIdentlist(self, ctx:miplParser.IdentlistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#typez.
#     def enterTypez(self, ctx:miplParser.TypezContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#array.
#     def enterArray(self, ctx:miplParser.ArrayContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#idx.
#     def enterIdx(self, ctx:miplParser.IdxContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#idxrange.
#     def enterIdxrange(self, ctx:miplParser.IdxrangeContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#simple.
#     def enterSimple(self, ctx:miplParser.SimpleContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#procdecpart.
#     def enterProcdecpart(self, ctx:miplParser.ProcdecpartContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#procdec.
#     def enterProcdec(self, ctx:miplParser.ProcdecContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#prochdr.
#     def enterProchdr(self, ctx:miplParser.ProchdrContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#stmtpart.
#     def enterStmtpart(self, ctx:miplParser.StmtpartContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#compound.
#     def enterCompound(self, ctx:miplParser.CompoundContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#stmtlist.
#     def enterStmtlist(self, ctx:miplParser.StmtlistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#stmt.
#     def enterStmt(self, ctx:miplParser.StmtContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#assign.
#     def enterAssign(self, ctx:miplParser.AssignContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#procstmt.
#     def enterProcstmt(self, ctx:miplParser.ProcstmtContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#procident.
#     def enterProcident(self, ctx:miplParser.ProcidentContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#read.
#     def enterRead(self, ctx:miplParser.ReadContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#inputlist.
#     def enterInputlist(self, ctx:miplParser.InputlistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#inputvar.
#     def enterInputvar(self, ctx:miplParser.InputvarContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#write.
#     def enterWrite(self, ctx:miplParser.WriteContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#outputlist.
#     def enterOutputlist(self, ctx:miplParser.OutputlistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#output.
#     def enterOutput(self, ctx:miplParser.OutputContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#condition.
#     def enterCondition(self, ctx:miplParser.ConditionContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#whileloop.
#     def enterWhileloop(self, ctx:miplParser.WhileloopContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#expr.
#     def enterExpr(self, ctx:miplParser.ExprContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#simpleexpr.
#     def enterSimpleexpr(self, ctx:miplParser.SimpleexprContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#addoplist.
#     def enterAddoplist(self, ctx:miplParser.AddoplistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#term.
#     def enterTerm(self, ctx:miplParser.TermContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#multoplist.
#     def enterMultoplist(self, ctx:miplParser.MultoplistContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#factor.
#     def enterFactor(self, ctx:miplParser.FactorContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#sign.
#     def enterSign(self, ctx:miplParser.SignContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#addop.
#     def enterAddop(self, ctx:miplParser.AddopContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#multop.
#     def enterMultop(self, ctx:miplParser.MultopContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#relop.
#     def enterRelop(self, ctx:miplParser.RelopContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#variable.
#     def enterVariable(self, ctx:miplParser.VariableContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#idxvar.
#     def enterIdxvar(self, ctx:miplParser.IdxvarContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#arrayvar.
#     def enterArrayvar(self, ctx:miplParser.ArrayvarContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#entirevar.
#     def enterEntirevar(self, ctx:miplParser.EntirevarContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#varident.
#     def enterVarident(self, ctx:miplParser.VaridentContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#constant.
#     def enterConstant(self, ctx:miplParser.ConstantContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#intconst.
#     def enterIntconst(self, ctx:miplParser.IntconstContext):
#         print(self.ruleNames[ctx.getRuleIndex()])

#     # Enter a parse tree produced by miplParser#boolconst.
#     def enterBoolconst(self, ctx:miplParser.BoolconstContext):
#         print(self.ruleNames[ctx.getRuleIndex()])


class MyErrorListener( ErrorListener ):

    def __init__(self):
        super(MyErrorListener, self).__init__()

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        raise Exception("SYNTAX ERROR ON LINE " + str(line) + "!!! \n" + " --> What the heck is '" +offendingSymbol.text + "' ?")


def main(argv):
    lexer = miplLexer(FileStream(argv[1]))
    stream = CommonTokenStream(lexer)
    parser = miplParser(stream)
    parser._listeners = [ MyErrorListener() ]
    tree = parser.prog()

if __name__ == '__main__':
    main(sys.argv)