
#include "team.h"
using namespace std;

int main()
{
    int addPoints1, addGoalsFor1, addGoalsAgainst1;
    int addPoints2, addGoalsFor2, addGoalsAgainst2;

    Team opponent, newOpponent;
    Team home("South-Africa", 1, 4, 6, 4);
    opponent.reset("Germany", 1, 4, 6, 4);

    cout << home;
    cout << opponent;

    if (home == opponent)
        cout << "This is a tie!\n";
    else if (home > opponent)
        ++home;
    else
        ++opponent;

    cout << home.getCountry() << endl;
    cout << home.getPoints() << endl;
    cout << home.getRound() << endl << endl;

    cout << opponent.getCountry() << endl;
    cout << opponent.getPoints() << endl;
    cout << opponent.getRound() << endl << endl;

    cin >> newOpponent;

    cout << "\nSouth-Africa has won the match!";
    cout << "Please capture the results:" << endl;
    home.update();
    newOpponent.update();

    if (home == newOpponent)
        cout << "This is a tie!\n";
    else if (home > newOpponent)
        ++home;
    else
        ++newOpponent;

    cout << home.getCountry() << endl;
    cout << home.getPoints() << endl;
    cout << home.getRound() << endl << endl;

    cout << newOpponent.getCountry() << endl;
    cout << newOpponent.getPoints() << endl;
    cout << newOpponent.getRound() << endl << endl;

    return 0;
}
