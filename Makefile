CC                  = cc
CFLAGS              = -g -std=c99 -I. -O1 -Wall
INSTALL             = $(shell which install)

ADS_LIB = libads.a
ADS_INC = linkedlist.h linkedstack.h

LINKEDLIST_TEST_OBJ = linkedlist_test.o
LINKEDLIST_TEST = linkedlist_test

LINKEDLIST_OBJ = linkedlist.o

LINKEDSTACK_TEST_OBJ = linkedstack_test.o
LINKEDSTACK_TEST = linkedstack_test


all: lib

lib: ${LINKEDLIST_OBJ}
	ar rcs ${ADS_LIB} $?

${LINKEDLIST_TEST}: ${LINKEDLIST_OBJ} ${LINKEDLIST_TEST_OBJ}

${LINKEDSTACK_TEST}: ${LINKEDLIST_OBJ} ${LINKEDSTACK_TEST_OBJ}

clean: force_look
	rm -f ${ADS_LIB}
	rm -f ${LINKEDLIST_OBJ} ${LINKEDLIST_TEST_OBJ} ${LINKEDSTACK_TEST_OBJ}
	rm -f ${LINKEDLIST_TEST} ${LINKEDSTACK_TEST}

test: ${LINKEDLIST_TEST} ${LINKEDSTACK_TEST}
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./${LINKEDLIST_TEST} 
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./${LINKEDSTACK_TEST}

install: lib
ifndef INSTALL_PREFIX
	$(error INSTALL_PREFIX is not defined)
else
	$(INSTALL) $(ADS_LIB) $(INSTALL_PREFIX)/lib/
	$(INSTALL) $(ADS_INC) $(INSTALL_PREFIX)/include/
endif

force_look:
	@true
