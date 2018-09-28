// Generated from mipl.g4 by ANTLR 4.7.1
// jshint ignore: start
var antlr4 = require('antlr4/index');

// This class defines a complete listener for a parse tree produced by miplParser.
function miplListener() {
	antlr4.tree.ParseTreeListener.call(this);
	return this;
}

miplListener.prototype = Object.create(antlr4.tree.ParseTreeListener.prototype);
miplListener.prototype.constructor = miplListener;

// Enter a parse tree produced by miplParser#proglbl.
miplListener.prototype.enterProglbl = function(ctx) {
};

// Exit a parse tree produced by miplParser#proglbl.
miplListener.prototype.exitProglbl = function(ctx) {
};


// Enter a parse tree produced by miplParser#prog.
miplListener.prototype.enterProg = function(ctx) {
};

// Exit a parse tree produced by miplParser#prog.
miplListener.prototype.exitProg = function(ctx) {
};


// Enter a parse tree produced by miplParser#block.
miplListener.prototype.enterBlock = function(ctx) {
};

// Exit a parse tree produced by miplParser#block.
miplListener.prototype.exitBlock = function(ctx) {
};


// Enter a parse tree produced by miplParser#vardecpart.
miplListener.prototype.enterVardecpart = function(ctx) {
};

// Exit a parse tree produced by miplParser#vardecpart.
miplListener.prototype.exitVardecpart = function(ctx) {
};


// Enter a parse tree produced by miplParser#vardeclist.
miplListener.prototype.enterVardeclist = function(ctx) {
};

// Exit a parse tree produced by miplParser#vardeclist.
miplListener.prototype.exitVardeclist = function(ctx) {
};


// Enter a parse tree produced by miplParser#vardec.
miplListener.prototype.enterVardec = function(ctx) {
};

// Exit a parse tree produced by miplParser#vardec.
miplListener.prototype.exitVardec = function(ctx) {
};


// Enter a parse tree produced by miplParser#ident.
miplListener.prototype.enterIdent = function(ctx) {
};

// Exit a parse tree produced by miplParser#ident.
miplListener.prototype.exitIdent = function(ctx) {
};


// Enter a parse tree produced by miplParser#identlist.
miplListener.prototype.enterIdentlist = function(ctx) {
};

// Exit a parse tree produced by miplParser#identlist.
miplListener.prototype.exitIdentlist = function(ctx) {
};


// Enter a parse tree produced by miplParser#typez.
miplListener.prototype.enterTypez = function(ctx) {
};

// Exit a parse tree produced by miplParser#typez.
miplListener.prototype.exitTypez = function(ctx) {
};


// Enter a parse tree produced by miplParser#array.
miplListener.prototype.enterArray = function(ctx) {
};

// Exit a parse tree produced by miplParser#array.
miplListener.prototype.exitArray = function(ctx) {
};


// Enter a parse tree produced by miplParser#idx.
miplListener.prototype.enterIdx = function(ctx) {
};

// Exit a parse tree produced by miplParser#idx.
miplListener.prototype.exitIdx = function(ctx) {
};


// Enter a parse tree produced by miplParser#idxrange.
miplListener.prototype.enterIdxrange = function(ctx) {
};

// Exit a parse tree produced by miplParser#idxrange.
miplListener.prototype.exitIdxrange = function(ctx) {
};


// Enter a parse tree produced by miplParser#simple.
miplListener.prototype.enterSimple = function(ctx) {
};

// Exit a parse tree produced by miplParser#simple.
miplListener.prototype.exitSimple = function(ctx) {
};


// Enter a parse tree produced by miplParser#procdecpart.
miplListener.prototype.enterProcdecpart = function(ctx) {
};

// Exit a parse tree produced by miplParser#procdecpart.
miplListener.prototype.exitProcdecpart = function(ctx) {
};


// Enter a parse tree produced by miplParser#prochdr.
miplListener.prototype.enterProchdr = function(ctx) {
};

// Exit a parse tree produced by miplParser#prochdr.
miplListener.prototype.exitProchdr = function(ctx) {
};


