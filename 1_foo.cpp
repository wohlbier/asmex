// Assembly for a function that adds two numbers and returns.

int foo(int a, int b)
{
    return a+b;
}

// g++ -O0

// pushq %rbp           // push calling frame base pointer qw onto stack
// movq %rsp, %rbp      // move the top of stack qw ptr to rbp
// movl %edi, -4(%rbp)  // move value in %edi (b) to 4 bytes below bp
// movq %esi, -8(%rbp)  // move value in %esi (a) to 8 bytes below bp
// movl -4(%rbp), %edx  // move val at 4 bytes below sp to %edx
// movl -8(%rbp), %eax  // move val at 4 bytes below sp to %eax
// addl %edx, %eax      // add values in %edx %eax, leave in %eax
// popq %rbp            // pop calling base pointer qw from stack
// ret                  // return

// -4(%rbp) skips pushed value of %rbp

// parameter 1 address < paramter 2 address

// No stack frame because no calling function. %rbp = %rsp
