grammar mipl;

prog : proglbl i=IDENT j=SCOLON block k=PERIOD {print("prog-> proglbl IDENT SCOLON block PERIOD")}
                {print("  TOKEN: IDENT\t LEXEME:", $i.text)}
                {print("  TOKEN: SCOLON\t LEXEME:", $j.text)}
                {print("  TOKEN: PERIOD\t LEXEME:", $k.text)};
proglbl : i=PROGRAM {print("proglbl -> PROGRAM")}
        {print("  TOKEN: PROGRAM\t LEXEME:", $i.text)};
block : vardecpart procdecpart stmtpart {print("block -> vardecpart procdecpart stmtpart")};
vardecpart : /* epsilon */ {print("vardecpart -> epsilon")}
            | i=VAR vardec j=SCOLON vardeclist {print("vardecpart -> VAR vardec SCOLON vardeclist")}
            {print("  TOKEN: VAR\t LEXEME:", $i.text)}
            {print("  TOKEN: SCOLON\t LEXEME:", $j.text)};
vardeclist : vardec i=SCOLON vardeclist {print("vardeclist -> vardec SCOLON vardeclist")}
            {print("  TOKEN: SCOLON\t LEXEME:", $i.text)}
            | /* epsilon */ {print("vardeclist -> epsilon")};
vardec : ident identlist i=COLON typez {print("vardec -> ident identlist COLON typez")}
        {print("  TOKEN: COLON\t LEXEME:", $i.text)};
ident :  i=IDENT {print("ident -> IDENT")}
         {print("  TOKEN: IDENT\t LEXEME:", $i.text)};
identlist : i=COMMA ident identlist {print("identlist -> COMMA ident identlist")}
            {print("  TOKEN: COMMA\t LEXEME:", $i.text)}
            | /* epsilon */ {print("identlist -> epsilon")};
typez : simple {print("typez -> simple")}
        | array {print("typez -> array")};
array : i=ARRAY j=LBRACKET idxrange k=RBRACKET l=OF simple {print("array -> ARRAY LBRACKET idxrange RBRACKET OF simple")}
        {print("  TOKEN: ARRAY\t LEXEME:", $i.text)}
        {print("  TOKEN: LPAREN\t LEXEME:", $j.text)}
        {print("  TOKEN: RPAREN\t LEXEME:", $k.text)}
        {print("  TOKEN: OF\t LEXEME:", $l.text)};
idx : intconst {print("idx -> intconst")};
idxrange : idx i=DOTDOT idx {print("idxrange -> idx DOTDOT idx")}
        {print("  TOKEN: DOTDOT\t LEXEME:", $i.text)};
simple : i=INTEGER {print("simple -> INTEGER")}
        {print("  TOKEN: INTEGER\t LEXEME:", $i.text)}
        | i=CHAR {print("simple -> CHAR")}
        {print("  TOKEN: CHAR\t LEXEME:", $i.text)}
        | i=BOOLEAN {print("simple -> BOOLEAN")}
        {print("  TOKEN: BOOLEAN\t LEXEME:", $i.text)};
procdecpart : procdec i=SCOLON procdecpart {print("procdecpart -> procdec SCOLON procdecpart")}
        {print("  TOKEN: SCOLON\t LEXEME:", $i.text)}
        | /* epsilon */ {print("procdecpart -> epsilon")};
procdec : prochdr block {print("procdec -> prochdr block")};
prochdr : PROCEDURE IDENT SCOLON {print("prochdr -> PROCEDURE IDENT SCOLON")};
stmtpart : compound {print("stmtpart -> compound")};
compound : i=BEGIN stmt stmtlist j=END {print("compound -> BEGIN stmt stmtlist END")}
           {print("  TOKEN: BEGIN\t LEXEME:", $i.text)}
           {print("  TOKEN: END\t LEXEME:", $j.text)};
stmtlist : i=SCOLON stmt stmtlist {print("stmtlist -> SCOLON stmt stmtlist")}
           {print("  TOKEN: SCOLON\t LEXEME:", $i.text)}
            | /* epsilon */ {print("stmtlist -> epsilon")};
