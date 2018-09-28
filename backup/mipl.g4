/*
 * Lexer rules
 */

grammar mipl;

WSPACE : [ \t\r\n]+ -> skip ;
ALPHA : [a-zA-Z];
IDENT : ('_'|ALPHA)[a-zA-Z0-9_]* ;
INTCONST : ('0'*[1-9][0-9]{0,8})|('0'+) ;
CHARCONST : '"'.'"' ;

proglbl : 'program' ;
prog : proglbl IDENT ';' block ;
block : vardecpart procdecpart stmtpart ;
vardecpart : /* epsilon */
            | 'var' vardec ';' vardeclist ;
vardeclist : vardec ';' vardeclist 
            | /* epsilon */ ;
vardec : ident identlist ':' typez ;
ident :  IDENT;
identlist : ',' ident identlist
            | /* epsilon */ ;
typez : simple 
        | array ;
array : 'array' '[' idxrange ']' 'of' simple ;
idx : intconst ;
idxrange : idx '..' idx ;
simple : 'integer' 
        | 'char'
        | 'boolean' ;
procdecpart : prochdr block ;
prochdr : 'procedure' IDENT ;
stmtpart : compound ;
compound : 'begin' stmt stmtlist 'end' ;
stmtlist : ';' stmt stmtlist
            | /* epsilon */ ;
stmt : assign
        | procstmt
        | read
        | write
        | condition
        | whileloop
        | compound ;
assign : variable ':=' expr ;
procstmt : procident ;
procident : IDENT ;
read : 'read' '(' inputvar inputlist ')' ;
inputlist : ',' inputvar inputlist
            | /* epsilon */ ;
inputvar : variable ;
write : 'write' '(' output outputlist ')' ;
outputlist : ',' output outputlist
            | /* epsilon */ ;
output : expr ;
condition : 'if' expr 'then' stmt
            | 'if' expr 'then' stmt 'else' stmt ;
whileloop : 'while' expr 'do' stmt ;
expr : simpleexpr 
        | simpleexpr relop simpleexpr ;
simpleexpr : term addoplist ;
addoplist : addop term addoplist
            | /* epsilon */ ;
term : factor multoplist ;
multoplist : multop factor multoplist
            | /* epsilon */ ;
factor : sign variable 
        | constant
        | '(' expr ')'
        | 'not' factor ;
sign : '+' 
        | '-'
        | /* epsilon */ ;
addop : '+' 
        | '-'
        | 'or' ;
multop : '*'
        | 'div'
        | 'and' ;
relop : '<'
        | '<='
        | '<>'
        | '='
        | '>'
        | '>=' ;
variable : entirevar 
            | idxvar ;
idxvar : arrayvar '[' expr ']' ;
arrayvar : entirevar ;
entirevar : varident ;
varident : IDENT ;
constant : intconst
        | CHARCONST
        | boolconst ;
intconst : sign INTCONST ;
boolconst : 'true'
            | 'false' ;

