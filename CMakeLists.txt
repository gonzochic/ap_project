CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT (ap_project)

IF (NOT DEFINED CMAKE_MODULE_PATH)
  SET(CMAKE_MODULE_PATH "/home/roman/development/cmake_modules")
ENDIF (NOT DEFINED CMAKE_MODULE_PATH)


SET(ap_project_version   1)
SET(ap_project_revision  0)
SET(ap_project_patch     0)

SET(ap_project_release
        "${ap_project_version}.${ap_project_revision}.${ap_project_patch}")

SET(libapproject_soname
  "${ap_project_version}")

SET(libapproject_version
  "${ap_project_version}.${ap_project_revision}.0")

FILE(WRITE incl/version.hpp
        "#ifndef AP_PROJECT_VERSION_HPP\n#define AP_PROJECT_VERSION_HPP\n\n"
        "#define AP_PROJECT_VERSION \"${ap_project_release}\"\n\n"
        "#endif // AP_PROJECT_VERSION_HPP\n"
)

INCLUDE(CacheCleanTarget)

SET(PROJECT_VERSION ${ap_project_release})

INCLUDE(DistTarget)

SET(clean_targets
	"${ap_project_SOURCE_DIR}/doxy.log"	
	"${ap_project_SOURCE_DIR}/doc/html/"
)

SET_DIRECTORY_PROPERTIES(PROPERTIES
	ADDITIONAL_MAKE_CLEAN_FILES "${clean_targets}"
)
######################################################################
# common
SET(CPACK_Boost_VERSION_REQUIRED 1.34)
SET(CPACK_ZThread_VERSION_REQUIRED 2.3.2)

FIND_PACKAGE(Boost ${CPACK_Boost_VERSION_REQUIRED} REQUIRED COMPONENTS system filesystem date_time program_options)
FIND_PACKAGE(Log4CPlus)
FIND_PACKAGE(XercesC)
FIND_PACKAGE(ZThread)# ${CPACK_ZThread_VERSION_REQUIRED} EXACT REQUIRED)


ADD_SUBDIRECTORY (src)
#ADD_SUBDIRECTORY (data)
#ADD_SUBDIRECTORY (ut)
#ADD_SUBDIRECTORY (cfg)

# CTest config
ENABLE_TESTING()

IF (NOT TEST_OUTPUT_FORMAT)
  SET(TEST_OUTPUT_FORMAT "xml")
  MESSAGE("setting output format of tests to ${TEST_OUTPUT_FORMAT}.. consider using: \"$ cmake -DTEST_OUTPUT_FORMAT=[plain|xml]\"")
ENDIF (NOT TEST_OUTPUT_FORMAT)

#ADD_TEST(ap_project ./ut/ut.ap_project_core ${TEST_OUTPUT_FORMAT} ${ap_project_SOURCE_DIR}/cfg/log/logging_ap_project.cfg)

#INCLUDE(CTest)

