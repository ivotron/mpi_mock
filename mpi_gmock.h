/**
 * Defines a GMock over the @c AbstractMPI class.
 */

#ifndef MPI_GMOCK_H
#define MPI_GMOCK_H

#include "mpi_mock.h"

#include "gmock/gmock.h"

class GMockedMPI : public AbstractMPI
{
public:
  MOCK_METHOD2(init, int(int *argc, char*** argv));
  MOCK_METHOD0(finalize, int());
  MOCK_METHOD6(
    send, int(
      void *buf,
      int count,
      MPI_Datatype datatype,
      int dest,
      int tag,
      MPI_Comm comm));
  MOCK_METHOD7(
    recv, int(
      void *buf,
      int count,
      MPI_Datatype datatype,
      int source,
      int tag,
      MPI_Comm comm,
      MPI_Status *status));
  MOCK_METHOD2(
    comm_rank, int(
      MPI_Comm comm,
      int *me));
  MOCK_METHOD2(
    comm_size, int(
      MPI_Comm comm,
      int *nprocs));
  MOCK_METHOD1(
    barrier, int(
      MPI_Comm comm));
};

#endif
