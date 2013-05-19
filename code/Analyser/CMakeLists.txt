MESSAGE( "Building analyser target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${TKOM_SOURCE_DIR}/Analyser/include
						${TKOM_SOURCE_DIR}/Tokens/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( ANALYSER_SRC
		${TKOM_SOURCE_DIR}/Analyser/src/DataBaseConnection.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/FileReader.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Header.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Lexer.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log1Base.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log1.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log2.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log3.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log4Base.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log4WithReading.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Log.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Parser.cpp
		${TKOM_SOURCE_DIR}/Analyser/src/Reading.cpp
)

add_library( analyser STATIC ${ANALYSER_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	analyser
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libtokens.a
)
