#include "StdAfx.h"
#include "Polje.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

CPolje::CPolje(int aN)
{
	podatki = new int[aN];
	velikost = aN;
}

CPolje::~CPolje(void)
{
	delete[] podatki;
}

int CPolje::vrniVelikost(){
    return velikost;
}

void CPolje::dolociVelikost(int aN){
	if(aN<=0)
		return;

    if(aN > vrniVelikost()){
	    int *polje2 = new int [aN];
	    for(int i=0;i<vrniVelikost();i++){
	    	polje2[i]=podatki[i];
	    }
	    delete[] podatki;
	    podatki = polje2;
	}else if (aN < vrniVelikost()){
	    int *polje2 = new int [aN];
		for(int i=0;i<aN;i++){
		    polje2[i]=podatki[i];
    	}
     	delete[] podatki;
    	podatki = polje2;
    }
}

int CPolje::vrniElement(int aIdx){
    if(aIdx < vrniVelikost() && aIdx >=0)
		return podatki[aIdx];
	else
        throw "ERR_NO_SUCH_ELEMENT";
}

void CPolje::dolociElement(int aIdx, int aValue){
	if (aIdx < vrniVelikost() && aIdx >=0)
		podatki[aIdx]=podatki[aValue];
	else
	    throw "ERR_NO_SUCH_ELEMENT";
}

bool CPolje::jeEnak(int aIdx, int aValue){
	if (aIdx < vrniVelikost() && aIdx >=0){
	    if (podatki[aIdx] == aValue)
			return true;
        else
	        return false;
	}else
       throw "ERR_NO_SUCH_ELEMENT";
}

void CPolje::napolniNakljucno(int aN){
	for(int i=0;i<vrniVelikost();i++){
        podatki[i] = rand()%(aN + 1); //  aN + 1   ker èe bi v aN vnesel 10, bi samo med 9 nakljuènimi izbral
	}
}

void CPolje::napolniNakljucno(int aLow, int aHigh){
	if (aLow > aHigh){
	    int a;
		a = aLow;
		aLow = aHigh;
		aHigh = a;
    }
	    for(int i=0;i<vrniVelikost();i++){
            podatki[i] = rand()%(aHigh - aLow + 1)+aLow;
    	}
}

void CPolje::napolniLinearno(){
    for(int i=0;i<vrniVelikost();i++){
        podatki[i] = i+1;
    }
}

void CPolje::napolniLinearno(int aLow, int aHigh){
	for(int i=0;i<vrniVelikost();i++){
        if (aLow+i<=aHigh)
			podatki[i] = aLow +i;
		else
			podatki[i] = aHigh;
	}
}

void CPolje::napolniLinearnoBrezNicle(int aLow, int aHigh){
    int j=aLow;
	for(int i=0;i<vrniVelikost();i++){
	    if(j==0)
			j++;
		if (j<aHigh){
			podatki[i] = j;
			j++;
		}else
			podatki[i] = j;

	}
}

bool CPolje::jeUrejeno(){
	for(int i = 0; i<vrniVelikost();i++){
	    if(podatki[i]>podatki[i+1])
		    return false;
    }
	return true;
}

void CPolje::zamenjaj(int aI, int aJ){
	if (aI<vrniVelikost() && aI >= 0 && aJ<vrniVelikost() && aJ >=0){
		int a;
	    a = podatki[aI];
		podatki[aI] = podatki[aJ];
		podatki[aJ] = a;
    }
	else
		throw "ERR_NO_SUCH_ELEMENT";
}

void CPolje::izpis(){
	if(vrniVelikost()!=0){
	    for(int i=0; i< vrniVelikost(); i++)
		    cout<<podatki[i]<<" ";
	    //cout<<podatki[vrniVelikost()-1]<<".";
	}else
		cout << "NO DATA";
}

void CPolje::premesaj(){
	for(int i=0; i<vrniVelikost()-1; i++){
	    int j = rand()%(vrniVelikost()-i-1)+i+1;
		zamenjaj(i,j);
    }
}

bool CPolje::jeElement(vector<int> aV, int aX){
	for (int i=0; i < aV.size();i++){
		if (aV[i] == aX)
			return true;
	}
	
	return false;
}

