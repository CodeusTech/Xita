#  Makefile
#  Cody Fagley
#  Authored on 	 January 25, 2019
#  Last Modified  August  9, 2021

#  Contains build directives for XCS Cross Compiler (AArch64)

CCOMP=g++
CFLAGS=-std=c++11 -lm -Wall -I${PWD}/src
MEMTEST=-g -O0
SILENT=-Wno-unused-variable -Wno-unused-but-set-variable -Wno-switch -Wno-conversion-null -Wno-write-strings

DESTDIR=/usr/local/bin
CTXOPT=${HOME}/.ctxopt
CROSS=${CTXOPT}/cross

#  Build and Install Cross Compiler
update: build tidy
	sudo cp _build/xcs-aarch64 ${DESTDIR}/xita
	sudo rm -rf _build

install: assemblers build tidy
	sudo cp _build/xcs-aarch64 ${DESTDIR}/xita
	sudo rm -rf _build

uninstall: 
	sudo rm -rf ${DESTDIR}/xita
	rm -rf ${CROSS}

#  Build XCSL Cross Compiler
build:  grammar src/xcs/xcs.cc
	rm -rf _build
	mkdir _build
	${CCOMP} ${CFLAGS} ${SILENT} src/xcs/xcs.cc -o _build/xcs-aarch64

leakTest: grammar src/xcs/xcs.cc
	rm -rf _build
	mkdir _build
	${CCOMP} ${CFLAGS} ${MEMTEST} ${SILENT} src/xcs/xcs.cc -o _build/xcs-aarch64


#  Build Grammar
grammar: src/xcs/grammar/xita.y src/xcs/grammar/xcsl.l 
	bison src/xcs/grammar/xita.y
	flex src/xcs/grammar/xcsl.l

grammar-test:  src/xcs/grammar/xita.y src/xcs/grammar/xcsl.l 
	bison -Wcounterexamples src/xcs/grammar/xita.y
	flex src/xcs/grammar/xcsl.l

#  Tidy Generated Files
tidy:
	rm lex.yy.c xita.tab.c

# Grabs freestanding (OS-independent) assemblers in this order
#		* ARMv7 (32-bit)
#		* ARMv8 (64-bit) 
assemblers:
	rm -rf /home/${USER}/.ctxopt/asm
	mkdir -p /home/${USER}/.ctxopt
	mkdir -p /home/${USER}/.ctxopt/asm
	cp asm/ARMv7.tar.gz asm/ARMv8.tar.gz ${HOME}/.ctxopt/asm
	tar -xf ${HOME}/.ctxopt/asm/ARMv8.tar.gz -C ${HOME}/.ctxopt/asm/
	tar -xf ${HOME}/.ctxopt/asm/ARMv7.tar.gz -C ${HOME}/.ctxopt/asm/
	rm ${HOME}/.ctxopt/asm/*.tar*

unit-tests:
	rm -rf _build
	mkdir _build
	${CCOMP} ${CFLAGS} ${SILENT} tests/unit/XitaTests.cc -o _build/test-xita
	./_build/test-xita

runtime-tests:
	./tests/run-tests arm64 -a


#  PHONY TARGETS
.PHONY: install uninstall build

