#pragma once

const int NUM_OF_ICONS = 11;
const int GAME_BTN_NUM = 3;

enum GameButtons { CLEAR = 11, DELETE = 12, SAVE = 13};
enum Icons { KING, WIZARD, WARRIOR, THIEF, WALL, GATE, FIRE, ORC, PORTAL, THRONE, KEY};
const std::string PIC_NAMES[NUM_OF_ICONS + GAME_BTN_NUM] = { "king", "wizard", "warrior", "thief", "brickwall_2",
											"gate", "fire", "orc", "portal", "throne", "key", "clear", "delete", "save"};
