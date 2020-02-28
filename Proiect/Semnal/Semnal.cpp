#include "Semnal.h"



void Semnal::setValoare(float valoare)
{
	val_in = valoare;
	val_out = val_in * (gama_out.max / gama_in.max);  //ex : int_AI * (5.0 / 1023.0) pt semnal de la fotorezistor
	Serial.print(val_out);
	Serial.println();
}

void Semnal::aduna(float x)
{
	val_out += x;
	val_in = val_out;
}

void Semnal::setInterval(float in_min, float in_max, float out_min, float out_max)
{
	gama_in.setInterval(in_min, in_max);
	gama_out.setInterval(out_min, out_max);
}

float Semnal::getVal_out()
{
	return val_out;
}

void Semnal::setAlarme(float _alaram_lo, float _alarma_hi)
{
	alarma_lo = _alaram_lo;
	alarma_hi = _alarma_hi;
}

void Semnal::setTip(bool _tip)
{
	tip = _tip;
}

void Semnal::actualizeaza(Alg_PID al)
{
	// doar pentru semnalul Comanda
	al.Eval_Com();
}