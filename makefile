
output: lex.yy.c y.tab.c
	gcc lex.yy.c y.tab.c -o output

lex.yy.c: ANSI-C.l
	flex ANSI-C.l

y.tab.c: structfe.y
	bison -yd structfe.y

clean:
	rm lex.yy.c y.tab.c output
