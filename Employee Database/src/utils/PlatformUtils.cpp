#include "PlatformUtils.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
    #include <cstdlib>
#endif

namespace EmployeeDB::Utils {
    void clearScreen() {
        #ifdef _WIN32
            // Windows
            system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            // Linux and macOS
            system("clear");
        #else
            // Fallback for other systems - print newlines
            for (int i = 0; i < 50; ++i) {
                std::cout << "\n";
            }
        #endif
    }
}
