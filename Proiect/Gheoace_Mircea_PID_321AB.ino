#include <LiquidCrystal.h>
#include <Regulator.h>
#include <AlgGen.h>
#include <Alg_PID.h>
#include <Semnal.h>
#include <Interval.h>
#include <Afiseaza.h>

using namespace std;
//made after baza_POO 
//copyright Gheoace Mircea 321AB 2019
// initializam un obiect din biblioteca cu pinii interfetei
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  
// 8 - pentru transmitere de informatii gen lcd.setCursor, etc
// 9 - enable - pentru a porni transmisia de date pe pinii 4,5,6,7 cate un bit pe fiecare
// 4,5,6,7 - transmit fiecare cate un bit odata, transmit practic ce se afiseaza pe ecran

int AO_pin = 3; // pinul pe care vom transmite date de la UNO spre LED
int AI_pin = A1;  // AI_pin = pinul de AnalogInput, cu el citim valoarea de pe fotorezistor

#define btnRIGHT  0
#define btnUP     1 //aceste numere de la #define nu sunt pini!!
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int adc_key_in = 0;  // aceasta var reprezinta val masurata de pe pinul 0


 void setup(){
  pinMode(AO_pin, OUTPUT);
  pinMode(AI_pin, INPUT);
  
  lcd.begin(16, 2); // 16 coloane, 2 randuri
  lcd.clear();  // stergem ecranul
  lcd.setCursor(0,0);  // setam cursorul(de unde incepem sa scriem) la pozitia 0, 0
  lcd.print("Start PID Alg");  // afisarea propriu zisa
  
  lcd.clear();
  delay(1000);
  
  lcd.setCursor(0,1);
  lcd.print("Init. OK");
  delay(1000);
  Serial.begin(9600);
 }
Regulator regulator;
Afiseaza aff;
 void loop(){
  regulator.setSemnalIntrare();  //AKA Masura
  regulator.setReferinta();  //modifica Referinta si foloseste Comanda_Manuala
  regulator.sendComanda();
  aff.afis(regulator);
  delay(1000);   //intarziere o secunda
 }

