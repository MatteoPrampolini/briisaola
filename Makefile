CC = gcc
SRC = src/main.c src/lib/brsar.c
OBJ = ${SRC:.c=.o}
OBJDIR = obj
CFLAGS = 
LDFLAGS = 

all: options briiscola

objdir:
	mkdir -p ${OBJDIR}

options:
	@echo briiscola build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $< -o ${OBJDIR}/$(notdir $@)

${OBJ}: objdir

briiscola: ${OBJ}
	${CC} -o $@ $(addprefix ${OBJDIR}/,$(notdir ${OBJ})) ${LDFLAGS}

clean:
	rm -rf ${OBJ}

.PHONY: all objdir clean
