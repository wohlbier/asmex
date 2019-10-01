- 0_main.cpp -- simple main program
- 1_foo.cpp  -- simple function



Examples of source files and their assembly.
- https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
- http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
- https://en.wikipedia.org/wiki/Call_stack#Structure

Assembly notes:

Suffixes:
- b - one byte integer
- w - word, two byte integer
- l - double word, four byte integer
- q - quad word, eight byte integer

16 registers in x86-64:
`%rax`, `%rbx`, `%rcx`, `%rdx`, `%rdi`, `%rsi`, `%rbp`, `%rsp`, and
`%r8-r15`.

Parentheses on a register dereference the register. E.g., if arr
is an array of integers, arr's address is in `%rax`, `i` is stored in
`%rcx`, then

`arr[i] = 3;`

can be represented as

`movq $3, (%rax, %rcx, 8)`

"move quadword value 3 to address `%rax + %rcx*8`".


Registers `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, and `%r9` are used to
pass first six integer or pointer parameters to called functions.

Additional parameters (or large parameters such as structs
passed by value) are passed on the stack.

An x64 program uses a region of memory called the stack to support
function calls. As the name suggests, this region is organized as a
stack data structure with the “top” of the stack growing towards lower
memory addresses. For each function call, new space is created on the
stack to store local variables and other data. This is known as a
stack frame. To accomplish this, you will need to write some code at
the beginning and end of each function to create and destroy the stack
frame.

When a call instruction is executed, the address of the following
instruction is pushed onto the stack as the return address and control
passes to the specified function.

If the function is going to use any of the callee-save registers
(`%rbx`, `%rbp`, or `%r12-r15`), the current value of each should be pushed
onto the stack to be restored at the end. For example:

```
pushq %rbx
pushq %r12
pushq %r13
```

Finally, additional space may be allocated on the stack for local
variables. While it is possible to make space on the stack as needed
in a function body, it is generally more efficient to allocate this
space all at once at the beginning of the function. This can be
accomplished using the call
`subq $N, %rsp`
where N is the size of the callee’s stack frame. For example:

`subq $0x18, %rsp # Allocate 24 bytes of space on the stack`

This set-up is called the function prologue.


Clean up
First, the callee frees the stack space it allocated by adding the
same amount to the stack pointer:

`addq $0x18, %rsp # Give back 24 bytes of stack space`

Then, it pops off the registers it saved earlier

```
popq %r13 # Remember that the stack is FILO! popq %r12
popq %rbx
```

Finally, the program should return to the call site, using the `ret`
instruction:
```
ret
```

Putting it together, the code for a function should look like this:

```
foo:
pushq %rbx # Save registers, if needed
pushq %r12
pushq %r13
subq $0x18, %rsp # Allocate stack space

# Function body

addq $0x18, %rsp popq %r13 # Deallocate stack space
popq %r12 # Restore registers
popq %rbx # Pop return address and return control to caller
ret
```

Recommend using
https://github.com/mattgodbolt/compiler-explorer

with an installation of nodejs using
https://github.com/nvm-sh/nvm
