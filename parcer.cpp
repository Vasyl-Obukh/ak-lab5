#include <getopt.h>
#include <iostream>

int num = -1;
bool is_done = false;
std::string write_file = "default_file.txt";

void PrintHelp()
{
    std::cout <<
            "--num <n>:           Set number of program\n"
            "--done:              Done with user\n"
            "--writeFile <fname>: File to write to\n"
            "--help:              Show help\n";
    exit(1);
}

void ProcessArgs(int argc, char** argv)
{
    const char* const short_opts = "n:dw:h";
    const option long_opts[] = {
            {"num", required_argument, nullptr, 'n'},
            {"done", no_argument, nullptr, 'd'},
            {"writeFile", required_argument, nullptr, 'w'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'n':
            num = std::stoi(optarg);
            std::cout << "Num set to: " << num << std::endl;
            break;

        case 'd':
            is_done = true;
            std::cout << "Done is set to true\n";
            break;

        case 'w':
            write_file = std::string(optarg);
            std::cout << "Write file set to: " << write_file << std::endl;
            break;

        case 'h':
        case '?':
        default:
            PrintHelp();
            break;
        }
    }
}

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);
    return 0;
}
