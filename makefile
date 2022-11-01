#Manage c Project by Makefile

OS=linux

CC = gcc -g -Wall -ansi -pedantic -std=c99

# PROG=manage_cypher
ARCHIVE=sortie.zip
TARGET_ARCHIVE=sources/*.c header/*.h Makefile

ifeq ($(OS), linux)
	DELETE=rm
	PROG=manage_cypher
else
	DELETE=del
	PROG=manage_cypher.exe
endif

#Identifier tous les fichiers .c de mon programme
SRC = $(wildcard sources/*.c)

#Créer une liste des fichiers .o liés aux fichiers .c
OBJ = $(SRC:.c=.o)

all: $(PROG)

$(PROG): $(OBJ)
	@echo "Fin build des fichiers .o et generation du fichier executable ==> \"$(PROG)\" : "
	$(CC) -o $@  $^

%.o : %.c
	$(CC) -o $@ -c $<

clean:
	@echo "Suppresion des fichiers .o : "
	$(DELETE) -rf sources/*.o

mrproper: clean
	@echo "Suppresion du programme executable \"$(PROG)\" et du fichier archive \"$(ARCHIVE)\" : "
	$(DELETE) -rf $(PROG) $(ARCHIVE)

zip:
	@echo "Generation du fichier archive \"$(ARCHIVE)\" : "
	tar -cvzf $(ARCHIVE) $(TARGET_ARCHIVE)
