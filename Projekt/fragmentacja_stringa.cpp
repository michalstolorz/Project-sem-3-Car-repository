#include "fragmentacja_stringa.h"

void fragmentacja_bufora(string &bufor, string &bufor_pomocniczy, int &index, int &licznik)
{
	bufor_pomocniczy = bufor.substr(0, index);
	bufor.erase(0, index + 2);
	licznik++;
	index = 0;
}