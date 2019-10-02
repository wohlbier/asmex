// g++ -O0

// pushq %rbp           // push calling frame base pointer qw onto stack
// movq %rsp, %rbp      // move the top of stack qw ptr to rbp
// movl %edi, -4(%rbp)  // move value in %edi (a) to 4 bytes below sp
// movq %esi, -8(%rbp)  // move value in %esi (b) to 8 bytes below sp

// movl -4(%rbp), %edx  // move val at 4 bytes below sp to %edx
// movl -8(%rbp), %eax  // move val at 4 bytes below sp to %eax
// addl %edx, %eax      // add values in %edx %eax, leave in %eax

// popq %rbp            // pop calling base pointer qw from stack
// ret                  // return

int foo(int a, int b)
{
    return a+b;
}
