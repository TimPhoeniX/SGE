set (GameSOURCES
		sge_game.hpp
		sge_game.cpp)

set (InputHandlerSOURCES
		InputHandler/sge_input_binder.hpp
		InputHandler/sge_input_binder.cpp
		InputHandler/sge_input_handler.hpp
		InputHandler/sge_input_handler.cpp)

set (DirectorSOURCES
		Director/sge_director.hpp
		Director/sge_director.cpp)

set (ActionHandlerSOURCES
		ActionHandler/sge_action_handler.hpp
		ActionHandler/sge_action_handler.cpp)

add_library (ActionHandler ${ActionHandlerSOURCES})

target_link_libraries(ActionHandler Action)

install(TARGETS ActionHandler DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")

add_library (Game
		${GameSOURCES}
		${InputHandlerSOURCES}
		${DirectorSOURCES})
		
	
target_link_libraries(Game
		Object
		Utils
		IO
		Level
		Scene
		Renderer
		Utils
		ActionHandler)

install(TARGETS Game DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")