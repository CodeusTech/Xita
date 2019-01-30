#  Makefile
#  Cody Fagley
#  Authored on 	 January 25, 2019
#  Last Modified January 25, 2019

#  Contains build directives for XCS Cross Compiler (AArch64)

CCOMP=gcc
CFLAGS=-std=gnu99

build:  grammar src/xcs.c
	rm -rf _build
	mkdir _build
	${CCOMP} ${CFLAGS} src/xcs.c -o _build/xcs

#  Build Grammar
grammar: src/grammar/xcsl.y src/grammar/xcsl.l 
	bison src/grammar/xcsl.y
	flex src/grammar/xcsl.l



#  Tidy Generated Files
tidy:
	rm lex.yy.c xcsl.tab.c

