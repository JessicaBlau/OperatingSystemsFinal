There are 2 C programs, client and server. To run these programs and show that not all the signals 
arrive at the server first you need to compile them both by running make server and make client or you
can run make all and it will compile server and client at the same time. After compiling
both you need to open 2 terminals, in one run ./server and in the other terminal run the command ps -ef | grep server
to find the pid of ./server. Once you have the pid run ./client pid server 10 or 2 and number of signals you want to send. 
example ./clinet 11704 10 1000, this is the example i gave in the pdf file. To send a SIGUSR1 wright 10 and for a SIGINT 2.