#ifndef REGULATOR_H

#define REGULATOR_H

#include"Alg_PID.h"
#include"Semnal.h"
#include <stdlib.h>

#define btnRIGHT  0
#define btnUP     1 //aceste numere de la #define nu sunt pini!!
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

extern int AI_pin;    // AI_pin = pinul de AnalogInput, cu el citim valoarea de pe fotorezistor
extern int AO_pin;     // pinul pe care vom transmite date de la UNO spre LED

class Regulator {
	Alg_PID Algoritm;
	//Afisare - clasa Aff
	//Comunicatie - clasa Comm
	bool Regim;  // daca mai aplica modificare sau nu, daca yk(semnal fotorez) > rk(semnal la care vrem sa ajungem)
	Semnal Comanda_manuala;  // afecteaza rk(referinta - semnal la care vrem sa ajungem)
	Semnal Referinta;  // referinta
	Semnal Masura;  //semnalul yk ce arata cata lumina este in camera pe o scara de 0-5(semnal de la fotorezistor)
	Semnal Comanda;  //semnalul uk pe care il avem in acest moment catre LED
	friend class Afiseaza;
public:
	Regulator();
	void setSemnalIntrare();
	void setReferinta();
	void setComanda_manuala();
	void sendComanda();
	
};
#endif
