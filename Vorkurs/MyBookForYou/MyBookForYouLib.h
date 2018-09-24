#include"MyBookForYouLib.c"

typedef struct {
	char isbn[10];
	char name[10];
	char author[10];
	Buch *next;
} Buch;

typedef struct {
	unsigned int nummer;
	char name[10];
	char vorname[10];
	Kunde *next;
} Kunde; 

typedef struct {
	Kunde *next;
	Kunde *prev;
} Kundenliste;

void kundeAnlegen(Kunde *, unsigned int, char *, char *);

void kundeLoeschen(Kunde *,unsigned int);

void kundeBearbeiten(Kunde *, unsigned int, char *, char *);

void BuchAnlegen(Buch *, char *, char *, char *);

void BuchLoeschen(Buch *, char *);

void BuchBearbeiten(Buch *, char *, char *, char *);
