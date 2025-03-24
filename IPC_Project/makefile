CC 		= clang++
CFLAGS 	= -std=c++20 -Wall -pedantic-errors -g

src 	= src

SRCS 	=  $(src)/main.cpp

EXEC 	= bin/ipc

all:
	${CC} ${CFLAGS} ${SRCS} -o ${EXEC}

clean:
	${RM} ${EXEC}
