// 2025-2026 ikasturtea

/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"


int tekla; // Sakatutako tekla gordetzeko aldagaia; baloratu ea behar den
// touchPosition pos_pantaila; // aldagai globala



int TeklaDetektatu() 
{
	// TRUE itzultzen du teklaren bat sakatu dela detektatzen badu
	if ((~TEKLAK_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int SakatutakoTekla() 
{

	// Sakatutako teklaren balioa itzultzen du: A=0;B=1;SELECT=2;START=3;ESKUBI=4;EZKER=5;
	// GORA=6;BEHERA=7;R=8;L=9;
        // Saiatu kodea irakurgarria idazten.

	int zenbat =0;
	while (zenbat<10)
	{
		
		if(~TEKLAK_DAT & (1<<zenbat)){
			return zenbat;
		}

		zenbat++;
	}
	return zenbat;

	

}



// int ukimenUkitua() {
//  touchRead(&pos_pantaila); // libnds-ko funtzioa
//  // Ez badago pixelik ukituta, return 0, bestela 1
//  return !(pos_pantaila.px==0 && pos_pantaila.py==0);
// }

// void ukimenPos(int *lekua){
// 	&lekua= touchRead(&pos_pantaila);
// }


void konfiguratuTeklatua(int TEK_konf)
{
	// Teklatuaren konfigurazioa bere S/I erregistroak aldatuz
	// Parametro bezala jasotako balioan 1 egoeran dauden bitak aldatu kontrol-erregistroan
	
}

void konfiguratuTenporizadorea(int Latch, int TENP_konf)
{
	// Tenporizadorearen konfigurazioa bere S/I erregistroak aldatuz
	// Parametro bezala jasotako balioan 1 egoeran dauden bitak aldatu kontrol-erregistroan
	
}

void TekEtenBaimendu()
{
	// Teklatuaren etenak baimendu
	// Lan hau burutzeko hasieran eten guztiak galarazi behar dira eta bukaeran baimendu 
	EtenakGalarazi();   // IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
	EtenakBaimendu();   // IME=1;
}

void TekEtenGalarazi()
{

	// Teklatuaren etenak galarazi
	// Lan hau burutzeko hasieran eten guztiak galarazi behar dira eta bukaeran baimendu 
	EtenakGalarazi();   // IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
	EtenakBaimendu();   // IME=1;
}  

void DenbEtenBaimendu()
{

// Tenporizadore baten etenak baimendu (Timer0)
// Horretarako hasieran eten guztiak galarazi eta bukaeran berriro baimendu
	EtenakGalarazi();   // IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
	EtenakBaimendu();   // IME=1;
}

void DenbEtenGalarazi()
{

// Tenporizadore baten etenak galarazi (Timer0)
// Horretarako hasieran eten guztiak galarazi eta bukaeran berriro baimendu
	EtenakGalarazi();   // IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
	EtenakBaimendu();   // IME=1;

}

void ErlojuaMartxanJarri()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
}

void ErlojuaGelditu()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	
}

/***********************2025-2026*******************************/

