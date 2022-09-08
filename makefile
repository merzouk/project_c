#Mon premier Makefile

OS=linux

ifeq ($(OS), linux)
	DELETE=rm
else
	DELETE=del
endif

CC = gcc -g -Wall -ansi -pedantic -std=c99

PROG=manage_cypher
ARCHIVE=sortie.zip
TARGET_ARCHIVE=*.c *.h Makefile

#Identifier tous les fichiers .c de mon programme
SRC = $(wildcard *.c)

#Créer une liste des fichiers .o liés aux fichiers .c
OBJ = $(SRC:.c=.o)

all: $(PROG)

$(PROG): $(OBJ)
	@echo "Fin build des fichiers .o et génération du fichier executable ==> \"$(PROG)\" : " 
	$(CC) -o $@  $^ 

%.o : %.c
	$(CC) -o $@ -c $< 

clean:
	@echo "Suppresion des fichiers .o : " 
	$(DELETE) -rf *.o

mrproper: clean
	@echo "Suppresion du programme executable \"$(PROG)\" et du fichier archive \"$(ARCHIVE)\" : " 
	$(DELETE) -rf $(PROG) $(ARCHIVE)

zip:
	@echo "Génération du fichier archive \"$(ARCHIVE)\" : " 
	tar -cvzf $(ARCHIVE) $(TARGET_ARCHIVE) 
