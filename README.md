# Time Converter

The Time Converter is a command-line tool designed to facilitate the conversion between standard time (hours and minutes) and a specific format known as "industrial time". This utility is particularly useful for industries or applications where time needs to be expressed in a more streamlined or specific decimal format.

## Features

- Convert standard time to industrial time.
- Convert industrial time back to standard time.
- Command-line interface for easy integration into scripts or other tools.

## Prerequisites

Before you begin, ensure you have met the following requirements:
- You have a modern C++ compiler that supports C++11 (e.g., GCC, Clang).
- You have `make` and `CMake` installed on your machine (for building the project).
- You are using a Unix-like operating system (Linux, macOS).

## Building the Project

To build the Time Converter, follow these steps:

```bash
git clone https://github.com/yourusername/time-converter.git
cd time-converter/build
cmake ..
make
