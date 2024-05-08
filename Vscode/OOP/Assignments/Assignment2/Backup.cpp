/* 
This program is made by(...)
The main purpose of the program is to (...) */

#include <iostream>
#include <fstream>
using namespace std;

class Player {
private:
    string name;
    int yearOfBirth;
    int height;
    int internationalGoals;
    string nationality;

public:
    Player() : name("\0"), yearOfBirth(0),
        height(0), internationalGoals(0),
        nationality("\0") {}  /* Implementaion of the default constructor, 
                                in order to set a default value for each member variable */


    Player(string name, int yearOfBirth, int height, int internationalGoals, string nationality) {
        this->name = name;
        this->yearOfBirth = yearOfBirth;
        this->height = height;
        this->internationalGoals = internationalGoals;
        this->nationality = nationality; /* Parameterized constructor  */
    }

    //Setters:

    void setName(string givenName) {
        name = givenName;
    }

    void setyearOfBirth(int givenYear) {
        yearOfBirth = givenYear;
    }

    void setHeight(int givenHeight) {
        height = givenHeight;
    }

    void setInternationalGoals(int givenGoals) {
        internationalGoals = givenGoals;
    }

    void setNationality(string givenNationality) {
        nationality = givenNationality;
    }


    //Getters:

    string getName() {
        return name;
    }

    int getYearOfBirth() {
        return yearOfBirth;
    }

    int getHeight() {
        return height;
    }

    int getInternationalGoals() {
        return internationalGoals;
    }

    string getNationality() {
        return nationality;
    }

    friend ostream& operator<<(ostream& output, const Player& player) {
        cout << endl;
        cout << "Player: " << player.name << endl << endl;

        cout << "Year Of Birth: " << player.yearOfBirth << endl;
        cout << "Height: " << player.height << endl;
        cout << "International Goals: " << player.internationalGoals << endl;
        cout << "Nationality: " << player.nationality << endl;
        return output;
    }


    void setAll(string givenName, int givenYear, int givenHeight, int givenGoals, string givenNationality) {
        setName(givenName);
        setyearOfBirth(givenYear);
        setHeight(givenHeight);
        setInternationalGoals(givenGoals);
        setNationality(givenNationality);
    }
};


class NationalTeam {
private:
    Player players[18];
    bool active[18];
    string country = "USA";
    int currentPlayersNumber = 0;
public:
    NationalTeam() { // Default constructor
        for (int i = 0; i < 18; i++) {
            active[i] = false;  // Initially setting all the active array elements to false
        }
    }

    bool addPlayer(const Player& player) {
        if (currentPlayersNumber <= 17)
        {
            players[currentPlayersNumber] = player;
            active[currentPlayersNumber++] = true; // switching the state of that player in the active array to array 
            // and incrementing the player index in case of a new player addition
            return true;
        }
        else {
            cout << "Max players number has been reached. No more players can be added." << endl;
            return false;
        }
    }

    bool removePlayer(string playerName) {
        for (int i = 0; i < currentPlayersNumber; i++) {
            if (playerName == players[i].getName()) {    // iterating through the entire players array to find the targeted player
                active[i] = false;   // setting his state as false
                cout << players[i].getName() << " Has been Removed." << endl;
                return true;
            }
        }

        // in case of not finding that player:
        cout << "Didn't find the player named: '" << playerName << "'." << endl;
        return false;
    }

    int getNumOfPlayers() {
        return currentPlayersNumber;
    }

    int AvgHeight() {
        int totalHeight = 0;

        for (int i = 0; i < currentPlayersNumber; i++) {
            totalHeight += players[i].getHeight();
        }
        int avgHeight = totalHeight / currentPlayersNumber;

        return avgHeight;
    }

    Player OldestPlayer() { // returning by reference
        int oldestYear = players[0].getYearOfBirth();
        Player oldestPlayer = players[0];

        for (int i = 0; i < currentPlayersNumber; i++) {
            if (players[i].getYearOfBirth() < oldestYear) {
                oldestYear = players[i].getYearOfBirth();
                oldestPlayer = players[i];
            }
        }
        return oldestPlayer;
    }

    Player YoungestPlayer() {
        int youngestYear = players[0].getYearOfBirth();
        Player youngestPlayer = players[0];

        for (int i = 0; i < currentPlayersNumber; i++) {
            if (players[i].getYearOfBirth() > youngestYear) {
                youngestYear = players[i].getYearOfBirth();
                youngestPlayer = players[i];
            }
        }
        return youngestPlayer;
    }

    int AvgIntGoals() {
        int totalIntGoals = 0;

        for (int i = 0; i < currentPlayersNumber; i++) {
            totalIntGoals += players[i].getInternationalGoals();
        }
        int avgIntGoals = totalIntGoals / currentPlayersNumber;

        return avgIntGoals;
    }

    Player highestIntGoals() {
        int highestIntGoals = players[0].getInternationalGoals();
        Player highestIntGoalsPlayer;

        for (int i = 0; i < currentPlayersNumber; i++) {
            if (players[i].getInternationalGoals() > highestIntGoals) {
                highestIntGoals = players[i].getInternationalGoals();
                highestIntGoalsPlayer = players[i];
            }
        }
        return highestIntGoalsPlayer;
    }

    friend ostream& operator<<(ostream& output, const NationalTeam& team) {
        output << team.country;
        for (int i = 0; i < team.currentPlayersNumber; i++) {
            cout << team.players[i];
        }
        return output;
    }

    void writeStatistics(ofstream& Outfile) {

        Outfile << "Country: " << country << endl;
        Outfile << "Number of players: " << currentPlayersNumber << endl;
        Outfile << "Average Height: " << AvgHeight() << endl;
        Outfile << "Oldest Player's " << "Name: " << OldestPlayer().getName() << ", His Age: " << (2024 - (OldestPlayer().getYearOfBirth())) << endl;
        Outfile << "Youngest Player's " << "Name: " << YoungestPlayer().getName() << ", His Age: " << (2024 - (YoungestPlayer().getYearOfBirth())) << endl;
        Outfile << "Average international goals: " << AvgIntGoals() << endl;
        Outfile << "Player with highest goals: " << highestIntGoals().getName() << ". with: " << highestIntGoals().getInternationalGoals() << " Goals" << endl;

        Outfile.close();
    }
};

void readPlayersFromFile(ifstream& Infile) {
    int numPlayers, birthYear, height, internationalGoals;
    string name, nationality;

    Infile >> numPlayers;
    Infile.ignore();

    Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        getline(Infile, name);

        Infile >> birthYear;
        Infile >> height;
        Infile >> internationalGoals;

        Infile.ignore();
        getline(Infile, nationality);

        players[i].setAll(name, birthYear, height, internationalGoals, nationality);

        cout << players[i] << endl;
    }

}

int main() {

    // testing

    Player p1("Akram", 2005, 177, 120, "Sudan");
    Player p2("Mohammed", 2002, 177, 145, "Yemen");
    Player p3("Kamel", 2004, 185, 170, "Egypt");
    Player p4("Mark", 2004, 174, 135, "USA");

    NationalTeam t1;

    ifstream Infile("players.txt");

    t1.addPlayer(p1);
    t1.addPlayer(p2);
    t1.addPlayer(p3);
    t1.addPlayer(p4);

    readPlayersFromFile(Infile);
}
