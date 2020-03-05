#pragma once
#ifndef _INCJALIZACJA_SAMOCHODOW_H_
#define _INCJALIZACJA_SAMOCHODOW_H_
#include "Samochody.h"
#include "wielkosci_tablic.h"
#include "fragmentacja_stringa.h"
#include <fstream>
Samochody *inicjalizacja_samochodow(string argv);
void wpisywanie_samochodow_do_tablicy(Samochody &wsk, string bufor);
#endif#