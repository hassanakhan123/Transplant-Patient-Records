#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "Lab4.h"

using namespace std;

void add_show_save_PatientRecord(int option, int i, int &listSize ,int &quit, char argument[])
{
    int j;
    string tempBloodType;
    string tempOrgan;	
    patient patient[100]; 

    if(option == 1)	//entering patient information
    {
        cout << "=============" << endl
             << "[Add Patient]" << endl
             << "Please enter the Patient Record (First Name, Last Name, Blood Type, Organ, Age, Year Added):" << endl << endl;
        cin  >> patient[i].firstName >> patient[i].lastName >> tempBloodType >> tempOrgan >> patient[i].age >> patient[i].yearAdded;
        cout << ".. [Adding]" << endl;

        //translate info into enum types

        if (tempBloodType == "A") {
            patient[i].bloodType = A;
        }
        if (tempBloodType == "AB") {
            patient[i].bloodType = AB;
        }
        if (tempBloodType == "O") {
            patient[i].bloodType = O;
        }
        if (tempBloodType == "B") {
            patient[i].bloodType = B;
        }
        if ((tempBloodType != "A") && (tempBloodType != "AB") && (tempBloodType != "O") && (tempBloodType != "B")) {
            cout << "\nInvalid blood type.";
        }

        if(tempOrgan == "Heart") {
            patient[i].organ = Heart;
        }
        if(tempOrgan == "Kidney") {
            patient[i].organ = Kidney;
        }
        if(tempOrgan == "Lung") {
            patient[i].organ = Lung;
        }
        if(tempOrgan == "Liver") {
            patient[i].organ = Liver;
        }
        if((tempOrgan != "Heart") && (tempOrgan != "Kidney") && (tempOrgan != "Lung") && (tempOrgan != "Liver")) {
            cout << "\nInvalid organ.";
        }

        patient[i].patientNumber = listSize + 1;

        listSize++; //update list size once patient info added

    }

    if(option == 2) 	//displaying patients
    {
        cout << "[Show List of Patients]";
        cout << "\nID\tName\t\tBlood\tOrgan\tAge\tYear Added";
        cout << "\n----------------------------------------------------------------------\n";
           
       for(j = 0; j < listSize; j++)
       {
           cout << patient[j].patientNumber << "\t" << patient[j].lastName << ", " << patient[j].firstName[0] << "\t";

           //translate info out of enum types
           if (patient[j].bloodType == 0) {
               cout << "A\t";
           }
           if (patient[j].bloodType == 1) {
               cout << "AB\t";
           }
           if(patient[j].bloodType == 2) {
               cout << "O\t";
           }
           if(patient[j].bloodType == 3) {
               cout << "B\t";
           }

           //translate info out of enum type
           if(patient[j].organ == 0) {
               cout << "Heart\t";
           }
           if(patient[j].organ == 1) {
               cout << "Kidney\t";
           }
           if(patient[j].organ == 2) {
               cout << "Lung\t";
           }
           if(patient[j].organ == 3) {
               cout << "Liver\t";
           }

           cout << patient[j].age << "\t" << patient[j].yearAdded << "\n";
        }
    }

    if(option == 3)	//saving patient list to file
    {
        ofstream myfile;	//outputting to file
        myfile.open("transplantPatients.txt");
        myfile << "Patients: " << listSize << endl;

        myfile << "\nID\tName\t\tBlood\tOrgan\tAge\tYear Added";
        myfile << "\n----------------------------------------------------------------------\n";

       for(j = 0; j < listSize; j++) //outputting to file
       {
           myfile << patient[j].patientNumber << "\t" << patient[j].lastName << ", " << patient[j].firstName[0] << "\t";
           if(patient[j].bloodType == 0) {
               myfile << "A\t";
           }
           if(patient[j].bloodType == 1) {
               myfile << "AB\t";
           }
           if(patient[j].bloodType == 2) {
               myfile << "O\t";
           }
           if(patient[j].bloodType == 3) {
               myfile << "B\t";
           }
           if(patient[j].organ == 0) {
               myfile << "Heart\t";
           }
           if(patient[j].organ == 1) {
               myfile << "Kidney\t";
           }
           if(patient[j].organ == 2) {
               myfile << "Lung\t";
           }
           if(patient[j].organ==3) {
               myfile << "Liver\t";
           }
           myfile << patient[j].age << "\t" << patient[j].yearAdded << "\n\n";
        }
        
        myfile.close();
        cout << "[Save List of Patients] (File: \"transplantPatients.txt)" << endl;
    }

    if(option==4) { //quit loop
        quit=1;
    }    
    else if((option!=1)&&(option!=2)&&(option!=3)&&(option!=4))
        cout << "\nInvalid option. Please try again.\n\n";
}


void displayTextFile (char argument []) //function for displaying text file contents in command line
{
    string line;
    if(strcmp (argument,"transplantPatients.txt") == 0) //check if argument from command line is "trasnplantPatients.txt"
    {
        ifstream myfile ("transplantPatients.txt");	//receiving input from file
        if (myfile.is_open())
        {
            while (getline (myfile,line))
            {
                cout << line << endl;	//output contents of file
            }
            myfile.close();
        }
    }

    else {
        cout << "\nInvalid Argument. Please try again\n";
    }

}

int main(int argc, char *argv[])
{
    int i;
    int option;
    int listSize = 0;
    int quit;
    
    if (argc == 1) //execution in command line without file name
    {
        for(i = 0; i < 100; i++) {
            cout << "=======================" << endl;
            cout << "[Organ Transplant List]" << endl;
            cout << "There are currently " << listSize << " patient(s) in the list" << endl << endl;
            cout << "Please choose an option:" << endl
                 << "1.  Add Patient" << endl 
                 << "2.  Show List of Patients" << endl
                 << "3.  Save List of Patients" << endl 
                 << "4.  Quit" << endl;
            cin  >> option;

            add_show_save_PatientRecord(option, i, listSize, quit, argv[1]);	//call add_show_save_PatientRecord function

            if( quit == 1) {
                break;
            }
        }
    }

    if (argc == 2)	//execution in the command line with file name
    {
        displayTextFile(argv[1]);
    }

    else if (argc < 1)
    {
        cout << "Invalid number of arguments.\n";
    }
    return(0);

}