#Manage c project by Makefile

OSFLAG 				:=
OS_DETAILS          :=
ifeq ($(OS),Windows_NT)
	OSFLAG := WIN
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OS_DETAILS:=WIN_AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OS_DETAILS:=WIN_X86
	endif
else
	OSFLAG := $(shell uname -s | tr A-Z a-z)
	OS_DETAILS := $(OSFLAG)
endif

CC := gcc -g -Wall -ansi -pedantic -std=c99

ifeq ($(OSFLAG), linux)
	COMPIL:="compilation sous Linux"
	PROG:=manage_cypher
	ARCHIVE:=sortie.zip
	TARGET_ARCHIVE:=sources/*.c header/*.h  makefile
	DELETE:=rm -rf $(PROG) $(ARCHIVE)
	ZIP:=tar -cvzf $(ARCHIVE) $(TARGET_ARCHIVE)
	CLEAN:=rm -rf sources/*.o
	MSG_CLEAN:="Suppresion du programme executable \"$(PROG)\" et du fichier archive \"$(ARCHIVE)\" : "
	MSG_BUILD_ZIP:="Generation du fichier archive \"$(ARCHIVE)\" : "
	MSG_BUILD_END:="Fin build des fichiers .o et generation du fichier executable ==> \"$(PROG)\" : "
	MSG_CLEAN_O_FILE:="Suppresion des fichiers .o : "
endif
ifeq ($(OSFLAG), WIN)
	COMPIL:="compilation sous windows"
	PROG:=manage_cypher.exe
	ARCHIVE:=sortie.zip
	TARGET_ARCHIVE:=sources\*.c header\*.h  makefile
	DELETE:=del $(ARCHIVE) $(PROG)
	CLEAN:=del sources\*.o
	ZIP:=7za a -t7z  $(ARCHIVE) $(TARGET_ARCHIVE) -r
	MSG_CLEAN:="Suppresion du programme executable \"$(PROG)\" et du fichier archive \"$(ARCHIVE)\" : "
	MSG_BUILD_ZIP:="Generation du fichier archive \"$(ARCHIVE)\" : "
	MSG_BUILD_END:="Fin build des fichiers .o et generation du fichier executable ==> \"$(PROG)\" : "
	MSG_CLEAN_O_FILE:="Suppresion des fichiers .o : "
endif

#Identifier tous les fichiers .cpp de mon programme
SRC := $(wildcard sources/*.c)

#Créer une liste des fichiers .o liés aux fichiers .cpp
OBJ := $(SRC:.c=.o)

all: $(PROG)

$(PROG): $(OBJ)
	@echo $(COMPIL)
	@echo "OS_DETAILS = $(OS_DETAILS)"
	@echo $(MSG_BUILD_END)
	$(CC) -o $@  $^

%.o : %.c
	$(CC) -o $@ -c $<

clean:
	@echo $(MSG_CLEAN_O_FILE)
	$(CLEAN)

mrproper: clean
	@echo $(MSG_CLEAN)
	$(DELETE)

zip:
	@echo $(MSG_BUILD_ZIP)
	$(ZIP)
