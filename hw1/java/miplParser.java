// Generated from mipl.g4 by ANTLR 4.7.1
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
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, T__37=38, 
		T__38=39, T__39=40, T__40=41, T__41=42, WSPACE=43, IDENT=44, INTCONST=45, 
		CHARCONST=46, COMMENT=47;
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
		null, "';'", "'.'", "'program'", "'var'", "':'", "','", "'array'", "'['", 
		"']'", "'of'", "'..'", "'integer'", "'char'", "'boolean'", "'procedure'", 
		"'begin'", "'end'", "':='", "'read'", "'('", "')'", "'write'", "'if'", 
		"'then'", "'else'", "'while'", "'do'", "'not'", "'+'", "'-'", "'or'", 
		"'*'", "'div'", "'and'", "'<'", "'<='", "'<>'", "'='", "'>'", "'>='", 
		"'true'", "'false'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, "WSPACE", "IDENT", "INTCONST", 
		"CHARCONST", "COMMENT"
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
		public ProglblContext proglbl() {
			return getRuleContext(ProglblContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProg(this);
		}
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
			match(IDENT);
			setState(100);
			match(T__0);
			setState(101);
			block();
			setState(102);
			match(T__1);
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
		public ProglblContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proglbl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProglbl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProglbl(this);
		}
	}

	public final ProglblContext proglbl() throws RecognitionException {
		ProglblContext _localctx = new ProglblContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_proglbl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			match(T__2);
			System.out.print("adlfkjaldfkjasldfkadsjflkadsjfl");
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			vardecpart();
			setState(108);
			procdecpart();
			setState(109);
			stmtpart();
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
		public VardecContext vardec() {
			return getRuleContext(VardecContext.class,0);
		}
		public VardeclistContext vardeclist() {
			return getRuleContext(VardeclistContext.class,0);
		}
		public VardecpartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecpart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterVardecpart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitVardecpart(this);
		}
	}

	public final VardecpartContext vardecpart() throws RecognitionException {
		VardecpartContext _localctx = new VardecpartContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_vardecpart);
		try {
			setState(117);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__14:
			case T__15:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__3:
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				match(T__3);
				setState(113);
				vardec();
				setState(114);
				match(T__0);
				setState(115);
				vardeclist();
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
		public VardecContext vardec() {
			return getRuleContext(VardecContext.class,0);
		}
		public VardeclistContext vardeclist() {
			return getRuleContext(VardeclistContext.class,0);
		}
		public VardeclistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardeclist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterVardeclist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitVardeclist(this);
		}
	}

	public final VardeclistContext vardeclist() throws RecognitionException {
		VardeclistContext _localctx = new VardeclistContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_vardeclist);
		try {
			setState(124);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(119);
				vardec();
				setState(120);
				match(T__0);
				setState(121);
				vardeclist();
				}
				break;
			case T__14:
			case T__15:
				enterOuterAlt(_localctx, 2);
				{
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
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public IdentlistContext identlist() {
			return getRuleContext(IdentlistContext.class,0);
		}
		public TypezContext typez() {
			return getRuleContext(TypezContext.class,0);
		}
		public VardecContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardec; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterVardec(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitVardec(this);
		}
	}

	public final VardecContext vardec() throws RecognitionException {
		VardecContext _localctx = new VardecContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_vardec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(126);
			ident();
			setState(127);
			identlist();
			setState(128);
			match(T__4);
			setState(129);
			typez();
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
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIdent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIdent(this);
		}
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_ident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(131);
			match(IDENT);
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
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public IdentlistContext identlist() {
			return getRuleContext(IdentlistContext.class,0);
		}
		public IdentlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIdentlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIdentlist(this);
		}
	}

	public final IdentlistContext identlist() throws RecognitionException {
		IdentlistContext _localctx = new IdentlistContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_identlist);
		try {
			setState(138);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__5:
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				match(T__5);
				setState(134);
				ident();
				setState(135);
				identlist();
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterTypez(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitTypez(this);
		}
	}

	public final TypezContext typez() throws RecognitionException {
		TypezContext _localctx = new TypezContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_typez);
		try {
			setState(142);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__11:
			case T__12:
			case T__13:
				enterOuterAlt(_localctx, 1);
				{
				setState(140);
				simple();
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 2);
				{
				setState(141);
				array();
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
		public IdxrangeContext idxrange() {
			return getRuleContext(IdxrangeContext.class,0);
		}
		public SimpleContext simple() {
			return getRuleContext(SimpleContext.class,0);
		}
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterArray(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitArray(this);
		}
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_array);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(144);
			match(T__6);
			setState(145);
			match(T__7);
			setState(146);
			idxrange();
			setState(147);
			match(T__8);
			setState(148);
			match(T__9);
			setState(149);
			simple();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIdx(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIdx(this);
		}
	}

	public final IdxContext idx() throws RecognitionException {
		IdxContext _localctx = new IdxContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_idx);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(151);
			intconst();
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
		public List<IdxContext> idx() {
			return getRuleContexts(IdxContext.class);
		}
		public IdxContext idx(int i) {
			return getRuleContext(IdxContext.class,i);
		}
		public IdxrangeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idxrange; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIdxrange(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIdxrange(this);
		}
	}

	public final IdxrangeContext idxrange() throws RecognitionException {
		IdxrangeContext _localctx = new IdxrangeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_idxrange);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			idx();
			setState(154);
			match(T__10);
			setState(155);
			idx();
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
		public SimpleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterSimple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitSimple(this);
		}
	}

	public final SimpleContext simple() throws RecognitionException {
		SimpleContext _localctx = new SimpleContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_simple);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(157);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__11) | (1L << T__12) | (1L << T__13))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		public ProcdecContext procdec() {
			return getRuleContext(ProcdecContext.class,0);
		}
		public ProcdecpartContext procdecpart() {
			return getRuleContext(ProcdecpartContext.class,0);
		}
		public ProcdecpartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procdecpart; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProcdecpart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProcdecpart(this);
		}
	}

	public final ProcdecpartContext procdecpart() throws RecognitionException {
		ProcdecpartContext _localctx = new ProcdecpartContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_procdecpart);
		try {
			setState(164);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__14:
				enterOuterAlt(_localctx, 1);
				{
				setState(159);
				procdec();
				setState(160);
				match(T__0);
				setState(161);
				procdecpart();
				}
				break;
			case T__15:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProcdec(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProcdec(this);
		}
	}

	public final ProcdecContext procdec() throws RecognitionException {
		ProcdecContext _localctx = new ProcdecContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_procdec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(166);
			prochdr();
			setState(167);
			block();
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
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public ProchdrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prochdr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProchdr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProchdr(this);
		}
	}

	public final ProchdrContext prochdr() throws RecognitionException {
		ProchdrContext _localctx = new ProchdrContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_prochdr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(169);
			match(T__14);
			setState(170);
			match(IDENT);
			setState(171);
			match(T__0);
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterStmtpart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitStmtpart(this);
		}
	}

	public final StmtpartContext stmtpart() throws RecognitionException {
		StmtpartContext _localctx = new StmtpartContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_stmtpart);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(173);
			compound();
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
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public StmtlistContext stmtlist() {
			return getRuleContext(StmtlistContext.class,0);
		}
		public CompoundContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterCompound(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitCompound(this);
		}
	}

	public final CompoundContext compound() throws RecognitionException {
		CompoundContext _localctx = new CompoundContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_compound);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(175);
			match(T__15);
			setState(176);
			stmt();
			setState(177);
			stmtlist();
			setState(178);
			match(T__16);
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
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public StmtlistContext stmtlist() {
			return getRuleContext(StmtlistContext.class,0);
		}
		public StmtlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmtlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterStmtlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitStmtlist(this);
		}
	}

	public final StmtlistContext stmtlist() throws RecognitionException {
		StmtlistContext _localctx = new StmtlistContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_stmtlist);
		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				setState(180);
				match(T__0);
				setState(181);
				stmt();
				setState(182);
				stmtlist();
				}
				break;
			case T__16:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitStmt(this);
		}
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_stmt);
		try {
			setState(194);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(187);
				assign();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(188);
				procstmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(189);
				read();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(190);
				write();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(191);
				condition();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(192);
				whileloop();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(193);
				compound();
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
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterAssign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitAssign(this);
		}
	}

	public final AssignContext assign() throws RecognitionException {
		AssignContext _localctx = new AssignContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_assign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(196);
			variable();
			setState(197);
			match(T__17);
			setState(198);
			expr();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProcstmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProcstmt(this);
		}
	}

	public final ProcstmtContext procstmt() throws RecognitionException {
		ProcstmtContext _localctx = new ProcstmtContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_procstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			procident();
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
		public TerminalNode IDENT() { return getToken(miplParser.IDENT, 0); }
		public ProcidentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procident; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterProcident(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitProcident(this);
		}
	}

	public final ProcidentContext procident() throws RecognitionException {
		ProcidentContext _localctx = new ProcidentContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_procident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			match(IDENT);
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
		public InputvarContext inputvar() {
			return getRuleContext(InputvarContext.class,0);
		}
		public InputlistContext inputlist() {
			return getRuleContext(InputlistContext.class,0);
		}
		public ReadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_read; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterRead(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitRead(this);
		}
	}

	public final ReadContext read() throws RecognitionException {
		ReadContext _localctx = new ReadContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_read);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(204);
			match(T__18);
			setState(205);
			match(T__19);
			setState(206);
			inputvar();
			setState(207);
			inputlist();
			setState(208);
			match(T__20);
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
		public InputvarContext inputvar() {
			return getRuleContext(InputvarContext.class,0);
		}
		public InputlistContext inputlist() {
			return getRuleContext(InputlistContext.class,0);
		}
		public InputlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inputlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterInputlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitInputlist(this);
		}
	}

	public final InputlistContext inputlist() throws RecognitionException {
		InputlistContext _localctx = new InputlistContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_inputlist);
		try {
			setState(215);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__5:
				enterOuterAlt(_localctx, 1);
				{
				setState(210);
				match(T__5);
				setState(211);
				inputvar();
				setState(212);
				inputlist();
				}
				break;
			case T__20:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterInputvar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitInputvar(this);
		}
	}

	public final InputvarContext inputvar() throws RecognitionException {
		InputvarContext _localctx = new InputvarContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_inputvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(217);
			variable();
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
		public OutputContext output() {
			return getRuleContext(OutputContext.class,0);
		}
		public OutputlistContext outputlist() {
			return getRuleContext(OutputlistContext.class,0);
		}
		public WriteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_write; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterWrite(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitWrite(this);
		}
	}

	public final WriteContext write() throws RecognitionException {
		WriteContext _localctx = new WriteContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_write);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(219);
			match(T__21);
			setState(220);
			match(T__19);
			setState(221);
			output();
			setState(222);
			outputlist();
			setState(223);
			match(T__20);
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
		public OutputContext output() {
			return getRuleContext(OutputContext.class,0);
		}
		public OutputlistContext outputlist() {
			return getRuleContext(OutputlistContext.class,0);
		}
		public OutputlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_outputlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterOutputlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitOutputlist(this);
		}
	}

	public final OutputlistContext outputlist() throws RecognitionException {
		OutputlistContext _localctx = new OutputlistContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_outputlist);
		try {
			setState(230);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__5:
				enterOuterAlt(_localctx, 1);
				{
				setState(225);
				match(T__5);
				setState(226);
				output();
				setState(227);
				outputlist();
				}
				break;
			case T__20:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterOutput(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitOutput(this);
		}
	}

	public final OutputContext output() throws RecognitionException {
		OutputContext _localctx = new OutputContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_output);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			expr();
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
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public ConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitCondition(this);
		}
	}

	public final ConditionContext condition() throws RecognitionException {
		ConditionContext _localctx = new ConditionContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_condition);
		try {
			setState(246);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(234);
				match(T__22);
				setState(235);
				expr();
				setState(236);
				match(T__23);
				setState(237);
				stmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(239);
				match(T__22);
				setState(240);
				expr();
				setState(241);
				match(T__23);
				setState(242);
				stmt();
				setState(243);
				match(T__24);
				setState(244);
				stmt();
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
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public WhileloopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileloop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterWhileloop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitWhileloop(this);
		}
	}

	public final WhileloopContext whileloop() throws RecognitionException {
		WhileloopContext _localctx = new WhileloopContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_whileloop);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(248);
			match(T__25);
			setState(249);
			expr();
			setState(250);
			match(T__26);
			setState(251);
			stmt();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitExpr(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_expr);
		try {
			setState(258);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(253);
				simpleexpr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(254);
				simpleexpr();
				setState(255);
				relop();
				setState(256);
				simpleexpr();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterSimpleexpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitSimpleexpr(this);
		}
	}

	public final SimpleexprContext simpleexpr() throws RecognitionException {
		SimpleexprContext _localctx = new SimpleexprContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_simpleexpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(260);
			term();
			setState(261);
			addoplist();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterAddoplist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitAddoplist(this);
		}
	}

	public final AddoplistContext addoplist() throws RecognitionException {
		AddoplistContext _localctx = new AddoplistContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_addoplist);
		try {
			setState(268);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__28:
			case T__29:
			case T__30:
				enterOuterAlt(_localctx, 1);
				{
				setState(263);
				addop();
				setState(264);
				term();
				setState(265);
				addoplist();
				}
				break;
			case T__0:
			case T__5:
			case T__8:
			case T__16:
			case T__20:
			case T__23:
			case T__24:
			case T__26:
			case T__34:
			case T__35:
			case T__36:
			case T__37:
			case T__38:
			case T__39:
				enterOuterAlt(_localctx, 2);
				{
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterTerm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitTerm(this);
		}
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_term);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(270);
			factor();
			setState(271);
			multoplist();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterMultoplist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitMultoplist(this);
		}
	}

	public final MultoplistContext multoplist() throws RecognitionException {
		MultoplistContext _localctx = new MultoplistContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_multoplist);
		try {
			setState(278);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__31:
			case T__32:
			case T__33:
				enterOuterAlt(_localctx, 1);
				{
				setState(273);
				multop();
				setState(274);
				factor();
				setState(275);
				multoplist();
				}
				break;
			case T__0:
			case T__5:
			case T__8:
			case T__16:
			case T__20:
			case T__23:
			case T__24:
			case T__26:
			case T__28:
			case T__29:
			case T__30:
			case T__34:
			case T__35:
			case T__36:
			case T__37:
			case T__38:
			case T__39:
				enterOuterAlt(_localctx, 2);
				{
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
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterFactor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitFactor(this);
		}
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_factor);
		try {
			setState(290);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(280);
				sign();
				setState(281);
				variable();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(283);
				constant();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(284);
				match(T__19);
				setState(285);
				expr();
				setState(286);
				match(T__20);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(288);
				match(T__27);
				setState(289);
				factor();
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
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterSign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitSign(this);
		}
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_sign);
		try {
			setState(295);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__28:
				enterOuterAlt(_localctx, 1);
				{
				setState(292);
				match(T__28);
				}
				break;
			case T__29:
				enterOuterAlt(_localctx, 2);
				{
				setState(293);
				match(T__29);
				}
				break;
			case IDENT:
			case INTCONST:
				enterOuterAlt(_localctx, 3);
				{
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
		public AddopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterAddop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitAddop(this);
		}
	}

	public final AddopContext addop() throws RecognitionException {
		AddopContext _localctx = new AddopContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_addop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(297);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__28) | (1L << T__29) | (1L << T__30))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		public MultopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterMultop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitMultop(this);
		}
	}

	public final MultopContext multop() throws RecognitionException {
		MultopContext _localctx = new MultopContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_multop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(299);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__31) | (1L << T__32) | (1L << T__33))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterRelop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitRelop(this);
		}
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(301);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__34) | (1L << T__35) | (1L << T__36) | (1L << T__37) | (1L << T__38) | (1L << T__39))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitVariable(this);
		}
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_variable);
		try {
			setState(305);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(303);
				entirevar();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(304);
				idxvar();
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
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public IdxvarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idxvar; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIdxvar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIdxvar(this);
		}
	}

	public final IdxvarContext idxvar() throws RecognitionException {
		IdxvarContext _localctx = new IdxvarContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_idxvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(307);
			arrayvar();
			setState(308);
			match(T__7);
			setState(309);
			expr();
			setState(310);
			match(T__8);
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterArrayvar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitArrayvar(this);
		}
	}

	public final ArrayvarContext arrayvar() throws RecognitionException {
		ArrayvarContext _localctx = new ArrayvarContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_arrayvar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			entirevar();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterEntirevar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitEntirevar(this);
		}
	}

	public final EntirevarContext entirevar() throws RecognitionException {
		EntirevarContext _localctx = new EntirevarContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_entirevar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(314);
			varident();
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterVarident(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitVarident(this);
		}
	}

	public final VaridentContext varident() throws RecognitionException {
		VaridentContext _localctx = new VaridentContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_varident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(316);
			match(IDENT);
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
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitConstant(this);
		}
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_constant);
		try {
			setState(321);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__28:
			case T__29:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(318);
				intconst();
				}
				break;
			case CHARCONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(319);
				match(CHARCONST);
				}
				break;
			case T__40:
			case T__41:
				enterOuterAlt(_localctx, 3);
				{
				setState(320);
				boolconst();
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
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public TerminalNode INTCONST() { return getToken(miplParser.INTCONST, 0); }
		public IntconstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intconst; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterIntconst(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitIntconst(this);
		}
	}

	public final IntconstContext intconst() throws RecognitionException {
		IntconstContext _localctx = new IntconstContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_intconst);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(323);
			sign();
			setState(324);
			match(INTCONST);
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
		public BoolconstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolconst; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).enterBoolconst(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof miplListener ) ((miplListener)listener).exitBoolconst(this);
		}
	}

	public final BoolconstContext boolconst() throws RecognitionException {
		BoolconstContext _localctx = new BoolconstContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_boolconst);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(326);
			_la = _input.LA(1);
			if ( !(_la==T__40 || _la==T__41) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\61\u014b\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\5\5x\n\5\3"+
		"\6\3\6\3\6\3\6\3\6\5\6\177\n\6\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\t\3\t\3\t"+
		"\3\t\3\t\5\t\u008d\n\t\3\n\3\n\5\n\u0091\n\n\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\f\3\f\3\r\3\r\3\r\3\r\3\16\3\16\3\17\3\17\3\17\3\17\3\17"+
		"\5\17\u00a7\n\17\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\22\3\22\3\23\3\23"+
		"\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\5\24\u00bc\n\24\3\25\3\25\3\25"+
		"\3\25\3\25\3\25\3\25\5\25\u00c5\n\25\3\26\3\26\3\26\3\26\3\27\3\27\3\30"+
		"\3\30\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\5\32\u00da"+
		"\n\32\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35"+
		"\5\35\u00e9\n\35\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37"+
		"\3\37\3\37\3\37\5\37\u00f9\n\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\5!\u0105"+
		"\n!\3\"\3\"\3\"\3#\3#\3#\3#\3#\5#\u010f\n#\3$\3$\3$\3%\3%\3%\3%\3%\5%"+
		"\u0119\n%\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\5&\u0125\n&\3\'\3\'\3\'\5\'\u012a"+
		"\n\'\3(\3(\3)\3)\3*\3*\3+\3+\5+\u0134\n+\3,\3,\3,\3,\3,\3-\3-\3.\3.\3"+
		"/\3/\3\60\3\60\3\60\5\60\u0144\n\60\3\61\3\61\3\61\3\62\3\62\3\62\2\2"+
		"\63\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@B"+
		"DFHJLNPRTVXZ\\^`b\2\7\3\2\16\20\3\2\37!\3\2\"$\3\2%*\3\2+,\2\u0133\2d"+
		"\3\2\2\2\4j\3\2\2\2\6m\3\2\2\2\bw\3\2\2\2\n~\3\2\2\2\f\u0080\3\2\2\2\16"+
		"\u0085\3\2\2\2\20\u008c\3\2\2\2\22\u0090\3\2\2\2\24\u0092\3\2\2\2\26\u0099"+
		"\3\2\2\2\30\u009b\3\2\2\2\32\u009f\3\2\2\2\34\u00a6\3\2\2\2\36\u00a8\3"+
		"\2\2\2 \u00ab\3\2\2\2\"\u00af\3\2\2\2$\u00b1\3\2\2\2&\u00bb\3\2\2\2(\u00c4"+
		"\3\2\2\2*\u00c6\3\2\2\2,\u00ca\3\2\2\2.\u00cc\3\2\2\2\60\u00ce\3\2\2\2"+
		"\62\u00d9\3\2\2\2\64\u00db\3\2\2\2\66\u00dd\3\2\2\28\u00e8\3\2\2\2:\u00ea"+
		"\3\2\2\2<\u00f8\3\2\2\2>\u00fa\3\2\2\2@\u0104\3\2\2\2B\u0106\3\2\2\2D"+
		"\u010e\3\2\2\2F\u0110\3\2\2\2H\u0118\3\2\2\2J\u0124\3\2\2\2L\u0129\3\2"+
		"\2\2N\u012b\3\2\2\2P\u012d\3\2\2\2R\u012f\3\2\2\2T\u0133\3\2\2\2V\u0135"+
		"\3\2\2\2X\u013a\3\2\2\2Z\u013c\3\2\2\2\\\u013e\3\2\2\2^\u0143\3\2\2\2"+
		"`\u0145\3\2\2\2b\u0148\3\2\2\2de\5\4\3\2ef\7.\2\2fg\7\3\2\2gh\5\6\4\2"+
		"hi\7\4\2\2i\3\3\2\2\2jk\7\5\2\2kl\b\3\1\2l\5\3\2\2\2mn\5\b\5\2no\5\34"+
		"\17\2op\5\"\22\2p\7\3\2\2\2qx\3\2\2\2rs\7\6\2\2st\5\f\7\2tu\7\3\2\2uv"+
		"\5\n\6\2vx\3\2\2\2wq\3\2\2\2wr\3\2\2\2x\t\3\2\2\2yz\5\f\7\2z{\7\3\2\2"+
		"{|\5\n\6\2|\177\3\2\2\2}\177\3\2\2\2~y\3\2\2\2~}\3\2\2\2\177\13\3\2\2"+
		"\2\u0080\u0081\5\16\b\2\u0081\u0082\5\20\t\2\u0082\u0083\7\7\2\2\u0083"+
		"\u0084\5\22\n\2\u0084\r\3\2\2\2\u0085\u0086\7.\2\2\u0086\17\3\2\2\2\u0087"+
		"\u0088\7\b\2\2\u0088\u0089\5\16\b\2\u0089\u008a\5\20\t\2\u008a\u008d\3"+
		"\2\2\2\u008b\u008d\3\2\2\2\u008c\u0087\3\2\2\2\u008c\u008b\3\2\2\2\u008d"+
		"\21\3\2\2\2\u008e\u0091\5\32\16\2\u008f\u0091\5\24\13\2\u0090\u008e\3"+
		"\2\2\2\u0090\u008f\3\2\2\2\u0091\23\3\2\2\2\u0092\u0093\7\t\2\2\u0093"+
		"\u0094\7\n\2\2\u0094\u0095\5\30\r\2\u0095\u0096\7\13\2\2\u0096\u0097\7"+
		"\f\2\2\u0097\u0098\5\32\16\2\u0098\25\3\2\2\2\u0099\u009a\5`\61\2\u009a"+
		"\27\3\2\2\2\u009b\u009c\5\26\f\2\u009c\u009d\7\r\2\2\u009d\u009e\5\26"+
		"\f\2\u009e\31\3\2\2\2\u009f\u00a0\t\2\2\2\u00a0\33\3\2\2\2\u00a1\u00a2"+
		"\5\36\20\2\u00a2\u00a3\7\3\2\2\u00a3\u00a4\5\34\17\2\u00a4\u00a7\3\2\2"+
		"\2\u00a5\u00a7\3\2\2\2\u00a6\u00a1\3\2\2\2\u00a6\u00a5\3\2\2\2\u00a7\35"+
		"\3\2\2\2\u00a8\u00a9\5 \21\2\u00a9\u00aa\5\6\4\2\u00aa\37\3\2\2\2\u00ab"+
		"\u00ac\7\21\2\2\u00ac\u00ad\7.\2\2\u00ad\u00ae\7\3\2\2\u00ae!\3\2\2\2"+
		"\u00af\u00b0\5$\23\2\u00b0#\3\2\2\2\u00b1\u00b2\7\22\2\2\u00b2\u00b3\5"+
		"(\25\2\u00b3\u00b4\5&\24\2\u00b4\u00b5\7\23\2\2\u00b5%\3\2\2\2\u00b6\u00b7"+
		"\7\3\2\2\u00b7\u00b8\5(\25\2\u00b8\u00b9\5&\24\2\u00b9\u00bc\3\2\2\2\u00ba"+
		"\u00bc\3\2\2\2\u00bb\u00b6\3\2\2\2\u00bb\u00ba\3\2\2\2\u00bc\'\3\2\2\2"+
		"\u00bd\u00c5\5*\26\2\u00be\u00c5\5,\27\2\u00bf\u00c5\5\60\31\2\u00c0\u00c5"+
		"\5\66\34\2\u00c1\u00c5\5<\37\2\u00c2\u00c5\5> \2\u00c3\u00c5\5$\23\2\u00c4"+
		"\u00bd\3\2\2\2\u00c4\u00be\3\2\2\2\u00c4\u00bf\3\2\2\2\u00c4\u00c0\3\2"+
		"\2\2\u00c4\u00c1\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c4\u00c3\3\2\2\2\u00c5"+
		")\3\2\2\2\u00c6\u00c7\5T+\2\u00c7\u00c8\7\24\2\2\u00c8\u00c9\5@!\2\u00c9"+
		"+\3\2\2\2\u00ca\u00cb\5.\30\2\u00cb-\3\2\2\2\u00cc\u00cd\7.\2\2\u00cd"+
		"/\3\2\2\2\u00ce\u00cf\7\25\2\2\u00cf\u00d0\7\26\2\2\u00d0\u00d1\5\64\33"+
		"\2\u00d1\u00d2\5\62\32\2\u00d2\u00d3\7\27\2\2\u00d3\61\3\2\2\2\u00d4\u00d5"+
		"\7\b\2\2\u00d5\u00d6\5\64\33\2\u00d6\u00d7\5\62\32\2\u00d7\u00da\3\2\2"+
		"\2\u00d8\u00da\3\2\2\2\u00d9\u00d4\3\2\2\2\u00d9\u00d8\3\2\2\2\u00da\63"+
		"\3\2\2\2\u00db\u00dc\5T+\2\u00dc\65\3\2\2\2\u00dd\u00de\7\30\2\2\u00de"+
		"\u00df\7\26\2\2\u00df\u00e0\5:\36\2\u00e0\u00e1\58\35\2\u00e1\u00e2\7"+
		"\27\2\2\u00e2\67\3\2\2\2\u00e3\u00e4\7\b\2\2\u00e4\u00e5\5:\36\2\u00e5"+
		"\u00e6\58\35\2\u00e6\u00e9\3\2\2\2\u00e7\u00e9\3\2\2\2\u00e8\u00e3\3\2"+
		"\2\2\u00e8\u00e7\3\2\2\2\u00e99\3\2\2\2\u00ea\u00eb\5@!\2\u00eb;\3\2\2"+
		"\2\u00ec\u00ed\7\31\2\2\u00ed\u00ee\5@!\2\u00ee\u00ef\7\32\2\2\u00ef\u00f0"+
		"\5(\25\2\u00f0\u00f9\3\2\2\2\u00f1\u00f2\7\31\2\2\u00f2\u00f3\5@!\2\u00f3"+
		"\u00f4\7\32\2\2\u00f4\u00f5\5(\25\2\u00f5\u00f6\7\33\2\2\u00f6\u00f7\5"+
		"(\25\2\u00f7\u00f9\3\2\2\2\u00f8\u00ec\3\2\2\2\u00f8\u00f1\3\2\2\2\u00f9"+
		"=\3\2\2\2\u00fa\u00fb\7\34\2\2\u00fb\u00fc\5@!\2\u00fc\u00fd\7\35\2\2"+
		"\u00fd\u00fe\5(\25\2\u00fe?\3\2\2\2\u00ff\u0105\5B\"\2\u0100\u0101\5B"+
		"\"\2\u0101\u0102\5R*\2\u0102\u0103\5B\"\2\u0103\u0105\3\2\2\2\u0104\u00ff"+
		"\3\2\2\2\u0104\u0100\3\2\2\2\u0105A\3\2\2\2\u0106\u0107\5F$\2\u0107\u0108"+
		"\5D#\2\u0108C\3\2\2\2\u0109\u010a\5N(\2\u010a\u010b\5F$\2\u010b\u010c"+
		"\5D#\2\u010c\u010f\3\2\2\2\u010d\u010f\3\2\2\2\u010e\u0109\3\2\2\2\u010e"+
		"\u010d\3\2\2\2\u010fE\3\2\2\2\u0110\u0111\5J&\2\u0111\u0112\5H%\2\u0112"+
		"G\3\2\2\2\u0113\u0114\5P)\2\u0114\u0115\5J&\2\u0115\u0116\5H%\2\u0116"+
		"\u0119\3\2\2\2\u0117\u0119\3\2\2\2\u0118\u0113\3\2\2\2\u0118\u0117\3\2"+
		"\2\2\u0119I\3\2\2\2\u011a\u011b\5L\'\2\u011b\u011c\5T+\2\u011c\u0125\3"+
		"\2\2\2\u011d\u0125\5^\60\2\u011e\u011f\7\26\2\2\u011f\u0120\5@!\2\u0120"+
		"\u0121\7\27\2\2\u0121\u0125\3\2\2\2\u0122\u0123\7\36\2\2\u0123\u0125\5"+
		"J&\2\u0124\u011a\3\2\2\2\u0124\u011d\3\2\2\2\u0124\u011e\3\2\2\2\u0124"+
		"\u0122\3\2\2\2\u0125K\3\2\2\2\u0126\u012a\7\37\2\2\u0127\u012a\7 \2\2"+
		"\u0128\u012a\3\2\2\2\u0129\u0126\3\2\2\2\u0129\u0127\3\2\2\2\u0129\u0128"+
		"\3\2\2\2\u012aM\3\2\2\2\u012b\u012c\t\3\2\2\u012cO\3\2\2\2\u012d\u012e"+
		"\t\4\2\2\u012eQ\3\2\2\2\u012f\u0130\t\5\2\2\u0130S\3\2\2\2\u0131\u0134"+
		"\5Z.\2\u0132\u0134\5V,\2\u0133\u0131\3\2\2\2\u0133\u0132\3\2\2\2\u0134"+
		"U\3\2\2\2\u0135\u0136\5X-\2\u0136\u0137\7\n\2\2\u0137\u0138\5@!\2\u0138"+
		"\u0139\7\13\2\2\u0139W\3\2\2\2\u013a\u013b\5Z.\2\u013bY\3\2\2\2\u013c"+
		"\u013d\5\\/\2\u013d[\3\2\2\2\u013e\u013f\7.\2\2\u013f]\3\2\2\2\u0140\u0144"+
		"\5`\61\2\u0141\u0144\7\60\2\2\u0142\u0144\5b\62\2\u0143\u0140\3\2\2\2"+
		"\u0143\u0141\3\2\2\2\u0143\u0142\3\2\2\2\u0144_\3\2\2\2\u0145\u0146\5"+
		"L\'\2\u0146\u0147\7/\2\2\u0147a\3\2\2\2\u0148\u0149\t\6\2\2\u0149c\3\2"+
		"\2\2\23w~\u008c\u0090\u00a6\u00bb\u00c4\u00d9\u00e8\u00f8\u0104\u010e"+
		"\u0118\u0124\u0129\u0133\u0143";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}