#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits> // For numeric_limits
using namespace std;
struct Patient {
    string namep;
    string cnicp;
    int agep;
    int idp;
    long int phnumber;
    int vitals;
    string pres;
    string com;

};
int ID;
struct staffBio {
    string name, cnic;
    int age;
    long int phoneNo;
};
struct staffLogin {
    string username;
    string password;
};

bool userLogin(const string& role, const string& username, const string& password);
bool isUsernameTaken(const string& username);
void adminDashboard(const string& username);
void doctorDashboard(const string& username);
void nurseDashboard(const string& username);
void addNewUser(const string& role);
void removeNurse();
void removeDoctor();
void removeUser(const string& role, const string& username);
void adminRegistration();
void viewStaff(const string& fileName, const string& role);
void add_patientrecord();
void register_patient();
void view_patient();
void update_patient();
void remove_patient();
void register_patient();
void add_doctor_orders();
void view_doctor_orders();
void readMedicalRecord();
bool containsNumeric(const string& str);
void searchMedicalRecord();

int main() {
    int choice;
    string Role, Username, Password;
    bool cond = false;

    do {

        cout << "Welcome to the Hospital Management System\n";
        cout << "1. Admin Login\n";
        cout << "2. Doctor Login\n";
        cout << "3. Nurse Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        // Check if the input is an integer
        if (!(cin >> choice)) {
            // If not an integer, clear the error state and consume invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numeric choice.\n";
            continue;
        }

        switch (choice) {
        case 1:
            Role = "admin";
            break;
        case 2:
            Role = "doctor";
            break;
        case 3:
            Role = "nurse";
            break;
        case 4:
            cout << "Exiting...\n";
            cond = true;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            continue;
        }
        cout << "Enter id > ";
        cin.ignore();
        getline(cin, Username);
        cout << "Enter password > ";
        getline(cin, Password);
        if (userLogin(Role, Username, Password))
        {
            if (Role == "admin")
            {
                adminDashboard(Username);
            }
            else if (Role == "doctor")
            {
                doctorDashboard(Username);
            }
            else if (Role == "nurse")
            {
                nurseDashboard(Username);
            }
        }
        else
        {
            cout << "wrong credentials!";
        }
    } while (true);

    return 0;
}

bool userLogin(const string& role, const string& username, const string& password) {
    ifstream credentialsFile("logincredentials.txt");
    if (!credentialsFile.is_open()) {
        cerr << "Unable to open credentials file." << endl;
        return false;
    }

    string storedRole, storedUsername, storedPassword;
    while (getline(credentialsFile, storedRole, ':') &&
        getline(credentialsFile, storedUsername, ':') &&
        getline(credentialsFile, storedPassword)) {
        if (role == storedRole && username == storedUsername && password == storedPassword) {
            credentialsFile.close();
            return true; // Authentication successful
        }
    }

    credentialsFile.close();
    return false; // Authentication failed
}

void adminDashboard(const string& username) {
    cout << "Welcome Admin: " << username << endl;
    int choice;
    bool cond = false;

    do {
        cout << "Admin Menu:" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. Add Nurse" << endl;
        cout << "3. Remove Doctor" << endl;
        cout << "4. Remove Nurse" << endl;
        cout << "5. View Doctors" << endl;
        cout << "6. View Nurses" << endl;
        cout << "7. Register Patient" << endl;
        cout << "8. Display All Patients" << endl;
        cout << "9. Logout" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numeric choice.\n";
            continue;
        }

        switch (choice) {
        case 1:
            addNewUser("doctor");
            break;

        case 2:
            addNewUser("nurse");
            break;

        case 3:
            removeDoctor();
            break;

        case 4:
            removeNurse();
            break;

        case 5:
            viewStaff("doctorBiodata.txt", "doctor");
            break;

        case 6:
            viewStaff("nurseBiodata.txt", "nurse");
            break;

        case 7:
            register_patient();
            break;
        case 8:
            view_patient();
            break;
        case 9:
            cout << "Exiting Admin Dashboard..." << endl;
            cond = true;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            continue;
        }
    } while (!cond);
}
void doctorDashboard(const string& username)
{
    int op;
    bool cond = false;
    do {
        cout << "Welcome Doctor: " << username << endl;
        cout << "1. Add Patient's Medical record" << endl;
        cout << "2. View Patient Data" << endl;
        cout << "3. Display Patients Medical record" << endl;
        cout << "4. Search for a Patient's Medical record" << endl;
        cout << "5. Exit.." << endl;
        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numeric choice.\n";
            continue;
        }

        switch (op) {

        case 1:
            add_patientrecord();
            break;
        case 2:
            view_patient();
            break;
        case 3:
            readMedicalRecord();
            break;
        case 4:
            searchMedicalRecord();
            break;
        case 5:
            cond = true;
            break;
        default:
            cout << "Invalid input" << endl;
            continue;
        }

    } while (!cond);

}

