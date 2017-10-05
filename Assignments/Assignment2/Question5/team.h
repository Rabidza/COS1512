//header file team.h: This is the interface for the class Team
#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Team
{
public:
    Team();
    //Initializes country to "Country 0"; and round, points, goalsFor and goalsAgainst to 0.

    Team(string TeamCountry, int TeamRound, int TeamPoints, int TeamGoalsFor, int TeamGoalsAgainst);
    //set the country, round, points, goalsFor and goalsAgainst member variables to
    //TeamCountry, TeamRound, TeamPoints, TeamGoalsFor and TeamGoalsAgainst

    ~Team();
    //Destructor which also outputs "Game Over" when called

    void setCountry(string TeamCountry);
    //Postcondition: The team country has been set to "Country TeamCountry".

    void setRound(int TeamRound);
    //Postcondition: The team round has been set to TeamRound.

    void setPoints(int TeamPoints);
    //Postcondition: The team points has been set to TeamPoints.

    void setGoalsFor(int TeamGoalsFor);
    //Postcondition: The team goalsFor has been set to TeamGoalsFor.

    void setGoalsAgainst(int TeamGoalsAgainst);
    //Postcondition: The team goalsAgainst has been set to TeamGoalsAgainst.

    string getCountry();
    //Returns the team country as a string.

    int getRound();
    //Returns the round in which the team currently plays as an int.

    int getPoints();
    //Returns the points of the team as in int.

    int getGoalsFor();
    //Returns the number of goals the team has scored as an int.

    int getGoalsAgainst();
    //Returns the number of goals scored against the team as an int.

    void reset(string TeamCountry, int TeamRound, int TeamPoints, int TeamGoalsFor, int TeamGoalsAgainst);
    //Postcondition: Resets the member variables of a Team to values specified by parameters.

    int calcGoalDifference() const;
    //Precondition: The teams goalsFor and goalsAgainst has been set.
    //Returns the difference between the goalsFor and goalsAgainst of the team as an int

    void update();
    //Postcondition: the points, goalsFor and goalsAgainst has
    //been set to teamPoints, teamGoalsFor, and teamGoalsAgainst.

    friend bool operator ==(const Team& Team1, const Team& Team2);
    //Precondition: Team1 and Team2 has been given values to points.
    //Returns true if both the points member variable and the goal
    //difference of Team1 is identical to that of Team2 and false otherwise.

    friend bool operator >(const Team& Team1, const Team& Team2);
    //Precondition: Team1 and Team2 has been given values to points
    //returns true if the points member variable of Team1 is bigger than that of Team2;
    //or if the points member variable of Team1 is equal to that of Team2 and the goal
    //difference of Team1 is bigger than that of Team2. Otherwise the function returns false.

    friend Team operator ++(Team& Team);
    //Returns the current instance of the class Team after incrementing the round member variable by 1

    friend ostream& operator <<(ostream& outs, const Team& theObject);
    //Precondition: If outs is a file output stream, then outs
    //has already been connected to a file.
    //Overloads the << operator so it can be used to dispaly
    //the country, round, points, goals for and goals against the team, for a team.

    friend istream& operator >>(istream& ins, Team& theObject);
    //Precondition: If outs is a file output stream, then outs
    //has already been connected to a file.
    //Overloads the >> operator so that it can be used to input values of type Team.

private:
    string country; // the name of the country for which this team plays
    int round; // the round in which the team currently plays
    int points; // the points the team has accumulated
    int goalsFor; // the goals the team has scored
    int goalsAgainst; // the goals scored against the team
};

#endif // TEAM_H
