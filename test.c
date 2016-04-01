/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Apr 2016 05:22:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main(){
        char s[] = "GET  /index.html  HTTP/1.1";
        char ss[] = "info.php";
        char *p;
        //printf("%s ", strtok(s, delim));
    printf("%s\n",strtok(s," /"));
    printf("%s\n",strtok(NULL," /"));



    printf("%s\n",strtok(ss,"."));
    printf("%s\n",strtok(NULL,"."));

    return 1;
    while((p = strtok(s, " /"))){

            printf("%s ", p);
            printf("\n");
            getchar();
    }

}
