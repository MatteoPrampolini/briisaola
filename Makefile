CC = gcc
SRC = src/main.c src/lib/brsar.c src/lib/structs/header.c src/lib/structs/symb.c src/lib/structs/util.c
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
	rm -f $(addprefix ${OBJDIR}/,$(notdir ${OBJ}))
	rmdir --ignore-fail-on-non-empty ${OBJDIR}

.PHONY: all objdir clean
