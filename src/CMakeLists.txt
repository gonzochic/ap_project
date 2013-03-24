SET(ap_project_sources
  main.cpp
  core.cpp
  calculationloop.cpp
  dataholder.cpp

  I2Cdev.cpp
  MPU6050.cpp
)
SET (ap_project_headers
  ../incl/main.hpp
  ../incl/core.hpp
  ../incl/calculationloop.hpp
)
ADD_EXECUTABLE(ap_project
  ${ap_project_sources}
  ${ap_project_headers}
)


ADD_DEPENDENCIES(ap_project includes)

INCLUDE_DIRECTORIES(
  ${ap_project_SOURCE_DIR}/incl
  ${Boost_INCLUDE_DIRS}
  ${ZThread_INCLUDE_DIRS}
  ${Log4Cplus_INCLUDE_DIRS}
)

TARGET_LINK_LIBRARIES(ap_project
  ${XercesC_LIBRARIES}
  ${ZThread_LIBRARIES}
  ${Boost_PROGRAM_OPTIONS_LIBRARIES}
  ${Log4CPlus_LIBRARIES}
  ${Boost_FILESYSTEM_LIBRARIES}
  ${Boost_SYSTEM_LIBRARIES}
)





