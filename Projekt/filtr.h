#pragma once
#include "Wlasciciele.h"
#include "Samochody.h"
#include "Relacje.h"
#include <fstream>
class filtr
{
public:
	filtr();
	virtual void filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku) = 0;
	~filtr();
};

