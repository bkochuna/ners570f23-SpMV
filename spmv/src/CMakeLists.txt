
add_library(spmv
    SparseMatrix.cpp
    SparseMatrix_COO.cpp
)

target_include_directories(spmv PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
  $<INSTALL_INTERFACE:include>
)