// Enter a parse tree produced by miplParser#stmtpart.
miplListener.prototype.enterStmtpart = function(ctx) {
};

// Exit a parse tree produced by miplParser#stmtpart.
miplListener.prototype.exitStmtpart = function(ctx) {
};


// Enter a parse tree produced by miplParser#compound.
miplListener.prototype.enterCompound = function(ctx) {
};

// Exit a parse tree produced by miplParser#compound.
miplListener.prototype.exitCompound = function(ctx) {
};


// Enter a parse tree produced by miplParser#stmtlist.
miplListener.prototype.enterStmtlist = function(ctx) {
};

// Exit a parse tree produced by miplParser#stmtlist.
miplListener.prototype.exitStmtlist = function(ctx) {
};


// Enter a parse tree produced by miplParser#stmt.
miplListener.prototype.enterStmt = function(ctx) {
};

// Exit a parse tree produced by miplParser#stmt.
miplListener.prototype.exitStmt = function(ctx) {
};


// Enter a parse tree produced by miplParser#assign.
miplListener.prototype.enterAssign = function(ctx) {
};

// Exit a parse tree produced by miplParser#assign.
miplListener.prototype.exitAssign = function(ctx) {
};


// Enter a parse tree produced by miplParser#procstmt.
miplListener.prototype.enterProcstmt = function(ctx) {
};

// Exit a parse tree produced by miplParser#procstmt.
miplListener.prototype.exitProcstmt = function(ctx) {
};


// Enter a parse tree produced by miplParser#procident.
miplListener.prototype.enterProcident = function(ctx) {
};

// Exit a parse tree produced by miplParser#procident.
miplListener.prototype.exitProcident = function(ctx) {
};


// Enter a parse tree produced by miplParser#read.
miplListener.prototype.enterRead = function(ctx) {
};

// Exit a parse tree produced by miplParser#read.
miplListener.prototype.exitRead = function(ctx) {
};


// Enter a parse tree produced by miplParser#inputlist.
miplListener.prototype.enterInputlist = function(ctx) {
};

// Exit a parse tree produced by miplParser#inputlist.
miplListener.prototype.exitInputlist = function(ctx) {
};


// Enter a parse tree produced by miplParser#inputvar.
miplListener.prototype.enterInputvar = function(ctx) {
};

// Exit a parse tree produced by miplParser#inputvar.
miplListener.prototype.exitInputvar = function(ctx) {
};


// Enter a parse tree produced by miplParser#write.
miplListener.prototype.enterWrite = function(ctx) {
};

// Exit a parse tree produced by miplParser#write.
miplListener.prototype.exitWrite = function(ctx) {
};


// Enter a parse tree produced by miplParser#outputlist.
miplListener.prototype.enterOutputlist = function(ctx) {
};

// Exit a parse tree produced by miplParser#outputlist.
miplListener.prototype.exitOutputlist = function(ctx) {
};


// Enter a parse tree produced by miplParser#output.
miplListener.prototype.enterOutput = function(ctx) {
};

// Exit a parse tree produced by miplParser#output.
miplListener.prototype.exitOutput = function(ctx) {
};


// Enter a parse tree produced by miplParser#condition.
miplListener.prototype.enterCondition = function(ctx) {
};

// Exit a parse tree produced by miplParser#condition.
miplListener.prototype.exitCondition = function(ctx) {
};


// Enter a parse tree produced by miplParser#whileloop.
miplListener.prototype.enterWhileloop = function(ctx) {
};

// Exit a parse tree produced by miplParser#whileloop.
miplListener.prototype.exitWhileloop = function(ctx) {
};


// Enter a parse tree produced by miplParser#expr.
miplListener.prototype.enterExpr = function(ctx) {
};

// Exit a parse tree produced by miplParser#expr.
miplListener.prototype.exitExpr = function(ctx) {
};


// Enter a parse tree produced by miplParser#simpleexpr.
miplListener.prototype.enterSimpleexpr = function(ctx) {
};

