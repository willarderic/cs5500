// Generated from mipl.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link miplParser}.
 */
public interface miplListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link miplParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(miplParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(miplParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#proglbl}.
	 * @param ctx the parse tree
	 */
	void enterProglbl(miplParser.ProglblContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#proglbl}.
	 * @param ctx the parse tree
	 */
	void exitProglbl(miplParser.ProglblContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(miplParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(miplParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#vardecpart}.
	 * @param ctx the parse tree
	 */
	void enterVardecpart(miplParser.VardecpartContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#vardecpart}.
	 * @param ctx the parse tree
	 */
	void exitVardecpart(miplParser.VardecpartContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#vardeclist}.
	 * @param ctx the parse tree
	 */
	void enterVardeclist(miplParser.VardeclistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#vardeclist}.
	 * @param ctx the parse tree
	 */
	void exitVardeclist(miplParser.VardeclistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#vardec}.
	 * @param ctx the parse tree
	 */
	void enterVardec(miplParser.VardecContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#vardec}.
	 * @param ctx the parse tree
	 */
	void exitVardec(miplParser.VardecContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#ident}.
	 * @param ctx the parse tree
	 */
	void enterIdent(miplParser.IdentContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#ident}.
	 * @param ctx the parse tree
	 */
	void exitIdent(miplParser.IdentContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#identlist}.
	 * @param ctx the parse tree
	 */
	void enterIdentlist(miplParser.IdentlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#identlist}.
	 * @param ctx the parse tree
	 */
	void exitIdentlist(miplParser.IdentlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#typez}.
	 * @param ctx the parse tree
	 */
	void enterTypez(miplParser.TypezContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#typez}.
	 * @param ctx the parse tree
	 */
	void exitTypez(miplParser.TypezContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(miplParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(miplParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#idx}.
	 * @param ctx the parse tree
	 */
	void enterIdx(miplParser.IdxContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#idx}.
	 * @param ctx the parse tree
	 */
	void exitIdx(miplParser.IdxContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#idxrange}.
	 * @param ctx the parse tree
	 */
	void enterIdxrange(miplParser.IdxrangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#idxrange}.
	 * @param ctx the parse tree
	 */
	void exitIdxrange(miplParser.IdxrangeContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#simple}.
	 * @param ctx the parse tree
	 */
	void enterSimple(miplParser.SimpleContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#simple}.
	 * @param ctx the parse tree
	 */
	void exitSimple(miplParser.SimpleContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#procdecpart}.
	 * @param ctx the parse tree
	 */
	void enterProcdecpart(miplParser.ProcdecpartContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#procdecpart}.
	 * @param ctx the parse tree
	 */
	void exitProcdecpart(miplParser.ProcdecpartContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#procdec}.
	 * @param ctx the parse tree
	 */
	void enterProcdec(miplParser.ProcdecContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#procdec}.
	 * @param ctx the parse tree
	 */
	void exitProcdec(miplParser.ProcdecContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#prochdr}.
	 * @param ctx the parse tree
	 */
	void enterProchdr(miplParser.ProchdrContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#prochdr}.
	 * @param ctx the parse tree
	 */
	void exitProchdr(miplParser.ProchdrContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#stmtpart}.
	 * @param ctx the parse tree
	 */
	void enterStmtpart(miplParser.StmtpartContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#stmtpart}.
	 * @param ctx the parse tree
	 */
	void exitStmtpart(miplParser.StmtpartContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#compound}.
	 * @param ctx the parse tree
	 */
	void enterCompound(miplParser.CompoundContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#compound}.
	 * @param ctx the parse tree
	 */
	void exitCompound(miplParser.CompoundContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#stmtlist}.
	 * @param ctx the parse tree
	 */
	void enterStmtlist(miplParser.StmtlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#stmtlist}.
	 * @param ctx the parse tree
	 */
	void exitStmtlist(miplParser.StmtlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(miplParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(miplParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#assign}.
	 * @param ctx the parse tree
	 */
	void enterAssign(miplParser.AssignContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#assign}.
	 * @param ctx the parse tree
	 */
	void exitAssign(miplParser.AssignContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#procstmt}.
	 * @param ctx the parse tree
	 */
	void enterProcstmt(miplParser.ProcstmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#procstmt}.
	 * @param ctx the parse tree
	 */
	void exitProcstmt(miplParser.ProcstmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#procident}.
	 * @param ctx the parse tree
	 */
	void enterProcident(miplParser.ProcidentContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#procident}.
	 * @param ctx the parse tree
	 */
	void exitProcident(miplParser.ProcidentContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#read}.
	 * @param ctx the parse tree
	 */
	void enterRead(miplParser.ReadContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#read}.
	 * @param ctx the parse tree
	 */
	void exitRead(miplParser.ReadContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#inputlist}.
	 * @param ctx the parse tree
	 */
	void enterInputlist(miplParser.InputlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#inputlist}.
	 * @param ctx the parse tree
	 */
	void exitInputlist(miplParser.InputlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#inputvar}.
	 * @param ctx the parse tree
	 */
	void enterInputvar(miplParser.InputvarContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#inputvar}.
	 * @param ctx the parse tree
	 */
	void exitInputvar(miplParser.InputvarContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#write}.
	 * @param ctx the parse tree
	 */
	void enterWrite(miplParser.WriteContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#write}.
	 * @param ctx the parse tree
	 */
	void exitWrite(miplParser.WriteContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#outputlist}.
	 * @param ctx the parse tree
	 */
	void enterOutputlist(miplParser.OutputlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#outputlist}.
	 * @param ctx the parse tree
	 */
	void exitOutputlist(miplParser.OutputlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#output}.
	 * @param ctx the parse tree
	 */
	void enterOutput(miplParser.OutputContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#output}.
	 * @param ctx the parse tree
	 */
	void exitOutput(miplParser.OutputContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#condition}.
	 * @param ctx the parse tree
	 */
	void enterCondition(miplParser.ConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#condition}.
	 * @param ctx the parse tree
	 */
	void exitCondition(miplParser.ConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#whileloop}.
	 * @param ctx the parse tree
	 */
	void enterWhileloop(miplParser.WhileloopContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#whileloop}.
	 * @param ctx the parse tree
	 */
	void exitWhileloop(miplParser.WhileloopContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(miplParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(miplParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#simpleexpr}.
	 * @param ctx the parse tree
	 */
	void enterSimpleexpr(miplParser.SimpleexprContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#simpleexpr}.
	 * @param ctx the parse tree
	 */
	void exitSimpleexpr(miplParser.SimpleexprContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#addoplist}.
	 * @param ctx the parse tree
	 */
	void enterAddoplist(miplParser.AddoplistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#addoplist}.
	 * @param ctx the parse tree
	 */
	void exitAddoplist(miplParser.AddoplistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(miplParser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(miplParser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#multoplist}.
	 * @param ctx the parse tree
	 */
	void enterMultoplist(miplParser.MultoplistContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#multoplist}.
	 * @param ctx the parse tree
	 */
	void exitMultoplist(miplParser.MultoplistContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(miplParser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(miplParser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#sign}.
	 * @param ctx the parse tree
	 */
	void enterSign(miplParser.SignContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#sign}.
	 * @param ctx the parse tree
	 */
	void exitSign(miplParser.SignContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#addop}.
	 * @param ctx the parse tree
	 */
	void enterAddop(miplParser.AddopContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#addop}.
	 * @param ctx the parse tree
	 */
	void exitAddop(miplParser.AddopContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#multop}.
	 * @param ctx the parse tree
	 */
	void enterMultop(miplParser.MultopContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#multop}.
	 * @param ctx the parse tree
	 */
	void exitMultop(miplParser.MultopContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#relop}.
	 * @param ctx the parse tree
	 */
	void enterRelop(miplParser.RelopContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#relop}.
	 * @param ctx the parse tree
	 */
	void exitRelop(miplParser.RelopContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(miplParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(miplParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#idxvar}.
	 * @param ctx the parse tree
	 */
	void enterIdxvar(miplParser.IdxvarContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#idxvar}.
	 * @param ctx the parse tree
	 */
	void exitIdxvar(miplParser.IdxvarContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#arrayvar}.
	 * @param ctx the parse tree
	 */
	void enterArrayvar(miplParser.ArrayvarContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#arrayvar}.
	 * @param ctx the parse tree
	 */
	void exitArrayvar(miplParser.ArrayvarContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#entirevar}.
	 * @param ctx the parse tree
	 */
	void enterEntirevar(miplParser.EntirevarContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#entirevar}.
	 * @param ctx the parse tree
	 */
	void exitEntirevar(miplParser.EntirevarContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#varident}.
	 * @param ctx the parse tree
	 */
	void enterVarident(miplParser.VaridentContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#varident}.
	 * @param ctx the parse tree
	 */
	void exitVarident(miplParser.VaridentContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(miplParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(miplParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#intconst}.
	 * @param ctx the parse tree
	 */
	void enterIntconst(miplParser.IntconstContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#intconst}.
	 * @param ctx the parse tree
	 */
	void exitIntconst(miplParser.IntconstContext ctx);
	/**
	 * Enter a parse tree produced by {@link miplParser#boolconst}.
	 * @param ctx the parse tree
	 */
	void enterBoolconst(miplParser.BoolconstContext ctx);
	/**
	 * Exit a parse tree produced by {@link miplParser#boolconst}.
	 * @param ctx the parse tree
	 */
	void exitBoolconst(miplParser.BoolconstContext ctx);
}