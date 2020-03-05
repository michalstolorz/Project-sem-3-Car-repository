#pragma once
#ifndef _INCJALIZACJA_WLASCICIELI_H_
#define _INCJALIZACJA_WLASCICIELI_H_
#include "Wlasciciele.h"
#include "fragmentacja_stringa.h"
#include "wielkosci_tablic.h"
#include <fstream>
Wlasciciele *inicjalizacja_wlascicieli(string argv);
void wpisywanie_wlascicieli_do_tablicy(Wlasciciele &wsk, string bufor);
#endif#