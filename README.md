Monty Interpreter

This is a simple interpreter for Monty 0.98 scripting language, which is compiled into Monty byte codes. Monty relies on a unique stack with specific instructions to manipulate it.
Compilation

To compile the Monty interpreter, use the following command:

bash

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

Usage

Run the Monty interpreter with the following command:

bash

$ ./monty file

where file is the path to the Monty byte code file.
Error Handling

    If no file or more than one argument is provided:

    bash

USAGE: monty file

If it's not possible to open the file:

bash

Error: Can't open file <file>

If an invalid instruction is encountered:

bash

L<line_number>: unknown instruction <opcode>

If malloc fails:

bash

    Error: malloc failed

Monty Byte Code Files

Monty byte code files have the .m extension. Each line contains one instruction, and there can be any number of spaces before or after the opcode and its argument.

Example:

monty

push 0
push 1
push 2
push 3
pall

Opcodes

    push
        Usage: push <int>
        Description: Pushes an element onto the stack.
    pall
        Usage: pall
        Description: Prints all values on the stack.
    pint
        Usage: pint
        Description: Prints the value at the top of the stack.
    pop
        Usage: pop
        Description: Removes the top element of the stack.
    swap
        Usage: swap
        Description: Swaps the top two elements of the stack.
    add
        Usage: add
        Description: Adds the top two elements of the stack.
    nop
        Usage: nop
        Description: No operation.
    sub (Advanced)
        Usage: sub
        Description: Subtracts the top element from the second top element.
    div (Advanced)
        Usage: div
        Description: Divides the second top element by the top element.
    mul (Advanced)
        Usage: mul
        Description: Multiplies the second top element by the top element.
    mod (Advanced)
        Usage: mod
        Description: Computes the rest of the division of the second top element by the top element.
    comments (Advanced)
        Usage: Lines starting with # are treated as comments.
    pchar (Advanced)
        Usage: pchar
        Description: Prints the char at the top of the stack.
    pstr (Advanced)
        Usage: pstr
        Description: Prints the string starting at the top of the stack.
    rotl (Advanced)
        Usage: rotl
        Description: Rotates the stack to the top.
    rotr (Advanced)
        Usage: rotr
        Description: Rotates the stack to the bottom.
    stack and queue (Advanced)
        Usage: stack or queue
        Description: Sets the format of the data to a stack (LIFO) or a queue (FIFO).

Brainf*ck

    1000-school.bf
        Description: Brainf*ck script that prints "School" followed by a new line.

Additional Brainf*ck Programs

    1001-add.bf
        Description: Adds two digits given by the user.
    1002-mul.bf
        Description: Multiplies two digits given by the user.
    1003-mul.bf
        Description: Multiplies two digits given by the user and prints the result followed by a new line.
