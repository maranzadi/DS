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

#include "grafikoak.h"		
#include "definizioak.h"
#include "spriteak.h"
#include "jokoa01.h"
#include "periferikoak.h"


//https://www.pmallory.com/bitmap-graphics-on-the-nintendo-ds-part-1-framebuffer-mode.html
#define OFFSET(r,c,w) ((r)*(w)+(c))
#define SCANLINECOUNTER   *(vu16 *)0x4000006
#define SCREENHEIGHT (192)
#define SCREENWIDTH  (256)

#define COLOR(r,g,b)  ((r) | (g)<<5 | (b)<<10)
#define REG_DISPCNT_MAIN  (*(vu32*)0x04000000)
#define REG_DISPCNT_SUB   (*(vu32*)0x04001000)
#define MODE_FB0          (0x00020000)
#define VRAM_A            ((u16*)0x6800000)
#define VRAM_A_CR         (*(vu8*)0x04000240)
#define VRAM_ENABLE       (1<<7)
#define SCANLINECOUNTER   *(vu16 *)0x4000006

int bgId;
u16* framebuffer;
//---------------------------------------------------------------------------------
void setPixel(int row, int col, u16 color);
void waitForVblank();


int main(void)
{
	REG_DISPCNT_MAIN = MODE_FB0;
	VRAM_A_CR = VRAM_ENABLE;

	setPixel(100, 100, COLOR(15,27,7));

	while(1) {
        if (ukimenUkitua()) {
            touchPosition touch = ukimenPos();
            
            // Pintar un punto blanco donde tocas para probar el stylus
            setPixel(touch.px, touch.py, COLOR(15,27,7));

            // El printf ahora sí encontrará la consola en la pantalla de ARRIBA
            iprintf("\x1b[3;1HLocation: %d, %d   ", touch.px, touch.py);
        }

        //swiWaitForVBlank();
    }
}
void setPixel(int row, int col, u16 color) {
    VRAM_A[OFFSET(row, col, SCREENWIDTH)] = color;
}
void waitForVblank() {
    while (SCANLINECOUNTER > SCREENHEIGHT);
    while (SCANLINECOUNTER < SCREENHEIGHT);
}
/***********************2025-2026*******************************/

