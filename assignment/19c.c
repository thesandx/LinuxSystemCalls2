/* strace -c mkfifo test1
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 39.15    0.000361         361         1           execve
 19.09    0.000176           6        27           mmap
  6.72    0.000062           6         9           mprotect
  5.53    0.000051           6         8           openat
  5.21    0.000048          48         1           mknod
  4.34    0.000040           4        10           close
  4.12    0.000038           5         7           read
  3.25    0.000030           3         8           pread64
  3.15    0.000029           3         8           fstat
  1.84    0.000017          17         1           munmap
  1.63    0.000015           7         2         2 statfs
  1.52    0.000014           4         3           brk
  1.30    0.000012           6         2         2 access
  0.87    0.000008           4         2         1 arch_prctl
  0.65    0.000006           3         2           rt_sigaction
  0.43    0.000004           4         1           set_tid_address
  0.43    0.000004           4         1           set_robust_list
  0.43    0.000004           4         1           prlimit64
  0.33    0.000003           3         1           rt_sigprocmask
------ ----------- ----------- --------- --------- ----------------
100.00    0.000922                    95         5 total
sandeep@sandeep:~$ strace -c mknod test2
mknod: missing operand after ‘test2’
Try 'mknod --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 25.33    0.000038           2        13         3 openat
 24.00    0.000036           9         4           write
 16.67    0.000025           2        12           close
 15.33    0.000023           2         9           read
  7.33    0.000011           0        28           mmap
  6.67    0.000010           1        10           fstat
  4.67    0.000007           3         2         2 access
  0.00    0.000000           0         9           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           rt_sigaction
  0.00    0.000000           0         1           rt_sigprocmask
  0.00    0.000000           0         8           pread64
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
------ ----------- ----------- --------- --------- ----------------
100.00    0.000150                   110         8 total
*/

//so mknod is faster then mkfifo
