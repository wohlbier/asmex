// g++ -O0

// foo(int, int):
//         pushq   %rbp            // push calling frame bp qw onto stack
//         movq    %rsp, %rbp      // move top of stack qw ptr into %rbp
//         movl    %edi, -4(%rbp)  // move val in %edi (a) to 4 bytes below sp
//         movl    %esi, -8(%rbp)  // move val in %esi (b) to 8 bytes below sp
//         movl    -4(%rbp), %edx  // move val at 4 bytes below sp to %edx
//         movl    -8(%rbp), %eax  // move val at 4 bytes below sp to %eax
//         addl    %edx, %eax      // add values in %edx %eax, leave in %eax
//         popq    %rbp            // pop calling base pointer qw from stack
//         ret                     // return
// main:
//         pushq   %rbp            // push calling frame bp qw onto stack
//         movq    %rsp, %rbp      // move top of stack qw ptr into %rbp
//         subq    $32, %rsp       // allocate 32 bytes of stack space
//         movl    %edi, -20(%rbp) // move argc to 20 bytes below top of stack
//         movq    %rsi, -32(%rbp) // move argv to 32 bytes below top of stack
//         movl    $3, -8(%rbp)    // put 3 into 8 bytes below top of stack
//         movl    $2, -4(%rbp)    // put 2 into 4 bytes below top of stack
//         movl    -4(%rbp), %edx  // move val 4 bytes below top stack to %edx
//         movl    -8(%rbp), %eax  // move val 8 bytes below top stack to %eax
//         movl    %edx, %esi      // move val in %edx to function arg %esi
//         movl    %eax, %edi      // move val in %eax to function arg %edi
//         call    foo(int, int)   // call foo
//         leave                   // set %rsp to %rbp, pop top stack into %rbp
//         ret                     // return

// %rbp points to top of stack, %rsp points to bottom of stack

// leave:
// movq    %rbp, %rsp
// popq    %rbp

int foo(int a, int b)
{
    return a+b;
}

int main(int argc, char* argv[])
{
    int a = 3;
    int b = 2;
    return foo(a,b);
}
