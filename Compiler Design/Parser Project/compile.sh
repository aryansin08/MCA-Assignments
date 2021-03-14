lex lexer.l
yacc -d -v parser.y
gcc y.tab.c
./a.out<input4.c
