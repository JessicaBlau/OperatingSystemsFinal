# OperatingSystemsFinal
Question 1: There is a given program in C. Find where all marked lines are allocated in the memory using 
objdump, nm, and size.
  - In the program itself next to a line there is a comment with where it is allocated.
  - In the pdf file screenshots of how I found where each is allocated and explanation.

Question 2.1: How to check if a pocess exists in a c program.
  - c file that shows the program it self using the function kill(pid,0).
  - pdf expleaing 2 other options we could use and the advantages or disadvantages of that option.

Question 2.2: Created server and client C program that will show that not all standerd signals will arive at the server.
  - Readme will explain how to run and compile.
  - 2 C programs called client and server.
  - pdf showing a screanshot of the output.
  
Question 3:

Question 4: Using the fundtion nftw() so we can scan a library recusivaly.
  - There is a C program called dir_traversal that will print the files of the folder that we want to check and       will ignore any soft link. 
  - The pdf shows the output of the example: 
    $ mkdir dir
    $ touch die/a dir/b
    $ ln -s a dir/sl
    $ mkdir dir/sub
    $ touch dir/sub/x
