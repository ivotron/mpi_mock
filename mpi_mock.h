/**
 * Implements the MPI interface through an abstract class (see @c AbstractMPI) that should be given 
 * at runtime. The MPI "implementation" (dummy stubs) invokes methods on the given @c AbstractMPI 
 * instance. The @c AbstractMPI object should be given before invoking any MPI calls.
 *
 * This is intended to be used with C++ mocking frameworks such as GoogleMock. Currently a very 
 * limited subset of the MPI standard is implemented, although extensions are trivial.
 *
 * TODO: add support for the whole MPI-3.1 standard
 */

#ifndef MPI_MOCK_H
#define MPI_MOCK_H

#include "mpi.h"

/**
 * Abstract class serving as the entry point to MPI mocks. There's a public member for each MPI 
 * call, without the @c MPI_ prefix and lower-cased, i.e. @c MPI_Send() becomes @c send(), @c 
 * MPI_Comm_size becomes @c comm_send, and so on.
 */
class AbstractMPI
{
public:
  virtual ~AbstractMPI() {}

  virtual int
    init(
      int *argc,
      char ***argv) = 0;

  virtual int
    send(
      void *buf,
      int count,
      MPI_Datatype datatype,
      int dest,
      int tag,
      MPI_Comm comm) = 0;

  virtual int
    recv(
      void *buf,
      int count,
      MPI_Datatype datatype,
      int source,
      int tag,
      MPI_Comm comm,
      MPI_Status *status) = 0;

  virtual int
    comm_rank(MPI_Comm comm, int *me) = 0;
  virtual int
    comm_size(MPI_Comm comm, int *nprocs) = 0;
  virtual int
    barrier(MPI_Comm comm) = 0;
  virtual int
    finalize(void) = 0;
};

/**
 * Function called from tests/mock definitions. It should be called BEFORE any MPI function is 
 * invoked, otherwise a SEGMENTATION_FAULT will get raised since the internal pointer to the @c 
 * AbstractMPI object won't defined.
 *
 * TODO: add checks to avoid SEGMENTATION_FAULTS and raise exceptions instead.
 */
void set_mpi_mock(AbstractMPI* mpi_mock);

#endif
