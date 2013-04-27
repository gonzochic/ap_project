SET(DESIRED_QT_VERSION 4 )
SET(CPACK_Qt4_VERSION_REQUIRED 4.4)
FIND_PACKAGE(Qt REQUIRED)

IF (QT4_INSTALLED)
  MESSAGE(STATUS "QT4 INSTALLED")
  FIND_PACKAGE(Qt4 ${CPACK_Qt4_VERSION_REQUIRED} REQUIRED)
ENDIF (QT4_INSTALLED)

IF (QT_FOUND)
  INCLUDE(UseQt4)
  MESSAGE(STATUS "Found Qt library at:   ${QT_QT_LIBRARY}")
  MESSAGE(STATUS "Found Qt libraries at: ${QT_LIBRARIES}")
  MESSAGE(STATUS "Found Qt headers at:   ${QT_INCLUDE_DIR}")
  MESSAGE(STATUS "Found Qt uic-tool at:  ${QT_UIC_EXECUTABLE}")
  MESSAGE(STATUS "Found Qt moc-tool at:  ${QT_MOC_EXECUTABLE}")
  MESSAGE(STATUS "Found Qt definitions:  ${QT_DEFINITIONS}")
  MESSAGE(STATUS "Found AP definitions:  ${ap_project_SOURCE_DIR}")
ENDIF (QT_FOUND)

FIND_PACKAGE(Qwt)

SET(QWT_INCLUDE_DIRS ${QWT_INCLUDE_DIR})
SET(QWT_LIBRARY ${QWT_LIBRARIES})

SET(ap_gui_SOURCE_DIR ${ap_project_SOURCE_DIR}/gui/src)

ADD_CUSTOM_COMMAND(OUTPUT ${ap_project_SOURCE_DIR}/gui/incl/ui_apgui.h
  COMMAND ${QT_UIC_EXECUTABLE}
    -o ${ap_project_SOURCE_DIR}/gui/incl/ui_apgui.h
    ${ap_project_SOURCE_DIR}/gui/apgui.ui
  DEPENDS ${ap_project_SOURCE_DIR}/gui/apgui.ui
  WORKING_DIRECTORY ${ap_project_SOURCE_DIR}/gui/incl
)

ADD_CUSTOM_COMMAND(OUTPUT ${ap_project_SOURCE_DIR}/gui/src/ap_gui_moc.cpp
  COMMAND ${QT_MOC_EXECUTABLE}
    -o ${ap_project_SOURCE_DIR}/gui/src/ap_gui_moc.cpp
    ${ap_project_SOURCE_DIR}/gui/incl/apgui.hpp
  DEPENDS ${ap_project_SOURCE_DIR}/gui/incl/apgui.hpp
  WORKING_DIRECTORY ${ap_project_SOURCE_DIR}
)

SET(ap_gui_generated_sources
   ${ap_project_SOURCE_DIR}/gui/incl/ui_apgui.h
   ${ap_project_SOURCE_DIR}/gui/src/ap_gui_moc.cpp
  )

SET_SOURCE_FILES_PROPERTIES(${ap_gui_generated_sources}
  PROPERTIES GENERATED TRUE
)

ADD_EXECUTABLE(ap_gui
  main.cpp
  apgui.cpp
  ${ap_gui_generated_sources}
)

INCLUDE_DIRECTORIES(
  ${ap_project_SOURCE_DIR}/gui/incl
  ${ap_project_SOURCE_DIR}/incl
  ${QT_INCLUDE_DIR}
  ${QT_QTOPENGL_INCLUDE_DIR}
  ${QWT_INCLUDE_DIRS}
)


TARGET_LINK_LIBRARIES(ap_gui

 ${QT_QT_LIBRARY}
 ${QT_LIBRARIES}
 ${QT_QTOPENGL_LIBRARY}
 ${QWT_LIBRARY}
)

