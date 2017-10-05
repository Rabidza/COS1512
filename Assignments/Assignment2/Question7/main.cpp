////Driver Program for Question 7b
//#include <iostream>
//#include "prescription.h"
//using namespace std;
//
//int main()
//{
//    Prescription meds("Panado", "John Apfelbaum", "THEAID", 12345, 39.59);
//    cout << "Prescription:       " << meds.getPrescription() << endl
//         << "Patient:            " << meds.getName() << endl
//         << "Medical Aid Fund:   " << meds.getMedicalAid() << endl
//         << "Medical Aid Number: " << meds.getMedicalAidNo() << endl
//         << "Cost:               R" << meds.getCost() << endl << endl;
//
//    meds.Discount(20);
//    meds.DisplayInfo();
//
//    return 0;
//}


//Driver Program for Question 7d
#include <iostream>
#include "repeatPrescription.h"
using namespace std;

int main()
{
    RepeatPrescription meds("Myprodol", "Annie Apfelbaum", "MYAID", 43215, 89.59, 1, "20170620");
    cout << "Prescription:       " << meds.getPrescription() << endl
         << "Patient:            " << meds.getName() << endl
         << "Medical Aid Fund:   " << meds.getMedicalAid() << endl
         << "Medical Aid Number: " << meds.getMedicalAidNo() << endl
         << "Cost:               R" << meds.getCost() << endl
         << "Number of Repeats:  " << meds.getNumberRepeats() << endl
         << "Date Last Issued:   " << meds.getLastDateIssued() << endl << endl;

    meds.issuePrescription("20170920");
    meds.DisplayInfo();

    return 0;
}
