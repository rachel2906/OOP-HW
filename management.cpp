#include <iostream>
#include <vector>
#include <string> 
#include <cctype>  
using namespace std;

// HUMAN 
class Human {
public:
    Human() {
        cout << "Human created\n";
    }
    void displayInfo() {
        cout << "Human Info\n";
    }
};

// PATIENT
class Patient : public Human {
private:
    bool active;
    string registrationDate;
    int visitCount;

protected:
    string name;
    string id;
    int age;
    vector<string> medicalHistory;

public:
    Patient() {
        name = "Unknown";
        id = "Unknown";
        age = 0;
        active = true;
        registrationDate = "10-09-2025";
        visitCount = 0;
    }

    Patient(string name, string id, int age) {
        this->name = name;
        this->id = id;
        this->age = age;
        active = true;
        registrationDate = "10-09-2025";
        visitCount = 0;
    }

    // Getter & Setter 
    string getName() {
        return name;
    }
    string getId() {
        return id;
    }
    int getAge() {
        return age;
    }
    void setName(string n) {
        name = n;
    }
    void setId(string i) {
        id = i;
    }
    void setAge(int a) {
        age = a;
    }

    void addMedicalHistory(string record) {
        medicalHistory.push_back(record);
        visitCount++;
    }

    void showMedicalHistory() {
        cout << "Medical History of " << name << ":\n";
        for (string h : medicalHistory ) {
            cout << "- " << h << endl;
        }
    }

    void deactivate() {
        active = false;
    }

    bool isActive() {
        return active;
    }

    void setRegistrationDate(string date) {
        registrationDate = date;
    }

    string getRegistrationDate() {
        return registrationDate;
    }

    int getVisitCount() {
        return visitCount;
    }

    void scheduleAppointment() {
        cout << "Appointment for regular patient\n";
    }

    void displayInfo() {
        cout << "Patient Info:\n";
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
        cout << "Registration Date: " << registrationDate 
             << ", Visits: " << visitCount << endl;
    }
};

// CHRONIC PATIENT 
class ChronicPatient : public Patient {
private:
    string conditionType;
    string lastCheckupDate;
    string riskLevel;
    vector<string> medications;
    string doctorNotes;

protected:
    string treatmentPlan;
    string nextAppointmentDate;

public:
    ChronicPatient(string name, string id, int age, string conditionType, string lastCheckupDate)
        : Patient(name, id, age) 
    {
        this->conditionType = conditionType;
        this->lastCheckupDate = lastCheckupDate;
        riskLevel = "Medium";
        doctorNotes = "Nope";
        treatmentPlan = "General monitoring";
        nextAppointmentDate = "Not scheduled";
    }

    string getConditionType() {
        return conditionType;
    }
    void setConditionType(string c) {
        conditionType = c;
    }
    string getLastCheckupDate() {
        return lastCheckupDate;
    }
    void setLastCheckupDate(string d) {
        lastCheckupDate = d;
    }
    void setRiskLevel(string r) {
        riskLevel = r;
    }
    void addMedication(string med) {
        medications.push_back(med);}
    void showMedications() {
        cout << "Medications: " << getName();
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
    void setDoctorNotes(string notes) {
        doctorNotes = notes;
    }
    string getDoctorNotes() {
        return doctorNotes;
    }
    void setNextAppointmentDate(string d) {
        nextAppointmentDate = d;
    }
    void setTreatmentPlan(string plan) {
        treatmentPlan = plan;
    }

    void scheduleAppointment() {
        cout << "Scheduling mandatory check-up every 3 months\n";
    }

    void displayInfo() {
        Patient::displayInfo();
        cout << "Condition: " << conditionType << ", Last Check-up: " << lastCheckupDate << endl;
        cout << "Risk Level: " << riskLevel << ", Treatment Plan: " << treatmentPlan << endl;
        cout << "Next Appointment: " << nextAppointmentDate << endl;
    }
};

// APPOINTMENT
class Appointment {
private:
    string date;
    string time;
    string reason;
    string status;
    Patient patient;    
    string doctorId;
    string location;
    string notes;

    bool isValidStatus(string s) {
        return (s == "SCHEDULED" || s == "COMPLETED" || s == "CANCELED");
    }

    string toUpperCase(string s) {
        for (auto& c : s) {
            c = (char) toupper((unsigned char)c);
        }
        return s;
    }

protected:
    string appointmentType;

public:
    Appointment(string date, string time, string reason, Patient p, string doctorId)
        : patient(p) 
    {   
        this->date = date;
        this->time = time;
        this->reason = reason;
        this->status = "SCHEDULED";
        this->doctorId = doctorId;
        this->location = "Room 101";
        this->notes = "Nope";
        this->appointmentType = "Offline";
    }

