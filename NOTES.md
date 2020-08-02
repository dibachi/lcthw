# running notes
these are my running notes, where I'll be documenting questions, comments, and helpful rules of thumb that I pick up along the way

# ex1
basic C programming and compiling

the main function has to be called main. It'll be interesting to see how multi-function definition and usage works as compared to python and matlab

vim sucks. I hate vim. Nano, you're ok but you're on thin ice.

# ex2
intro to Makefiles

Makefiles are sensitive to types of whitespace
"make all" corresponds to "make" and vice versa, as long as there's a "make all" defined in the makefile

running linux on a VM w/ Windows host means I can use VS Code as my text editor. I love that: 

a) I can see the text I'm editing

b) the text editor makes it easy to edit the text, for it is a text editor

c) I don't have to crack the da vinci code to save a file or to type something in. Why do programmers insist on suffering?

# ex3
more makefile stuff and program writing

not much to report here. just more code stuff I mostly know already. modified Makefile to compile both ex1 and ex3

# ex4
intro to debugging tools

quick note: including "-g" under the CFLAGS in the Makefile includes debugging line numbers when in gdb