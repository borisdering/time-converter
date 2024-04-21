#include <iostream>
#include <iomanip>
#include <locale>

#ifndef INDUSTRIAL_TIME
#define INDUSTRIAL_TIME 0

/** 
 * @brief   Converts standard time hours and minutes to industrial time units 
 *          153 hours and 45 minutes is equal to 153.75 industrial time
 * @param   hours   The hours in standard time
 * @param   minutes The minutes in standard time
 * 
 * @return  The industrial time equivalent of the standard time
*/
double standard_to_industrial(uint64_t hours, uint64_t minutes);

/** 
 * @brief   Converts industrial time units to standard time hours and minutes
 *          153.75 industrial time is equal to 153 hours and 45 minutes
 * @param   industrial_time  The industrial time to convert
 * @param   hours           The hours in standard time
 * @param   minutes         The minutes in standard time
*/
void industrial_to_standard(double industrial_time, uint16_t &hours, uint16_t &minutes);

#endif // !INDUSTRIAL_TIME
// Path: industrial_time.cpp