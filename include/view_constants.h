#pragma once

#include "numof.h"
#include <iostream>
#include <string>



const std::string TITLE = "Save The King - Level Generator";
const int WINDOW_W = 1270;
const int WINDOW_H = 800;

const int MENU_H = 190;

const int BOARD_H = WINDOW_H - MENU_H - 20;

const int BTN_W = ( WINDOW_W / NUM_OF_ICONS ) * 0.75;
const int BTN_H = MENU_H / 2.75;
const int BTN_SPACE = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS;