void nurseDashboard(const string& username) {
    int select;
    bool cond = false;
    do {
        cout << "Welcome Nurse: " << username << endl;
        cout << "1. View Patient Information" << endl;
        cout << "2.Update Patient Medical Information" << endl;
        cout << "3. Add Doctor's Orders" << endl;
        cout << "4. View Doctor's Orders" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> select)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numeric choice.\n";
            continue;
        }

        switch (select) {
        case 1:
            view_patient();
            break;
        case 2:
            update_patient();
            break;
        case 3:
            add_doctor_orders();
            break;
        case 4:
            view_doctor_orders();
            break;
        case 5:
            cout << "Exiting Nurse Dashboard..." << endl;
            cond = true;
            break;
        default:
            cout << "Invalid selection, try again" << endl;
            break;
        }
    } while (!cond);
}

void adminRegistration() {
}
void addNewUser(const string& role) {
    staffBio newstaffBio;
    staffLogin newstaffLogin;

    do {
        cout << "Enter new " << role << "'s username: ";
        cin >> newstaffLogin.username;

        if (isUsernameTaken(newstaffLogin.username)) {
            cout << "Username already exists. Try a different username." << endl;
        }
        else {
            break;
        }
    } while (true);

    cout << "Enter new " << role << "'s password: ";
    cin >> newstaffLogin.password;

    cout << "Enter new " << role << "'s name: ";
    cin.ignore();
    getline(cin, newstaffBio.name);

    while (containsNumeric(newstaffBio.name)) {
        cout << "Name should not contain numbers. Enter " << role << "'s name again: ";
        getline(cin, newstaffBio.name);
    }

    cout << "Enter new " << role << "'s age: ";
    while (!(cin >> newstaffBio.age) || newstaffBio.age < 0) {
        cout << "Invalid input. Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter new " << role << "'s phone number: ";
    while (!(cin >> newstaffBio.phoneNo) || newstaffBio.phoneNo < 0) {
        cout << "Invalid input. Please enter a valid phone number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter new " << role << "'s CNIC (11121-2223322-4): ";
    cin.ignore();
    getline(cin, newstaffBio.cnic);

    while (newstaffBio.cnic.length() != 15 || newstaffBio.cnic[5] != '-' || newstaffBio.cnic[13] != '-') {
        cout << "Invalid CNIC format. Please enter a valid CNIC: ";
        getline(cin, newstaffBio.cnic);
    }
    ofstream userFile("logincredentials.txt", ios::app);
    if (userFile.is_open()) {
        userFile << endl << role << ":" << newstaffLogin.username << ":" << newstaffLogin.password;
        userFile.close();
        cout << role << " added successfully!" << endl;
    }
    else {
        cerr << "Error opening credentials file!" << endl;
    }

    ofstream bioFile(role + "Biodata.txt", ios::app);
    if (bioFile.is_open()) {
        bioFile << newstaffLogin.username << ":" << newstaffBio.name << ":" << newstaffBio.age << ":" << newstaffBio.phoneNo << ":" << newstaffBio.cnic << endl;
        bioFile.close();
        cout << role << "'s biodata added successfully!" << endl;
    }
    else {
        cerr << "Error opening biodata file!" << endl;
    }
}

void removeUser(const string& role, const string& username) {
    ifstream loginFile("logincredentials.txt");
    ofstream temploginFile("temp.txt");
    ifstream bioFile(role + "Biodata.txt");
    ofstream tempbioFile("Biotemp.txt");

    if (!loginFile.is_open() || !temploginFile.is_open() || !bioFile.is_open() || !tempbioFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool userFound = false;

    while (getline(loginFile, line)) {
        stringstream ss(line);
        string storedRole, storedUsername;
        getline(ss, storedRole, ':');
        getline(ss, storedUsername, ':');

        if (storedRole == role && storedUsername == username) {
            userFound = true;
        }
        else {
            temploginFile << line << endl;
        }
    }

    loginFile.close();
    temploginFile.close();

    while (getline(bioFile, line)) {
        stringstream ss(line);
        string storedName;
        getline(ss, storedName, ':');

        if (storedName == username) {
            userFound = true;
        }
        else {
            tempbioFile << line << endl;
        }
    }

    bioFile.close();
    tempbioFile.close();

    if (remove("logincredentials.txt") != 0 || remove((role + "Biodata.txt").c_str()) != 0) {
        cerr << "Error deleting file!" << endl;
        return;
    }

    if (rename("temp.txt", "logincredentials.txt") != 0 || rename("Biotemp.txt", (role + "Biodata.txt").c_str()) != 0) {
        cerr << "Error renaming file!" << endl;
        return;
    }

    if (userFound) {
        cout << "User removed successfully!" << endl;
    }
    else {
        cout << "User not found!" << endl;
    }
}

void removeDoctor() {
    string username;
    cout << "Enter doctor's username to remove: ";
    cin >> username;
    removeUser("doctor", username);
}

void removeNurse() {
    string username;
    cout << "Enter nurse's username to remove: ";
    cin >> username;
    removeUser("nurse", username);
}
bool isUsernameTaken(const string& username) {
    ifstream loginFile("logincredentials.txt");
    if (!loginFile.is_open()) {
        cerr << "Error opening login credentials file!" << endl;
        return true;
    }

    string line;
    while (getline(loginFile, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string storedUsername = line.substr(pos + 1, line.find(':', pos + 1) - pos - 1);
            if (storedUsername == username) {
                loginFile.close();
                return true;
            }
        }
    }

    loginFile.close();
    return false;
}
void viewStaff(const string& fileName, const string& role) {
    ifstream staffFile(fileName);
    if (!staffFile.is_open()) {
        cerr << "Error opening " << role << " biodata file!" << endl;
        return;
    }

    cout << role << " Details:" << endl;
    cout << "----------------" << endl;

    staffBio staffInfo;
    string line;

    while (getline(staffFile, line)) {
        stringstream ss(line);
        getline(ss, line, ':');
        getline(ss, staffInfo.name, ':');
        ss >> staffInfo.age;
        ss.ignore();
        ss >> staffInfo.phoneNo;
        ss.ignore();
        getline(ss, staffInfo.cnic);

        cout << "Name: " << staffInfo.name << endl;
        cout << "Age: " << staffInfo.age << endl;
        cout << "Phone Number: " << staffInfo.phoneNo << endl;
        cout << "CNIC: " << staffInfo.cnic << endl;
        cout << "----------------" << endl;
    }

    staffFile.close();
}

void register_patient() {
    // system("CLS"); // Avoid system calls for portability
    Patient p;

    ifstream counter("id_count.txt");
    if (!(counter >> ID)) {
        ID = 0; // If file is empty or missing, start from 0
    }
    counter.close();

    cout << "Enter Patient Full Name (without numbers): ";
    cin.ignore();
    getline(cin, p.namep);
    while (containsNumeric(p.namep)) {
        cout << "Name should not contain numbers. Enter Patient Full Name again: ";
        getline(cin, p.namep);
    }

    cout << "Enter Patient Age: ";
    while (!(cin >> p.agep) || p.agep <= 0) {
        cout << "Invalid age. Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Patient CNIC (in the format 11121-2223322-4): ";
    cin.ignore();
    getline(cin, p.cnicp);

    while (p.cnicp.length() != 15 || p.cnicp[5] != '-' || p.cnicp[13] != '-') {
        cout << "Invalid CNIC format. Please enter a valid CNIC: ";
        getline(cin, p.cnicp);
    }

    cout << "Enter Patient Phone Number: ";
    while (!(cin >> p.phnumber) || p.phnumber <= 0) {
        cout << "Invalid phone number. Please enter a valid phone number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ID++;
    ofstream file("patient_records.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening patient records file!" << endl;
        return;
    }
    file << ID;
    file << "\n" << p.namep;
    file << "\n" << p.agep;
    file << "\n" << p.cnicp;
    file << "\n" << p.phnumber << "\n";
    file.close();
    cout << "Patient added successfully!" << endl;
    ofstream counts("id_count.txt", ios::out);
    if (!counts.is_open()) {
        cerr << "Error opening id_count.txt!" << endl;
        return;
    }
    counts << ID;
    counts.close();
}

void add_patientrecord() {
    view_patient();
    Patient p;
    int ids;

    cout << "Enter patient ID" << endl;
    while (!(cin >> ids)) {
        cout << "Invalid input. Please enter a valid patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("patient_records.txt");

    bool patientFound = false;

    while (file >> p.idp &&
        getline(file >> ws, p.namep) &&
        file >> p.agep &&
        getline(file >> ws, p.cnicp) &&
        file >> p.phnumber) {
        if (p.idp == ids) {
            patientFound = true;
            break;
        }
    }

    file.close();
    if (!patientFound) {
        cout << "Patient Not Registered" << endl;
        return; // Don't auto-register, let user do it explicitly
    }

    cout << "Enter Patient Vitals" << endl;
    cin >> p.vitals;

    cout << "Enter Patient Prescription " << endl;
    cin.ignore();
    getline(cin, p.pres);

    cout << "Enter Patient Comments" << endl;
    getline(cin, p.com);

    ofstream report("medical_record.txt", ios::app);
    report << p.idp << "\n" << p.vitals << "\n" << p.pres << "\n" << p.com << "\n";
    report.close();
}

void view_patient() {

    Patient p;
    ifstream read("patient_records.txt");

    if (!read.is_open()) {
        cout << "Error opening patient file!" << endl;
        return;
    }

    while (read >> p.idp &&
        getline(read >> ws, p.namep) &&
        read >> p.agep &&
        getline(read >> ws, p.cnicp) &&
        read >> p.phnumber) {
        cout << "Patient ID: " << p.idp << endl;
        cout << "Patient Name:  " << p.namep << endl;
        cout << "Patient Age : " << p.agep << endl;
        cout << "Patient CNIC: " << p.cnicp << endl;
        cout << "Patient Phone Number: " << p.phnumber << endl;
        cout << "----------------" << endl << endl;
    }

    read.close();
}



void update_patient() {
    Patient p;
    int id;
    bool found = false;

    cout << "Enter Patient ID to update record" << endl;
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream read("medical_record.txt");
    ofstream tempFile("temp.txt", ios::app);

    while (read >> p.idp >> p.vitals) {
        read.ignore();
        getline(read, p.pres);
        getline(read, p.com);

        if (p.idp == id) {
            found = true;

            cout << "\nEnter new Patient Vital: ";
            cin >> p.vitals;
            cout << "\nEnter new Patient Presciption: ";
            cin.ignore();
            getline(cin, p.pres);
            cout << "\nEnter new Patient Comments: ";
            getline(cin, p.com);

            cout << "\nRecord updated successfully!";
        }
        tempFile << p.idp << "\n" << p.vitals << "\n" << p.pres << "\n" << p.com << "\n";
    }
    read.close();
    tempFile.close();

    if (found) {
        remove("medical_record.txt");
        rename("temp.txt", "medical_record.txt");
    }
    else {
        cout << "\n\tRecord not found!";
    }
}
void remove_patient() {
    Patient p;
    int id;

    cout << "Enter Id of the Patient you want to remove" << endl;
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream readPatient("patient_records.txt");
    bool foundPatient = false;

    while (readPatient >> p.idp >> p.namep >> p.agep >> p.cnicp >> p.phnumber) {
        if (p.idp == id) {
            foundPatient = true;
            break;
        }
    }

    readPatient.close();

    if (!foundPatient) {
        cout << "\n\tPatient not found in records";
        return;
    }


    ifstream readMedical("medical_record.txt");
    ofstream tempMedical("tempMedical.txt", ios::app);

    bool foundMedical = false;

    while (readMedical >> p.idp >> p.vitals) {
        readMedical.ignore();
        getline(readMedical, p.pres);
        getline(readMedical, p.com);

        if (p.idp == id) {
            foundMedical = true;
            cout << "\n\tMedical Record deleted successfully";
        }
        else {
            tempMedical << p.idp << "\n" << p.vitals << "\n" << p.pres << "\n" << p.com << "\n";
        }
    }

    readMedical.close();
    tempMedical.close();

    if (foundMedical) {
        remove("medical_record.txt");
        rename("tempMedical.txt", "medical_record.txt");
    }
    else {
        cout << "\n\tMedical Record not found";
    }
}


void add_doctor_orders() {
    int id;
    cout << "\nEnter Patient ID: ";
    if (!(cin >> id)) {
        cout << "Invalid ID, try again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "Enter Doctor's Orders for Patient ID " << id << " (Enter an empty line to finish):" << endl;

    ofstream docOrderFile("doctor_orders.txt", ios::app);
    if (!docOrderFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    docOrderFile << id << '\n';

    string orders;
    cin.ignore();
    while (true) {
        getline(cin, orders);
        if (orders.empty()) {
            break;
        }
        docOrderFile << orders << "\n";
    }
    docOrderFile.close();
    cout << "Doctor's Orders added successfully for Patient ID " << id << "." << endl;

}
void view_doctor_orders() {
    int id;
    cout << "\nEnter Patient ID: ";

    if (!(cin >> id)) {
        cout << "Invalid ID, try again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    ifstream docOrderFile("doctor_orders.txt");
    if (!docOrderFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string line;
    bool patientFound = false;
    while (getline(docOrderFile, line)) {
        stringstream ss(line);
        int storedPatientID;
        ss >> storedPatientID;

        if (storedPatientID == id) {
            patientFound = true;
            cout << "Doctor's Orders for Patient ID " << id << ":" << endl;
            while (getline(docOrderFile, line) && !line.empty()) {
                cout << line << endl;
            }
            break;
        }
    }
    docOrderFile.close();
    if (!patientFound) {
        cout << "Doctor's orders not found for Patient ID " << id << "!" << endl;
    }
}
bool containsNumeric(const string& str) {
    for (char c : str) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}
void readMedicalRecord() {
    ifstream file("medical_record.txt");

    if (!file.is_open()) {
        cout << "Error opening medical record file!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        cout << "Error: Medical record file is empty!" << endl;
        file.close();
        return;
    }
    file.seekg(0, ios::beg);

    Patient p;
    while (file >> p.idp >> p.vitals) {
        file.ignore();
        getline(file, p.pres);
        getline(file, p.com);
        cout << "Patient ID: " << p.idp << endl;
        cout << "Patient Vitals: " << p.vitals << endl;
        cout << "Patient Prescription: " << p.pres << endl;
        cout << "Patient Comments: " << p.com << endl;
        cout << "----------------" << endl;
    }
    file.close();
}
void searchMedicalRecord() {
    int patientId;
    cout << "Enter the Patient ID to search: ";
    while (!(cin >> patientId)) {
        cout << "Invalid input. Please enter a valid patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifstream file("medical_record.txt");

    if (!file.is_open()) {
        cout << "Error opening medical record file!" << endl;
        return;
    }

    Patient p;
    bool patientFound = false;

    while (file >> p.idp >> p.vitals) {
        file.ignore();
        getline(file, p.pres);
        getline(file, p.com);
        if (p.idp == patientId) {
            cout << "Patient ID: " << p.idp << endl;
            cout << "Patient Vitals: " << p.vitals << endl;
            cout << "Patient Prescription: " << p.pres << endl;
            cout << "Patient Comments: " << p.com << endl;
            patientFound = true;
        }
    }

    file.close();

    if (!patientFound) {
        cout << "Patient not found in the medical records." << endl;
    }
}



