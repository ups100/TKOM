MESSAGE( "Building analyser target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${TKOM_SOURCE_DIR}/Analyser/include
						${TKOM_SOURCE_DIR}/Tokens/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( TESTS_SRC
		${TKOM_SOURCE_DIR}/Tests/src/main.cpp
		
)

add_executable( testProgram ${TESTS_SRC} )
MESSAGE(${QT_QTSQL_LIBRARIES})
set(CMAKE_EXE_LINKER_FLAGS "-lQtSql")
#here add some additional qt modules
TARGET_LINK_LIBRARIES(	testProgram
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libanalyser.a
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libtokens.a
		${QT_QTSQL_LIBRARIES}
		${QT_LIBRARIES}
		${QT_QTNETWORK_LIBRARIES}
		${Boost_LIBRARIES}
)
