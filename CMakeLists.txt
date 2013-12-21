CMAKE_MINIMUM_REQUIRED (VERSION 2.8.7)
PROJECT (mpi_mock)

# create library
SET (SRC "mpi_mock.cpp")
ADD_LIBRARY (mpi_mock ${SRC})

# define variables that parents can use
SET (MPI_MOCK_LIBRARIES mpi_mock PARENT_SCOPE)
SET (MPI_MOCK_INCLUDE_DIR "." PARENT_SCOPE)
