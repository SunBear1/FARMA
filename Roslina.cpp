#include "Klasy.h"
void Roslina::SetX(int x)
{
	this->x = x;
}
void Roslina::SetY(int y)
{
	this->y = y;
}
int Roslina::GetX()
{
	return x;
}
int Roslina::GetY()
{
	return y;
}
int Roslina::GetSila()
{
	return sila;
}
char Roslina::GetID()
{
	return id;
}
string Roslina::GetImie()
{
	return imie;
}
void Roslina::SetImie(string imie)
{
	this->imie = imie;
}
void Roslina::SetSila(int sila)
{
	this->sila = sila;
}
int Roslina::GetInicjatywa()
{
	return inicjatywa;
}
void Roslina::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Roslina::GetWiek()
{
	return wiek;
}
void Roslina::SetID(char id)
{
	this->id = id;
}
void Roslina::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Roslina::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	
}
Organizm* Roslina::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return def;
}
void Roslina::rysowanie()
{

}
Roslina::~Roslina()
{

}