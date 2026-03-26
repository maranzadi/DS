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
#include "spriteak.h"

int denb; // denbora neurtzen joateko; baloratu ea beharrezkoa den

const char *lista[] = {"A", "B", "SELECT", "START", "ESKUBI","EZKER", "GORA", "BEHERA", "R", "L"};
touchPosition pos_pantaila; // aldagai globala





int kolorea=0;

float presioa(int z1, int z2, int x);
void jokoa01()
{	
	int rgbKol[3] = {0, 0, 0};
    u16 color = RGB15(rgbKol[0], rgbKol[1], rgbKol[2]);
	// Aldagai baten definizioa
	int i=9;
	int tekla=0;;

	EGOERA=ZAI;

	swiWaitForVBlank();

	// float tickS =0.5;
	// int bitX =1024;
	// int latch = 65.536 - (1/tickS)*33554432/bitX; //latc=0
	// DENB0_DAT = latch;
	// DENB0_KNT = 0x00C3; //1024
	// irqSet(IRQ_TIMER0 , denbZerbErr)
	
	
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
			//iprintf("\x1b[1;1H\033[K");
			iprintf("\x1b[1;1HTekla=%s", lista[tekla]);
			//iprintf("\x1b[23;5HTekla sakatuta. Balioa=%c", lista[tekla]);
			// iprintf("\x1b[1;1HAldagai. Balioa=%s", lista[tekla]);

			if (tekla==R)
			{
				kolorea++;
			}else if (tekla==L)
			{
				kolorea++;
			}
			
			if(tekla==START){
				memset(VRAM_A, 0, 256 * 192 * 2);
			}

			if (kolorea>2)
			{
				kolorea=0;
			}else if (kolorea<0)
			{
				kolorea=2;
			}

			if (tekla==GORA)
			{
				rgbKol[kolorea]+=1;
			}else if (tekla==BEHERA)
			{
				rgbKol[kolorea]-=1;
			}
			if (rgbKol[kolorea]<0)
			{
				rgbKol[kolorea]=0;
			}else if (rgbKol[kolorea]>31)
			{
				rgbKol[kolorea]=31;
			}
			color = RGB15(rgbKol[0], rgbKol[1], rgbKol[2]);

			//iprintf("\x1b[5;1H\033[K");
			iprintf("\x1b[5;1Hrgb=%d, %d, %d", rgbKol[0], rgbKol[1], rgbKol[2]);
			iprintf("\x1b[7;1HKolorea: %d", kolorea);

			//iprintf("\x1b[50;5HTekla sakatuta. Balioa=%d", tekla);
		}else{
			
			iprintf("\x1b[1;1HTekla=null");
		}

		if (ukimenUkitua()==1)
		{
			pos_pantaila = ukimenPos(); 

			// size_t i;
			// for (i = 0; i < 3; i++)
			// {
			// 	iprintf("\x1b[%d;1H\033[K", i+12);
			// }
			

			int x= pos_pantaila.px;
			int y= pos_pantaila.py;
			float pres= presioa(pos_pantaila.z1, pos_pantaila.z2, x);
			iprintf("\x1b[12;1HposX=%d, posY=%d", x, y);
			iprintf("\x1b[13;1HRaw: %04X, %04X", pos_pantaila.z1, pos_pantaila.z2);
			iprintf("\x1b[14;1HPres: %d", (int)pres);

			
			float minP = 100;   // presión fuerte
			float maxP = 3000;  // presión débil

			float t = (pres - minP) / (maxP - minP);

			// Clamp
			if (t < 0) t = 0;
			if (t > 1) t = 1;

			
			t = 1.0f - t;

			// Escalar a radio
			int radius = 1 + t * 20;
			drawCircle(x, y, radius, color);
			iprintf("\x1b[16;1HRadius: %d", (int)t);


	

		}else{
			// size_t i;
			// for (i = 0; i < 2*2; i=i+2)
			// {
			// 	iprintf("\x1b[%d;1H\033[K", i+12);
			
			// }

			iprintf("\x1b[12;1HposX=%04X, posY=%04X", 0, 0);
			iprintf("\x1b[13;1HRaw: %04X, %04X", 0, 0);

		}
		
			
	}
	// Bukaeran etenak galarazi.
}

/***********************2025-2026*******************************/

float presioa(int z1, int z2, int x){
	if (z1 != 0) {
		float rtouch = x * ((float)z2 / z1 - 1.0f);

		// Umbral típico
		if (rtouch < 1000) {
			return rtouch;
		}else{
			return 0;
		}
	}
	return 0;
}