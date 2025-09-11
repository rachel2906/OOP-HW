#include <iostream>
#include <vector>
#include <string> 
#include <cctype>  
using namespace std;

// HUMAN 
class Human {
public:
    Human() {
        cout << "Human created"<<endl;
    }

    // Display general information of a human
    void displayInfo() {
        cout << "Human Info"<<endl;
    }
};

// PATIENT
class Patient : public Human {
private:
    bool active;                 // The patient is active
    string regisDate;            // Registration date of the patient
    int visit;                   // Number of visits

protected:
    string name;                 // Patient name
    string id;                   // Patient ID
    int age;                     // Patient age
    vector<string> medicalHistory; // List of medical history

public:
    Patient() {
        name = "Unknown";
        id = "Unknown";
        age = 0;
        active = true;
        regisDate = "2025-01-01";
        visit = 0;
    }

    Patient(string name, string id, int age) {
        this->name = name;
        this->id = id;
        this->age = age;
        active = true;
        regisDate = "2025-01-01";
        visit = 0;
    }

    // Getter and Setter
    string getName() { return name; }
    string getId() { return id; }
    int getAge() { return age; }
    void setName(string n) { name = n; }
    void setId(string i) { id = i; }
    void setAge(int a) { age = a; }

    // Add a record to patient medical history
    void addMedicalHistory(string record) {
        medicalHistory.push_back(record);
        visit++;
    }

    // Display  medical history of the patient
    void showMedicalHistory() {
        cout << "Medical History of " << name << ":"<<endl;
        for (string h : medicalHistory) {
            cout << "- " << h << endl;
        }
    }

    // The patient is not active 
    void deactivate() { active = false; }

    // Check if patient is active
    bool isActive() { return active; }

    void setRegisDate(string date) { regisDate = date; }
    string getRegisDate() { return regisDate; }
    int getVisit() { return visit; }

    // Virtual method to schedule appointment
    virtual void scheduleAppointment() {
        cout << "Scheduling appointment for regular patient.\n";
    }

    // Show patient information
    void displayInfo() {
        cout << "Patient Info:\n";
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
        cout << "Registration date: " << regisDate;
        cout << ", Visit: " << visit << endl;
    }
};
// CHRONIC PATIENT
class ChronicPatient : public Patient {
private:
    string conditionType;       // Type of chronic condition 
    string last;                // Last check up date
    string risk;                // Risk level 
    vector<string> medications; // List of medications
    string doctorNotes;         // Doctor notes about the patient

protected:
    string treatmentPlan;       // Treatment plan for patient
    string nextAppointmentDate; // Next scheduled appointment

public:
    ChronicPatient(string name, string id, int age, string conditionType, string lastCheckupDate)
        : Patient(name, id, age) 
    {
        this->conditionType = conditionType;
        this->last= lastCheckupDate;
        risk = "Medium";
        doctorNotes = "Nope";
        treatmentPlan = "General monitoring";
        nextAppointmentDate = "Not scheduled";
    }

    // Getter and Setter
    string getConditionType() { return conditionType; }
    void setConditionType(string c) { conditionType = c; }
    string getLast() { return last; }
    void setLast(string d) { last = d; }
    void setRisk(string r) { risk = r; }

    // Add a medication to list
    void addMedication(string med) { medications.push_back(med); }

    // Show list of medication
    void showMedications() {
        cout << "Medications of " << getName() << ": ";
        if (medications.empty()) {
            cout << "NONE";
        } else {
            for (size_t i = 0; i < medications.size(); i++) {
                cout << medications[i];
                if (i + 1 < medications.size()) {
                    cout << ", ";
                }
            }
        }
        cout << endl;
    }

    void setDoctorNotes(string n) { doctorNotes = n; }
    string getDoctorNotes() { return doctorNotes; }
    void setNextAppointmentDate(string d) { nextAppointmentDate = d; }
    void setTreatmentPlan(string plan) { treatmentPlan = plan; }

    // Override scheduleAppointment for chronic patients
    void scheduleAppointment() override {
        cout << "Scheduling mandatory check-up every 3 months\n";
    }

