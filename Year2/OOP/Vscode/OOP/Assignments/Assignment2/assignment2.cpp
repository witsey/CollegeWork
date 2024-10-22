/* 
This program is made by Akram Omer and Mohammed
The main purpose of the program is to systemically manage national soccer teams and players ( adding and removing players) 
As well as gathering statistics for any national team */

#include <iostream>
#include <fstream>
using namespace std;

// Classes:

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


    Player( string name, int yearOfBirth, int height, int internationalGoals, string nationality) {
        this->name = name;
        this->yearOfBirth = yearOfBirth;
        this->height = height;
        this->internationalGoals = internationalGoals;
        this->nationality = nationality; /* Parameterized constructor  */
    }

   //Setters:

    void setName( string givenName ) {
        name = givenName;
    }


    void setyearOfBirth( int givenYear ) {
        yearOfBirth = givenYear;
    }


    void setHeight( int givenHeight ) {
        height = givenHeight;
    }


    void setInternationalGoals( int givenGoals ) {
        internationalGoals = givenGoals;
    }


    void setNationality( string givenNationality ) {
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


    friend ostream& operator<<( ostream& output, const Player& player) { // overloading the << operator to print a player's information
        cout << "Player: " << player.name << endl << endl;

        cout << "Year Of Birth: " << player.yearOfBirth << endl;
        cout << "Height: " << player.height << endl;
        cout << "International Goals: " << player.internationalGoals << endl;
        cout << "Nationality: " << player.nationality << endl;
        return output;
    }


    void setAll( string givenName, int givenYear, int givenHeight, int givenGoals, string givenNationality) {
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
        string country;
        int index = 0;
        int currentPlayersNumber = 0;
    public:
        NationalTeam() { // Default constructor
            for (int i = 0; i < 18; i++) {
                active[i] = false;  // Initially setting all the active array elements to false
            }
        }


        NationalTeam( string country ) {

            this->country = country;

            for (int i = 0; i < 18; i++) {
                active[i] = false;  // Initially setting all the active array elements to false
            }
        }


        bool addPlayer( Player& player ) {
            if (index <= 17) 
            {
                players[index] = player;
                active[index++] = true; // switching the state of that player in the active array to array 
                                              // and incrementing the player index in case of a new player addition

                cout << player.getName() << " has been added to " << country << "." << endl;
                
                ++currentPlayersNumber;
                return true;
            }
            else {
                cout << "Max players number has been reached. No more players can be added." << endl;
                return false;
            }            
        }


        bool removePlayer(string playerName) {
            for ( int i = 0; i < index; i++) {
                if (playerName == players[i].getName()) {    // iterating through the entire players array to find the targeted player

                    if(active[i] == false) { // checking whether if that player is already removed or has a false state
                        cout << "This player is already out of the team." << endl;
                        return false;
                    }
                  // if not
                    active[i] = false; // set his state as false
                    cout << players[i].getName() << " Has been Removed." << endl; 
                    --currentPlayersNumber;
                    return true;
                }
            }

            // in case of not finding that player:
            cout << "Couldn't find the player named: '" << playerName << "'." << endl;
            return false;
        }


        int getNumOfPlayers() {
            return currentPlayersNumber;
        }


        string getCountry() {
            return country;
        }


        void setCountry( string givenCountry) {
            country = givenCountry;
        }


        int AvgHeight() {
            int totalHeight = 0;

            for (int i = 0; i < index; i++) {
                if(active[i]) // checking whether if that player active or not before adding his height to that total
                    totalHeight += players[i].getHeight();
            }
            int avgHeight = totalHeight / currentPlayersNumber;

            return avgHeight;
        }


        Player OldestPlayer() { 
            int oldestYear = 4000; // initializing random big number to the oldest Year to compare it later with the players years
            Player oldestPlayer; // A placeholder that will later hold the player with the oldest year

            for (int i = 0; i < index; i++) {
                if ( players[i].getYearOfBirth() < oldestYear && active[i] /* checking if he's active or not */ ) {
                    oldestYear = players[i].getYearOfBirth();
                    oldestPlayer = players[i];
                }
            }
            return oldestPlayer;
        }


        Player YoungestPlayer() {
            int youngestYear = 0; // same as the other function but in opposite
            Player youngestPlayer;

            for (int i = 0; i < index; i++) {
                if ( players[i].getYearOfBirth() > youngestYear && active[i] ) {
                    youngestYear = players[i].getYearOfBirth();
                    youngestPlayer = players[i];
                }
            }
            return youngestPlayer;
        }


        int AvgIntGoals() {
            int totalIntGoals = 0;

            for (int i = 0; i < index; i++) {
                if(active[i])
                    totalIntGoals += players[i].getInternationalGoals();
            }
            int avgIntGoals = totalIntGoals / index;

            return avgIntGoals;
        }


        Player highestIntGoals() {
            int highestIntGoals = 2000;
            Player highestIntGoalsPlayer;

            for (int i = 0; i < index; i++) {
                if ( players[i].getInternationalGoals() > highestIntGoals && active[i] ) {
                    highestIntGoals = players[i].getInternationalGoals();
                    highestIntGoalsPlayer = players[i];
                }
            }
            return highestIntGoalsPlayer;
        }


        friend ostream& operator<<( ostream& output, const NationalTeam& team) { // overloading the << operator to later use it when printing a team information
            output << endl;
            output << team.country << endl;
            output << "-- {  Players  } --" << endl;
            for ( int i = 0; i < team.index; i++) {
                if(team.active[i])
                    cout << team.players[i];
            }
            return output;
        }


        void writeStatistics( ofstream& Outfile /* An ofStream object that will be passed as a parameter to use it to write the statistics */) {
            
            // writing the statistics using the ofStream object:
            Outfile << "Country: " << country << endl;
            Outfile << "Number of players: " << index << endl;
            Outfile << "Average Height: " << AvgHeight() << endl;
            Outfile << "Oldest Player's " << "Name: " << OldestPlayer().getName() << ", His Age: " << (2024 - (OldestPlayer().getYearOfBirth()) ) << endl;
            Outfile << "Youngest Player's " << "Name: " << YoungestPlayer().getName() << ", His Age: " << (2024 - (YoungestPlayer().getYearOfBirth()) ) << endl;
            Outfile << "Average international goals: " << AvgIntGoals() << endl;
            Outfile << "Player with highest goals: " << highestIntGoals().getName() << ". with: " << highestIntGoals().getInternationalGoals() << " Goals" <<  endl;

            Outfile.close();
        }
};


// Functions:

NationalTeam *teams; // declaring a NationalTeam pointer and a Player pointer to later use them to create dynamic arrays
Player *players;

int teamsNumber;
int playersNumber;

void initializeTeams(int GivenTeamsNum) {
    teams = new NationalTeam[GivenTeamsNum]; // initializing the team array that will hold the teams
}


void initializePlayers( int GivenPlayersNum) {
    players = new Player[GivenPlayersNum]; // initializing the player array that will hold the players
}


void readPlayersFromFile(ifstream& Infile) {
    int birthYear, height, internationalGoals;
    string name, nationality;

    Infile >> playersNumber; // reading the players numebr from the first line in the txt through the ifStream object that will be passed as parameter
    Infile.ignore();

    initializePlayers(playersNumber);
    
    // reading the players data and putting each in the array of players
    for (int i = 0; i < playersNumber; i++) {
        getline(Infile, name);

        Infile >> birthYear;
        Infile >> height;
        Infile >> internationalGoals;

        Infile.ignore();
        getline(Infile, nationality);

        players[i].setAll(name, birthYear, height, internationalGoals, nationality);
    }

}


void displayPlayers() {

    cout << endl;
    for ( int i = 0; i < playersNumber; i++) {
        cout << i + 1 << "."  << players[i] << endl;
    }
}


void displayTeams() {

    for(int i = 0; i < teamsNumber; i++) {

        cout << "Team " << i + 1 << ": " << teams[i].getCountry() << endl;
    }
}


void addPlayerToTeam();


void removePlayerFromTeam();



int main() {

    string teamCountryName;
    bool again;
    int choice;

    ifstream Infile("players.txt"); 
    ofstream OutFile("TeamStatistics.txt"); // creating to objects one ifStream to read the players and one ofStream that will write the statistics in the txt

    cout << "Enter a number of national teams: ";
    cin >> teamsNumber;

    initializeTeams(teamsNumber);
    readPlayersFromFile(Infile);

    cout << endl;

    for (int i = 0; i < teamsNumber; i++) {

        cout << "Enter team " << i + 1 << " name: ";
        cin >> teamCountryName;

        teams[i].setCountry(teamCountryName);
    }


    cout << endl;

    do {
        cout << "---------------------" << endl;

        cout << "\n\nPlayers: " << endl << endl;
        displayPlayers();

        cout << "Teams: " << endl << endl;
        displayTeams();

        cout << "-------------------------------\nTo add a player to a team enter 1\nTo remove a player from a team enter 2\nTo exit enter 3\n";
        cin >> choice;

        if (choice == 1) {
            addPlayerToTeam();
        }
        else if(choice == 2) {
            removePlayerFromTeam();
        }
        else if(choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
            again = true;
            continue;
        }

        cout << "Do you want to continue adding/removing players to your teams? (1 for yes, 0 for no): ";
        cin >> again;

    } while (again);


    cout << "\n\nYou've added the following teams with the following players: " << endl;
    for( int i = 0; i < teamsNumber; i++) {

        cout << "Team " << i + 1 << ": " << teams[i];
    }

    for( int i = 0; i < teamsNumber; i++) {

        teams[i].writeStatistics(OutFile);
    }
    
}


void addPlayerToTeam() {

    int targetedPlayerNumber;
    string targetedTeam;
    bool teamExists = false;

    cout << "\nEnter a player (by his number in the above list): ";
    cin >> targetedPlayerNumber;

    cout << "\nEnter a team (by its name): ";
    cin >> targetedTeam;

    for (int i = 0; i < teamsNumber; i++) {
        if (teams[i].getCountry() == targetedTeam /* searching for the team through it's name.*/) {
            teams[i].addPlayer(players[targetedPlayerNumber - 1]);
            teamExists = true;
        }
    }

    if(!teamExists) // incase of inputting a team that doesn't exist
        cout << "Couldn't find the team: \"" << targetedTeam << "\"." << endl; 
}


void removePlayerFromTeam() {
    string targetedPlayerName;
    string targetedTeam;
    bool teamExists = false;

    cout << "Enter a player (by his Name): ";
    cin >> targetedPlayerName;

    cout << "\nEnter a team (by its name): ";
    cin >> targetedTeam;

    for (int i = 0; i < teamsNumber; i++) {
        if (teams[i].getCountry() == targetedTeam ) {
            teams[i].removePlayer(targetedPlayerName);
            teamExists = true;
        }
    }

    if(!teamExists) // incase of inputting a team that doesn't exist
        cout << "Couldn't find the team: \"" << targetedTeam << "\"." << endl; 
}
