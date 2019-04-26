//Parent
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/wait.h>//waitpid()

int main()
{
    int rc{0};
    pid_t child_pid{ fork() };
    pid_t my_pid{ getpid() };
    pid_t parent_pid{ getppid() };

    if (child_pid == -1){
        perror("Fork: ");
    }else if (child_pid == 0)
    {
        char **args = (char**) malloc(sizeof(char*));
        std::string buf;
        int count{0};
        std::cout << "\nInput command [arguments]: ";

        do{
            std::cin >> buf;
            args[count] = new char[buf.size()];
            buf.copy(args[count], buf.size());
            args = (char**) realloc(args, sizeof(char*) * (++count+1));
        }while(getchar() != '\n');

        args[count] = nullptr;

        if ((rc = execvp(args[0], (char* const*)args)) == -1){
            perror("Exec: ");
        }

        for (int i = 0; i < count; ++i){
            delete[] args[i];
        }

        delete args;
    }else
    {
        std::cout << "Parent: Parent PID: " << parent_pid << "\n";
        std::cout << "Parent: My PID: " << my_pid << "\n";
        std::cout << "Parent: Child PID: " << child_pid << "\n";

        int status{0};

        //True, если child был продолжен

        do{
            rc = waitpid(child_pid, &status, WNOHANG);
            if (rc==-1){
                perror("Waitpid: ");
            }
            else if (rc>0){
                std::cout << "Parent: Child proccess has ended successfully: " << WEXITSTATUS(status) << "\n";  
            }
            sleep(1);
        }while(rc<=0);

        // if ((rc = waitpid(child_pid, &status, WNOHANG)) == -1){
        //     perror("Waitpid: ");
        // }

        // if (status == 0){
        //     std::cout << "Parent: Child proccess has ended successfully: " << WEXITSTATUS(status) << "\n";
        // }else{
        //     std::cout << "Parent: Child proccess has ended wrong\n";
        // }

    }
    return 0;
}
