package main;

import java.io.IOException;
import java.io.InputStream;

import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.TokenStream;


class Main {
   public static void main(String[] args) {
      try {
        InputStream inputStream = Main.class.getResourceAsStream("../input/mipl00.txt");
        Lexer lexer = new miplLexer(CharStreams.fromStream(inputStream));
        TokenStream tokenStream = new CommonTokenStream(lexer);
        miplParser parser = new miplParser(tokenStream);
      } catch (IOException e) {
        e.printStackTrace();
      }
   }
}