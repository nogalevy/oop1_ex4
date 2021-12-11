#pragma once

#include "numof.h"

const int D_MENU_WIDTH = 1270;
const int D_MENU_HEIGHT = 500;

const int D_BTN_WIDTH = D_MENU_WIDTH / NUM_OF_ICONS * 0.75;
const int D_BTN_HEIGHT = D_BTN_WIDTH;
#include <iostream>
#include <string>

const int CON_HEIGHT = D_BTN_HEIGHT + D_BTN_HEIGHT * 0.75 + 20 + 40;


//-------------- new ---------------------------
const std::string TITLE = "Save The King - Level Generator";
const int WINDOW_W = 1270;
const int WINDOW_H = 790;

const int MENU_H = 190;

const int BOARD_H = WINDOW_H - MENU_H - 20;

const int BTN_W = ( WINDOW_W / NUM_OF_ICONS ) * 0.75;
const int BTN_H = MENU_H / 2.75;
const int BTN_SPACE = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS;

