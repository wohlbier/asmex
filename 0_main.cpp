// g++ -O0

// pushq %rbp           // push calling frame base pointer qw onto stack
// movq %rsp, %rbp      // move the top of stack qw ptr to rbp
// movl %edi, -4(%rbp)  // move value in %edi (argc) to 4 bytes below sp
// movq %rsi, -16(%rbp) // move value in %rsi (argv) to 16 bytes below sp
// movl $0, %eax        // move 0 (l, 4 bytes) into %eax as return value
// popq %rbp            // pop calling base pointer qw from stack
// ret                  // return

int main(int argc, char* argv[])
{
    return 0;
}
