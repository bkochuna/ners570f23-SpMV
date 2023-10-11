add_executable(mwe mwe.cpp)

target_include_directories(mwe PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../spmv/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(mwe spmv)