stmt : assign {print("stmt -> assign")}
        | procstmt {print("stmt -> procstmt")}
        | read {print("stmt -> read")}
        | write {print("stmt -> write")}
        | condition {print("stmt -> condition")}
        | whileloop {print("stmt -> whileloop")}
        | compound {print("stmt -> compound")};
assign : variable i=ASSIGN expr {print("assign -> variable ASSIGN expr")}
        {print("  TOKEN: ASSIGN\t LEXEME:", $i.text)};
procstmt : procident {print("procstmt -> procident")};
procident : i=IDENT {print("procident -> IDENT")}
        {print("  TOKEN: IDENT\t LEXEME:", $i.text)}; 
read : i=READ j=LPAREN inputvar inputlist k=RPAREN {print("read -> READ LPAREN inputvar inputlist RPAREN")}
        {print("  TOKEN: READ\t LEXEME:", $i.text)}
        {print("  TOKEN: LPAREN\t LEXEME:", $j.text)}
        {print("  TOKEN: RPAREN\t LEXEME:", $k.text)};
inputlist : i=COMMA inputvar inputlist {print("inputlist -> COMMA inputvar inputlist")}
            {print("  TOKEN: COMMA\t LEXEME:", $i.text)}
            | /* epsilon */ {print("inputlist -> epsilon")};
inputvar : variable {print("inputvar -> variable")};
write : i=WRITE j=LPAREN output outputlist k=RPAREN {print("write -> WRITE LPAREN output outputlist RPAREN")}
        {print("  TOKEN: WRITE\t LEXEME:", $i.text)}
        {print("  TOKEN: LPAREN\t LEXEME:", $j.text)}
        {print("  TOKEN: RPAREN\t LEXEME:", $k.text)};
outputlist : i=COMMA output outputlist {print("outputlist -> COMMA output outputlist")}
                {print("  TOKEN: COMMA\t LEXEME:", $i.text)}
            | /* epsilon */ {print("outputlist -> epsilon")};
output : expr {print("output -> expr")};
condition : i=IF expr j=THEN stmt {print("condition -> IF expr THEN stmt")}
            {print("  TOKEN: IF\t LEXEME:", $i.text)}
            {print("  TOKEN: THEN\t LEXEME:", $j.text)}
            | i=IF expr j=THEN stmt k=ELSE stmt {print("condition -> IF expr THEN stmt ELSE stmt")}
            {print("  TOKEN: IF\t LEXEME:", $i.text)}
            {print("  TOKEN: THEN\t LEXEME:", $j.text)}
            {print("  TOKEN: ELSE\t LEXEME:", $k.text)};
whileloop : i=WHILE expr j=DO stmt {print("whileloop -> WHILE expr DO stmt")};
expr : simpleexpr {print("expr -> simpleexpr")}
        | simpleexpr relop simpleexpr {print("expr -> simpleexpr relop simpleexpr")};
simpleexpr : term addoplist {print("simpleexpr -> term addoplist")};
addoplist : addop term addoplist {print("addoplist -> addop term addoplist")}
            | /* epsilon */ {print("addoplist -> epsilon")};
term : factor multoplist {print("term -> factor multoplist")};
multoplist : multop factor multoplist {print("multoplist -> multop factor multoplist")}
            | /* epsilon */ {print("multoplist -> epsilon")};
factor : sign variable {print("factor -> sign variable")}
        | constant {print("factor -> constant")}
        | i=LPAREN expr j=RPAREN {print("factor -> LPAREN expr RPAREN")}
        {print("  TOKEN: LPAREN\t LEXEME:", $i.text)}
        {print("  TOKEN: RPAREN\t LEXEME:", $j.text)}
        | i=NOT factor {print("factor -> NOT factor")}
        {print("  TOKEN: NOT\t LEXEME:", $i.text)};
sign : i=PLUS {print("sign -> PLUS")}
        {print("  TOKEN: PLUS\t LEXEME:", $i.text)}
        | i=MINUS {print("sign -> MINUS")}
        {print("  TOKEN: MINUS\t LEXEME:", $i.text)}
        | /* epsilon */ {print("sign -> epsilon")};
