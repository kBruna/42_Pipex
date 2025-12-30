# Pipex
A 42SP school project.

Notes:

	To do the HERE_DOC function:
	- GNL inside a loop;
	- Loop with break comparing with LIMITER\n\0;
	- GNL receives input from user until a line with LIMITER, then the loop breaks.
	- Input is put inside a temp file to be parsed to cmd1.
	- Temp file must be deleted after.
	- Outfile must be created before, if needed.
	- At first, a check if argv[1] is 'here_doc', then store argv[2] that will be the LIMITER.

New functions:

-> access :  Check for ownership of a file before any command operation on it.

`	#include <unistd.h>
	 int	access(const char *pathname, int mode); 

	#include <fcntl.h> // Definition of AT_*constants*`
Check whether the calling process has permission to access a file before you try to open or execute it. If the name is a symbolic link, it is dereferenced.

int mode -> Specifies the accessibility check(s) to be performed. 
	F_OK -> Tests for the existence of the file.
	R_OK -> Tests for the existence of the file and if it grands read permissions.
	w_OK -> Tests for the existence of the file and if it grands write permissions.
	X_OK -> Tests for the existence of the file and if it grands execute permissions.


Checks is done calling process's real UID and GID, as if it were a real operation on the file.
The function does not act as if the programmer were calling the function, but act as the user that is using the program. This prevents the possibility to prevent malicious users from causing them to read files which users shouldn't be able to read.

Return Value : On sucess (all requests permissions granted, or mode is F_OK and the file exists), zero is returned. On error (at least one bit in mode asked for a permission that is denied, or mode is F_OK and the file does not exist, or some other error occured), -1 is returned, and errno is set appropriately.


-> dup / dup2 : Duplicate a file descriptor.

`	#include <unistd.h>
	int	dup(int oldfd);
	int dup2(int oldfd, int newfd);

	#include <fcntl.h> // Obtain 0_* constant definitions`

Dup / Dup2 system call creates a copy of the file descriptor oldfd. Dup use the lowest-numbered unused file descriptor for the new descriptor. Dup2 uses the file descriptor number specified in newfd. If the file descriptor newfd was previously open, it is silently closed before being reused.

After a sucessfull return, the old and the new fd can be used interchangeably. They refer to the same ope file description and thus share file offset and file status flags. The two file descriptors do not share file descriptor flags (the close-on-exec flag).

Notes:
	- If oldfd is not a valid file descriptor, then the call fails, and newfd is not closed.
	- If oldfd is a valid file descriptor, and new fd has the same value as oldfd, them dup2() does nothing, and returns newfd.

Return Value : On success, these system calls return the new file descriptor. On error, -1 is returned, and errno is set appropriately.


-> execve : Execute a program.
`	#include <unistd.h>

	int execve(const char *pathname, char *const argv[], char *const envp[]);`

Execv() executes the program reffered to by pathname. This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and (initialized and unitialized) data segments.

pathname must be either a binary executable, or a script starting with a line of the form:

`#!interpreter [optional-arg]`

argv is an array of pointers to strings passed to the new program as its command-line arguments. By convention, the first of these strings (argv[0]) should contain the filename associated with the file being executed.

envp is an array of pointers to strings, conventionally of the form key=value.

execve() does not return on success, and the text, initialized data, unitialized data (bss), and stack of the calling process are overwritten according to the contents of the newly loaded program. On error -1 is returned, and errno is set appropriately.

Notes :
	- All threads other than the calling thread are destroyed during an execve(). Mutexes, condition variables, and other pthreads are not preserved.
	- By default, file descriptors remain open across an execve(). File descriptors that are marked close-on-exec are closed.


-> fork :	Create a child process.

`	#include <sys/types.h>
	#include <unistd.h>

	pid_t	fork(void);`

Fork() creates a new process by duplicating the calling process. The new process is referred as the child process.

-> pipe :
`	#include <unistd.h>

	int	pipe(int pipefd[2]);

	#define _GNU_SOURCE	//feature_test_macros(7)
	#include <fcntl.h>
	#include <unistd.h>`

pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication

-> unlink :

-> wait :

-> waitpid :

