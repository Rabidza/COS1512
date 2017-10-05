//This is the header file repeatPrescription.h
//This is the interface for the class RepeatPrescription.
#ifndef REPEATPRESCRIPTION_H
#define REPEATPRESCRIPTION_H

#include "prescription.h"

using namespace std;

class RepeatPrescription : public Prescription
{
public:
    RepeatPrescription();
    //Initializes Repeatprescription to default values.

    RepeatPrescription(string Pprescription, string Pname, string PmedicalAid, int PmedicalAidNo, double Pcost, int PnumberOfRepeats, string PlastDateIssued);
    //Initializes the Prescription to the arguments passed.

    void issuePrescription(string date);
    //Updates the date the prescription is issued and
    //decreases the member variable numberOfRepeats by one.
    //When member variablenumberOfRepeats becomes 0, a message
    //is displayed indicate that this is the last issue of the current prescription.

    void DisplayInfo();
    //Displays the prescription itself, the patient’s name, the medical aid fund,
    //the medical aid number, cost and numberOfRepeats.

    int getNumberRepeats();
    //Returns the number of repeate prescriptions

    string getLastDateIssued();
    //Returns lastDateIssued

private:
    int numberOfRepeats;
    string lastDateIssued;
};
#endif // REPEATPRESCRIPTION_H
