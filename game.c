// Copyright (c) 2021 St. Mother Teresa HS All rights reserved.
//
// Created by: Lily Liu
// Created on: Nov 2021
// This program is the "Hello, World!" program for the GameBoy

#include <gb/gb.h>
#include <gb/font.h>

#include "simplebackground.c"
#include "simplebackgroundtiles.c"
#include "windowmap.c"

void interruptLCD() {
    HIDE_WIN;
}

void main() {
    font_t min_font;

    STAT_REG = 0x45;
    LYC_REG = 0x08;  //  Fire LCD Interupt on the 8th scan line (just first row)

    disable_interrupts();

    font_init();
    min_font = font_load(font_min);  // 36 tile
    font_set(min_font);

    set_bkg_data(37, 7, backgroundtiles);
    set_bkg_tiles(0, 0, 40, 18, background);

    set_win_tiles(0, 0, 5, 1, windowmap);
    move_win(7, 0);

    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    add_LCD(interruptLCD);
    enable_interrupts();
    set_interrupts(VBL_IFLAG | LCD_IFLAG);

    while (1) {
        SHOW_WIN;
        scroll_bkg(1, 0);
        wait_vbl_done();
    }
}
