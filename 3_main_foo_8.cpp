// Assembly showing function call with 8 arguments. Arguments 7 and 8
// are passed through the stack frame.

#include <cstddef>
typedef size_t Index_t;

Index_t foo(Index_t a, Index_t b, Index_t c, Index_t d,
            Index_t e, Index_t f, Index_t g, Index_t h)
{
    return a+b+c+d+e+f+g+h;
}

int main(int argc, char* argv[])
{
    Index_t a = 1;
    Index_t b = 2;
    Index_t c = 3;
    Index_t d = 4;
    Index_t e = 5;
    Index_t f = 6;
    Index_t g = 7;
    Index_t h = 8;
    return foo(a,b,c,d,e,f,g,h);
}

// g++ -O0

// foo(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long):
//         pushq   %rbp            // push caller bp
//         movq    %rsp, %rbp      // put %rsp into %rbp. 96B below main's bp
//         movq    %rdi, -8(%rbp)  // a
//         movq    %rsi, -16(%rbp) // b
//         movq    %rdx, -24(%rbp) // c
//         movq    %rcx, -32(%rbp) // d
//         movq    %r8, -40(%rbp)  // e
//         movq    %r9, -48(%rbp)  // f
//         movq    -8(%rbp), %rdx  // "pop" h, but %rsp doesn't increase
//         movq    -16(%rbp), %rax // "pop" g
//         addq    %rax, %rdx      // h+g
//         movq    -24(%rbp), %rax // c
//         addq    %rax, %rdx      // c+h+g
//         movq    -32(%rbp), %rax // d
//         addq    %rax, %rdx      // d+c+h+g
//         movq    -40(%rbp), %rax // e
//         addq    %rax, %rdx      // e+d+c+h+g
//         movq    -48(%rbp), %rax // f
//         addq    %rax, %rdx      // f+e+d+c+h+g
//         movq    16(%rbp), %rax
//         addq    %rax, %rdx
//         movq    24(%rbp), %rax
//         addq    %rdx, %rax
//         popq    %rbp
//         ret
// main:
//         pushq   %rbp
//         movq    %rsp, %rbp      // %rbp = %rsp
//         subq    $80, %rsp       // make stack frame. %rsp=%rbp-80
//         movl    %edi, -68(%rbp) // argc
//         movq    %rsi, -80(%rbp) // argv on top of stack
//         movq    $1, -64(%rbp)   // a
//         movq    $2, -56(%rbp)   // b
//         movq    $3, -48(%rbp)   // c
//         movq    $4, -40(%rbp)   // d
//         movq    $5, -32(%rbp)   // e
//         movq    $6, -24(%rbp)   // f
//         movq    $7, -16(%rbp)   // g
//         movq    $8, -8(%rbp)    // h
//         movq    -24(%rbp), %r8  // put f in %r8
//         movq    -32(%rbp), %rdi // put e in %rdi
//         movq    -40(%rbp), %rcx // put d in %rcx
//         movq    -48(%rbp), %rdx // put c in %rdx
//         movq    -56(%rbp), %rsi // put b in %rsi
//         movq    -64(%rbp), %rax // put a in %rax
//         pushq   -8(%rbp)        // push h onto stack, %rsp=%rbp-88
//         pushq   -16(%rbp)       // push g onto stack, %rsp=%rbp-96
//         movq    %r8, %r9        // put f in %rd9
//         movq    %rdi, %r8       // put e in %r8
//         movq    %rax, %rdi      // put a in %rdi
//         call    foo(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//         addq    $16, %rsp       // increase %rsp for g,h
//         leave
//         ret
