/*
 * Caliper
 *
 * Author: Zach McKenna
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "MaintenanceRecord.h" // Includes

std::vector<MaintenanceRecord> getRecordsFromFile();
std::string generateIndex(size_t length);
void printAllRecords();
void overwriteRecords(std::vector<MaintenanceRecord> overwriteRecords);
bool deleteRecord(std::string indexToDelete); // Definitions for the functions found in Functions.cpp
#endif
