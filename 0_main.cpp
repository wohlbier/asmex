// Assembly for a main function that does nothing.
int main(int argc, char* argv[])
{
    return 0;
}

// g++ -O0

// pushq %rbp           // push calling frame base pointer qw onto stack
// movq %rsp, %rbp      // move the top of stack qw ptr to rbp
// movl %edi, -4(%rbp)  // move value in %edi (argv) to 4 bytes below bp
// movq %rsi, -16(%rbp) // move value in %rsi (argc) to 16 bytes below bp
// movl $0, %eax        // move 0 (l, 4 bytes) into %eax as return value
// popq %rbp            // pop calling base pointer qw from stack
// ret                  // return

// %rbp is pushed onto the stack.
// %edi is 4 below %rsp to skip %rbp
// %rsi is 16 below %rsp to skip %rbp and %edi

// parameter 1 address < paramter 2 address