addop : i=PLUS {print("addop -> PLUS")}
        {print("  TOKEN: PLUS\t LEXEME:", $i.text)}
        | i=MINUS {print("addop -> MINUS")}
        {print("  TOKEN: MINUS\t LEXEME:", $i.text)}
        | i=OR {print("addop -> OR")}
        {print("  TOKEN: OR\t LEXEME:", $i.text)};
multop : i=MULT {print("multop -> MULT")}
        {print("  TOKEN: MULT\t LEXEME:", $i.text)}
        | i=DIV {print("multop -> DIV")}
        {print("  TOKEN: DIV\t LEXEME:", $i.text)}
        | i=AND {print("multop -> AND")}
        {print("  TOKEN: AND\t LEXEME:", $i.text)};
relop : i=LT {print("relop -> LT")}
        {print("  TOKEN: LT\t LEXEME:", $i.text)}
        | i=LEQ {print("relop -> LEQ")}
        {print("  TOKEN: LEQ\t LEXEME:", $i.text)}
        | i=NEQ {print("relop -> NEQ")}
        {print("  TOKEN: NEQ\t LEXEME:", $i.text)}
        | i=EQ {print("relop -> EQ")}
        {print("  TOKEN: EQ\t LEXEME:", $i.text)}
        | i=GT {print("relop -> GT")}
        {print("  TOKEN: GT\t LEXEME:", $i.text)}
        | i=GEQ  {print("relop -> GEQ")}
        {print("  TOKEN: GEQ\t LEXEME:", $i.text)};
variable : entirevar {print("variable -> entirevar")}
            | idxvar {print("variable -> idxvar")};
idxvar : arrayvar LBRACKET expr RBRACKET {print("idxvar -> arrayvar LBRACKET expr RBRACKET")};
arrayvar : entirevar {print("arrayvar -> entirevar")};  
entirevar : varident {print("entirevar -> varident")};
varident : IDENT {print("varident -> IDENT")};
constant : intconst {print("constant -> intconst")}
        | CHARCONST {print("constant -> CHARCONST")}
        | boolconst {print("constant -> boolconst")};
intconst : sign i=INTCONST {print("intconst -> sign VALIDINT")}
                {print("TOKEN: INTCONST\t LEXEME:", $i.text)}
{
if (int($i.text) > 2147483647):
        print($i.text, "Error : integer overflow")
        exit()
};
boolconst : i=TRUE {print("boolconst -> TRUE")}
        {print("  TOKEN: TRUE\t LEXEME:", $i.text)}
            | i=FALSE {print("boolconst -> FALSE")}
            {print("  TOKEN: FALSE\t LEXEME:", $i.text)};

COMMENT : '(*' .*? '*)' -> skip ;
SCOLON : ';' ;
VAR : 'var' ;
IF : 'if' ;
THEN : 'then' ;
ARRAY : 'array' ;
ELSE : 'else' ;
WHILE : 'while' ;
READ : 'read' ;
WRITE : 'write' ;
COLON : ':' ;
DOTDOT : '..' ;
PERIOD : '.' ;
COMMA : ',' ;
LBRACKET : '[' ;
RBRACKET : ']' ;
INTEGER : 'integer' ;
BOOLEAN : 'boolean' ;
CHAR : 'char' ;
BEGIN : 'begin' ;
PROCEDURE : 'procedure' ;
END : 'end' ;
ASSIGN : ':=' ;
LPAREN : '(' ;
RPAREN : ')' ;
DO : 'do' ;
NOT : 'not' ;
TRUE : 'true' ;
FALSE : 'false' ;
LT : '<' ;
LEQ : '<=' ;
GEQ : '>=' ;
GT : '>' ;
EQ : '=' ;
NEQ : '<>' ;
AND : 'and' ;
OR : 'or' ;
DIV : 'div' ;
MULT : '*' ;
PLUS : '+' ;
MINUS : '-' ;
PROGRAM : 'program' ;
OF : 'of' ;
INTCONST : [0-9]+;
IDENT : ('_'|[a-zA-Z])[a-zA-Z0-9_]* ;
CHARCONST : '\''.'\'' ;
WSPACE : [ \t\r\n]+ -> skip ;

