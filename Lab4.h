#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

//enum types
enum bloods {A, AB, O, B};
enum organs {Heart, Kidney, Lung, Liver};

struct patient
{
    char firstName[50];
    char lastName[50];
    bloods bloodType;
    organs organ;
    int age;
    int yearAdded;
    int patientNumber;
};

//function declarations
void add_show_save_PatientRecord (int option, int i, int &list_size, int &quit, char argument[]);
void displayTextFile (char argument []);

#endif /* LAB4_H */

