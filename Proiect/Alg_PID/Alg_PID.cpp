#include "Alg_PID.h"

Alg_PID::Alg_PID()
{
	this->Set_Param(0.25, 0.125, 0, 1.0);  // Kr, Ti, Td, Te
	this->Set_Ref(35);  // set rk
	this->Set_Mas(35);  // set yk
	//q0 = Kr * (1 + Te / Ti + Td / Te);
	//q1 = -Kr * (1 + 2 * Td / Te);  aceste randuri erau de la POO
	//q2 = Kr * Te / Ti;
	q0 = Kr + Ti * Te / 2 + Td / Te;
	q1 = -Kr + Ti * Te / 2 - 2 * Td * Te;
	q2 = Td / Te;
	uk = 0.0;
	uk_1 = 0.0;
	ek = 0.0;
	ek_1 = 0.0;
	ek_2 = 0.0;
}

void Alg_PID::Set_Param(float _Kr, float _Ti, float _Td, float _Te)
{
	Kr = _Kr;
	Ti = _Ti;
	Td = _Td;
	Te = _Te;
}

void Alg_PID::Set_Ref(float _Ref)
{
	rk = _Ref;
}

void Alg_PID::Set_Mas(float _Mas)
{
	yk = _Mas;
	Serial.print("Valoare fotorezisto in Alg_PID");
	Serial.print(yk);
	Serial.println();
}



void Alg_PID::Eval_Com()
{
	ek = rk - yk;
	uk = uk_1 + q0 * ek + q1 * ek_1 + q2 * ek_2;
	uk_1 = uk;
	ek_2 = ek_1;
	ek_1 = ek;
	if (uk > 5.0)   //daca e mai mare decat maximul pe UNO opreste la 5V
		uk = 5.0;
	if (uk < 0.0)  // daca e mai mica decat e logic pt a nu aplica o tensiune inversa pe dioda si a o strapunge
		uk = 0.0;  //opreste la 0.
}

float Alg_PID::Get_Com()
{
	return uk;
}