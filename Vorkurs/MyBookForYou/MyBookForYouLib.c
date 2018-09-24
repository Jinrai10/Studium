#include"MyBookForYouLib.h"

Kunde KundeAnlegen(unsigned int kundennummer, char * name, char * vorname) {
	Kunde kunde;
	kunde.nummer = kundennummer;
	kunde.name = name;
	kunde.vorname = vorname; 
	return kunde;
}

void KundeBearbeiten(Kunde * kunde, unsigned int kundennummer, char *name, char * vorname) {
	kunde.kundenummer = kundennummer;
	kunde.name = name;
	kunde.vorname = vorname;
}

void KundeLoeschen(kunde * kunde) {
	free(kunde);
}
