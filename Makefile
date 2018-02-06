.PHONY: all fmt clean

SRC = flag.c
OBJ = ${SRC:.c=.o}

all: ${OBJ}

.c.o:
	@${CC} -c ${CFLAGS} $<

fmt:
	@clang-format -style=file -i $(wildcard *.c) $(wildcard *.h)

clean:
	@rm ${OBJ}