    // Show chronic patient details
    void displayInfo() {
        Patient::displayInfo();
        cout << "Condition: " << conditionType << ", Last Check-up: " << last << endl;
        cout << "Risk level: " << risk << ", Treatment Plan: " << treatmentPlan << endl;
        cout << "Next Appointment: " << nextAppointmentDate << endl;
    }
};
// APPOINTMENT
class Appointment {
private:
    string date;        // Appointment date
    string time;        // Appointment time
    string reason;      // Reason for appointment
    string status;      // Status 
    Patient patient;    // Patient linked to appointment
    string doctorId;    // Doctor ID handling the appointment
    string location;    // Location of appointment
    string notes;       // Notes

    // Validate appointment status
    bool isValidStatus(string s) {
        return (s == "SCHEDULED" || s == "COMPLETED" || s == "CANCELED");
    }

    // Convert string to uppercase
    string toUpperCase(string s) {
        for (auto& c : s) {
            c = (char) toupper((unsigned char)c);
        }
        return s;
    }

protected:
    string appointmentType; // Appointment type

public:
    Appointment(string date, string time, string reason, Patient p, string doctorId)
        : patient(p) 
    {   
        this->date = date;
        this->time = time;
        this->reason = reason;
        this->status = "SCHEDULED";
        this->doctorId = doctorId;
        this->location = "Room 403";
        this->notes = "Nope";
        this->appointmentType = "Offline";
    }

    // Change status of appointment
    void changeStatus(string s) {
        s = toUpperCase(s);
        if (isValidStatus(s)) {
            status = s;
        } else {
            cout << "Invalid status\n";
        }
    }

    void setLocation(string loc) { location = loc; }
    string getLocation() { return location; }
    void setNotes(string n) { notes = n; }
    string getNotes() { return notes; }
    string getStatus() { return status; }

    // Display appointment details
    void displayInfo() {
        cout << "Appointment: " << date << " " << time << " | Reason: " << reason << endl;
        cout << "Doctor ID: " << doctorId << " | Status: " << status << endl;
        cout << "Location: " << location << " | Type: " << appointmentType << endl;
        cout << "Patient: " << patient.getName() << " (ID: " << patient.getId() << ")" << endl;
    }
};

// DOCTOR
class Doctor {
private:
    string name;                    // Doctor name
    string id;                      // Doctor ID
    string specialty;               // Doctor specialty field
    vector<Appointment> appointments; // List of appointments handled by doctor
    string phoneNumber;             // Contact phone number
    string email;                   // Contact email

protected:
    int experienceYears;            // Years of experience
    vector<string> certifications;  // List of certifications

public:
    Doctor(string name, string id, string specialty) {
        this->name = name;
        this->id = id;
        this->specialty = specialty;
        phoneNumber = "Unknown";
        email = "Unknown";
        experienceYears = 0;
    }

    // Getter and Setter
    string getName() { return name; }
    string getId() { return id; }
    string getSpecialty() { return specialty; }
    string getPhoneNumber() { return phoneNumber; }    
    string getEmail() { return email; }                
    int getExperienceYears() { return experienceYears; }
    void setPhoneNumber(string p) { phoneNumber = p; }
    void setEmail(string e) { email = e; }
    void setExperienceYears(int y) { experienceYears = y; }

    // Add certification
    void addCertification(string cert) { certifications.push_back(cert); }

    // Add appointment
    void addAppointment(Appointment a) { appointments.push_back(a); }

    // View doctor appointments
    void viewAppointments() {
        cout << "Appointments of: " << name << endl;
        for (auto& a : appointments) {
            a.displayInfo();
        }
    }

    // Display doctor certifications
    void displayCertifications() {
        cout << "Doctor Certifications: ";
        if (certifications.empty()) {
            cout << "None";
        } else {
            for (size_t i = 0; i < certifications.size(); ++i) {
                cout << certifications[i];
                if (i + 1 < certifications.size()) {
                    cout << ", ";
                }
            }
        }
    }
};
