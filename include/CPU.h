/*

ESPectrum, a Sinclair ZX Spectrum emulator for Espressif ESP32 SoC

Copyright (c) 2023 Víctor Iborra [Eremus] and David Crespo [dcrespo3d]
https://github.com/EremusOne/ZX-ESPectrum-IDF

Based on ZX-ESPectrum-Wiimote
Copyright (c) 2020, 2022 David Crespo [dcrespo3d]
https://github.com/dcrespo3d/ZX-ESPectrum-Wiimote

Based on previous work by Ramón Martinez and Jorge Fuertes
https://github.com/rampa069/ZX-ESPectrum

Original project by Pete Todd
https://github.com/retrogubbins/paseVGA

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

To Contact the dev team you can write to zxespectrum@gmail.com or 
visit https://zxespectrum.speccy.org/contacto

*/

#ifndef CPU_h
#define CPU_h

#include <inttypes.h>
#include "ESPectrum.h"
#include "ESP32Lib/ESP32Lib.h"

// #define INT_START48 0
// #define INT_END48 32
// #define INT_START128 0
// #define INT_END128 36

#define INT_START48 0
#define INT_END48 32
#define INT_START128 0
#define INT_END128 36

class CPU
{
public:
    // call this for initializing CPU
    static void setup();

    // call this for executing a frame's worth of instructions
    static void IRAM_ATTR loop_fast();

    // call this for executing a frame's worth of instructions   
    static void IRAM_ATTR loop_trap();

    // call this for executing a frame's worth of instructions    
    static void IRAM_ATTR (*loop)();

    static void IRAM_ATTR checkTraps();

    // call this for resetting the CPU
    static void reset();

    // Flush screen
    static void FlushOnHalt();

    // get the number of CPU Tstates per frame (machine dependant)
    static uint32_t statesPerFrame();

    // get the number of microseconds per frame (machine dependant)
    static uint32_t microsPerFrame();

    // CPU Tstates elapsed in current frame
    static uint32_t tstates;

    // CPU Tstates elapsed since reset
    static uint64_t global_tstates;

    // CPU Tstates in frame
    static uint32_t statesInFrame;

    // Frames elapsed
    static uint32_t framecnt;

    // Late timing
    static uint8_t latetiming;

    // INT signal lenght
    static uint8_t IntStart;
    static uint8_t IntEnd;

};

static const unsigned char DRAM_ATTR wait_st[243] = { 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    6, 5, 4, 3, 2, 1, 0, 0, 6, 5, 4, 3, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0
}; // sequence of wait states

#endif // CPU_h
