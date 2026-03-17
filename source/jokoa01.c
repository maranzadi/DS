// 2025-2026 ikasturtea

/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

// Guk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"

int denb; // denbora neurtzen joateko; baloratu ea beharrezkoa den

const char *lista[] = {"A", "B", "SELECT", "START", "ESKUBI","EZKER", "GORA", "BEHERA", "R", "L"};

void jokoa01()
{	
	// Aldagai baten definizioa
	int i=9;
	int tekla=0;;

	EGOERA=ZAI;
	
	
	iprintf("\x1b[22;5HHau idazte proba bat da");	// Hau 22 lerroan eta 5 zutabean hasiko da idazten.
						        //Aldagai baten idatzi nahi izanez gero, %d komatxoen barruan eta 
							//komatxoen kanpoan aldagaiaren balioa.
	iprintf("\x1b[23;5HAldagai proba. Balioa=%d", i);

	//******************************2.JARDUERAN************************************************//
	// ORDEN HONETAN ZEREGIN HAUEK EGITEA GOMENDATZEN DA:
	// Teklatua konfiguratu behar da.	
	// Tenporizadorea konfiguratu behar da.
	// Etenen zerbitzu errutinak ezarri behar dira.
	// Teklatuaren etenak baimendu behar dira.
	// Tenporizadorearen etenak baimendu behar dira.
	// Etenak baimendu behar dira.
	//***************************************************************************************//

	

	while (1)
	{	
		/*************************************1.JARDUERAN**************************************/
		// ZAI egoeran dagoela, hemen teklatuaren inkesta egin, sakatu den tekla pantailaratu, eta START
		// sakatzean egoera aldatu
	
		if(TeklaDetektatu() ==1){
			tekla=SakatutakoTekla();
			iprintf("\x1b[23;5Tekla sakatuta. Balioa=%d", a[tekla]);

		}
			
	}
	// Bukaeran etenak galarazi.
}

/***********************2025-2026*******************************/

