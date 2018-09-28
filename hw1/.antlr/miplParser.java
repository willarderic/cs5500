// Generated from /Users/ewillard/dev/school/cs5500/hw1/mipl.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class miplParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		COMMENT=1, SCOLON=2, VAR=3, IF=4, THEN=5, ARRAY=6, ELSE=7, WHILE=8, READ=9, 
		WRITE=10, COLON=11, DOTDOT=12, PERIOD=13, COMMA=14, LBRACKET=15, RBRACKET=16, 
		INTEGER=17, BOOLEAN=18, CHAR=19, BEGIN=20, PROCEDURE=21, END=22, ASSIGN=23, 
		LPAREN=24, RPAREN=25, DO=26, NOT=27, TRUE=28, FALSE=29, LT=30, LEQ=31, 
		GEQ=32, GT=33, EQ=34, NEQ=35, AND=36, OR=37, DIV=38, MULT=39, PLUS=40, 
		MINUS=41, PROGRAM=42, OF=43, INTCONST=44, IDENT=45, CHARCONST=46, WSPACE=47;
	public static final int
		RULE_prog = 0, RULE_proglbl = 1, RULE_block = 2, RULE_vardecpart = 3, 
		RULE_vardeclist = 4, RULE_vardec = 5, RULE_ident = 6, RULE_identlist = 7, 
		RULE_typez = 8, RULE_array = 9, RULE_idx = 10, RULE_idxrange = 11, RULE_simple = 12, 
		RULE_procdecpart = 13, RULE_procdec = 14, RULE_prochdr = 15, RULE_stmtpart = 16, 
		RULE_compound = 17, RULE_stmtlist = 18, RULE_stmt = 19, RULE_assign = 20, 
		RULE_procstmt = 21, RULE_procident = 22, RULE_read = 23, RULE_inputlist = 24, 
		RULE_inputvar = 25, RULE_write = 26, RULE_outputlist = 27, RULE_output = 28, 
		RULE_condition = 29, RULE_whileloop = 30, RULE_expr = 31, RULE_simpleexpr = 32, 
		RULE_addoplist = 33, RULE_term = 34, RULE_multoplist = 35, RULE_factor = 36, 
		RULE_sign = 37, RULE_addop = 38, RULE_multop = 39, RULE_relop = 40, RULE_variable = 41, 
		RULE_idxvar = 42, RULE_arrayvar = 43, RULE_entirevar = 44, RULE_varident = 45, 
		RULE_constant = 46, RULE_intconst = 47, RULE_boolconst = 48;
	public static final String[] ruleNames = {
		"prog", "proglbl", "block", "vardecpart", "vardeclist", "vardec", "ident", 
		"identlist", "typez", "array", "idx", "idxrange", "simple", "procdecpart", 
		"procdec", "prochdr", "stmtpart", "compound", "stmtlist", "stmt", "assign", 
		"procstmt", "procident", "read", "inputlist", "inputvar", "write", "outputlist", 
		"output", "condition", "whileloop", "expr", "simpleexpr", "addoplist", 
		"term", "multoplist", "factor", "sign", "addop", "multop", "relop", "variable", 
		"idxvar", "arrayvar", "entirevar", "varident", "constant", "intconst", 
		"boolconst"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, "';'", "'var'", "'if'", "'then'", "'array'", "'else'", "'while'", 
		"'read'", "'write'", "':'", "'..'", "'.'", "','", "'['", "']'", "'integer'", 
		"'boolean'", "'char'", "'begin'", "'procedure'", "'end'", "':='", "'('", 
		"')'", "'do'", "'not'", "'true'", "'false'", "'<'", "'<='", "'>='", "'>'", 
		"'='", "'<>'", "'and'", "'or'", "'div'", "'*'", "'+'", "'-'", "'program'", 
		"'of'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "COMMENT", "SCOLON", "VAR", "IF", "THEN", "ARRAY", "ELSE", "WHILE", 
		"READ", "WRITE", "COLON", "DOTDOT", "PERIOD", "COMMA", "LBRACKET", "RBRACKET", 
		"INTEGER", "BOOLEAN", "CHAR", "BEGIN", "PROCEDURE", "END", "ASSIGN", "LPAREN", 
		"RPAREN", "DO", "NOT", "TRUE", "FALSE", "LT", "LEQ", "GEQ", "GT", "EQ", 
		"NEQ", "AND", "OR", "DIV", "MULT", "PLUS", "MINUS", "PROGRAM", "OF", "INTCONST", 
		"IDENT", "CHARCONST", "WSPACE"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "mipl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public miplParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public Token k;
		public ProglblContext proglbl() {
			return getRuleContext(ProglblContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public TerminalNode PERIOD() { return getToken(miplParser.PERIOD, 0); }
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(98);
			proglbl();
			setState(99);
			((ProgContext)_localctx).i = match(IDENT);
			setState(100);
			((ProgContext)_localctx).j = match(SCOLON);
			setState(101);
			block();
			setState(102);
			((ProgContext)_localctx).k = match(PERIOD);
			print("prog-> proglbl IDENT SCOLON block PERIOD")
			print("  TOKEN: IDENT\t LEXEME:", (((ProgContext)_localctx).i!=null?((ProgContext)_localctx).i.getText():null))
			print("  TOKEN: SCOLON\t LEXEME:", (((ProgContext)_localctx).j!=null?((ProgContext)_localctx).j.getText():null))
			print("  TOKEN: PERIOD\t LEXEME:", (((ProgContext)_localctx).k!=null?((ProgContext)_localctx).k.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProglblContext extends ParserRuleContext {
		public Token i;
		public TerminalNode PROGRAM() { return getToken(miplParser.PROGRAM, 0); }
		public ProglblContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proglbl; }
	}

	public final ProglblContext proglbl() throws RecognitionException {
		ProglblContext _localctx = new ProglblContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_proglbl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			((ProglblContext)_localctx).i = match(PROGRAM);
			print("proglbl -> PROGRAM")
			print("  TOKEN: PROGRAM\t LEXEME:", (((ProglblContext)_localctx).i!=null?((ProglblContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public VardecpartContext vardecpart() {
			return getRuleContext(VardecpartContext.class,0);
		}
		public ProcdecpartContext procdecpart() {
			return getRuleContext(ProcdecpartContext.class,0);
		}
		public StmtpartContext stmtpart() {
			return getRuleContext(StmtpartContext.class,0);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(112);
			vardecpart();
			setState(113);
			procdecpart();
			setState(114);
			stmtpart();
			print("block -> vardecpart procdecpart stmtpart")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardecpartContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public VardecContext vardec() {
			return getRuleContext(VardecContext.class,0);
		}
		public VardeclistContext vardeclist() {
			return getRuleContext(VardeclistContext.class,0);
		}
		public TerminalNode VAR() { return getToken(miplParser.VAR, 0); }
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public VardecpartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecpart; }
	}

	public final VardecpartContext vardecpart() throws RecognitionException {
		VardecpartContext _localctx = new VardecpartContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_vardecpart);
		try {
			setState(126);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BEGIN:
			case PROCEDURE:
				enterOuterAlt(_localctx, 1);
				{
				print("vardecpart -> epsilon")
				}
				break;
			case VAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(118);
				((VardecpartContext)_localctx).i = match(VAR);
				setState(119);
				vardec();
				setState(120);
				((VardecpartContext)_localctx).j = match(SCOLON);
				setState(121);
				vardeclist();
				print("vardecpart -> VAR vardec SCOLON vardeclist")
				print("  TOKEN: VAR\t LEXEME:", (((VardecpartContext)_localctx).i!=null?((VardecpartContext)_localctx).i.getText():null))
				print("  TOKEN: SCOLON\t LEXEME:", (((VardecpartContext)_localctx).j!=null?((VardecpartContext)_localctx).j.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardeclistContext extends ParserRuleContext {
		public Token i;
		public VardecContext vardec() {
			return getRuleContext(VardecContext.class,0);
		}
		public VardeclistContext vardeclist() {
			return getRuleContext(VardeclistContext.class,0);
		}
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public VardeclistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardeclist; }
	}

	public final VardeclistContext vardeclist() throws RecognitionException {
		VardeclistContext _localctx = new VardeclistContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_vardeclist);
		try {
			setState(135);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(128);
				vardec();
				setState(129);
				((VardeclistContext)_localctx).i = match(SCOLON);
				setState(130);
				vardeclist();
				print("vardeclist -> vardec SCOLON vardeclist")
				print("  TOKEN: SCOLON\t LEXEME:", (((VardeclistContext)_localctx).i!=null?((VardeclistContext)_localctx).i.getText():null))
				}
				break;
			case BEGIN:
			case PROCEDURE:
				enterOuterAlt(_localctx, 2);
				{
				print("vardeclist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardecContext extends ParserRuleContext {
		public Token i;
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public IdentlistContext identlist() {
			return getRuleContext(IdentlistContext.class,0);
		}
		public TypezContext typez() {
			return getRuleContext(TypezContext.class,0);
		}
		public TerminalNode COLON() { return getToken(miplParser.COLON, 0); }
		public VardecContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardec; }
	}

	public final VardecContext vardec() throws RecognitionException {
		VardecContext _localctx = new VardecContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_vardec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(137);
			ident();
			setState(138);
			identlist();
			setState(139);
			((VardecContext)_localctx).i = match(COLON);
			setState(140);
			typez();
			print("vardec -> ident identlist COLON typez")
			print("  TOKEN: COLON\t LEXEME:", (((VardecContext)_localctx).i!=null?((VardecContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentContext extends ParserRuleContext {
		public Token i;
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_ident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(144);
			((IdentContext)_localctx).i = match(IDENT);
			print("ident -> IDENT")
			print("  TOKEN: IDENT\t LEXEME:", (((IdentContext)_localctx).i!=null?((IdentContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentlistContext extends ParserRuleContext {
		public Token i;
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public IdentlistContext identlist() {
			return getRuleContext(IdentlistContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(miplParser.COMMA, 0); }
		public IdentlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identlist; }
	}

	public final IdentlistContext identlist() throws RecognitionException {
		IdentlistContext _localctx = new IdentlistContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_identlist);
		try {
			setState(155);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case COMMA:
				enterOuterAlt(_localctx, 1);
				{
				setState(148);
				((IdentlistContext)_localctx).i = match(COMMA);
				setState(149);
				ident();
				setState(150);
				identlist();
				print("identlist -> COMMA ident identlist")
				print("  TOKEN: COMMA\t LEXEME:", (((IdentlistContext)_localctx).i!=null?((IdentlistContext)_localctx).i.getText():null))
				}
				break;
			case COLON:
				enterOuterAlt(_localctx, 2);
				{
				print("identlist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypezContext extends ParserRuleContext {
		public SimpleContext simple() {
			return getRuleContext(SimpleContext.class,0);
		}
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public TypezContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typez; }
	}

	public final TypezContext typez() throws RecognitionException {
		TypezContext _localctx = new TypezContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_typez);
		try {
			setState(163);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INTEGER:
			case BOOLEAN:
			case CHAR:
				enterOuterAlt(_localctx, 1);
				{
				setState(157);
				simple();
				print("typez -> simple")
				}
				break;
			case ARRAY:
				enterOuterAlt(_localctx, 2);
				{
				setState(160);
				array();
				print("typez -> array")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public Token k;
		public Token l;
		public IdxrangeContext idxrange() {
			return getRuleContext(IdxrangeContext.class,0);
		}
		public SimpleContext simple() {
			return getRuleContext(SimpleContext.class,0);
		}
		public TerminalNode ARRAY() { return getToken(miplParser.ARRAY, 0); }
		public TerminalNode LBRACKET() { return getToken(miplParser.LBRACKET, 0); }
		public TerminalNode RBRACKET() { return getToken(miplParser.RBRACKET, 0); }
		public TerminalNode OF() { return getToken(miplParser.OF, 0); }
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_array);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(165);
			((ArrayContext)_localctx).i = match(ARRAY);
			setState(166);
			((ArrayContext)_localctx).j = match(LBRACKET);
			setState(167);
			idxrange();
			setState(168);
			((ArrayContext)_localctx).k = match(RBRACKET);
			setState(169);
			((ArrayContext)_localctx).l = match(OF);
			setState(170);
			simple();
			print("array -> ARRAY LBRACKET idxrange RBRACKET OF simple")
			print("  TOKEN: ARRAY\t LEXEME:", (((ArrayContext)_localctx).i!=null?((ArrayContext)_localctx).i.getText():null))
			print("  TOKEN: LPAREN\t LEXEME:", (((ArrayContext)_localctx).j!=null?((ArrayContext)_localctx).j.getText():null))
			print("  TOKEN: RPAREN\t LEXEME:", (((ArrayContext)_localctx).k!=null?((ArrayContext)_localctx).k.getText():null))
			print("  TOKEN: OF\t LEXEME:", (((ArrayContext)_localctx).l!=null?((ArrayContext)_localctx).l.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdxContext extends ParserRuleContext {
		public IntconstContext intconst() {
			return getRuleContext(IntconstContext.class,0);
		}
		public IdxContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idx; }
	}

	public final IdxContext idx() throws RecognitionException {
		IdxContext _localctx = new IdxContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_idx);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			intconst();
			print("idx -> intconst")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdxrangeContext extends ParserRuleContext {
		public Token i;
		public List<IdxContext> idx() {
			return getRuleContexts(IdxContext.class);
		}
		public IdxContext idx(int i) {
			return getRuleContext(IdxContext.class,i);
		}
		public TerminalNode DOTDOT() { return getToken(miplParser.DOTDOT, 0); }
		public IdxrangeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idxrange; }
	}

	public final IdxrangeContext idxrange() throws RecognitionException {
		IdxrangeContext _localctx = new IdxrangeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_idxrange);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(180);
			idx();
			setState(181);
			((IdxrangeContext)_localctx).i = match(DOTDOT);
			setState(182);
			idx();
			print("idxrange -> idx DOTDOT idx")
			print("  TOKEN: DOTDOT\t LEXEME:", (((IdxrangeContext)_localctx).i!=null?((IdxrangeContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleContext extends ParserRuleContext {
		public Token i;
		public TerminalNode INTEGER() { return getToken(miplParser.INTEGER, 0); }
		public TerminalNode CHAR() { return getToken(miplParser.CHAR, 0); }
		public TerminalNode BOOLEAN() { return getToken(miplParser.BOOLEAN, 0); }
		public SimpleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple; }
	}

	public final SimpleContext simple() throws RecognitionException {
		SimpleContext _localctx = new SimpleContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_simple);
		try {
			setState(195);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INTEGER:
				enterOuterAlt(_localctx, 1);
				{
				setState(186);
				((SimpleContext)_localctx).i = match(INTEGER);
				print("simple -> INTEGER")
				print("  TOKEN: INTEGER\t LEXEME:", (((SimpleContext)_localctx).i!=null?((SimpleContext)_localctx).i.getText():null))
				}
				break;
			case CHAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(189);
				((SimpleContext)_localctx).i = match(CHAR);
				print("simple -> CHAR")
				print("  TOKEN: CHAR\t LEXEME:", (((SimpleContext)_localctx).i!=null?((SimpleContext)_localctx).i.getText():null))
				}
				break;
			case BOOLEAN:
				enterOuterAlt(_localctx, 3);
				{
				setState(192);
				((SimpleContext)_localctx).i = match(BOOLEAN);
				print("simple -> BOOLEAN")
				print("  TOKEN: BOOLEAN\t LEXEME:", (((SimpleContext)_localctx).i!=null?((SimpleContext)_localctx).i.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcdecpartContext extends ParserRuleContext {
		public Token i;
		public ProcdecContext procdec() {
			return getRuleContext(ProcdecContext.class,0);
		}
		public ProcdecpartContext procdecpart() {
			return getRuleContext(ProcdecpartContext.class,0);
		}
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public ProcdecpartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procdecpart; }
	}

	public final ProcdecpartContext procdecpart() throws RecognitionException {
		ProcdecpartContext _localctx = new ProcdecpartContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_procdecpart);
		try {
			setState(204);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PROCEDURE:
				enterOuterAlt(_localctx, 1);
				{
				setState(197);
				procdec();
				setState(198);
				((ProcdecpartContext)_localctx).i = match(SCOLON);
				setState(199);
				procdecpart();
				print("procdecpart -> procdec SCOLON procdecpart")
				print("  TOKEN: SCOLON\t LEXEME:", (((ProcdecpartContext)_localctx).i!=null?((ProcdecpartContext)_localctx).i.getText():null))
				}
				break;
			case BEGIN:
				enterOuterAlt(_localctx, 2);
				{
				print("procdecpart -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcdecContext extends ParserRuleContext {
		public ProchdrContext prochdr() {
			return getRuleContext(ProchdrContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ProcdecContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procdec; }
	}

	public final ProcdecContext procdec() throws RecognitionException {
		ProcdecContext _localctx = new ProcdecContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_procdec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			prochdr();
			setState(207);
			block();
			print("procdec -> prochdr block")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProchdrContext extends ParserRuleContext {
		public TerminalNode PROCEDURE() { return getToken(miplParser.PROCEDURE, 0); }
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public ProchdrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prochdr; }
	}

	public final ProchdrContext prochdr() throws RecognitionException {
		ProchdrContext _localctx = new ProchdrContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_prochdr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(210);
			match(PROCEDURE);
			setState(211);
			match(IDENT);
			setState(212);
			match(SCOLON);
			print("prochdr -> PROCEDURE IDENT SCOLON")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtpartContext extends ParserRuleContext {
		public CompoundContext compound() {
			return getRuleContext(CompoundContext.class,0);
		}
		public StmtpartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmtpart; }
	}

	public final StmtpartContext stmtpart() throws RecognitionException {
		StmtpartContext _localctx = new StmtpartContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_stmtpart);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			compound();
			print("stmtpart -> compound")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompoundContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public StmtlistContext stmtlist() {
			return getRuleContext(StmtlistContext.class,0);
		}
		public TerminalNode BEGIN() { return getToken(miplParser.BEGIN, 0); }
		public TerminalNode END() { return getToken(miplParser.END, 0); }
		public CompoundContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound; }
	}

	public final CompoundContext compound() throws RecognitionException {
		CompoundContext _localctx = new CompoundContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_compound);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			((CompoundContext)_localctx).i = match(BEGIN);
			setState(219);
			stmt();
			setState(220);
			stmtlist();
			setState(221);
			((CompoundContext)_localctx).j = match(END);
			print("compound -> BEGIN stmt stmtlist END")
			print("  TOKEN: BEGIN\t LEXEME:", (((CompoundContext)_localctx).i!=null?((CompoundContext)_localctx).i.getText():null))
			print("  TOKEN: END\t LEXEME:", (((CompoundContext)_localctx).j!=null?((CompoundContext)_localctx).j.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtlistContext extends ParserRuleContext {
		public Token i;
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public StmtlistContext stmtlist() {
			return getRuleContext(StmtlistContext.class,0);
		}
		public TerminalNode SCOLON() { return getToken(miplParser.SCOLON, 0); }
		public StmtlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmtlist; }
	}

	public final StmtlistContext stmtlist() throws RecognitionException {
		StmtlistContext _localctx = new StmtlistContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_stmtlist);
		try {
			setState(233);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SCOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(226);
				((StmtlistContext)_localctx).i = match(SCOLON);
				setState(227);
				stmt();
				setState(228);
				stmtlist();
				print("stmtlist -> SCOLON stmt stmtlist")
				print("  TOKEN: SCOLON\t LEXEME:", (((StmtlistContext)_localctx).i!=null?((StmtlistContext)_localctx).i.getText():null))
				}
				break;
			case END:
				enterOuterAlt(_localctx, 2);
				{
				print("stmtlist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public AssignContext assign() {
			return getRuleContext(AssignContext.class,0);
		}
		public ProcstmtContext procstmt() {
			return getRuleContext(ProcstmtContext.class,0);
		}
		public ReadContext read() {
			return getRuleContext(ReadContext.class,0);
		}
		public WriteContext write() {
			return getRuleContext(WriteContext.class,0);
		}
		public ConditionContext condition() {
			return getRuleContext(ConditionContext.class,0);
		}
		public WhileloopContext whileloop() {
			return getRuleContext(WhileloopContext.class,0);
		}
		public CompoundContext compound() {
			return getRuleContext(CompoundContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_stmt);
		try {
			setState(256);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(235);
				assign();
				print("stmt -> assign")
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(238);
				procstmt();
				print("stmt -> procstmt")
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(241);
				read();
				print("stmt -> read")
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(244);
				write();
				print("stmt -> write")
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(247);
				condition();
				print("stmt -> condition")
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(250);
				whileloop();
				print("stmt -> whileloop")
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(253);
				compound();
				print("stmt -> compound")
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignContext extends ParserRuleContext {
		public Token i;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(miplParser.ASSIGN, 0); }
		public AssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign; }
	}

	public final AssignContext assign() throws RecognitionException {
		AssignContext _localctx = new AssignContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_assign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(258);
			variable();
			setState(259);
			((AssignContext)_localctx).i = match(ASSIGN);
			setState(260);
			expr();
			print("assign -> variable ASSIGN expr")
			print("  TOKEN: ASSIGN\t LEXEME:", (((AssignContext)_localctx).i!=null?((AssignContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcstmtContext extends ParserRuleContext {
		public ProcidentContext procident() {
			return getRuleContext(ProcidentContext.class,0);
		}
		public ProcstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procstmt; }
	}

	public final ProcstmtContext procstmt() throws RecognitionException {
		ProcstmtContext _localctx = new ProcstmtContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_procstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(264);
			procident();
			print("procstmt -> procident")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcidentContext extends ParserRuleContext {
		public Token i;
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public ProcidentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procident; }
	}

	public final ProcidentContext procident() throws RecognitionException {
		ProcidentContext _localctx = new ProcidentContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_procident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(267);
			((ProcidentContext)_localctx).i = match(IDENT);
			print("procident -> IDENT")
			print("  TOKEN: IDENT\t LEXEME:", (((ProcidentContext)_localctx).i!=null?((ProcidentContext)_localctx).i.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReadContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public Token k;
		public InputvarContext inputvar() {
			return getRuleContext(InputvarContext.class,0);
		}
		public InputlistContext inputlist() {
			return getRuleContext(InputlistContext.class,0);
		}
		public TerminalNode READ() { return getToken(miplParser.READ, 0); }
		public TerminalNode LPAREN() { return getToken(miplParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(miplParser.RPAREN, 0); }
		public ReadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_read; }
	}

	public final ReadContext read() throws RecognitionException {
		ReadContext _localctx = new ReadContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_read);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(271);
			((ReadContext)_localctx).i = match(READ);
			setState(272);
			((ReadContext)_localctx).j = match(LPAREN);
			setState(273);
			inputvar();
			setState(274);
			inputlist();
			setState(275);
			((ReadContext)_localctx).k = match(RPAREN);
			print("read -> READ LPAREN inputvar inputlist RPAREN")
			print("  TOKEN: READ\t LEXEME:", (((ReadContext)_localctx).i!=null?((ReadContext)_localctx).i.getText():null))
			print("  TOKEN: LPAREN\t LEXEME:", (((ReadContext)_localctx).j!=null?((ReadContext)_localctx).j.getText():null))
			print("  TOKEN: RPAREN\t LEXEME:", (((ReadContext)_localctx).k!=null?((ReadContext)_localctx).k.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InputlistContext extends ParserRuleContext {
		public Token i;
		public InputvarContext inputvar() {
			return getRuleContext(InputvarContext.class,0);
		}
		public InputlistContext inputlist() {
			return getRuleContext(InputlistContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(miplParser.COMMA, 0); }
		public InputlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inputlist; }
	}

	public final InputlistContext inputlist() throws RecognitionException {
		InputlistContext _localctx = new InputlistContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_inputlist);
		try {
			setState(288);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case COMMA:
				enterOuterAlt(_localctx, 1);
				{
				setState(281);
				((InputlistContext)_localctx).i = match(COMMA);
				setState(282);
				inputvar();
				setState(283);
				inputlist();
				print("inputlist -> COMMA inputvar inputlist")
				print("  TOKEN: COMMA\t LEXEME:", (((InputlistContext)_localctx).i!=null?((InputlistContext)_localctx).i.getText():null))
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				print("inputlist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InputvarContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public InputvarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inputvar; }
	}

	public final InputvarContext inputvar() throws RecognitionException {
		InputvarContext _localctx = new InputvarContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_inputvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(290);
			variable();
			print("inputvar -> variable")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WriteContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public Token k;
		public OutputContext output() {
			return getRuleContext(OutputContext.class,0);
		}
		public OutputlistContext outputlist() {
			return getRuleContext(OutputlistContext.class,0);
		}
		public TerminalNode WRITE() { return getToken(miplParser.WRITE, 0); }
		public TerminalNode LPAREN() { return getToken(miplParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(miplParser.RPAREN, 0); }
		public WriteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_write; }
	}

	public final WriteContext write() throws RecognitionException {
		WriteContext _localctx = new WriteContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_write);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(293);
			((WriteContext)_localctx).i = match(WRITE);
			setState(294);
			((WriteContext)_localctx).j = match(LPAREN);
			setState(295);
			output();
			setState(296);
			outputlist();
			setState(297);
			((WriteContext)_localctx).k = match(RPAREN);
			print("write -> WRITE LPAREN output outputlist RPAREN")
			print("  TOKEN: WRITE\t LEXEME:", (((WriteContext)_localctx).i!=null?((WriteContext)_localctx).i.getText():null))
			print("  TOKEN: LPAREN\t LEXEME:", (((WriteContext)_localctx).j!=null?((WriteContext)_localctx).j.getText():null))
			print("  TOKEN: RPAREN\t LEXEME:", (((WriteContext)_localctx).k!=null?((WriteContext)_localctx).k.getText():null))
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OutputlistContext extends ParserRuleContext {
		public Token i;
		public OutputContext output() {
			return getRuleContext(OutputContext.class,0);
		}
		public OutputlistContext outputlist() {
			return getRuleContext(OutputlistContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(miplParser.COMMA, 0); }
		public OutputlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_outputlist; }
	}

	public final OutputlistContext outputlist() throws RecognitionException {
		OutputlistContext _localctx = new OutputlistContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_outputlist);
		try {
			setState(310);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case COMMA:
				enterOuterAlt(_localctx, 1);
				{
				setState(303);
				((OutputlistContext)_localctx).i = match(COMMA);
				setState(304);
				output();
				setState(305);
				outputlist();
				print("outputlist -> COMMA output outputlist")
				print("  TOKEN: COMMA\t LEXEME:", (((OutputlistContext)_localctx).i!=null?((OutputlistContext)_localctx).i.getText():null))
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				print("outputlist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OutputContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public OutputContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_output; }
	}

	public final OutputContext output() throws RecognitionException {
		OutputContext _localctx = new OutputContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_output);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			expr();
			print("output -> expr")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConditionContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public Token k;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode IF() { return getToken(miplParser.IF, 0); }
		public TerminalNode THEN() { return getToken(miplParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(miplParser.ELSE, 0); }
		public ConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condition; }
	}

	public final ConditionContext condition() throws RecognitionException {
		ConditionContext _localctx = new ConditionContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_condition);
		try {
			setState(334);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(315);
				((ConditionContext)_localctx).i = match(IF);
				setState(316);
				expr();
				setState(317);
				((ConditionContext)_localctx).j = match(THEN);
				setState(318);
				stmt();
				print("condition -> IF expr THEN stmt")
				print("  TOKEN: IF\t LEXEME:", (((ConditionContext)_localctx).i!=null?((ConditionContext)_localctx).i.getText():null))
				print("  TOKEN: THEN\t LEXEME:", (((ConditionContext)_localctx).j!=null?((ConditionContext)_localctx).j.getText():null))
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(323);
				((ConditionContext)_localctx).i = match(IF);
				setState(324);
				expr();
				setState(325);
				((ConditionContext)_localctx).j = match(THEN);
				setState(326);
				stmt();
				setState(327);
				((ConditionContext)_localctx).k = match(ELSE);
				setState(328);
				stmt();
				print("condition -> IF expr THEN stmt ELSE stmt")
				print("  TOKEN: IF\t LEXEME:", (((ConditionContext)_localctx).i!=null?((ConditionContext)_localctx).i.getText():null))
				print("  TOKEN: THEN\t LEXEME:", (((ConditionContext)_localctx).j!=null?((ConditionContext)_localctx).j.getText():null))
				print("  TOKEN: ELSE\t LEXEME:", (((ConditionContext)_localctx).k!=null?((ConditionContext)_localctx).k.getText():null))
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileloopContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public TerminalNode WHILE() { return getToken(miplParser.WHILE, 0); }
		public TerminalNode DO() { return getToken(miplParser.DO, 0); }
		public WhileloopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileloop; }
	}

	public final WhileloopContext whileloop() throws RecognitionException {
		WhileloopContext _localctx = new WhileloopContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_whileloop);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(336);
			((WhileloopContext)_localctx).i = match(WHILE);
			setState(337);
			expr();
			setState(338);
			((WhileloopContext)_localctx).j = match(DO);
			setState(339);
			stmt();
			print("whileloop -> WHILE expr DO stmt")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public List<SimpleexprContext> simpleexpr() {
			return getRuleContexts(SimpleexprContext.class);
		}
		public SimpleexprContext simpleexpr(int i) {
			return getRuleContext(SimpleexprContext.class,i);
		}
		public RelopContext relop() {
			return getRuleContext(RelopContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_expr);
		try {
			setState(350);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(342);
				simpleexpr();
				print("expr -> simpleexpr")
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(345);
				simpleexpr();
				setState(346);
				relop();
				setState(347);
				simpleexpr();
				print("expr -> simpleexpr relop simpleexpr")
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleexprContext extends ParserRuleContext {
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public AddoplistContext addoplist() {
			return getRuleContext(AddoplistContext.class,0);
		}
		public SimpleexprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleexpr; }
	}

	public final SimpleexprContext simpleexpr() throws RecognitionException {
		SimpleexprContext _localctx = new SimpleexprContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_simpleexpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(352);
			term();
			setState(353);
			addoplist();
			print("simpleexpr -> term addoplist")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AddoplistContext extends ParserRuleContext {
		public AddopContext addop() {
			return getRuleContext(AddopContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public AddoplistContext addoplist() {
			return getRuleContext(AddoplistContext.class,0);
		}
		public AddoplistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addoplist; }
	}

	public final AddoplistContext addoplist() throws RecognitionException {
		AddoplistContext _localctx = new AddoplistContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_addoplist);
		try {
			setState(362);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OR:
			case PLUS:
			case MINUS:
				enterOuterAlt(_localctx, 1);
				{
				setState(356);
				addop();
				setState(357);
				term();
				setState(358);
				addoplist();
				print("addoplist -> addop term addoplist")
				}
				break;
			case SCOLON:
			case THEN:
			case ELSE:
			case COMMA:
			case RBRACKET:
			case END:
			case RPAREN:
			case DO:
			case LT:
			case LEQ:
			case GEQ:
			case GT:
			case EQ:
			case NEQ:
				enterOuterAlt(_localctx, 2);
				{
				print("addoplist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TermContext extends ParserRuleContext {
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public MultoplistContext multoplist() {
			return getRuleContext(MultoplistContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_term);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(364);
			factor();
			setState(365);
			multoplist();
			print("term -> factor multoplist")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MultoplistContext extends ParserRuleContext {
		public MultopContext multop() {
			return getRuleContext(MultopContext.class,0);
		}
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public MultoplistContext multoplist() {
			return getRuleContext(MultoplistContext.class,0);
		}
		public MultoplistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multoplist; }
	}

	public final MultoplistContext multoplist() throws RecognitionException {
		MultoplistContext _localctx = new MultoplistContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_multoplist);
		try {
			setState(374);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AND:
			case DIV:
			case MULT:
				enterOuterAlt(_localctx, 1);
				{
				setState(368);
				multop();
				setState(369);
				factor();
				setState(370);
				multoplist();
				print("multoplist -> multop factor multoplist")
				}
				break;
			case SCOLON:
			case THEN:
			case ELSE:
			case COMMA:
			case RBRACKET:
			case END:
			case RPAREN:
			case DO:
			case LT:
			case LEQ:
			case GEQ:
			case GT:
			case EQ:
			case NEQ:
			case OR:
			case PLUS:
			case MINUS:
				enterOuterAlt(_localctx, 2);
				{
				print("multoplist -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FactorContext extends ParserRuleContext {
		public Token i;
		public Token j;
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(miplParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(miplParser.RPAREN, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public TerminalNode NOT() { return getToken(miplParser.NOT, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_factor);
		try {
			setState(395);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(376);
				sign();
				setState(377);
				variable();
				print("factor -> sign variable")
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(380);
				constant();
				print("factor -> constant")
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(383);
				((FactorContext)_localctx).i = match(LPAREN);
				setState(384);
				expr();
				setState(385);
				((FactorContext)_localctx).j = match(RPAREN);
				print("factor -> LPAREN expr RPAREN")
				print("  TOKEN: LPAREN\t LEXEME:", (((FactorContext)_localctx).i!=null?((FactorContext)_localctx).i.getText():null))
				print("  TOKEN: RPAREN\t LEXEME:", (((FactorContext)_localctx).j!=null?((FactorContext)_localctx).j.getText():null))
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(390);
				((FactorContext)_localctx).i = match(NOT);
				setState(391);
				factor();
				print("factor -> NOT factor")
				print("  TOKEN: NOT\t LEXEME:", (((FactorContext)_localctx).i!=null?((FactorContext)_localctx).i.getText():null))
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignContext extends ParserRuleContext {
		public Token i;
		public TerminalNode PLUS() { return getToken(miplParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(miplParser.MINUS, 0); }
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_sign);
		try {
			setState(404);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PLUS:
				enterOuterAlt(_localctx, 1);
				{
				setState(397);
				((SignContext)_localctx).i = match(PLUS);
				print("sign -> PLUS")
				print("  TOKEN: PLUS\t LEXEME:", (((SignContext)_localctx).i!=null?((SignContext)_localctx).i.getText():null))
				}
				break;
			case MINUS:
				enterOuterAlt(_localctx, 2);
				{
				setState(400);
				((SignContext)_localctx).i = match(MINUS);
				print("sign -> MINUS")
				print("  TOKEN: MINUS\t LEXEME:", (((SignContext)_localctx).i!=null?((SignContext)_localctx).i.getText():null))
				}
				break;
			case INTCONST:
			case IDENT:
				enterOuterAlt(_localctx, 3);
				{
				print("sign -> epsilon")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AddopContext extends ParserRuleContext {
		public Token i;
		public TerminalNode PLUS() { return getToken(miplParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(miplParser.MINUS, 0); }
		public TerminalNode OR() { return getToken(miplParser.OR, 0); }
		public AddopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addop; }
	}

	public final AddopContext addop() throws RecognitionException {
		AddopContext _localctx = new AddopContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_addop);
		try {
			setState(415);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PLUS:
				enterOuterAlt(_localctx, 1);
				{
				setState(406);
				((AddopContext)_localctx).i = match(PLUS);
				print("addop -> PLUS")
				print("  TOKEN: PLUS\t LEXEME:", (((AddopContext)_localctx).i!=null?((AddopContext)_localctx).i.getText():null))
				}
				break;
			case MINUS:
				enterOuterAlt(_localctx, 2);
				{
				setState(409);
				((AddopContext)_localctx).i = match(MINUS);
				print("addop -> MINUS")
				print("  TOKEN: MINUS\t LEXEME:", (((AddopContext)_localctx).i!=null?((AddopContext)_localctx).i.getText():null))
				}
				break;
			case OR:
				enterOuterAlt(_localctx, 3);
				{
				setState(412);
				((AddopContext)_localctx).i = match(OR);
				print("addop -> OR")
				print("  TOKEN: OR\t LEXEME:", (((AddopContext)_localctx).i!=null?((AddopContext)_localctx).i.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MultopContext extends ParserRuleContext {
		public Token i;
		public TerminalNode MULT() { return getToken(miplParser.MULT, 0); }
		public TerminalNode DIV() { return getToken(miplParser.DIV, 0); }
		public TerminalNode AND() { return getToken(miplParser.AND, 0); }
		public MultopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multop; }
	}

	public final MultopContext multop() throws RecognitionException {
		MultopContext _localctx = new MultopContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_multop);
		try {
			setState(426);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MULT:
				enterOuterAlt(_localctx, 1);
				{
				setState(417);
				((MultopContext)_localctx).i = match(MULT);
				print("multop -> MULT")
				print("  TOKEN: MULT\t LEXEME:", (((MultopContext)_localctx).i!=null?((MultopContext)_localctx).i.getText():null))
				}
				break;
			case DIV:
				enterOuterAlt(_localctx, 2);
				{
				setState(420);
				((MultopContext)_localctx).i = match(DIV);
				print("multop -> DIV")
				print("  TOKEN: DIV\t LEXEME:", (((MultopContext)_localctx).i!=null?((MultopContext)_localctx).i.getText():null))
				}
				break;
			case AND:
				enterOuterAlt(_localctx, 3);
				{
				setState(423);
				((MultopContext)_localctx).i = match(AND);
				print("multop -> AND")
				print("  TOKEN: AND\t LEXEME:", (((MultopContext)_localctx).i!=null?((MultopContext)_localctx).i.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelopContext extends ParserRuleContext {
		public Token i;
		public TerminalNode LT() { return getToken(miplParser.LT, 0); }
		public TerminalNode LEQ() { return getToken(miplParser.LEQ, 0); }
		public TerminalNode NEQ() { return getToken(miplParser.NEQ, 0); }
		public TerminalNode EQ() { return getToken(miplParser.EQ, 0); }
		public TerminalNode GT() { return getToken(miplParser.GT, 0); }
		public TerminalNode GEQ() { return getToken(miplParser.GEQ, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_relop);
		try {
			setState(446);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LT:
				enterOuterAlt(_localctx, 1);
				{
				setState(428);
				((RelopContext)_localctx).i = match(LT);
				print("relop -> LT")
				print("  TOKEN: LT\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			case LEQ:
				enterOuterAlt(_localctx, 2);
				{
				setState(431);
				((RelopContext)_localctx).i = match(LEQ);
				print("relop -> LEQ")
				print("  TOKEN: LEQ\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			case NEQ:
				enterOuterAlt(_localctx, 3);
				{
				setState(434);
				((RelopContext)_localctx).i = match(NEQ);
				print("relop -> NEQ")
				print("  TOKEN: NEQ\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			case EQ:
				enterOuterAlt(_localctx, 4);
				{
				setState(437);
				((RelopContext)_localctx).i = match(EQ);
				print("relop -> EQ")
				print("  TOKEN: EQ\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			case GT:
				enterOuterAlt(_localctx, 5);
				{
				setState(440);
				((RelopContext)_localctx).i = match(GT);
				print("relop -> GT")
				print("  TOKEN: GT\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			case GEQ:
				enterOuterAlt(_localctx, 6);
				{
				setState(443);
				((RelopContext)_localctx).i = match(GEQ);
				print("relop -> GEQ")
				print("  TOKEN: GEQ\t LEXEME:", (((RelopContext)_localctx).i!=null?((RelopContext)_localctx).i.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableContext extends ParserRuleContext {
		public EntirevarContext entirevar() {
			return getRuleContext(EntirevarContext.class,0);
		}
		public IdxvarContext idxvar() {
			return getRuleContext(IdxvarContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_variable);
		try {
			setState(454);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(448);
				entirevar();
				print("variable -> entirevar")
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(451);
				idxvar();
				print("variable -> idxvar")
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdxvarContext extends ParserRuleContext {
		public ArrayvarContext arrayvar() {
			return getRuleContext(ArrayvarContext.class,0);
		}
		public TerminalNode LBRACKET() { return getToken(miplParser.LBRACKET, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RBRACKET() { return getToken(miplParser.RBRACKET, 0); }
		public IdxvarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idxvar; }
	}

	public final IdxvarContext idxvar() throws RecognitionException {
		IdxvarContext _localctx = new IdxvarContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_idxvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(456);
			arrayvar();
			setState(457);
			match(LBRACKET);
			setState(458);
			expr();
			setState(459);
			match(RBRACKET);
			print("idxvar -> arrayvar LBRACKET expr RBRACKET")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayvarContext extends ParserRuleContext {
		public EntirevarContext entirevar() {
			return getRuleContext(EntirevarContext.class,0);
		}
		public ArrayvarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayvar; }
	}

	public final ArrayvarContext arrayvar() throws RecognitionException {
		ArrayvarContext _localctx = new ArrayvarContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_arrayvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(462);
			entirevar();
			print("arrayvar -> entirevar")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EntirevarContext extends ParserRuleContext {
		public VaridentContext varident() {
			return getRuleContext(VaridentContext.class,0);
		}
		public EntirevarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_entirevar; }
	}

	public final EntirevarContext entirevar() throws RecognitionException {
		EntirevarContext _localctx = new EntirevarContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_entirevar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(465);
			varident();
			print("entirevar -> varident")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VaridentContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public VaridentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varident; }
	}

	public final VaridentContext varident() throws RecognitionException {
		VaridentContext _localctx = new VaridentContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_varident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(468);
			match(IDENT);
			print("varident -> IDENT")
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public IntconstContext intconst() {
			return getRuleContext(IntconstContext.class,0);
		}
		public TerminalNode CHARCONST() { return getToken(miplParser.CHARCONST, 0); }
		public BoolconstContext boolconst() {
			return getRuleContext(BoolconstContext.class,0);
		}
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_constant);
		try {
			setState(479);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PLUS:
			case MINUS:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(471);
				intconst();
				print("constant -> intconst")
				}
				break;
			case CHARCONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(474);
				match(CHARCONST);
				print("constant -> CHARCONST")
				}
				break;
			case TRUE:
			case FALSE:
				enterOuterAlt(_localctx, 3);
				{
				setState(476);
				boolconst();
				print("constant -> boolconst")
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntconstContext extends ParserRuleContext {
		public Token i;
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public TerminalNode INTCONST() { return getToken(miplParser.INTCONST, 0); }
		public IntconstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intconst; }
	}

	public final IntconstContext intconst() throws RecognitionException {
		IntconstContext _localctx = new IntconstContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_intconst);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(481);
			sign();
			setState(482);
			((IntconstContext)_localctx).i = match(INTCONST);
			print("intconst -> sign VALIDINT")
			print("TOKEN: INTCONST\t LEXEME:", (((IntconstContext)_localctx).i!=null?((IntconstContext)_localctx).i.getText():null))

			if (int((((IntconstContext)_localctx).i!=null?((IntconstContext)_localctx).i.getText():null)) > 2147483647):
			        print((((IntconstContext)_localctx).i!=null?((IntconstContext)_localctx).i.getText():null), "Error : integer overflow")
			        exit()

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BoolconstContext extends ParserRuleContext {
		public Token i;
		public TerminalNode TRUE() { return getToken(miplParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(miplParser.FALSE, 0); }
		public BoolconstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolconst; }
	}

	public final BoolconstContext boolconst() throws RecognitionException {
		BoolconstContext _localctx = new BoolconstContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_boolconst);
		try {
			setState(493);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(487);
				((BoolconstContext)_localctx).i = match(TRUE);
				print("boolconst -> TRUE")
				print("  TOKEN: TRUE\t LEXEME:", (((BoolconstContext)_localctx).i!=null?((BoolconstContext)_localctx).i.getText():null))
				}
				break;
			case FALSE:
				enterOuterAlt(_localctx, 2);
				{
				setState(490);
				((BoolconstContext)_localctx).i = match(FALSE);
				print("boolconst -> FALSE")
				print("  TOKEN: FALSE\t LEXEME:", (((BoolconstContext)_localctx).i!=null?((BoolconstContext)_localctx).i.getText():null))
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\61\u01f2\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\5\5\u0081\n\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6"+
		"\u008a\n\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\5\t\u009e\n\t\3\n\3\n\3\n\3\n\3\n\3\n\5\n\u00a6\n\n\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3"+
		"\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\5"+
		"\16\u00c6\n\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00cf\n\17\3\20"+
		"\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\22\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\24\3\24\5\24\u00ec"+
		"\n\24\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25"+
		"\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\5\25\u0103\n\25\3\26\3\26\3\26"+
		"\3\26\3\26\3\26\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\3\32\5\32"+
		"\u0123\n\32\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34"+
		"\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\5\35\u0139\n\35\3\36\3\36\3\36"+
		"\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37"+
		"\3\37\3\37\3\37\3\37\3\37\5\37\u0151\n\37\3 \3 \3 \3 \3 \3 \3!\3!\3!\3"+
		"!\3!\3!\3!\3!\5!\u0161\n!\3\"\3\"\3\"\3\"\3#\3#\3#\3#\3#\3#\5#\u016d\n"+
		"#\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\5%\u0179\n%\3&\3&\3&\3&\3&\3&\3&\3&\3"+
		"&\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\5&\u018e\n&\3\'\3\'\3\'\3\'\3\'\3\'\3"+
		"\'\5\'\u0197\n\'\3(\3(\3(\3(\3(\3(\3(\3(\3(\5(\u01a2\n(\3)\3)\3)\3)\3"+
		")\3)\3)\3)\3)\5)\u01ad\n)\3*\3*\3*\3*\3*\3*\3*\3*\3*\3*\3*\3*\3*\3*\3"+
		"*\3*\3*\3*\5*\u01c1\n*\3+\3+\3+\3+\3+\3+\5+\u01c9\n+\3,\3,\3,\3,\3,\3"+
		",\3-\3-\3-\3.\3.\3.\3/\3/\3/\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\5"+
		"\60\u01e2\n\60\3\61\3\61\3\61\3\61\3\61\3\61\3\62\3\62\3\62\3\62\3\62"+
		"\3\62\5\62\u01f0\n\62\3\62\2\2\63\2\4\6\b\n\f\16\20\22\24\26\30\32\34"+
		"\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`b\2\2\2\u01e6\2d\3\2\2\2"+
		"\4n\3\2\2\2\6r\3\2\2\2\b\u0080\3\2\2\2\n\u0089\3\2\2\2\f\u008b\3\2\2\2"+
		"\16\u0092\3\2\2\2\20\u009d\3\2\2\2\22\u00a5\3\2\2\2\24\u00a7\3\2\2\2\26"+
		"\u00b3\3\2\2\2\30\u00b6\3\2\2\2\32\u00c5\3\2\2\2\34\u00ce\3\2\2\2\36\u00d0"+
		"\3\2\2\2 \u00d4\3\2\2\2\"\u00d9\3\2\2\2$\u00dc\3\2\2\2&\u00eb\3\2\2\2"+
		"(\u0102\3\2\2\2*\u0104\3\2\2\2,\u010a\3\2\2\2.\u010d\3\2\2\2\60\u0111"+
		"\3\2\2\2\62\u0122\3\2\2\2\64\u0124\3\2\2\2\66\u0127\3\2\2\28\u0138\3\2"+
		"\2\2:\u013a\3\2\2\2<\u0150\3\2\2\2>\u0152\3\2\2\2@\u0160\3\2\2\2B\u0162"+
		"\3\2\2\2D\u016c\3\2\2\2F\u016e\3\2\2\2H\u0178\3\2\2\2J\u018d\3\2\2\2L"+
		"\u0196\3\2\2\2N\u01a1\3\2\2\2P\u01ac\3\2\2\2R\u01c0\3\2\2\2T\u01c8\3\2"+
		"\2\2V\u01ca\3\2\2\2X\u01d0\3\2\2\2Z\u01d3\3\2\2\2\\\u01d6\3\2\2\2^\u01e1"+
		"\3\2\2\2`\u01e3\3\2\2\2b\u01ef\3\2\2\2de\5\4\3\2ef\7/\2\2fg\7\4\2\2gh"+
		"\5\6\4\2hi\7\17\2\2ij\b\2\1\2jk\b\2\1\2kl\b\2\1\2lm\b\2\1\2m\3\3\2\2\2"+
		"no\7,\2\2op\b\3\1\2pq\b\3\1\2q\5\3\2\2\2rs\5\b\5\2st\5\34\17\2tu\5\"\22"+
		"\2uv\b\4\1\2v\7\3\2\2\2w\u0081\b\5\1\2xy\7\5\2\2yz\5\f\7\2z{\7\4\2\2{"+
		"|\5\n\6\2|}\b\5\1\2}~\b\5\1\2~\177\b\5\1\2\177\u0081\3\2\2\2\u0080w\3"+
		"\2\2\2\u0080x\3\2\2\2\u0081\t\3\2\2\2\u0082\u0083\5\f\7\2\u0083\u0084"+
		"\7\4\2\2\u0084\u0085\5\n\6\2\u0085\u0086\b\6\1\2\u0086\u0087\b\6\1\2\u0087"+
		"\u008a\3\2\2\2\u0088\u008a\b\6\1\2\u0089\u0082\3\2\2\2\u0089\u0088\3\2"+
		"\2\2\u008a\13\3\2\2\2\u008b\u008c\5\16\b\2\u008c\u008d\5\20\t\2\u008d"+
		"\u008e\7\r\2\2\u008e\u008f\5\22\n\2\u008f\u0090\b\7\1\2\u0090\u0091\b"+
		"\7\1\2\u0091\r\3\2\2\2\u0092\u0093\7/\2\2\u0093\u0094\b\b\1\2\u0094\u0095"+
		"\b\b\1\2\u0095\17\3\2\2\2\u0096\u0097\7\20\2\2\u0097\u0098\5\16\b\2\u0098"+
		"\u0099\5\20\t\2\u0099\u009a\b\t\1\2\u009a\u009b\b\t\1\2\u009b\u009e\3"+
		"\2\2\2\u009c\u009e\b\t\1\2\u009d\u0096\3\2\2\2\u009d\u009c\3\2\2\2\u009e"+
		"\21\3\2\2\2\u009f\u00a0\5\32\16\2\u00a0\u00a1\b\n\1\2\u00a1\u00a6\3\2"+
		"\2\2\u00a2\u00a3\5\24\13\2\u00a3\u00a4\b\n\1\2\u00a4\u00a6\3\2\2\2\u00a5"+
		"\u009f\3\2\2\2\u00a5\u00a2\3\2\2\2\u00a6\23\3\2\2\2\u00a7\u00a8\7\b\2"+
		"\2\u00a8\u00a9\7\21\2\2\u00a9\u00aa\5\30\r\2\u00aa\u00ab\7\22\2\2\u00ab"+
		"\u00ac\7-\2\2\u00ac\u00ad\5\32\16\2\u00ad\u00ae\b\13\1\2\u00ae\u00af\b"+
		"\13\1\2\u00af\u00b0\b\13\1\2\u00b0\u00b1\b\13\1\2\u00b1\u00b2\b\13\1\2"+
		"\u00b2\25\3\2\2\2\u00b3\u00b4\5`\61\2\u00b4\u00b5\b\f\1\2\u00b5\27\3\2"+
		"\2\2\u00b6\u00b7\5\26\f\2\u00b7\u00b8\7\16\2\2\u00b8\u00b9\5\26\f\2\u00b9"+
		"\u00ba\b\r\1\2\u00ba\u00bb\b\r\1\2\u00bb\31\3\2\2\2\u00bc\u00bd\7\23\2"+
		"\2\u00bd\u00be\b\16\1\2\u00be\u00c6\b\16\1\2\u00bf\u00c0\7\25\2\2\u00c0"+
		"\u00c1\b\16\1\2\u00c1\u00c6\b\16\1\2\u00c2\u00c3\7\24\2\2\u00c3\u00c4"+
		"\b\16\1\2\u00c4\u00c6\b\16\1\2\u00c5\u00bc\3\2\2\2\u00c5\u00bf\3\2\2\2"+
		"\u00c5\u00c2\3\2\2\2\u00c6\33\3\2\2\2\u00c7\u00c8\5\36\20\2\u00c8\u00c9"+
		"\7\4\2\2\u00c9\u00ca\5\34\17\2\u00ca\u00cb\b\17\1\2\u00cb\u00cc\b\17\1"+
		"\2\u00cc\u00cf\3\2\2\2\u00cd\u00cf\b\17\1\2\u00ce\u00c7\3\2\2\2\u00ce"+
		"\u00cd\3\2\2\2\u00cf\35\3\2\2\2\u00d0\u00d1\5 \21\2\u00d1\u00d2\5\6\4"+
		"\2\u00d2\u00d3\b\20\1\2\u00d3\37\3\2\2\2\u00d4\u00d5\7\27\2\2\u00d5\u00d6"+
		"\7/\2\2\u00d6\u00d7\7\4\2\2\u00d7\u00d8\b\21\1\2\u00d8!\3\2\2\2\u00d9"+
		"\u00da\5$\23\2\u00da\u00db\b\22\1\2\u00db#\3\2\2\2\u00dc\u00dd\7\26\2"+
		"\2\u00dd\u00de\5(\25\2\u00de\u00df\5&\24\2\u00df\u00e0\7\30\2\2\u00e0"+
		"\u00e1\b\23\1\2\u00e1\u00e2\b\23\1\2\u00e2\u00e3\b\23\1\2\u00e3%\3\2\2"+
		"\2\u00e4\u00e5\7\4\2\2\u00e5\u00e6\5(\25\2\u00e6\u00e7\5&\24\2\u00e7\u00e8"+
		"\b\24\1\2\u00e8\u00e9\b\24\1\2\u00e9\u00ec\3\2\2\2\u00ea\u00ec\b\24\1"+
		"\2\u00eb\u00e4\3\2\2\2\u00eb\u00ea\3\2\2\2\u00ec\'\3\2\2\2\u00ed\u00ee"+
		"\5*\26\2\u00ee\u00ef\b\25\1\2\u00ef\u0103\3\2\2\2\u00f0\u00f1\5,\27\2"+
		"\u00f1\u00f2\b\25\1\2\u00f2\u0103\3\2\2\2\u00f3\u00f4\5\60\31\2\u00f4"+
		"\u00f5\b\25\1\2\u00f5\u0103\3\2\2\2\u00f6\u00f7\5\66\34\2\u00f7\u00f8"+
		"\b\25\1\2\u00f8\u0103\3\2\2\2\u00f9\u00fa\5<\37\2\u00fa\u00fb\b\25\1\2"+
		"\u00fb\u0103\3\2\2\2\u00fc\u00fd\5> \2\u00fd\u00fe\b\25\1\2\u00fe\u0103"+
		"\3\2\2\2\u00ff\u0100\5$\23\2\u0100\u0101\b\25\1\2\u0101\u0103\3\2\2\2"+
		"\u0102\u00ed\3\2\2\2\u0102\u00f0\3\2\2\2\u0102\u00f3\3\2\2\2\u0102\u00f6"+
		"\3\2\2\2\u0102\u00f9\3\2\2\2\u0102\u00fc\3\2\2\2\u0102\u00ff\3\2\2\2\u0103"+
		")\3\2\2\2\u0104\u0105\5T+\2\u0105\u0106\7\31\2\2\u0106\u0107\5@!\2\u0107"+
		"\u0108\b\26\1\2\u0108\u0109\b\26\1\2\u0109+\3\2\2\2\u010a\u010b\5.\30"+
		"\2\u010b\u010c\b\27\1\2\u010c-\3\2\2\2\u010d\u010e\7/\2\2\u010e\u010f"+
		"\b\30\1\2\u010f\u0110\b\30\1\2\u0110/\3\2\2\2\u0111\u0112\7\13\2\2\u0112"+
		"\u0113\7\32\2\2\u0113\u0114\5\64\33\2\u0114\u0115\5\62\32\2\u0115\u0116"+
		"\7\33\2\2\u0116\u0117\b\31\1\2\u0117\u0118\b\31\1\2\u0118\u0119\b\31\1"+
		"\2\u0119\u011a\b\31\1\2\u011a\61\3\2\2\2\u011b\u011c\7\20\2\2\u011c\u011d"+
		"\5\64\33\2\u011d\u011e\5\62\32\2\u011e\u011f\b\32\1\2\u011f\u0120\b\32"+
		"\1\2\u0120\u0123\3\2\2\2\u0121\u0123\b\32\1\2\u0122\u011b\3\2\2\2\u0122"+
		"\u0121\3\2\2\2\u0123\63\3\2\2\2\u0124\u0125\5T+\2\u0125\u0126\b\33\1\2"+
		"\u0126\65\3\2\2\2\u0127\u0128\7\f\2\2\u0128\u0129\7\32\2\2\u0129\u012a"+
		"\5:\36\2\u012a\u012b\58\35\2\u012b\u012c\7\33\2\2\u012c\u012d\b\34\1\2"+
		"\u012d\u012e\b\34\1\2\u012e\u012f\b\34\1\2\u012f\u0130\b\34\1\2\u0130"+
		"\67\3\2\2\2\u0131\u0132\7\20\2\2\u0132\u0133\5:\36\2\u0133\u0134\58\35"+
		"\2\u0134\u0135\b\35\1\2\u0135\u0136\b\35\1\2\u0136\u0139\3\2\2\2\u0137"+
		"\u0139\b\35\1\2\u0138\u0131\3\2\2\2\u0138\u0137\3\2\2\2\u01399\3\2\2\2"+
		"\u013a\u013b\5@!\2\u013b\u013c\b\36\1\2\u013c;\3\2\2\2\u013d\u013e\7\6"+
		"\2\2\u013e\u013f\5@!\2\u013f\u0140\7\7\2\2\u0140\u0141\5(\25\2\u0141\u0142"+
		"\b\37\1\2\u0142\u0143\b\37\1\2\u0143\u0144\b\37\1\2\u0144\u0151\3\2\2"+
		"\2\u0145\u0146\7\6\2\2\u0146\u0147\5@!\2\u0147\u0148\7\7\2\2\u0148\u0149"+
		"\5(\25\2\u0149\u014a\7\t\2\2\u014a\u014b\5(\25\2\u014b\u014c\b\37\1\2"+
		"\u014c\u014d\b\37\1\2\u014d\u014e\b\37\1\2\u014e\u014f\b\37\1\2\u014f"+
		"\u0151\3\2\2\2\u0150\u013d\3\2\2\2\u0150\u0145\3\2\2\2\u0151=\3\2\2\2"+
		"\u0152\u0153\7\n\2\2\u0153\u0154\5@!\2\u0154\u0155\7\34\2\2\u0155\u0156"+
		"\5(\25\2\u0156\u0157\b \1\2\u0157?\3\2\2\2\u0158\u0159\5B\"\2\u0159\u015a"+
		"\b!\1\2\u015a\u0161\3\2\2\2\u015b\u015c\5B\"\2\u015c\u015d\5R*\2\u015d"+
		"\u015e\5B\"\2\u015e\u015f\b!\1\2\u015f\u0161\3\2\2\2\u0160\u0158\3\2\2"+
		"\2\u0160\u015b\3\2\2\2\u0161A\3\2\2\2\u0162\u0163\5F$\2\u0163\u0164\5"+
		"D#\2\u0164\u0165\b\"\1\2\u0165C\3\2\2\2\u0166\u0167\5N(\2\u0167\u0168"+
		"\5F$\2\u0168\u0169\5D#\2\u0169\u016a\b#\1\2\u016a\u016d\3\2\2\2\u016b"+
		"\u016d\b#\1\2\u016c\u0166\3\2\2\2\u016c\u016b\3\2\2\2\u016dE\3\2\2\2\u016e"+
		"\u016f\5J&\2\u016f\u0170\5H%\2\u0170\u0171\b$\1\2\u0171G\3\2\2\2\u0172"+
		"\u0173\5P)\2\u0173\u0174\5J&\2\u0174\u0175\5H%\2\u0175\u0176\b%\1\2\u0176"+
		"\u0179\3\2\2\2\u0177\u0179\b%\1\2\u0178\u0172\3\2\2\2\u0178\u0177\3\2"+
		"\2\2\u0179I\3\2\2\2\u017a\u017b\5L\'\2\u017b\u017c\5T+\2\u017c\u017d\b"+
		"&\1\2\u017d\u018e\3\2\2\2\u017e\u017f\5^\60\2\u017f\u0180\b&\1\2\u0180"+
		"\u018e\3\2\2\2\u0181\u0182\7\32\2\2\u0182\u0183\5@!\2\u0183\u0184\7\33"+
		"\2\2\u0184\u0185\b&\1\2\u0185\u0186\b&\1\2\u0186\u0187\b&\1\2\u0187\u018e"+
		"\3\2\2\2\u0188\u0189\7\35\2\2\u0189\u018a\5J&\2\u018a\u018b\b&\1\2\u018b"+
		"\u018c\b&\1\2\u018c\u018e\3\2\2\2\u018d\u017a\3\2\2\2\u018d\u017e\3\2"+
		"\2\2\u018d\u0181\3\2\2\2\u018d\u0188\3\2\2\2\u018eK\3\2\2\2\u018f\u0190"+
		"\7*\2\2\u0190\u0191\b\'\1\2\u0191\u0197\b\'\1\2\u0192\u0193\7+\2\2\u0193"+
		"\u0194\b\'\1\2\u0194\u0197\b\'\1\2\u0195\u0197\b\'\1\2\u0196\u018f\3\2"+
		"\2\2\u0196\u0192\3\2\2\2\u0196\u0195\3\2\2\2\u0197M\3\2\2\2\u0198\u0199"+
		"\7*\2\2\u0199\u019a\b(\1\2\u019a\u01a2\b(\1\2\u019b\u019c\7+\2\2\u019c"+
		"\u019d\b(\1\2\u019d\u01a2\b(\1\2\u019e\u019f\7\'\2\2\u019f\u01a0\b(\1"+
		"\2\u01a0\u01a2\b(\1\2\u01a1\u0198\3\2\2\2\u01a1\u019b\3\2\2\2\u01a1\u019e"+
		"\3\2\2\2\u01a2O\3\2\2\2\u01a3\u01a4\7)\2\2\u01a4\u01a5\b)\1\2\u01a5\u01ad"+
		"\b)\1\2\u01a6\u01a7\7(\2\2\u01a7\u01a8\b)\1\2\u01a8\u01ad\b)\1\2\u01a9"+
		"\u01aa\7&\2\2\u01aa\u01ab\b)\1\2\u01ab\u01ad\b)\1\2\u01ac\u01a3\3\2\2"+
		"\2\u01ac\u01a6\3\2\2\2\u01ac\u01a9\3\2\2\2\u01adQ\3\2\2\2\u01ae\u01af"+
		"\7 \2\2\u01af\u01b0\b*\1\2\u01b0\u01c1\b*\1\2\u01b1\u01b2\7!\2\2\u01b2"+
		"\u01b3\b*\1\2\u01b3\u01c1\b*\1\2\u01b4\u01b5\7%\2\2\u01b5\u01b6\b*\1\2"+
		"\u01b6\u01c1\b*\1\2\u01b7\u01b8\7$\2\2\u01b8\u01b9\b*\1\2\u01b9\u01c1"+
		"\b*\1\2\u01ba\u01bb\7#\2\2\u01bb\u01bc\b*\1\2\u01bc\u01c1\b*\1\2\u01bd"+
		"\u01be\7\"\2\2\u01be\u01bf\b*\1\2\u01bf\u01c1\b*\1\2\u01c0\u01ae\3\2\2"+
		"\2\u01c0\u01b1\3\2\2\2\u01c0\u01b4\3\2\2\2\u01c0\u01b7\3\2\2\2\u01c0\u01ba"+
		"\3\2\2\2\u01c0\u01bd\3\2\2\2\u01c1S\3\2\2\2\u01c2\u01c3\5Z.\2\u01c3\u01c4"+
		"\b+\1\2\u01c4\u01c9\3\2\2\2\u01c5\u01c6\5V,\2\u01c6\u01c7\b+\1\2\u01c7"+
		"\u01c9\3\2\2\2\u01c8\u01c2\3\2\2\2\u01c8\u01c5\3\2\2\2\u01c9U\3\2\2\2"+
		"\u01ca\u01cb\5X-\2\u01cb\u01cc\7\21\2\2\u01cc\u01cd\5@!\2\u01cd\u01ce"+
		"\7\22\2\2\u01ce\u01cf\b,\1\2\u01cfW\3\2\2\2\u01d0\u01d1\5Z.\2\u01d1\u01d2"+
		"\b-\1\2\u01d2Y\3\2\2\2\u01d3\u01d4\5\\/\2\u01d4\u01d5\b.\1\2\u01d5[\3"+
		"\2\2\2\u01d6\u01d7\7/\2\2\u01d7\u01d8\b/\1\2\u01d8]\3\2\2\2\u01d9\u01da"+
		"\5`\61\2\u01da\u01db\b\60\1\2\u01db\u01e2\3\2\2\2\u01dc\u01dd\7\60\2\2"+
		"\u01dd\u01e2\b\60\1\2\u01de\u01df\5b\62\2\u01df\u01e0\b\60\1\2\u01e0\u01e2"+
		"\3\2\2\2\u01e1\u01d9\3\2\2\2\u01e1\u01dc\3\2\2\2\u01e1\u01de\3\2\2\2\u01e2"+
		"_\3\2\2\2\u01e3\u01e4\5L\'\2\u01e4\u01e5\7.\2\2\u01e5\u01e6\b\61\1\2\u01e6"+
		"\u01e7\b\61\1\2\u01e7\u01e8\b\61\1\2\u01e8a\3\2\2\2\u01e9\u01ea\7\36\2"+
		"\2\u01ea\u01eb\b\62\1\2\u01eb\u01f0\b\62\1\2\u01ec\u01ed\7\37\2\2\u01ed"+
		"\u01ee\b\62\1\2\u01ee\u01f0\b\62\1\2\u01ef\u01e9\3\2\2\2\u01ef\u01ec\3"+
		"\2\2\2\u01f0c\3\2\2\2\30\u0080\u0089\u009d\u00a5\u00c5\u00ce\u00eb\u0102"+
		"\u0122\u0138\u0150\u0160\u016c\u0178\u018d\u0196\u01a1\u01ac\u01c0\u01c8"+
		"\u01e1\u01ef";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}