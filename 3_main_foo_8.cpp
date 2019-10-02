// g++ -O0

// foo(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long):
//         pushq   %rbp
//         movq    %rsp, %rbp
//         movq    %rdi, -8(%rbp)
//         movq    %rsi, -16(%rbp)
//         movq    %rdx, -24(%rbp)
//         movq    %rcx, -32(%rbp)
//         movq    %r8, -40(%rbp)
//         movq    %r9, -48(%rbp)
//         movq    -8(%rbp), %rdx
//         movq    -16(%rbp), %rax
//         addq    %rax, %rdx
//         movq    -24(%rbp), %rax
//         addq    %rax, %rdx
//         movq    -32(%rbp), %rax
//         addq    %rax, %rdx
//         movq    -40(%rbp), %rax
//         addq    %rax, %rdx
//         movq    -48(%rbp), %rax
//         addq    %rax, %rdx
//         movq    16(%rbp), %rax
//         addq    %rax, %rdx
//         movq    24(%rbp), %rax
//         addq    %rdx, %rax
//         popq    %rbp
//         ret
// main:
//         pushq   %rbp
//         movq    %rsp, %rbp
//         subq    $80, %rsp
//         movl    %edi, -68(%rbp)
//         movq    %rsi, -80(%rbp)
//         movq    $1, -64(%rbp)
//         movq    $2, -56(%rbp)
//         movq    $3, -48(%rbp)
//         movq    $4, -40(%rbp)
//         movq    $5, -32(%rbp)
//         movq    $6, -24(%rbp)
//         movq    $7, -16(%rbp)
//         movq    $8, -8(%rbp)
//         movq    -24(%rbp), %r8
//         movq    -32(%rbp), %rdi
//         movq    -40(%rbp), %rcx
//         movq    -48(%rbp), %rdx
//         movq    -56(%rbp), %rsi
//         movq    -64(%rbp), %rax
//         pushq   -8(%rbp)
//         pushq   -16(%rbp)
//         movq    %r8, %r9
//         movq    %rdi, %r8
//         movq    %rax, %rdi
//         call    foo(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//         addq    $16, %rsp
//         leave
//         ret


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
