# Hospital-Management-System
# Hospital Management System

A simple C++ console-based Hospital Management System for managing patients, doctors, nurses, and medical records.

## Features
- Admin, Doctor, and Nurse login roles
- Add, view, update, and remove patients
- Add and view doctors and nurses
- Manage medical records and doctor's orders
- Simple file-based data storage (no database required)

## Prerequisites
- Windows OS
- Visual Studio 2019 or later (uses MSVC v142 toolset)

## How to Build and Run
1. Open the `ConsoleApplication18.sln` or the `.vcxproj` file in Visual Studio.
2. Build the solution (Ctrl+Shift+B).
3. Run the application (F5 or Ctrl+F5).

### Command Line (if you have MSVC tools installed)
```
cd ConsoleApplication18
cl /EHsc ConsoleApplication18.cpp
ConsoleApplication18.exe
```

## File Descriptions
- `ConsoleApplication18.cpp`: Main source code for the hospital management system.
- `logincredentials.txt`: Stores user credentials (role, username, password).
- `doctorBiodata.txt`, `nurseBiodata.txt`: Stores biodata for doctors and nurses.
- `patient_records.txt`: Stores patient information.
- `medical_record.txt`: Stores patient medical records.
- `doctor_orders.txt`: Stores doctor's orders for patients.
- `id_count.txt`: Stores the last used patient ID.

## Notes
- All data is stored in plain text files in the executable directory.
- For first use, create empty text files as needed (e.g., `logincredentials.txt`, `id_count.txt` with a starting value of 0).
- Do not share sensitive data as files are not encrypted.
