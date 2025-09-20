# Employee Database Management System

A cross-platform C++ console application for managing employee data with SQLite database backend.

## Features

- **Employee Management**: Add, update, delete, and view employee records
- **Department Management**: Manage department information
- **Role-based Operations**: Support for Engineers, Finance, HR, QA, and Managers
- **Data Export**: Export tables to CSV format
- **Database Operations**: Create and delete custom tables
- **Cross-platform Compatibility**: Works on Windows, Linux, and macOS

## Platform Independence

This project has been made platform-independent with the following improvements:

- **Cross-platform Screen Clearing**: Replaced Windows-specific `system("cls")` with platform-aware screen clearing
- **Standard C++ Libraries**: Uses standard C++17 features and libraries
- **CMake Build System**: Replaced Visual Studio project files with CMake for cross-platform building
- **Portable File Paths**: Uses `std::filesystem` for cross-platform path handling

## Prerequisites

- **C++ Compiler**: Supporting C++17 standard
  - GCC 7+ (Linux/macOS)
  - Clang 5+ (Linux/macOS)
  - MSVC 2017+ (Windows)
- **CMake**: Version 3.16 or higher
- **SQLite**: Included in the project (no separate installation needed)

## Building the Project

### Using CMake Presets (Recommended)

This project includes CMake presets for easy building across different platforms. The presets automatically detect your platform and configure the appropriate build settings.

#### Available Presets:
- **Windows**: `windows-debug`, `windows-release`, `mingw-debug`, `mingw-release`
- **Linux**: `linux-debug`, `linux-release`
- **macOS**: `macos-debug`, `macos-release`

#### Quick Start:

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd Employee-Management/Employee\ Database
   ```

2. **List available presets**:
   ```bash
   cmake --list-presets
   ```

3. **Configure with preset**:
   ```bash
   # Windows (Visual Studio)
   cmake --preset windows-release
   
   # Linux
   cmake --preset linux-release
   
   # macOS
   cmake --preset macos-release
   
   # Windows (MinGW)
   cmake --preset mingw-release
   ```

4. **Build with preset**:
   ```bash
   cmake --build --preset windows-release    # Windows
   cmake --build --preset linux-release      # Linux
   cmake --build --preset macos-release      # macOS
   cmake --build --preset mingw-release      # Windows MinGW
   ```

5. **Run the application**:
   ```bash
   # Windows (Visual Studio)
   ./build/windows-release/bin/Release/EmployeeDatabase.exe
   
   # Linux
   ./build/linux-release/bin/EmployeeDatabase
   
   # macOS
   ./build/macos-release/bin/EmployeeDatabase
   
   # Windows (MinGW)
   ./build/mingw-release/bin/EmployeeDatabase.exe
   ```

### Manual Build (Alternative)

If you prefer not to use presets:

#### Windows
```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
```

#### Linux/macOS
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## Project Structure

```
Employee Database/
├── CMakeLists.txt              # CMake build configuration
├── README.md                   # This file
├── main.cpp                    # Application entry point
├── include/                    # Header files
│   ├── utils/
│   │   └── PlatformUtils.h     # Cross-platform utilities
│   ├── model/                  # Data models
│   ├── controller/             # Business logic controllers
│   └── views/                  # User interface
├── src/                        # Source files
│   ├── utils/
│   │   └── PlatformUtils.cpp   # Platform-specific implementations
│   ├── controller/             # Controller implementations
│   └── views/                  # View implementations
├── lib/sqlite/                 # SQLite library
├── data/                       # Database files
├── tablesInCSV/               # CSV export directory
└── Logs/                      # Logging utilities
```

## Key Platform-Independent Features

### Cross-Platform Screen Clearing
The application uses a custom `PlatformUtils::clearScreen()` function that:
- Uses `system("cls")` on Windows
- Uses `system("clear")` on Linux/macOS
- Falls back to printing newlines on other systems

### Standard Library Usage
- **File System**: Uses `std::filesystem` for portable path operations
- **Input/Output**: Standard C++ streams for console I/O
- **String Handling**: Standard string operations with proper encoding

### CMake Integration
- Automatic platform detection
- Compiler-specific optimizations
- Cross-platform library linking
- Automated resource copying

## Database Schema

The application manages the following entities:
- **Employees**: Basic employee information
- **Engineers**: Technical employees with technology specialization
- **Finance**: Financial department employees
- **HR**: Human resources employees
- **QA**: Quality assurance employees
- **Managers**: Management employees with team information
- **Departments**: Organizational departments

## Usage

1. **Main Menu**: Choose between table operations and employee database management
2. **Table Operations**: Create or delete custom database tables
3. **Employee Operations**: Perform CRUD operations on employee data
4. **Export Features**: Export data to CSV format for external use

## Contributing

1. Ensure code follows C++17 standards
2. Test on multiple platforms before submitting
3. Update CMakeLists.txt if adding new source files
4. Maintain cross-platform compatibility

## Platform Testing

This application has been designed to work on:
- ✅ Windows 10/11 (MSVC, MinGW)
- ✅ Linux (GCC, Clang)
- ✅ macOS (Clang, GCC via Homebrew)

## License

[Add your license information here]

## Troubleshooting

### Build Issues
- Ensure CMake version is 3.16+
- Check C++17 compiler support
- Verify all source files are present

### Runtime Issues
- Ensure database files have proper permissions
- Check that CSV export directory exists
- Verify SQLite database integrity

### Platform-Specific Notes
- **Windows**: May require Visual C++ Redistributable
- **Linux**: Ensure pthread library is available
- **macOS**: May require Xcode command line tools
