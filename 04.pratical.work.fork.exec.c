#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
    int pid = fork();
    if (pid == 0) {
	write(1, "\n=============================\n",30);
	write(1, "\n[*] Executing 'ps -ef'\n",30);
        system("ps -ef");
	pid = fork();
	if (pid == 0) {
	    write(1, "\n=============================\n",30);
	    write(1, "\n[*] Executing 'free -h'\n",30);
	    system("free -h");
    	}	    
    }
    return 0;
}
