target_sources (${CMAKE_PROJECT_NAME} PRIVATE "main.cpp"
                                             "MyWindow.cpp"
                                             "Board.cpp"
                                             "Menu.cpp"
                                             "Button.cpp"
                                             "ObjBtn.cpp"
                                                )

configure_file("Board.txt" ${CMAKE_BINARY_DIR} COPYONLY)