// Exit a parse tree produced by miplParser#simpleexpr.
miplListener.prototype.exitSimpleexpr = function(ctx) {
};


// Enter a parse tree produced by miplParser#addoplist.
miplListener.prototype.enterAddoplist = function(ctx) {
};

// Exit a parse tree produced by miplParser#addoplist.
miplListener.prototype.exitAddoplist = function(ctx) {
};


// Enter a parse tree produced by miplParser#term.
miplListener.prototype.enterTerm = function(ctx) {
};

// Exit a parse tree produced by miplParser#term.
miplListener.prototype.exitTerm = function(ctx) {
};


// Enter a parse tree produced by miplParser#multoplist.
miplListener.prototype.enterMultoplist = function(ctx) {
};

// Exit a parse tree produced by miplParser#multoplist.
miplListener.prototype.exitMultoplist = function(ctx) {
};


// Enter a parse tree produced by miplParser#factor.
miplListener.prototype.enterFactor = function(ctx) {
};

// Exit a parse tree produced by miplParser#factor.
miplListener.prototype.exitFactor = function(ctx) {
};


// Enter a parse tree produced by miplParser#sign.
miplListener.prototype.enterSign = function(ctx) {
};

// Exit a parse tree produced by miplParser#sign.
miplListener.prototype.exitSign = function(ctx) {
};


// Enter a parse tree produced by miplParser#addop.
miplListener.prototype.enterAddop = function(ctx) {
};

// Exit a parse tree produced by miplParser#addop.
miplListener.prototype.exitAddop = function(ctx) {
};


// Enter a parse tree produced by miplParser#multop.
miplListener.prototype.enterMultop = function(ctx) {
};

// Exit a parse tree produced by miplParser#multop.
miplListener.prototype.exitMultop = function(ctx) {
};


// Enter a parse tree produced by miplParser#relop.
miplListener.prototype.enterRelop = function(ctx) {
};

// Exit a parse tree produced by miplParser#relop.
miplListener.prototype.exitRelop = function(ctx) {
};


// Enter a parse tree produced by miplParser#variable.
miplListener.prototype.enterVariable = function(ctx) {
};

// Exit a parse tree produced by miplParser#variable.
miplListener.prototype.exitVariable = function(ctx) {
};


// Enter a parse tree produced by miplParser#idxvar.
miplListener.prototype.enterIdxvar = function(ctx) {
};

// Exit a parse tree produced by miplParser#idxvar.
miplListener.prototype.exitIdxvar = function(ctx) {
};


// Enter a parse tree produced by miplParser#arrayvar.
miplListener.prototype.enterArrayvar = function(ctx) {
};

// Exit a parse tree produced by miplParser#arrayvar.
miplListener.prototype.exitArrayvar = function(ctx) {
};


// Enter a parse tree produced by miplParser#entirevar.
miplListener.prototype.enterEntirevar = function(ctx) {
};

// Exit a parse tree produced by miplParser#entirevar.
miplListener.prototype.exitEntirevar = function(ctx) {
};


// Enter a parse tree produced by miplParser#varident.
miplListener.prototype.enterVarident = function(ctx) {
};

// Exit a parse tree produced by miplParser#varident.
miplListener.prototype.exitVarident = function(ctx) {
};


// Enter a parse tree produced by miplParser#constant.
miplListener.prototype.enterConstant = function(ctx) {
};

// Exit a parse tree produced by miplParser#constant.
miplListener.prototype.exitConstant = function(ctx) {
};


// Enter a parse tree produced by miplParser#intconst.
miplListener.prototype.enterIntconst = function(ctx) {
};

// Exit a parse tree produced by miplParser#intconst.
miplListener.prototype.exitIntconst = function(ctx) {
};


// Enter a parse tree produced by miplParser#boolconst.
miplListener.prototype.enterBoolconst = function(ctx) {
};

// Exit a parse tree produced by miplParser#boolconst.
miplListener.prototype.exitBoolconst = function(ctx) {
};



exports.miplListener = miplListener;