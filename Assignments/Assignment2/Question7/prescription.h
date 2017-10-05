//header file prescription.h: This is the interface for the class Prescription
#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#include <iostream>
#include <string>
using namespace std;

class Prescription
{
public:
    Prescription();
    //Initializes the Precsciption to empty values;

    Prescription(string Pprescription, string Pname, string PmedicalAid, int PmedicalAidNo, double Pcost);
    //Initializes the Prescription to the arguments passed.

    ~Prescription();
    //Destructor for Prescription.

    string getPrescription();
    //Returns the prescription.

    string getName();
    //Returns the name of the patient.

    string getMedicalAid();
    //Returns the name of the medicalAid.

    int getMedicalAidNo();
    //Returns the medical aid number.

    double getCost();
    //Returns the cost of the prescription.

    void Discount(double discount);
    //Calculates a discount for prescriptions for members of THEAID medical aid,
    //based on a discount percentage provided by the shop owner.

    void DisplayInfo();
    //Displays the prescription itself, the patient’s name, the medical aid fund, the medical aid number and cost.

private:
    string prescription, name, medicalAid;
    int medicalAidNo;
    double cost;

};

#endif // PRESCRIPTION_H
