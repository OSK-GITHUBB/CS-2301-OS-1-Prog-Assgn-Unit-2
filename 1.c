#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
int x = 100;
printf("hello world (pid:%d)\n", (int) getpid());
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
printf("hello, I am child (pid:%d)\n", (int) getpid());
printf("%d", x);
// x = 90;
} else {
// parent goes down this path (main)
printf("hello, I am parent of %d (pid:%d)\n",
rc, (int) getpid());
// x = 80;
}
return 0;
}
