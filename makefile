CC=g++
CFLAGS=
LDFLAGS=
BINDIR=~/bin
PROGS=numbers

OBJECTS=numbers.o
numbers : ${OBJECTS}
	${CC} -o $@ ${OBJECTS} ${CFLAGS} ${LDFLAGS}

all: ${PROGS}
	make install -s
clean:
	rm -f ${PROGS} *.o *~
install:
	mkdir -p ${BINDIR}
	install -p -m 555 ${PROGS} ${BINDIR}
