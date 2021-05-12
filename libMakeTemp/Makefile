# ==========================================
# © 2020 EExuke. All Rights Reserved.
# ==========================================

DIR_OBJ = .
DIR_SRC = .
INC_SRC = .

SRC = $(wildcard ${DIR_SRC}/*.c)
OBJ = $(patsubst %.c, ${DIR_OBJ}/%.o, $(notdir $(SRC)))

ST_LIB = libadd.a
DY_LIB = libadd.so

main_s = main_s
main_d = main_d

CC = gcc
CFLAGS = -g -Wall -I $(INC_SRC)

${main_s}: ${OBJ}
	@${CC} main.c ${DIR_OBJ}/${ST_LIB} -o main_s

${main_d}: ${OBJ}
	@${CC} main.c ${DIR_OBJ}/${DY_LIB} -o main_d

${DIR_OBJ}/%.o: ${DIR_SRC}/%.c
	$(warning Comping add.o ...)
	@$(CC) $(CFLAGS) add.c -c -o add.o
	ar -cr ${ST_LIB} add.o
	${CC} add.c -shared -fPIC -o ${DY_LIB}

# Prevent naming conflicts such as the existence of a file named clean.
.PHONY: clean

clean:
	rm ./*.o ./*.a ./*.so ./main_*
