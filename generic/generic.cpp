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
    ini.parse(is);

    if (ini.errors.size()) {
        for (const auto &s: ini.errors) {
            std::cout << "Invalid input: " << s << "\n";
        }
    } else {

        std::string topString;
        inipp::extract(ini.sections["DEFAULT"]["top-string"],topString);
        std::cout << "top-string = " << topString << "\n";

        int topInt = 0;
        bool result = inipp::extract(ini.sections["DEFAULT"]["top-int"],topInt);
        std::cout << "top-int = " << topInt << " result = " << result << "\n";

        result = inipp::extract(ini.sections["foo"]["blah"],topInt);
        std::cout << "result for bad section/name = " << result << "\n";

        bool topBool = false;
        inipp::extract(ini.sections["DEFAULT"]["top-bool"],topBool);
        std::cout << "top-bool = " << topBool << "\n";

        std::string name;
        inipp::extract(ini.sections["test"]["name"],name);
        std::cout << "name = " << name << "\n";

    }

}