//Implementation file prescription.cpp:
//This is the IMPLEMENTATION of the ADT Prescription.
//The interface for the class Team is in the header file prescription.h.
#include <iostream>
#include <string>
#include "prescription.h"

Prescription::Prescription() : prescription(""), name(""), medicalAid(""), medicalAidNo(0), cost(0)
{
    //Intentionally left blank
}

Prescription::Prescription(string Pprescription, string Pname, string PmedicalAid, int PmedicalAidNo, double Pcost)
    : prescription(Pprescription), name(Pname), medicalAid(PmedicalAid), medicalAidNo(PmedicalAidNo), cost(Pcost)
{
    //Intentionally left blank
}

Prescription::~Prescription()
{
    //Destructor for Prescription.
}

string Prescription::getPrescription()
{
    return prescription;
}

string Prescription::getName()
{
    return name;
}

string Prescription::getMedicalAid()
{
    return medicalAid;
}

int Prescription::getMedicalAidNo()
{
    return medicalAidNo;
}

double Prescription::getCost()
{
    return cost;
}

void Prescription::Discount(double discount)
{
    if (medicalAid == "THEAID")
        cost = cost - cost * discount / 100;
}

void Prescription::DisplayInfo()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Prescription:       " << prescription << endl
         << "Patient:            " << name << endl
         << "Medical Aid Fund:   " << medicalAid << endl
         << "Medical Aid Number: " << medicalAidNo << endl
         << "Cost:               R" << cost << endl << endl;

}
