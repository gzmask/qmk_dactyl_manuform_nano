#pragma once

#ifdef KEYBOARD_handwired_dactyl_manuform_nano_4x5
    #include "4x5.h"
#endif

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif
