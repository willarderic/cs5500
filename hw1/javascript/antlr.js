const antlr4 = require('antlr4/index');
const miplLexer = require('./miplLexer');
const miplParser = require('./miplParser');
const fs = require('fs')

var input = fs.readFileSync('../input/mipl00.txt', 'utf-8')
var chars = new antlr4.InputStream(input);
var lexer = new miplLexer.miplLexer(chars);
var tokens  = new antlr4.CommonTokenStream(lexer);
var parser = new miplParser.miplParser(tokens);
parser.buildParseTrees = true;   
var tree = parser.prog();   
