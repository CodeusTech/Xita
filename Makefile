#  Makefile
#  Cody Fagley
#  Authored on 	 January 25, 2019
#  Last Modified January 25, 2019

#  Contains build directives for XCS Cross Compiler (AArch64)

CCOMP=gcc
CFLAGS=-std=gnu99

#  Build and Install Cross Compiler
install: build tidy
	cp _build/xcs-aarch64 /usr/bin/xcs-aarch64

#  Build XCSL Cross Compiler
build:  grammar src/xcs.c
	rm -rf _build
	mkdir _build
	${CCOMP} ${CFLAGS} src/xcs.c -o _build/xcs-aarch64

#  Build Grammar
grammar: src/grammar/xcsl.y src/grammar/xcsl.l 
	bison src/grammar/xcsl.y
	flex src/grammar/xcsl.l



#  Tidy Generated Files
tidy:
	rm lex.yy.c xcsl.tab.c

