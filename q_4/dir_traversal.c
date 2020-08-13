
       #define _XOPEN_SOURCE 500
       #include <ftw.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>
       #include <stdint.h>

       static int display_info(const char *fpath, const struct stat *sb,
                    int tflag, struct FTW *ftwbuf)
       {
           if(tflag == FTW_SL || tflag == FTW_SLN){
                return 0;
            }
            printf("%-3s  ",
                   (tflag == FTW_D) ?   "D"   : (tflag == FTW_DNR) ? "dnr" :
                   (tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "F" :
                   (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
                   (tflag == FTW_SLN) ? "sln" : "???");

           if (tflag == FTW_NS)
               printf("-------"); 
           else
               printf("%7jd", (intmax_t) sb->st_ino);

            
            printf("   %-40s\n",
                   fpath);

           return 0;  
       }

       int main(int argc, char *argv[])
       {
           int flags = 0;

           if (argc > 2 && strchr(argv[2], 'd') != NULL)
               flags |= FTW_DEPTH;
               flags |= FTW_PHYS;

           if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags) == -1) {
               perror("nftw");
               exit(EXIT_FAILURE);
           }

           exit(EXIT_SUCCESS);
       }
