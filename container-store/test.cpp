#include <stdlib.h>
#include <stdio.h>
#include "columnstore.h"

int main() {
	cs_container *cs;
	cs_element *el;
	cs = new cs_container("Tabel1");
	printf("Container: %s\n", cs->name());
	cs->addElement("Voornaam");
	cs->addElement("Achternaam");
	el=cs->firstElement();
	while (el!=NULL) {
		printf("Element: %s\n", el->name());
		el=cs->nextElement();
	}

	delete cs;
}


