/*
** EPITECH PROJECT, 2019
** time_management.hpp
** File description:
** defines for managing time with std lib
*/

#ifndef TIME_MANAGEMENT_HPP
#define TIME_MANAGEMENT_HPP

#include <chrono>

#define NOW std::chrono::high_resolution_clock::now()
#define TIMEPOINT std::chrono::high_resolution_clock::time_point
#define DURATION std::chrono::duration_cast
#define SECONDS std::chrono::seconds
#define MILLISECONDS std::chrono::milliseconds

#endif