    void updateStatus(string s) {
        s = toUpperCase(s);
        if (isValidStatus(s)) {
            status = s;
        } else {
            cout << "Invalid status\n";
        }
    }
    void setLocation(string loc) {
        location = loc;
    }
    string getLocation() {
        return location;
    }
    void setNotes(string n) {
        notes = n;
    }
    string getNotes() {
        return notes;
    }
    string getStatus() {
        return status;
    }
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
    string name;
    string id;
    string specialty;
    vector<Appointment> appointments;
    string phoneNumber;
    string email;

protected:
    int experienceYears;
    vector<string> certifications;

public:
    Doctor(string name, string id, string specialty) {
        this->name = name;
        this->id = id;
        this->specialty = specialty;
        phoneNumber = "Unknown";
        email = "Unknown";
        experienceYears = 0;
    }

    string getName() {
        return name;
    }
    string getId() {
        return id;
    }
    string getSpecialty() {
        return specialty;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }    
    string getEmail() {
        return email;
    }                
    int getExperienceYears() {
        return experienceYears;
    } 
    void setPhoneNumber(string p) {
        phoneNumber = p;
    }
    void setEmail(string e) {
        email = e;
    }
    void addCertification(string cert) {
        certifications.push_back(cert);
    }
    void setExperienceYears(int y) {
        experienceYears = y;
    }
    void addAppointment(Appointment a) {
        appointments.push_back(a);
    }
    void viewAppointments() {
        cout << "Appointments of: " << name << endl;
        for (auto& a : appointments) {
            a.displayInfo();
        }
    }

    void showCertifications() {
        cout << "Certifications: ";
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
        cout << endl;
    }
};

// MAIN
int main() {
    // Tạo bệnh nhân thường
    Patient p1("Alice", "P001", 25);
    p1.addMedicalHistory("Flu - 2023");
    p1.addMedicalHistory("Check-up - 2024");

    // Tạo bệnh nhân mãn tính
    ChronicPatient cp1("Bob", "P002", 50, "Diabetes", "2025-01-10");
    cp1.addMedicalHistory("Diabetes diagnosis - 2020");
    cp1.addMedicalHistory("Blood sugar check - 2024");
    cp1.setTreatmentPlan("Daily insulin, diet monitoring");
    cp1.setNextAppointmentDate("2025-12-01");
    cp1.addMedication("Insulin");
    cp1.addMedication("Metformin");

    // Tạo bác sĩ
    Doctor d1("Dr. Smith", "D001", "Cardiology");
    d1.setPhoneNumber("0123456789");
    d1.setEmail("dr.smith@hospital.com");
    d1.setExperienceYears(15);
    d1.addCertification("Cardiology Specialist");
    d1.addCertification("Endocrinology Training");

    // Tạo các cuộc hẹn
    Appointment a1("2025-09-12", "10:00", "Routine check-up", p1, d1.getId());
    Appointment a2("2025-09-15", "14:00", "Diabetes follow-up", cp1, d1.getId());

    // Thêm cuộc hẹn cho bác sĩ
    d1.addAppointment(a1);
    d1.addAppointment(a2);

    // Hiển thị thông tin bệnh nhân
    cout << "PATIENTS\n";
    p1.displayInfo();
    p1.showMedicalHistory();
    cout << endl;

    cp1.displayInfo();
    cp1.showMedicalHistory();
    cp1.showMedications();         
    cout << "Doctor Notes: " << cp1.getDoctorNotes() << endl;

    // Hiển thị thông tin bác sĩ và các cuộc hẹn
    cout << "\nDOCTOR INFO & APPOINTMENTS\n";
    cout << "Doctor: " << d1.getName() << " (" << d1.getSpecialty() << ")\n";
    cout << "Phone: " << d1.getPhoneNumber() << ", Email: " << d1.getEmail() << endl;
    cout << "Experience: " << d1.getExperienceYears() << " years\n";
    d1.showCertifications();       
    cout << "\n";
    d1.viewAppointments();

    // Cập nhật trạng thái cuộc hẹn
    cout << "\nUPDATING STATUS\n";
    cout << "Updating appointment 1\n";
    a1.updateStatus("completed");
    a1.displayInfo();

    cout << "\nUpdating appointment 2 with invalid status\n";
    a2.updateStatus("waiting"); 

    return 0;
}

