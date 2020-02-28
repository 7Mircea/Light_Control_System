#ifndef ALG_PID_H

#define ALG_PID_H
#include "AlgGen.h"
#include "Arduino.h"
class Alg_PID : public AlgGen {
	float Kr, Ti, Td, Te;  // param
						   // ------------------------
						   // Kr - componenta proportionala - constanta
						   // Ti - componenta integratoare(i) - constanta
						   // Td - componenta derivatoare(d) - constanta
						   // Te - pas de esantionare(e) - constanta
						   // ------------------------
	float q0, q1, q2;  // param_int
					   // ------------------------
					   // q0 =  Kr*(1+Te/Ti+Td/Te);
					   // q1 = -Kr*(1+2*Td/Te);
					   // q2 = Kr*Te/Ti;
					   // aceste valori sunt coeficientii contanti ai erorilor ek, ek_1 si ek_2;
					   // ------------------------
	float rk, yk, uk, uk_1, ek, ek_1, ek_2;  // var_int
											 // ------------------------
											 // rk = referinta sau semnalul la care vrem sa ajungem
											 // yk = semnalul de la fotorezistor
											 // uk = semnalul actual de transmis ledului(tensiunea)
											 // uk_1 = semnalul anterior transmis ledului(tensiunea)
											 // ek_1 = eroarea
											 // ------------------------
public:
	void Set_Param(float, float, float, float);  //seteaza ct integratoare deriv si 
	void Set_Ref(float);  // seteaza referinta la care vrem sa ajungem
	void Set_Mas(float);  // seteaza semnalul primit de la fotorezistor
	void Eval_Com();  // actualizeaza variabilele
	float Get_Com();  // returneaza uk AKA vf_com
	Alg_PID();

};
#endif
