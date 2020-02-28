#include "Regulator.h"

Regulator::Regulator()
{
	pinMode(AO_pin, OUTPUT);

	Comanda_manuala.setInterval(0, 790, 0, 790);
	Comanda_manuala.setAlarme(-0.5, 0.5);
	Comanda_manuala.setTip(1);
	
	Referinta.setInterval(0,5,0,5);
	Referinta.setAlarme(0, 5);
	Referinta.setTip(0);

	Masura.setInterval(0, 1023, 0, 5);
	Masura.setAlarme(0, 5);
	Masura.setTip(0);  //0 = INPUT

	Comanda.setInterval(0, 5, 0, 255);
	Comanda.setAlarme(0, 5);
	Comanda.setTip(1);
}

void Regulator::setSemnalIntrare()
{
	int int_AI = analogRead(AI_pin);
	Masura.setValoare(int_AI);
	Algoritm.Set_Mas(Masura.val_out);
}

void Regulator::setReferinta()
{
	this->setComanda_manuala();
	if (abs(Comanda_manuala.val_out - btnUP) < 1e-10) // in functie de butonul apasat luam o actiune
	{
		Referinta.aduna(0.5);
		if (Referinta.val_out > Referinta.alarma_hi)
			Referinta.setValoare(Referinta.alarma_hi);
	}
	else if (abs(btnDOWN - Comanda_manuala.val_out) < 1e-10)
	{
		Referinta.aduna(-0.5);
		if (Referinta.val_out < Referinta.alarma_lo)
			Referinta.setValoare(Referinta.alarma_lo);
	}
	Algoritm.Set_Ref(Referinta.val_out);
}

void Regulator::setComanda_manuala()
{
	int val_buton = analogRead(0);
	// citim valoarea de pe senzor, in cazul nostru este pinul 0 = A0  = RX. Este folosit la transmiterea seriala de info
	// butoanele mele cand sunt citite ar trebui sa aiba valori centrate in : 0, 144, 329, 504, 741
	// pentru aproximare adaugam 50 la limite
	if (val_buton > 1000) Comanda_manuala.setValoare(btnNONE); // We make this the 1st option for speed reasons since it will be the most likely result
	if (val_buton < 50)  Comanda_manuala.setValoare(btnRIGHT);
	if (val_buton < 195 && val_buton >= 50) Comanda_manuala.setValoare(btnUP);
	if (val_buton < 380 && val_buton >= 195) Comanda_manuala.setValoare(btnDOWN);
	if (val_buton < 555 && val_buton >= 380) Comanda_manuala.setValoare(btnLEFT);
	if (val_buton < 790 && val_buton >= 555) Comanda_manuala.setValoare(btnSELECT);
}

void Regulator::sendComanda()
{
	Algoritm.Eval_Com();  //calculam valoarea
	Comanda.setValoare(Algoritm.Get_Com());
	 //transforma in format analog, probabil 1 analog = 0.02V
	analogWrite(AO_pin, Comanda.val_out);
}

