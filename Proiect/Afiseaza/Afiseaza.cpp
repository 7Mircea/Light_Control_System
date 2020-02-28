
#include "Afiseaza.h"

/*Afiseaza::Afiseaza()
{
	Regulator regulator;
}

Afiseaza::Afiseaza(Regulator& _regulator)
{
	regulator = _regulator;
}*/

void Afiseaza::afis(Regulator& regulator) {
	lcd.clear();
	lcd.setCursor(0, 0); //  prima cifra coloana, a doua linia
	lcd.print("Ref: Mas: Com:");  // Referinta(semnalul la care vrem sa ajungem)
	// Mas = Masurat = Semnalul masurat(ce am obtinu)
	// Com = Comanda = Semnalul pe care il trimitem pentru  aduce semnalul Masurat la aceasi valoare cu Referinta
	//lcd.setCursor(5,0);
	//lcd.print("Mas:");
	lcd.setCursor(0, 1);
	lcd.print(regulator.Referinta.getVal_out());  // de afisat valoarea in Volti
	lcd.setCursor(5, 1);
	lcd.print(regulator.Masura.getVal_out());  // de afisat valoarea in Volti a semnalului de la fotorezistor
	lcd.setCursor(10, 1);
	lcd.print(regulator.Comanda.getVal_out() / 255 * 5);  // de afisat in Volti semnalul trimis LED-ului

									  // comunicatie seriala pe monitor apar datele in domeniu 0 - 100 %
									  // print out the value you read:
	Serial.print("rk = ");
	Serial.print(regulator.Referinta.getVal_out());//*20.0);
	Serial.print("  yk = ");
	Serial.print(regulator.Masura.getVal_out());// *20.0);
	Serial.print("  uk = ");
	Serial.println(regulator.Comanda.getVal_out());// *20.0);   // afisare in procente
}