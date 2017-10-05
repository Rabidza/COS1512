//Implementation file team.cpp:
//This is the IMPLEMENTATION of the ADT Team.
//The interface for the class Team is in the header file team.h.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include "team.h"

using namespace std;

Team::Team()
{
    //Initializes country to "Country 0"; and round, points, goalsFor and goalsAgainst to 0.
    country = "Country 0";
    round = 0;
    points = 0;
    goalsFor = 0;
    goalsAgainst = 0;
}


Team::Team(string TeamCountry, int TeamRound, int TeamPoints, int TeamGoalsFor, int TeamGoalsAgainst)
{
    country = TeamCountry;
    round = TeamRound;
    points = TeamPoints;
    goalsFor = TeamGoalsFor;
    goalsAgainst = TeamGoalsAgainst;
}


Team::~Team()
{
    cout << "Game Over\n";
}


void Team::setCountry(string TeamCountry)
{
    country = TeamCountry;
}


void Team::setRound(int TeamRound)
{
    round = TeamRound;
}

void Team::setPoints(int TeamPoints)
{
    points = TeamPoints;
}

void Team::setGoalsFor(int TeamGoalsFor)
{
    goalsFor = TeamGoalsFor;
}

void Team::setGoalsAgainst(int TeamGoalsAgainst)
{
    goalsAgainst = TeamGoalsAgainst;
}

string Team::getCountry()
{
    return country;
}

int Team::getRound()
{
    return round;
}

int Team::getPoints()
{
    return points;
}

int Team::getGoalsFor()
{
    return goalsFor;
}

int Team::getGoalsAgainst()
{
    return goalsAgainst;
}

void Team::reset(string TeamCountry, int TeamRound, int TeamPoints, int TeamGoalsFor, int TeamGoalsAgainst)
{
    country = TeamCountry;
    round = TeamRound;
    points = TeamPoints;
    goalsFor = TeamGoalsFor;
    goalsAgainst = TeamGoalsAgainst;
}

int Team::calcGoalDifference() const
{
    return goalsAgainst - goalsFor;
}

void Team::update()
{
    int addPoints, addGoalsFor, addGoalsAgainst;
    cout << "Update stats for: " << country << endl;
    cout << "Enter points: ";
    cin >> addPoints;
    points+= addPoints;
    cout << "Enter Goals For: ";
    cin >> addGoalsFor;
    goalsFor+= addGoalsFor;
    cout << "Enter Goals Against: ";
    cin >> addGoalsAgainst;
    goalsAgainst+= addGoalsAgainst;
}

bool operator ==(const Team& Team1, const Team& Team2)
{
    return (Team1.points == Team2.points && Team1.calcGoalDifference() == Team2.calcGoalDifference());
}

bool operator >(const Team& Team1, const Team& Team2)
{
    if (Team1.points > Team2.points)
        return true;
    else if (Team1 == Team2)
        return true;
    else
        return false;
}

Team operator ++(Team& Team)
{
    Team.setRound(++Team.round);
    return Team;
}

ostream& operator <<(ostream& outs, const Team& theObject)
{
    outs << "Country:       " << theObject.country << endl;
    outs << "Round:         " << theObject.round << endl;
    outs << "Points:        " << theObject.points << endl;
    outs << "Goals For:     " << theObject.goalsFor << endl;
    outs << "Goals Against: " << theObject.goalsAgainst << endl << endl;
}

istream& operator >>(istream& ins, Team& theObject)
{
    cout << "Enter the country: ";
    getline(ins, theObject.country, '\n');
    cout << "Enter the round: ";
    cin >> theObject.round;
    cout << "Enter the points: ";
    cin >> theObject.points;
    cout << "Enter the goals for: ";
    cin >> theObject.goalsFor;
    cout << "Enter the goals against: ";
    cin >> theObject.goalsAgainst;
}
