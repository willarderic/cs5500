# ----------------------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
#     gcc -c hello.s && ld hello.o && ./a.out
#
# or
#
#     gcc -nostdlib hello.s && ./a.out
# ----------------------------------------------------------------------------------------

        .global _start

        .text
_start:
        # write(1, message, 13)
        movq     $1, %rax                # system call 1 is write
        movq     $1, %rdi                # file handle 1 is stdout
        movq     $message, %rsi          # address of string to output
        movq     $13, %rdx               # number of bytes
        syscall                         # invoke operating system to do the write

        # exit(0)
        movq     $60, %rax               # system call 60 is exit
        xor     %rdi, %rdi              # we want return code 0
        syscall                         # invoke operating system to exit
message:
        .ascii  "Hello, world\n"
