CC = gcc
SRC = src/main.c src/lib/brsar.c
OBJ = ${SRC:.c=.o}
OBJDIR = obj
CFLAGS = 
LDFLAGS = 

ifeq (${OS},Windows_NT)
    MKDIR = if not exist ${OBJDIR} mkdir ${OBJDIR}
    RM = del /Q
    EXECUTABLE = briiscola.exe
else
    MKDIR = mkdir -p ${OBJDIR}
    RM = rm -f $(addprefix ${OBJDIR}/,$(notdir ${OBJ}))
    RMDIR = rmdir --ignore-fail-on-non-empty ${OBJDIR}
    EXECUTABLE = briiscola
endif

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
	${RM}
	${RMDIR}

.PHONY: all objdir clean
