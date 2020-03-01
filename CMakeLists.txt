# (c) 2016  XingXing(HappyASR#gmail.com)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
project(GAME C ASM)
set(CMAKE_SUPPRESS_REGENERATION 1)
set(CMAKE_USE_RELATIVE_PATHS ON)
file(GLOB_RECURSE c_source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE asm_source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.S")
FOREACH(src ${asm_source_files})
	IF(src MATCHES "${CMAKE_CURRENT_SOURCE_DIR}/src/patch/.+\\.S")
		set(p_source_files ${p_source_files} ${src})
	ELSE(src MATCHES "${CMAKE_CURRENT_SOURCE_DIR}/src/patch/.+\\.S")
		set(s_source_files ${s_source_files} ${src})
	ENDIF(src MATCHES "${CMAKE_CURRENT_SOURCE_DIR}/src/patch/.+\\.S")
ENDFOREACH(src)

#this would be text->.h
add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/patch.S
                    DEPENDS ${p_source_files}
                    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen_patch.py ${ROM_OFFSET} ${CMAKE_CURRENT_SOURCE_DIR}/src/patch.S ${p_source_files}
)
	set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/patch.S)
add_custom_target( generate_patch DEPENDS ${p_source_files} )

set(SRC_LIST ${c_source_files} ${s_source_files} ${CMAKE_CURRENT_SOURCE_DIR}/src/patch.S)
add_executable(game ${SRC_LIST})
add_dependencies( game generate_patch )
target_link_libraries(game c nosys gcc g m)

#custom command to use objcopy to create .bin files out of ELF files
function(apply_patch INPUT)
	add_custom_command(TARGET ${INPUT} POST_BUILD
		COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/app_patch.py ${CROSS_COMPILE} ${INPUT} ${GAME_MAP} ${CMAKE_CURRENT_SOURCE_DIR}/${ROM_INPUT} ${CMAKE_CURRENT_SOURCE_DIR}/${ROM_OUTPUT}
		COMMENT "Generating Final ROM")
	set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${ROM_OUTPUT})
endfunction(apply_patch)

apply_patch(game)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "" )
