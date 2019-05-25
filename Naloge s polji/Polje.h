#pragma once
#include <vector>

using namespace std;
class CPolje
{
public:
	CPolje(int aN);
	~CPolje(void);//void lahko tudi izbrišemo, to je prazen seznam
	int vrniVelikost();
	void dolociVelikost(int aN);
	int vrniElement(int aIdx);
	void dolociElement(int aIdx, int aValue);
	bool jeEnak(int aIdx, int aValue);
	void napolniNakljucno(int aN);
	void napolniNakljucno(int aLow, int aHigh);
	void napolniLinearno();
	void napolniLinearno(int aLow, int aHigh);
	void napolniLinearnoBrezNicle(int aLow, int aHigh);
	bool jeUrejeno();
	void zamenjaj(int aI, int aJ);
	void izpis();
	void premesaj();
	int stRazlicnih();
	void obrni(int i, int j);
	void zamenjajPredpono(int a);
	int bisekcija(int i);
	void urediZzlivanjem();
	void hitrourejanje();
	int vicinski (int dno, int vrh);

private:
	int *podatki;
	int *novo;
	int velikost;
    bool jeElement(vector<int> aV, int aX);
	int bisekcija(int aX,int l, int d);
	void zlij (int al, int as, int ad);
	void uredizzlivanjem(int z, int k);
	void hitrouredi(int l, int d);
	int deli(int al, int ad);
};
