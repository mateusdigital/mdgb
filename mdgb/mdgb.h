//~---------------------------------------------------------------------------//
//                               *       +                                    //
//                         '                  |                               //
//                     ()    .-.,="``"=.    - o -                             //
//                           '=/_       \     |                               //
//                        *   |  '=._    |                                    //
//                             \     `=./`,        '                          //
//                          .   '=.__.=' `='      *                           //
//                 +                         +                                //
//                      O      *        '       .                             //
//                                                                            //
//  File      : mdgb.h                                                        //
//  Project   : mateus.digital - gameboy                                      //
//  Date      : 2024-03-20                                                    //
//  License   : See project's COPYING.TXT for full info.                      //
//  Author    : mateus.digital <hello@mateus.digital>                         //
//  Copyright : mateus.digital - 2024                                         //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __MDGB_H__
#define __MDGB_H__

//------------------------------------------------------------------------------
#include <gb/gb.h>
#include <gbdk/emu_debug.h>

#include <rand.h>
#include <types.h>

#include <stdio.h>
#include <string.h>

//
// Types
//

// -----------------------------------------------------------------------------
#define bool uint8_t
#define u8   uint8_t
#define u16  uint16_t
#define i8   int8_t
#define i16  int16_t

#define false 0
#define true  (!false)

//
// Tiles Sizes
//

// -----------------------------------------------------------------------------
#define TILE_SIZE     8
#define TILE_SIZE_x2 16
#define TILE_SIZE_x3 24
#define TILE_SIZE_x4 32

#define TILE_SIZE_SHIFT 3

#define SCREEN_WIDTH  SCREENWIDTH
#define SCREEN_HEIGHT SCREENHEIGHT

#define SCREEN_WIDTH_IN_TILES  20
#define SCREEN_HEIGHT_IN_TILES 18

#define FIRST_PIXEL_X   8
#define FIRST_PIXEL_Y  16
#define LAST_PIXEL_X  168
#define LAST_PIXEL_Y  160


//
// Input
//

// -----------------------------------------------------------------------------
extern u8 last_input;
extern u8 curr_input;

#define JUST_PRESSED(J) ((J & last_input) == 0 && (curr_input & J))
#define UPDATE_INPUT()  { last_input = curr_input; curr_input = joypad(); }

//
// Math
//

// -----------------------------------------------------------------------------
#define Math_Clamp(_v_, _min_, _max_)  \
    ((_v_) < (_min_)) ? (_min_) :      \
    ((_v_) > (_max_)) ? (_max_) :      \
                        (_v_)   ;

#define Math_Min(_a_, _b_) \
    ((_a_) <= (_b_)) ? (_a_) : (_b_)

//
// Memory
//

// -----------------------------------------------------------------------------
#define Memory_ZeroArr(_var_, _type_, _size_) \
    memset(&_var_, 0, sizeof(_type_) * (_size_))


//
// Random
//

// -----------------------------------------------------------------------------
#define Rand_Seed(_v_) initrand(_v_)
#define Rand_u8() ((u8)(rand() % 255))
#define Rand_u8_ex(_min_, _max_) ((_min_) + (Rand_u8() % ((_max_) - (_min_))));


//
// Print
//

// -----------------------------------------------------------------------------
// #define flushprint(s, ...) do { printf(s, __VA_ARGS__); } while(0);

#define debugprint(...) { \
    do {                \
        EMU_printf("%s:%d", __FILE__, __LINE__); \
        EMU_printf(__VA_ARGS__); \
        EMU_printf("-------------------\n"); \
    } while(0); \
}


#endif // __MDGB_H__