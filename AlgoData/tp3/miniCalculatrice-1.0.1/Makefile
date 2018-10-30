#NOM : CAI Chaolei
#NUMERO : 17812776
#EMAIL : chaoleicai@gmail.com

SHELL = /bin/sh
#définition des commandes utilisees
CC = gcc
ECHO = echo
RM = rm -rf
TAR = tar
MKDIR = mkdir
CHMOD = chmod
CP = rsync -R
#déclaration des options pour gcc
CFLAGS = -Wall
CPPFLAGS = -I. #ajouter un chemin pour les includes
LDFLAGS = -L/usr/lib -lm
#définition des fichiers et dossiers
PROGNAME = miniCalculatrice
PACKAGE=$(PROGNAME)
VERSION = 1.0.1
distdir = $(PACKAGE)-$(VERSION)
HEADERS = myLib/ratio.h myLib/rpile.h myLib/pile.h 
SOURCES = myMain.c myLib/ratio.c myLib/rpile.c myLib/pile.c 
OBJS = $(SOURCES:.c=.o)
DISTFILES = $(SOURCES) Makefile $(HEADERS)
all: $(PROGNAME)

$(PROGNAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(PROGNAME)

%.o: %.c #dependence
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

dist: distdir
	$(CHMOD) -R a+r $(distdir)
	$(TAR) zcvf $(distdir).tgz $(distdir)
	$(RM) $(distdir)
distdir: $(DISTFILES)
	$(RM) $(distdir)
	$(MKDIR) $(distdir)
	$(CHMOD) 777 $(distdir)
	$(CP) $(DISTFILES) $(distdir)/
clean:
	$(RM) $(PROGNAME) $(OBJS) *~ $(distdir).tgz
