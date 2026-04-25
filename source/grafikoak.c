// 2025-2026 ikasturtea

/*---------------------------------------------------------------------------------
Hemen bideo sistemaren definizioa baino ez dugu egiten, beste EZER EZ DA IKUTU BEHAR

Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia
#include "grafikoak.h"
#include "spriteak.h"


void hasieratuBideoa() {
    /*  Bi pantailatan irudiak erakutsi ahal izateko memoria mapeatu */

     // VRAM configuración moderna
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);
    vramSetBankD(VRAM_D_SUB_SPRITE);
    vramSetBankE(VRAM_E_MAIN_SPRITE);

    /* Pantaila nagusia (main screen) */
    videoSetMode(MODE_5_2D |
                 DISPLAY_BG2_ACTIVE |
                 DISPLAY_BG3_ACTIVE);

    /* Pantaila azpikoa (sub screen) */
    videoSetModeSub(MODE_5_2D |
                    DISPLAY_BG3_ACTIVE);
}


/* ---- ZATI HAU EZ DA ALDATU BEHAR ---- */
/* ----  FONDOEN KONFIGURAZIOA DA   ---- */
/* ----     HEMENDIK HASITA         ---- */

/* Fondo sistema konfiguratzeko prozedura */
void hasieratuFondoak() {
    /*  Pantaila nagusiko 3 fondoaren afinitatea ezarri 16 biteko koloretarako */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // Memoriako hasierako helbidea
                 BG_PRIORITY(3); // Lehentasun baxua

    /*  Pantaila nagusiko 3 fondoaren transformazio matrizeari identitate matrizea esleitu */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Pantaila nagusiko 3 fondoaren egoera definitu */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Pantaila nagusiko 3 fondoaren afinitatea ezarri 16 biteko koloretarako */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // Memoriako hasierako helbidea
                 BG_PRIORITY(2);  // Lehentasun baxua

    /*  Pantaila nagusiko 3 fondoaren transformazio matrizeari identitate matrizea esleitu */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Pantaila nagusiko 3 fondoaren egoera definitu */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Bigarren mailako pantailako 3 fondoaren afinitatea ezarri 16 biteko koloretarako. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // Memoriako hasierako helbidea
                     BG_PRIORITY(3); // Lehentasun baxua

    /*  Bigarren mailako pantailako 3 fondoaren transformazio matrizeari identitate matrizea esleitu */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Bigarren mailako pantailako 3 fondoaren egoera definitu */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* ----       HONAINO       ---- */

void GrafikoakHasieratu()
{
	powerOn(POWER_ALL_2D);
    lcdMainOnBottom();
    hasieratuBideoa();
	consoleDemoInit(); // Goiko pantaila testua erakusteko eta behekoa irudiak erakusteko erabiliko da
}


//************************************************
//Spriteak
//************************************************

/* Spritentzako memoria hasieratu */
void initSpriteMem() {

	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);
}



void HasieratuGrafikoakSpriteak()
{
	GrafikoakHasieratu();
	hasieratuFondoak();
	initSpriteMem();
	memoriaErreserbatu();
	PaletaNagusiaEzarri();
	SpriteakMemorianGorde();
}

/***********************2025-2026*******************************/

