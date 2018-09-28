# Generated from mipl.g4 by ANTLR 4.7.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .miplParser import miplParser
else:
    from miplParser import miplParser

# This class defines a complete listener for a parse tree produced by miplParser.
class miplListener(ParseTreeListener):

    # Enter a parse tree produced by miplParser#prog.
    def enterProg(self, ctx:miplParser.ProgContext):
        pass

    # Exit a parse tree produced by miplParser#prog.
    def exitProg(self, ctx:miplParser.ProgContext):
        pass


    # Enter a parse tree produced by miplParser#proglbl.
    def enterProglbl(self, ctx:miplParser.ProglblContext):
        pass

    # Exit a parse tree produced by miplParser#proglbl.
    def exitProglbl(self, ctx:miplParser.ProglblContext):
        pass


    # Enter a parse tree produced by miplParser#block.
    def enterBlock(self, ctx:miplParser.BlockContext):
        pass

    # Exit a parse tree produced by miplParser#block.
    def exitBlock(self, ctx:miplParser.BlockContext):
        pass


    # Enter a parse tree produced by miplParser#vardecpart.
    def enterVardecpart(self, ctx:miplParser.VardecpartContext):
        pass

    # Exit a parse tree produced by miplParser#vardecpart.
    def exitVardecpart(self, ctx:miplParser.VardecpartContext):
        pass


    # Enter a parse tree produced by miplParser#vardeclist.
    def enterVardeclist(self, ctx:miplParser.VardeclistContext):
        pass

    # Exit a parse tree produced by miplParser#vardeclist.
    def exitVardeclist(self, ctx:miplParser.VardeclistContext):
        pass


    # Enter a parse tree produced by miplParser#vardec.
    def enterVardec(self, ctx:miplParser.VardecContext):
        pass

    # Exit a parse tree produced by miplParser#vardec.
    def exitVardec(self, ctx:miplParser.VardecContext):
        pass


    # Enter a parse tree produced by miplParser#ident.
    def enterIdent(self, ctx:miplParser.IdentContext):
        pass

    # Exit a parse tree produced by miplParser#ident.
    def exitIdent(self, ctx:miplParser.IdentContext):
        pass


    # Enter a parse tree produced by miplParser#identlist.
    def enterIdentlist(self, ctx:miplParser.IdentlistContext):
        pass

    # Exit a parse tree produced by miplParser#identlist.
    def exitIdentlist(self, ctx:miplParser.IdentlistContext):
        pass


    # Enter a parse tree produced by miplParser#typez.
    def enterTypez(self, ctx:miplParser.TypezContext):
        pass

    # Exit a parse tree produced by miplParser#typez.
    def exitTypez(self, ctx:miplParser.TypezContext):
        pass


    # Enter a parse tree produced by miplParser#array.
    def enterArray(self, ctx:miplParser.ArrayContext):
        pass

    # Exit a parse tree produced by miplParser#array.
    def exitArray(self, ctx:miplParser.ArrayContext):
        pass


    # Enter a parse tree produced by miplParser#idx.
    def enterIdx(self, ctx:miplParser.IdxContext):
        pass

    # Exit a parse tree produced by miplParser#idx.
    def exitIdx(self, ctx:miplParser.IdxContext):
        pass


    # Enter a parse tree produced by miplParser#idxrange.
    def enterIdxrange(self, ctx:miplParser.IdxrangeContext):
        pass

    # Exit a parse tree produced by miplParser#idxrange.
    def exitIdxrange(self, ctx:miplParser.IdxrangeContext):
        pass


    # Enter a parse tree produced by miplParser#simple.
    def enterSimple(self, ctx:miplParser.SimpleContext):
        pass

    # Exit a parse tree produced by miplParser#simple.
    def exitSimple(self, ctx:miplParser.SimpleContext):
        pass


    # Enter a parse tree produced by miplParser#procdecpart.
    def enterProcdecpart(self, ctx:miplParser.ProcdecpartContext):
        pass

    # Exit a parse tree produced by miplParser#procdecpart.
    def exitProcdecpart(self, ctx:miplParser.ProcdecpartContext):
        pass


    # Enter a parse tree produced by miplParser#procdec.
    def enterProcdec(self, ctx:miplParser.ProcdecContext):
        pass

    # Exit a parse tree produced by miplParser#procdec.
    def exitProcdec(self, ctx:miplParser.ProcdecContext):
        pass


    # Enter a parse tree produced by miplParser#prochdr.
    def enterProchdr(self, ctx:miplParser.ProchdrContext):
        pass

    # Exit a parse tree produced by miplParser#prochdr.
    def exitProchdr(self, ctx:miplParser.ProchdrContext):
        pass


    # Enter a parse tree produced by miplParser#stmtpart.
    def enterStmtpart(self, ctx:miplParser.StmtpartContext):
        pass

    # Exit a parse tree produced by miplParser#stmtpart.
    def exitStmtpart(self, ctx:miplParser.StmtpartContext):
        pass


    # Enter a parse tree produced by miplParser#compound.
    def enterCompound(self, ctx:miplParser.CompoundContext):
        pass

    # Exit a parse tree produced by miplParser#compound.
    def exitCompound(self, ctx:miplParser.CompoundContext):
        pass


    # Enter a parse tree produced by miplParser#stmtlist.
    def enterStmtlist(self, ctx:miplParser.StmtlistContext):
        pass

    # Exit a parse tree produced by miplParser#stmtlist.
    def exitStmtlist(self, ctx:miplParser.StmtlistContext):
        pass


    # Enter a parse tree produced by miplParser#stmt.
    def enterStmt(self, ctx:miplParser.StmtContext):
        pass

    # Exit a parse tree produced by miplParser#stmt.
    def exitStmt(self, ctx:miplParser.StmtContext):
        pass


    # Enter a parse tree produced by miplParser#assign.
    def enterAssign(self, ctx:miplParser.AssignContext):
        pass

    # Exit a parse tree produced by miplParser#assign.
    def exitAssign(self, ctx:miplParser.AssignContext):
        pass


    # Enter a parse tree produced by miplParser#procstmt.
    def enterProcstmt(self, ctx:miplParser.ProcstmtContext):
        pass

    # Exit a parse tree produced by miplParser#procstmt.
    def exitProcstmt(self, ctx:miplParser.ProcstmtContext):
        pass


    # Enter a parse tree produced by miplParser#procident.
    def enterProcident(self, ctx:miplParser.ProcidentContext):
        pass

    # Exit a parse tree produced by miplParser#procident.
    def exitProcident(self, ctx:miplParser.ProcidentContext):
        pass


    # Enter a parse tree produced by miplParser#read.
    def enterRead(self, ctx:miplParser.ReadContext):
        pass

    # Exit a parse tree produced by miplParser#read.
    def exitRead(self, ctx:miplParser.ReadContext):
        pass


    # Enter a parse tree produced by miplParser#inputlist.
    def enterInputlist(self, ctx:miplParser.InputlistContext):
        pass

    # Exit a parse tree produced by miplParser#inputlist.
    def exitInputlist(self, ctx:miplParser.InputlistContext):
        pass


    # Enter a parse tree produced by miplParser#inputvar.
    def enterInputvar(self, ctx:miplParser.InputvarContext):
        pass

    # Exit a parse tree produced by miplParser#inputvar.
    def exitInputvar(self, ctx:miplParser.InputvarContext):
        pass


    # Enter a parse tree produced by miplParser#write.
    def enterWrite(self, ctx:miplParser.WriteContext):
        pass

    # Exit a parse tree produced by miplParser#write.
    def exitWrite(self, ctx:miplParser.WriteContext):
        pass


    # Enter a parse tree produced by miplParser#outputlist.
    def enterOutputlist(self, ctx:miplParser.OutputlistContext):
        pass

    # Exit a parse tree produced by miplParser#outputlist.
    def exitOutputlist(self, ctx:miplParser.OutputlistContext):
        pass


    # Enter a parse tree produced by miplParser#output.
    def enterOutput(self, ctx:miplParser.OutputContext):
        pass

    # Exit a parse tree produced by miplParser#output.
    def exitOutput(self, ctx:miplParser.OutputContext):
        pass


    # Enter a parse tree produced by miplParser#condition.
    def enterCondition(self, ctx:miplParser.ConditionContext):
        pass

    # Exit a parse tree produced by miplParser#condition.
    def exitCondition(self, ctx:miplParser.ConditionContext):
        pass


    # Enter a parse tree produced by miplParser#whileloop.
    def enterWhileloop(self, ctx:miplParser.WhileloopContext):
        pass

    # Exit a parse tree produced by miplParser#whileloop.
    def exitWhileloop(self, ctx:miplParser.WhileloopContext):
        pass


    # Enter a parse tree produced by miplParser#expr.
    def enterExpr(self, ctx:miplParser.ExprContext):
        pass

    # Exit a parse tree produced by miplParser#expr.
    def exitExpr(self, ctx:miplParser.ExprContext):
        pass


    # Enter a parse tree produced by miplParser#simpleexpr.
    def enterSimpleexpr(self, ctx:miplParser.SimpleexprContext):
        pass

    # Exit a parse tree produced by miplParser#simpleexpr.
    def exitSimpleexpr(self, ctx:miplParser.SimpleexprContext):
        pass


    # Enter a parse tree produced by miplParser#addoplist.
    def enterAddoplist(self, ctx:miplParser.AddoplistContext):
        pass

    # Exit a parse tree produced by miplParser#addoplist.
    def exitAddoplist(self, ctx:miplParser.AddoplistContext):
        pass


    # Enter a parse tree produced by miplParser#term.
    def enterTerm(self, ctx:miplParser.TermContext):
        pass

    # Exit a parse tree produced by miplParser#term.
    def exitTerm(self, ctx:miplParser.TermContext):
        pass


    # Enter a parse tree produced by miplParser#multoplist.
    def enterMultoplist(self, ctx:miplParser.MultoplistContext):
        pass

    # Exit a parse tree produced by miplParser#multoplist.
    def exitMultoplist(self, ctx:miplParser.MultoplistContext):
        pass


    # Enter a parse tree produced by miplParser#factor.
    def enterFactor(self, ctx:miplParser.FactorContext):
        pass

    # Exit a parse tree produced by miplParser#factor.
    def exitFactor(self, ctx:miplParser.FactorContext):
        pass


    # Enter a parse tree produced by miplParser#sign.
    def enterSign(self, ctx:miplParser.SignContext):
        pass

    # Exit a parse tree produced by miplParser#sign.
    def exitSign(self, ctx:miplParser.SignContext):
        pass


    # Enter a parse tree produced by miplParser#addop.
    def enterAddop(self, ctx:miplParser.AddopContext):
        pass

    # Exit a parse tree produced by miplParser#addop.
    def exitAddop(self, ctx:miplParser.AddopContext):
        pass


    # Enter a parse tree produced by miplParser#multop.
    def enterMultop(self, ctx:miplParser.MultopContext):
        pass

    # Exit a parse tree produced by miplParser#multop.
    def exitMultop(self, ctx:miplParser.MultopContext):
        pass


    # Enter a parse tree produced by miplParser#relop.
    def enterRelop(self, ctx:miplParser.RelopContext):
        pass

    # Exit a parse tree produced by miplParser#relop.
    def exitRelop(self, ctx:miplParser.RelopContext):
        pass


    # Enter a parse tree produced by miplParser#variable.
    def enterVariable(self, ctx:miplParser.VariableContext):
        pass

    # Exit a parse tree produced by miplParser#variable.
    def exitVariable(self, ctx:miplParser.VariableContext):
        pass


    # Enter a parse tree produced by miplParser#idxvar.
    def enterIdxvar(self, ctx:miplParser.IdxvarContext):
        pass

    # Exit a parse tree produced by miplParser#idxvar.
    def exitIdxvar(self, ctx:miplParser.IdxvarContext):
        pass


    # Enter a parse tree produced by miplParser#arrayvar.
    def enterArrayvar(self, ctx:miplParser.ArrayvarContext):
        pass

    # Exit a parse tree produced by miplParser#arrayvar.
    def exitArrayvar(self, ctx:miplParser.ArrayvarContext):
        pass


    # Enter a parse tree produced by miplParser#entirevar.
    def enterEntirevar(self, ctx:miplParser.EntirevarContext):
        pass

    # Exit a parse tree produced by miplParser#entirevar.
    def exitEntirevar(self, ctx:miplParser.EntirevarContext):
        pass


    # Enter a parse tree produced by miplParser#varident.
    def enterVarident(self, ctx:miplParser.VaridentContext):
        pass

    # Exit a parse tree produced by miplParser#varident.
    def exitVarident(self, ctx:miplParser.VaridentContext):
        pass


    # Enter a parse tree produced by miplParser#constant.
    def enterConstant(self, ctx:miplParser.ConstantContext):
        pass

    # Exit a parse tree produced by miplParser#constant.
    def exitConstant(self, ctx:miplParser.ConstantContext):
        pass


    # Enter a parse tree produced by miplParser#intconst.
    def enterIntconst(self, ctx:miplParser.IntconstContext):
        pass

    # Exit a parse tree produced by miplParser#intconst.
    def exitIntconst(self, ctx:miplParser.IntconstContext):
        pass


    # Enter a parse tree produced by miplParser#boolconst.
    def enterBoolconst(self, ctx:miplParser.BoolconstContext):
        pass

    # Exit a parse tree produced by miplParser#boolconst.
    def exitBoolconst(self, ctx:miplParser.BoolconstContext):
        pass


