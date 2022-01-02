# Transplant-Patient-Records
### Overview & Goals
This C++ programming project involved working with struct, enum, and text file I/O. The goal was related to the construction and archival of transplant patient records. The task 
included storage of patient records in an array, display of those records, saving (i.e. writing) of those records in a text file, and finally, loading (i.e. reading) the patient records from a previously saved file into records. The implementation supported up to 100 patients maximum.

### Part 1: Storing Patient Information
In this part each patient’s information is stored in a struct that records the patient’s:
- First name 
- Last name
- Bloodtype (A, AB, O or B)
- Organ (Heart, Kidney, Lung or Liver only)
- Age
- Year Added (the year the patient record was added to the list)
 
An array of instances of struct of the Patient Record is used. Enumerated types (enum) are used for the attributes (bloodtype and organ). 
Each record has to been specified in the following format:
`<firstName> <surName> <bloodType> <organType> <age> <yearAdded>`
 
 ### Part 2: Saving/Archiving the Patient Records
 In this part the current list of records of patients is saved in a text file `transplantPatients.txt`. The file `transplantPatients.txt` is created inside the folder from where the program is run.

### Part 3: Loading Saved Records
This part is not 100% operational at the moment. However, the program is expected to implement the loading (i.e. reading) of patient records from the file 
`transplantPatients.txt` into the array of struct. The executable `lab4proj.exe` should do so when run from the command-line. Once the text file transplantPatients.txt has been read, it should be closed.

### *An Example Usage Of The Program For Part 1 & 2:*
![image](https://user-images.githubusercontent.com/80440201/147890243-53097ee4-12c4-49cf-81e7-2ebef822fcb8.png)
![image](https://user-images.githubusercontent.com/80440201/147890251-88ed518c-682b-4f80-82a2-0057ee50043e.png)
