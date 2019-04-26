//Child
#include <iostream>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t my_pid{ getpid() };
	pid_t parent_pid{ getppid() };

	std::cout << "\nChild: my PID: " << my_pid << "\n";
	std::cout << "Child: Parent PID: " << parent_pid << "\n";

	if (argc == 1)
	{
		std::cout << "No arguments\n";

	}else{

		std::cout << "There are arguments:\n";

		for (int i = 1; i < argc; ++i)
		{
			std::cout << i << ": " << argv[i] << "\n";
			sleep(1);
		}
	}
	return 0;
}
