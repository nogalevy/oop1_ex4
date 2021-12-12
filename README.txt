OOP ex3 - Game Level Editor for Save the King

Written by: Tali Kalev (טלי כלב), ID:208629691
            Noga Levy (נוגה לוי), ID:315260927

General Description of the Assignment:
  In this assignment, the user can edit a game level used for the game Save The King.
  The user can either start editing from a file with a level already created or start
  a new one. There is a menu with all the objects and a board in which the user can place
  the objects on.

Design:
  Classes: Window, Board, Menu, Button, ObjBtn 
    Window
        - deals with display of window and objects on window (menu, board etc)
        - processes events by sending them to where they are used (board/menu)
    Board
        - deals with loading and saving of board to file
        - adds and deletes objects from board
        - draws board onto window
    Menu
        - deals with display of buttons (characters, save, delete and clear)
        - checks with buttons if can be added to board
        - draws menu onto window
    Button
        - deals with design and display of buttons on menu
    ObjBtn
        - deals with capabilities of adding objects onto board
   Other:
        King, Mage, Warrior, Thief and throne can appear only once on the board. If the user 
        would like to change one of the locations of these objects and it already appears on 
        the board, they must first erase the previous appearance before placing in a new spot.
        The board can be a square only (all side lengths are equal). When the program starts, 
        the first character (King) is already chosen.

Files:
    Window.h and Window.cpp
        - deals with window class
    Board.h and Board.cpp
        - deals with board class
    Menu.h and Menu.cpp
        - deals with menu class
    Button.h and Button.cpp
        - deals with button class
    ObjBtn.h and ObjBtn.cpp
        - deals with objBtn class
    colors.h
        - contains consts of different colours used by sfml library
    numof.h
        - contains consts and enums of different objects and images displayed
    view_constants.h
        - contains consts used in displaying of objects/window

Main Data Structures and their Jobs:
	- see Design above

Notable Algorithms:
	- no notable algorithms

Known Bugs:
	- no known bugs

Other General Notes:
	- none

Board.txt File Format:
    The first value in the file will be one integer that will be the side lengths of the square board.
    On the following line the board will be displayed using the character representations.
