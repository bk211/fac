#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Define the function to be called when ctrl-c (SIGINT) signal is sent to process

void signal_callback_handler(int signum)
{
	if (signum == 2 ){

		printf("bad signal Caught signal %d == SIGINT\n",signum);
	}
	
	else if (signum == 3 ){

		printf("bad signal .. continue Caught signal ==SIGQUIT %d\n",signum);
	}

	
	else if (signum == 9 ){

		printf("can't be reached Caught signal %d\n",signum);
	}   
	// Cleanup and close up stuff here	
	

	// Terminate program
	
	
   	//exit(1);
}

int main()
{
	// Register signal and signal handler
	signal(SIGINT, signal_callback_handler);
   	signal(SIGQUIT, signal_callback_handler);
   	signal(SIGKILL, signal_callback_handler);
	while(1)
		{
		printf("Program processing stuff here.\n");
		sleep(1);
   		}
   return EXIT_SUCCESS;
}


