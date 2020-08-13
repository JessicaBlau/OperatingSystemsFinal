First you need to compile with the makefile by runing make. After compiling open another terminal along
side the one that is opened. Run on the first terminal sudo ./set_policy <policy> <piority> . In the second
terminal go to the q_3 directory and run the commant chrt -p <PID>. whem you run that command it should show the new policy and priority.