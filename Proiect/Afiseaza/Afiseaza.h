#ifndef AFISEAZA_H

#define AFISEAZA_H
#include<LiquidCrystal.h>
#include"Regulator.h"
extern LiquidCrystal lcd;
class Afiseaza {
	//Regulator regulator;
public:
	//Afiseaza();
	//Afiseaza(Regulator&);
	void afis(Regulator&);
};

#endif
