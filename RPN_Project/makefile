CC 		= clang++
CFLAGS 	= -std=c++20 -Wall -pedantic-errors -g

src 	= src

SRCS 	= $(src)/main.cpp \
		  $(src)/RPN_Parser.cpp \
		  $(src)/RPN_Stack.cpp

EXEC 	= bin/calculator

all:
	${CC} ${CFLAGS} ${SRCS} -o ${EXEC}

clean:
	${RM} ${EXEC}
