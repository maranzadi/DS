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
touchPosition pos_pantaila; // aldagai globala


int *rgb[]={0,0,0}
u16 color = RGB15(rgb[0], rgb[1], rgb[2]);

int kolorea=0;

void jokoa01()
{	
	// Aldagai baten definizioa
	int i=9;
	int tekla=0;;

	EGOERA=ZAI;

	swiWaitForVBlank();
	
	
	//iprintf("\x1b[22;5HHau idazte proba bat da");	// Hau 22 lerroan eta 5 zutabean hasiko da idazten.
						        //Aldagai baten idatzi nahi izanez gero, %d komatxoen barruan eta 
							//komatxoen kanpoan aldagaiaren balioa.
	//iprintf("\x1b[23;5HAldagai proba. Balioa=%d", i);

	//******************************2.JARDUERAN************************************************//
	// ORDEN HONETAN ZEREGIN HAUEK EGITEA GOMENDATZEN DA:
	// Teklatua konfiguratu behar da.	
	// Tenporizadorea konfiguratu behar da.
	// Etenen zerbitzu errutinak ezarri behar dira.
	// Teklatuaren etenak baimendu behar dira.
	// Tenporizadorearen etenak baimendu behar dira.
	// Etenak baimendu behar dira.
	//***************************************************************************************//

	
	//erakutsiAtea();
	while (1)
	{	
		/*************************************1.JARDUERAN**************************************/
		// ZAI egoeran dagoela, hemen teklatuaren inkesta egin, sakatu den tekla pantailaratu, eta START
		// sakatzean egoera aldatu
	
		if(TeklaDetektatu() ==1){
			//consoleClear();
			

			// if(tekla==3){
			// 	erakutsiAteaIrekita();
			// }

			//consoleClear();
			tekla=SakatutakoTekla();
			iprintf("\x1b[1;1H\033[K");
			iprintf("\x1b[1;1HAldagai. Balioa=%s", lista[tekla]);
			//iprintf("\x1b[23;5HTekla sakatuta. Balioa=%c", lista[tekla]);
			// iprintf("\x1b[1;1HAldagai. Balioa=%s", lista[tekla]);

			if (tekla=R)
			{
				kolorea++;
			}else if (tekla=L)
			{
				kolorea++;
			}
			
			if(tekla=START){
				emset(VRAM_A, 0, 256 * 192 * 2);
			}

			if (kolorea>2)
			{
				kolorea=0;
			}else if (kolorea<0)
			{
				kolorea=2;
			}

			if (tekla=GORA)
			{
				rgb[kolorea]+=10;
			}else if (tekla=BEHERA)
			{
				rgb[kolorea]-=10;
			}
			if (rgb[kolorea]<0)
			{
				rgb[kolorea]=0;
			}else if (rgb[kolorea]>255)
			{
				rgb[kolorea]=255
			}

			iprintf("\x1b[1;10H\033[K");
			iprintf("\x1b[1;10HAldagai. RGB=%d, %d, %d", rgb[0], rgb[1], rgb[2]);
			iprintf("\x1b[7;1HKolorea: %d", kolorea);

			//iprintf("\x1b[50;5HTekla sakatuta. Balioa=%d", tekla);
		}else{
			iprintf("\x1b[1;1H\033[K");
			iprintf("\x1b[1;1HAldagai. Balioa=null");
		}

		if (ukimenUkitua()==1)
		{
			pos_pantaila = ukimenPos(); 

			
			for (size_t i = 0; i < 2; i++)
			{
				iprintf("\x1b[%d;1H\033[K", i+6);
			}
			

			iprintf("\x1b[6;1HposX=%d, posY=%d", pos_pantaila.px, pos_pantaila.py);
			iprintf("\x1b[7;1HRaw: %04X, %04X", pos_pantaila.z1, pos_pantaila.z2);

		}else{
			for (size_t i = 0; i < 3*2; i=i+2)
			{
				iprintf("\x1b[%d;1H\033[K", i+8);
			
			}

			iprintf("\x1b[6;1HposX=%d, posY=%d", 0, 0);
			iprintf("\x1b[7;1HRaw: %04X, %04X", 0, 0);

		}
		
			
	}
	// Bukaeran etenak galarazi.
}

/***********************2025-2026*******************************/

