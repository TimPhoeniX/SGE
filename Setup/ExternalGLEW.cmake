message(STATUS "External project: GLEW")
message(STATUS "INSTALL_DEPENDENCIES_DIR: ${INSTALL_DEPENDENCIES_DIR}")

set(GLEW_PREFIX "${INSTALL_DEPENDENCIES_DIR}/glew_prefix") 
set(GLEW_INSTALL_DIR "${INSTALL_DEPENDENCIES_DIR}/glew")

ExternalProject_Add(GLEW_EXTERNAL 
	PREFIX ${GLEW_PREFIX}
	GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git

	UPDATE_COMMAND ""

	CMAKE_ARGS
		"-DCMAKE_INSTALL_PREFIX=${GLEW_INSTALL_DIR}"
		"-DCMAKE_BUILD_TYPE=Debug"

	CMAKE_CACHE_ARGS
		"-DCMAKE_C_COMPILER:FILEPATH=${CMAKE_C_COMPILER}"
		"-DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER}"

	INSTALL_DIR ${GLEW_INSTALL_DIR}
	
	LOG_DOWNLOAD ON
	LOG_UPDATE ON
	LOG_CONFIGURE ON 
	LOG_BUILD ON
	LOG_INSTALL ON 
)

message(STATUS "GLEW_PREFIX: ${GLEW_PREFIX}")
message(STATUS "GLEW_INSTALL_DIR: ${GLEW_INSTALL_DIR}")