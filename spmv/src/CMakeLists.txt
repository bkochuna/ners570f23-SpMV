
add_library(spmv
    SparseMatrix.cpp
    SparseMatrix_ELL.cpp
)

target_include_directories(spmv PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
  $<INSTALL_INTERFACE:include>
)