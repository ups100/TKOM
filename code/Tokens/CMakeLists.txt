MESSAGE( "Building tokens target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${TKOM_SOURCE_DIR}/Tokens/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( TOKENS_SRC
		${TKOM_SOURCE_DIR}/Tokens/src/HexPairT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/HexSignT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/MultiOptionToken.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/SensorTypeT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/SingleOptionToken.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/StatusT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/StringT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/Token.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/Type2T.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/TypeSignT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/TypeT.cpp
		${TKOM_SOURCE_DIR}/Tokens/src/UnitT.cpp

)

add_library( tokens STATIC ${TOKENS_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	tokens
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
)
