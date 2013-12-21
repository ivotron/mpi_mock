#include "mpi_mock.h"

// define global pointer.
AbstractMPI* mpi;

void
set_mpi_mock(
  AbstractMPI* mpi_mock)
{
  mpi = mpi_mock;
}

int
MPI_Send(
  void *buf,
  int count,
  MPI_Datatype datatype,
  int dest,
  int tag,
  MPI_Comm comm)
{
  return mpi->send(buf, count, datatype, dest, tag, comm);
}

int
MPI_Recv(
  void *buf,
  int count,
  MPI_Datatype datatype,
  int source,
  int tag,
  MPI_Comm comm,
  MPI_Status *status)
{
  return mpi->recv(buf, count, datatype, source, tag, comm, status);
}

int
MPI_Init(
  int *argc,
  char **argv[])
{
  return mpi->init(argc, argv);
}

int
MPI_Comm_rank(
  MPI_Comm comm,
  int *me)
{
  return mpi->comm_rank(comm, me);
}

int
MPI_Comm_size(
  MPI_Comm comm,
  int *nprocs )
{
  return mpi->comm_size(comm, nprocs);
}

int
MPI_Barrier(MPI_Comm comm)
{
  return mpi->barrier(comm);
}

int
MPI_Finalize()
{
  return mpi->finalize();
}
