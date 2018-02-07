.PHONY: all fmt clean

CFLAGS = -std=c99 -Wall -Werror -Wextra -g

SRC = flag.c
OBJ = ${SRC:.c=.o}

all: ${OBJ}

.c.o:
	@${CC} -c ${CFLAGS} $<

fmt:
	@clang-format -style=file -i $(wildcard *.c) $(wildcard *.h)

clean:
	@rm ${OBJ}