int CPolje::stRazlicnih(){
	if(jeUrejeno()){
	    int stR=0;
		for (int i=0; i<vrniVelikost()-1; i++){
		    if(podatki[i] != podatki[i+1])
				stR++;
		}
		return stR;// linearna èasovna zahtevnost
	}else{
	    vector<int> novoPolje;
		for (int i=0; i<vrniVelikost();i++){
		    if(!jeElement(novoPolje, podatki[i]))
				novoPolje.push_back(podatki[i]);
		}
		//vrni velikost novega polja
		return novoPolje.size();//èasovna zahtavnost: najslabše bo, ko bodo vsi elementi razlièni
	}							//0,1,2,3,...,n-1 }((n-1)n)/2
}								//prostorska zahtevnost: linearna


void CPolje::obrni(int i, int j){
	for (int h=0; h<((j-i+1)/2); h++){
			zamenjaj(i+h,j-h);
	}

}

void CPolje::zamenjajPredpono(int a){
	obrni(0,vrniVelikost()-1);
	obrni(0,a-1);
	obrni(a,vrniVelikost()-1);

}

int CPolje::bisekcija(int i){
	return bisekcija(i,0,vrniVelikost()-1);
}

int CPolje::bisekcija(int aX,int l,int d){
	if (l<=d){
		int s=(l+d)/2;
		if (podatki [s]==aX)
			return s+1;
		if (podatki [s]>aX)
			return bisekcija (aX, l, s-1);
		if (podatki [s]<aX)
			return bisekcija (aX, s+1, d);
	}else
		cout << "ni elementa";
}

void CPolje::zlij (int al, int as, int ad){
	
	
	int l=al;
	int d=as;
	int i=al;

	while (l<as && d<=ad){
		if (podatki[l]<podatki[d]){
			novo[i]=podatki[l];
			l++;
		}else{
			novo[i]=podatki[d];
			d++;
		}
		i++;
	}
	if (l>=as){
		for (int h=d; h<=ad; h++){
			novo[i]=podatki[h];
			i++;
		}
	}else{
		for (int h=l; h<as; h++){
			novo[i]=podatki[h];
			i++;
		}
	
	}
	for (int m=0; m<vrniVelikost(); m++)
		podatki[m]=novo[al+m];
	

}

void CPolje::urediZzlivanjem(){
	novo=new int [vrniVelikost()];
	uredizzlivanjem(0,(vrniVelikost()-1));
	delete [] novo;

}


void CPolje::uredizzlivanjem(int z, int k){
	if (z<k){
		int s =(z+k)/2;
		uredizzlivanjem(z,s);
		uredizzlivanjem(s+1,k);
		zlij(z,s,k);
	}
}

void CPolje::hitrourejanje(){
	hitrouredi(0,(vrniVelikost()-1));
}

void CPolje::hitrouredi(int l, int d){
	if (l<d){
		int s=deli(l,d);
		hitrouredi(l,s-1);
		hitrouredi(s+1,d);
	
	}
}
int CPolje::deli(int al, int ad){
	int delilni = podatki[al];
	int l=al;
	int d=ad;
	while (true){
		while(l<ad && podatki[l]<=delilni)
			l++;
		while(d>ad && podatki[d]>=delilni)
			d--;
		if(l<d)
			zamenjaj(d,l);
		else
			break;
	}
	zamenjaj(al,d);
	return d;

}
/*
int CPolje::vicinski (int dno, int vrh){
	if (dno==vrh)
		return podatki [dno];
	else{
		int s=(dno+vrh)/2;
		int a1=vicinski(dno,s);
		int a2=vicinski(s+1,vrh);
		if (a1== -1 && a2== -1){
			return -1;
		}else if (a2== -1){
			int x=0;
			for (int i=dno; i<=vrh; i++){
				if (podatki [i]==a1)
					x++;
			}
			if (x>(dno+vrh)/2)
				return a1;
			else
				return -1;
		}else if (a1== -1){
			int x=0;
			for (int i=dno; i<=vrh; i++){
				if (podatki [i]==a2)
					x++;
			}
			if (x>(dno+vrh)/2)
				return a2;
			else
				return -1;
		}else {

			int x=0;
			int y=0;

			for (int i=dno; i<vrh/2; i++){
				if (podatki [i]==a1)
					x++;

			for (int i=dno; i<vrh; i++){
				if (podatki [i]==a2)
					y++;
			if (x>(dno+vrh)/2)
				return a2;
			if (y>(dno+vrh)/2)
				return a2;
			return -1;
			
		}
	}

}*/