add_executable(mwe mwe.cpp)
add_executable(accessingValues accessingValues.cpp)

target_include_directories(mwe PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../spmv/include>
  $<INSTALL_INTERFACE:include>
)
target_include_directories(accessingValues PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../spmv/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(mwe spmv )
target_link_libraries(accessingValues spmv )