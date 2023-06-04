
SET(LINE_SRC    
    global.h  
	drawPix.h     drawPix.cpp
	drawLine.h    drawLine.cpp
	main.cpp)

add_executable(line_algo ${LINE_SRC})

set_target_properties(line_algo PROPERTIES FOLDER "01line")
