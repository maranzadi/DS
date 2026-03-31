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
int tekla;




int kolorea=0;
void drawPixel(int x, int y, u16 color) {
    if (x >= 0 && x < 256 && y >= 0 && y < 192) {
        framebuffer[y * 256 + x] = color;
    }
}
void jokoa01()
{	
	

	EGOERA=ZAI;

	for(int i = 0; i < 256 * 192; i++) framebuffer[i] = RGB15(31,31,31);

    // 4. Draw a red dot
    drawPixel(128, 96, RGB15(31, 0, 0));

	

	
	
	//erakutsiAtea();
	while (1)
	{

		if (TeklaDetektatu())
		{
			tekla=SakatutakoTekla();

			if (tekla==START)
			{
				int i;
				for(i = 0; i < 256 * 192; i++) framebuffer[i] = RGB15(31,31,31);

			}
			if (tekla==SELECT)
			{
				for(i = 0; i < 256 * 192; i++) framebuffer[i] = RGB15(0,0,0);

			}
			
		}
		


		if (ukimenUkitua())
		{
			touchPosition touch = ukimenPos();

			int x= touch.px;
			int y = touch.py;

			printf("\x1b[3;1HLocation: %d, %d", x, y);

			drawPixel(x, y, RGB15(31,0,0));
		}

		
		

		swiWaitForVBlank();
	}
	
}

/***********************2025-2026*******************************/

