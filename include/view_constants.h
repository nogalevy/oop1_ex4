#pragma once

#include "numof.h"
#include <iostream>
#include <string>


const std::string TITLE = "Save The King - Level Generator"; //window title

const int WINDOW_H = 800;  //window width
const int WINDOW_W = 1270; //window height

const int MENU_H = 190;	   //menu height

const int BOARD_H = WINDOW_H - MENU_H - 20; //board height

const int BTN_W = ( WINDOW_W / NUM_OF_ICONS ) * 0.75; //button width
const int BTN_H = MENU_H / 2.75;					  //button height
const int BTN_SPACE = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS; 

