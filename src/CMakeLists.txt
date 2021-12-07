target_sources (${CMAKE_PROJECT_NAME} PRIVATE "main.cpp"
                                             "MyWindow.cpp"
                                             "Board.cpp"
                                             "Menu.cpp"
                                                )

configure_file("level.txt" ${CMAKE_BINARY_DIR} COPYONLY)
