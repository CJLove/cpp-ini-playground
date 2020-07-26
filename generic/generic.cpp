#include "inipp.h"
#include <fstream>
#include <iostream>

#include <unistd.h>

void usage()
{
    std::cout << "Usage:\n"
              << "generic [-f <file>]\n";
    exit(1);
}


int main(int argc, char**argv)
{
    const char *file = "../inputs/sample.ini";
    int c = 0;
    while ((c = getopt(argc, argv, "f:?")) != EOF)
    {
        switch (c)
        {
        case 'f':
            file = optarg;
            break;
        case '?':
            usage();
            break;
        default:
            std::cerr << "Unexpected arg " << (char)c << "\n";
            usage();
        }
    }
 
    inipp::Ini<char> ini;
    std::ifstream is(file);
    try {
        ini.parse(is);

        std::string topString;
        inipp::extract(ini.sections["DEFAULT"]["top-string"],topString);
        std::cout << "top-string = " << topString << "\n";

        int topInt = 0;
        inipp::extract(ini.sections["DEFAULT"]["top-int"],topInt);
        std::cout << "top-int = " << topInt << "\n";

        bool topBool = false;
        inipp::extract(ini.sections["DEFAULT"]["top-bool"],topBool);
        std::cout << "top-bool = " << topBool << "\n";

    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception " << e.what() << "\n";
    }

}