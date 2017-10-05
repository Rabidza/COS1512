//This is the file repeatPrescription.cpp
//This is the implementation for the class RepeatPrescription.
//The interace for the class RepeatPrescription is in
//the header file repeatPrescription.cpp

#include <iostream>
#include <string>
#include "repeatPrescription.h"

using namespace std;

RepeatPrescription::RepeatPrescription() : Prescription(), numberOfRepeats(0), lastDateIssued("")
{
    //deliberately empty.
}

RepeatPrescription::RepeatPrescription(string Pprescription, string Pname, string PmedicalAid, int PmedicalAidNo, double Pcost, int PnumberOfRepeats, string PlastDateIssued)
    : Prescription(Pprescription, Pname, PmedicalAid,  PmedicalAidNo,Pcost), numberOfRepeats(PnumberOfRepeats), lastDateIssued(PlastDateIssued)
{
    //Intentionally left blank
}


void RepeatPrescription::issuePrescription(string date)
{
    lastDateIssued = date;
    numberOfRepeats--;
    if (numberOfRepeats == 0)
        cout << "This is the last issue of the current prescription" << endl << endl;
}


void RepeatPrescription::DisplayInfo()
{
    cout << "Prescription:       " << getPrescription() << endl
         << "Patient:            " << getName() << endl
         << "Medical Aid Fund:   " << getMedicalAid() << endl
         << "Medical Aid Number: " << getMedicalAidNo() << endl
         << "Cost:               R" << getCost() << endl
         << "Number of Repeats:  " << getNumberRepeats() << endl
         << "Date Last Issued:   " << getLastDateIssued() << endl << endl;
}


int RepeatPrescription::getNumberRepeats()
{
    return numberOfRepeats;
}

string RepeatPrescription::getLastDateIssued()
{
    return lastDateIssued;
}
