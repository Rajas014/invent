add_library(xlntMaster STATIC IMPORTED GLOBAL)

set_target_properties(xlntMaster PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/xlntMaster/include)
