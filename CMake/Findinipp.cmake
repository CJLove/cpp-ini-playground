# - Find inipp

if(INIPP_INCLUDE_DIRS)
    set(INIPP_FOUND TRUE)

else(INIPP_INCLUDE_DIRS)
    find_path(INIPP_INCLUDE_DIRS inipp.h
      /usr/include
      /usr/local/include/
      )

  if(INIPP_INCLUDE_DIRS)
      set(INIPP_FOUND TRUE)
      message(STATUS "Found inipp: ${INIPP_INCLUDE_DIRS}")
  else(INIPP_INCLUDE_DIRS AND INIPP_LIBRARIES)
      set(INIPP_FOUND FALSE)
    message(STATUS "inipp not found.")
  endif(INIPP_INCLUDE_DIRS)

  mark_as_advanced(INIPP_INCLUDE_DIRS)

endif(INIPP_INCLUDE_DIRS)
