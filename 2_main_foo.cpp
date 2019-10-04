// Assembly for a main function that calls a simple function that adds
// two numbers and returns.

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

// g++ -O0

// foo(int, int):
//         pushq   %rbp            // push calling frame bp qw onto stack
//         movq    %rsp, %rbp      // move top of stack qw ptr into %rbp
//         movl    %edi, -4(%rbp)  // move val in %edi (a) to 4 bytes below sp
//         movl    %esi, -8(%rbp)  // move val in %esi (b) to 8 bytes below sp
//         movl    -4(%rbp), %edx  // move val at 4 bytes below bp to %edx (a)
//         movl    -8(%rbp), %eax  // move val at 4 bytes below bp to %eax (b)
//         addl    %edx, %eax      // add values in %edx %eax, leave in %eax
//         popq    %rbp            // pop calling base pointer qw from stack
//         ret                     // return
// main:
//         pushq   %rbp            // push calling frame bp qw onto stack
//         movq    %rsp, %rbp      // move top of stack qw ptr into %rbp
//         subq    $32, %rsp       // make stack frame
//         movl    %edi, -20(%rbp) // move argc to 20 bytes below bp
//         movq    %rsi, -32(%rbp) // move argv to 32 bytes below bp
//         movl    $3, -8(%rbp)    // put 3 (a) into 8 bytes below bp
//         movl    $2, -4(%rbp)    // put 2 (b) into 4 bytes below bp
//         movl    -4(%rbp), %edx  // move val 4 bytes below bp to %edx (b)
//         movl    -8(%rbp), %eax  // move val 8 bytes below bp to %eax (a)
//         movl    %edx, %esi      // move val in %edx to function arg %esi (b)
//         movl    %eax, %edi      // move val in %eax to function arg %edi (a)
//         call    foo(int, int)   // call foo
//         leave                   // set %rsp to %rbp, pop top stack into %rbp
//         ret                     // return

// leave:
// movq    %rbp, %rsp
// popq    %rbp

// %rbp points to bottom of stack, %rsp points to top of stack. Top of
// stack has lower address than bottom.

// parameter 1 address < paramter 2 address

// stack frame created in main, %rbp != %rsp. Not sure why argc, argv
// are put in the frame.

// note that a, b change relative positions wrt %rbp in foo
