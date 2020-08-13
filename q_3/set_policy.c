 #include <sched.h>
 #include <stdio.h>

int setPolicy(int policy, int priority){
    pid_t pid = 0;
    struct sched_param Spriority = {
        Spriority.sched_priority = priority
    };
    if(sched_setscheduler(pid, policy, &Spriority)){
        return 0;
    }
    return 1;
}
int main(int argc,char* argv[]){
    if(argc <= 2){
        printf("Please enter policy and priority that is wanted\n");
        return 0;
    } 
    if(setPolicy(atoi(argv[1]), atoi(argv[2])))
    {
        pid_t pid = getpid();
        printf("The policy was sucessfully changed\n");
        printf("PID: %d\n", pid);
        sleep(15);
        return 0;
    }
    printf("The policy change was unsecessful.\n");
    return 0;
}