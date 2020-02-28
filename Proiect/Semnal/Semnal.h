#ifndef SEMNAL_H

#define SEMNAL_H
//Arduino
#include "Arduino.h"
# include "Interval.h"
#include "Alg_PID.h"
class Semnal {
	Interval gama_in;  // intervalul in care trebuie sa fie la primire
	Interval gama_out;  // intervalul in care trebuie sa fie la transmitere
	float alarma_lo;  // valoarea maxima a seamnalului
	float alarma_hi;  // valoarea minima a semnalului
	bool tip; //(0 – IN / 1 - OUT)
	float val_in;  // cum e primit
	float val_out;  // cum e transmis
	friend class Regulator;
public:
	void setValoare(float);
	void aduna(float);
	void setInterval(float, float, float, float);
	float getVal_out();
	void setAlarme(float, float);
	void setTip(bool);
	void actualizeaza(Alg_PID);
};
#endif
