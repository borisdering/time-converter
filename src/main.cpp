#include <iostream>
#include <iomanip>
#include <locale>
#include "industrial_time.h"

/**
 * @brief   Displays the help menu for the program
*/
void display_help() {
    std::cout << "Industrial Time Converter" << std::endl;
    std::cout << "Usage: industrial_time_converter [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "-h, --help\tDisplay this help menu" << std::endl;
    std::cout << "-s, --standard\tConvert standard time to industrial time" << std::endl;
    std::cout << "-i, --industrial\tConvert industrial time to standard time" << std::endl;
}

/** 
 * @brief   The main function of the program
*/
int main(int argc, char *argv[]) {

    try {
        // Set the global locale to the user's preferred locale
        std::locale::global(std::locale("")); // Set to system's default locale
        std::cout.imbue(std::locale()); // Apply the locale to cout
    } catch (const std::runtime_error& e) {
        std::cerr << "Error setting the locale: " << e.what() << std::endl;
        return 1;
    }

    // if the user passes less than 3 arguments, display the help menu
    if(argc < 3) {
        std::cerr << "Invalid number of arguments" << std::endl;
        display_help();
        return 1;
    }

    // if no arguments are passed, display the help menu
    // or if -h is passed as an argument, display the help menu
    if (argc == 1 || std::string(argv[1]) == "-h") {
        display_help();
        return 0;
    }

    // if the user wants to convert standard time to industrial time
    // and -s or --standard is passed as an argument
    if (std::string(argv[1]) == "-s" || std::string(argv[1]) == "--standard") {
        // read the hours and minutes from the arguments passed as 
        // for example 148:41:39 is 148 hours and 41 minutes and 39 seconds
        // we only need the hours and minutes
        uint64_t hours, minutes;
        if (sscanf(argv[2], "%llu:%llu", &hours, &minutes) != 2) {
            std::cerr << "Error: Invalid time format. Expected format 'HH:MM'." << std::endl;
            return 1;
        }

        // convert the standard time to industrial time
        float_t industrial_time = standard_to_industrial(hours, minutes);

        // round up the industrial time to 2 decimal places-s 
        industrial_time = roundf(industrial_time * 100) / 100;

        // display the industrial time rounded to 2 decimal places
        std::cout << std::fixed << std::setprecision(2) << industrial_time << std::endl;

        return 0;
    } else if (std::string(argv[1]) == "-i" || std::string(argv[1]) == "--industrial") {
        // read the industrial time from the arguments passed
        double industrial_time;
        sscanf(argv[2], "%lf", &industrial_time);

        // convert the industrial time to standard time
        uint16_t hours, minutes;
        industrial_to_standard(industrial_time, hours, minutes);

        // Display the standard time with hours and minutes padded with leading zeros
        std::cout << std::setfill('0') << std::setw(3) << hours << ":" << std::setfill('0') << std::setw(2) << minutes << std::endl;

        return 0;
    }

    // if the user passes an invalid argument, display the help menu
    display_help();

    return 0;
}