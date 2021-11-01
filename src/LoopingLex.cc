#include "Lexer.h"

#include <getopt.h>
#include <iostream>
#include <string>


void usage() {
    std::cout <<
            "--file <file-name>:  Source code to analyze \n"
            "--accelerate:        Enable OpenMP acceleration \n"
            "--help:              Print usage \n";
}

void argparse(int argc, char** argv) {
    using namespace plex;

    const char* const short_opts = "af:h";
    const option long_opts[] = {
        {
            "accelerate", no_argument, nullptr, 'a'
        },
        {
            "file", required_argument, nullptr, 'f'
        }, 
        {
            "help", no_argument, nullptr, 'h'
        }
    };
    
    std::string file;
    bool accelerate = false;

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt) {
            break;
        }

        switch (opt)
        {
        case 'f':
            file = optarg;
            break;

        case 'a':
            accelerate = true;
            break;

        case 'h':
        case '?':
        default:
            usage();
            return;
        }
    }
    auto l = new Lexer(file, accelerate); 
    l->Scan();
    return;
}


int main(int argc, char **argv)
{
    argparse(argc, argv);
    return 0;
}

