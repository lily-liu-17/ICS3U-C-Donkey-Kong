// Copyright (c) 2021 St. Mother Teresa HS All rights reserved.
//
// Created by: Lily Liu
// Created on: Nov 2021
// This program is the "Hello, World!" program for the GameBoy

#include <stdio.h>
#include <gb/gb.h>

#include "smiler.c"

int main() {
    // this function displays a happy face

    set_sprite_data(0, 2, smiler);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;
}
