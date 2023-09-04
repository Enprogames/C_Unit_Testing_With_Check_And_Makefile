CC = gcc
CFLAGS = -g -ggdb -Wall -Iinclude
STD = -std=c18
MATH = -lm

# These libraries must be included when compiling a test binary with check
CHECK = -pthread -lcheck -lrt -lm

BINARY = bin
BUILD = build
INCLUDE = include
SOURCE = src
TEST = tests

.PHONY: run debug test clean

# Main binary targets
${BINARY}/main: ${BUILD}/main.o ${BUILD}/point.o ${BUILD}/vector.o
	${CC} ${CFLAGS} ${STD} $^ -o $@ ${MATH}

# Object file targets
${BUILD}/main.o: ${SOURCE}/main.c ${INCLUDE}/point.h
	${CC} ${CFLAGS} ${STD} -c $< -o $@

${BUILD}/point.o: ${SOURCE}/point.c ${INCLUDE}/point.h
	${CC} ${CFLAGS} ${STD} ${MATH} -c $< -o $@

${BUILD}/vector.o: ${SOURCE}/vector.c ${INCLUDE}/vector.h
	${CC} ${CFLAGS} ${STD} ${MATH} -c $< -o $@

# Test targets
${BINARY}/test_all: ${BUILD}/test_all.o ${BUILD}/point.o ${BUILD}/vector.o
	${CC} ${CFLAGS} ${STD} $^ -o $@ ${CHECK}

${BUILD}/test_all.o: ${TEST}/test_all.c
	${CC} ${CFLAGS} ${STD} -c $< -o $@

${BUILD}/test_vector.o: ${TEST}/test_vector.c ${INCLUDE}/vector.h
	${CC} ${CFLAGS} ${STD} -c $< -o $@

${BUILD}/test_point.o: ${TEST}/test_point.c ${INCLUDE}/point.h
	${CC} ${CFLAGS} ${STD} -c $< -o $@

run: ${BINARY}/main
	${BINARY}/main

test: ${BINARY}/test_all
	${BINARY}/test_all

debug: ${BINARY}/main
	gdb ${BINARY}/main

clean: 
	rm -rf ${BUILD}/*.o ${BINARY}/*
