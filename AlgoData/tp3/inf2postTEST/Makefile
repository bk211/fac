SHELL = /bin/sh
#definition des commandes utilisees
CC = gcc
ECHO = echo
RM = rm -f
TAR = tar
MKDIR = mkdir
CHMOD = chmod
CP = cp
#declaration des options pour gcc
PG_FLAGS =
CFLAGS = -Wall -O3 $(PG_FLAGS)
CPPFLAGS = -I.
LDFLAGS = $(PG_FLAGS)
#definition des fichiers et dossiers
PROG = exce
PACKAGE=fuu
VERSION = 0.1
distdir = $(PACKAGE)-$(VERSION)
HEADERS = pile.h
OBJ = fuu.o pile.o
SOURCES = $(OBJ:.o=.c)
DISTFILES = $(SOURCES) Makefile $(HEADERS)
all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROG)
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<
dist: distdir
	$(CHMOD) -R a+r $(distdir)
	$(TAR) czvf $(distdir).tgz $(distdir)
	$(RM) -r $(distdir)
distdir: $(DISTFILES)
	$(RM) -r $(distdir)
	$(MKDIR) $(distdir)
	$(CHMOD) 777 $(distdir)
	$(CP) -rf $(DISTFILES) $(distdir)
clean:
	@$(RM) $(PROG) $(OBJ) *~ $(distdir).tgz gmon.out