// prints out "matrix" style 1s and 0s to terminal

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <csignal>

using namespace std;

bool do_exit = false;
void signal_handler (int signal);
int main ()
{
	signal (SIGINT, signal_handler);
	signal (SIGTERM, signal_handler);
	srand (time (NULL));
	string tmp;
	while (!do_exit)
	{
		tmp.clear ();
		for (int i = 0; i < 80; i++)
		{
			if (rand () < RAND_MAX/2)
				tmp.append ("0");
			else
				tmp.append ("1");
		}
		printf ("%s\n", tmp.c_str ());
		usleep (10);
	}
	return 0;
}

void signal_handler (int signal)
{
	do_exit = true;
	return;
}
