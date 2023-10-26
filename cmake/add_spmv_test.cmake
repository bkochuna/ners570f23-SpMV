macro(add_spmv_test FILENAME)
  # Strip the path and extension from the filename to get the test name
  set(TESTNAME ${FILENAME})
  get_filename_component(TESTNAME ${TESTNAME} NAME_WE)
  get_filename_component(TESTNAME ${TESTNAME} NAME_WLE)

  # Add a float version and a double version of the test
  set(TESTNAME_FLOAT "${TESTNAME}_float")
  set(TESTNAME_DOUBLE "${TESTNAME}_double")
  
  add_executable(${TESTNAME_FLOAT} ${FILENAME})
  add_executable(${TESTNAME_DOUBLE} ${FILENAME})

  target_link_libraries(${TESTNAME_FLOAT} PRIVATE spmv)
  target_link_libraries(${TESTNAME_DOUBLE} PRIVATE spmv)

  target_compile_definitions(${TESTNAME_FLOAT} PRIVATE -D__SPMV_FPTYPE__=float)
  target_compile_definitions(${TESTNAME_DOUBLE} PRIVATE -D__SPMV_FPTYPE__=double)

  add_test(${TESTNAME_FLOAT} ${TESTNAME_FLOAT})
  add_test(${TESTNAME_DOUBLE} ${TESTNAME_DOUBLE})

  set_target_properties(${TESTNAME_FLOAT} PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})
  set_target_properties(${TESTNAME_DOUBLE} PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})
endmacro()
