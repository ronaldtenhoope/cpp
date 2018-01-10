#include <syslog.h>
#include <unistd.h>
#include "become_daemon.h"

int main(int argc, char *argv[])
{

	if (becomeDaemon(04) == -1)
		return -1;

	for(;;) {
		sleep(100);
	}

	return 0;
}
