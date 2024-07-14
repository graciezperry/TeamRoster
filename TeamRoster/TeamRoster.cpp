#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

void DisplayMainMenu() {

    cout << "Roster Manager\n";
    cout << "1. Display Roster\n";
    cout << "2. Add Player\n";
    cout << "3. Update Player\n";
    cout << "4. Delete Player\n";
    cout << "5. Quit\n\n";

    cout << "Choose an option: ";
}

void DisplayRoster(vector<string>& playerName, vector<int>& playerNumber) {

    int j = playerName.size() - 2;
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i <= j; i++) {
            if (playerName.at(i) > playerName.at(i + 1)) {
                swap(playerName.at(i), playerName.at(i + 1));
                swap(playerNumber.at(i), playerNumber.at(i + 1));
                swapped = true;
            }
        }
        j--;
    } while (swapped);

    cout << "Roster: " << endl;
    if (playerName.size() > 0) {
        for (int i = 0; i < playerName.size(); i++) {
            cout << i + 1 << ". " << playerName.at(i) << " - " << playerNumber.at(i) << endl;
        }
    }
    else {
        cout << "Empty\n";
    }
    cout << endl;
}

void AddPlayer(vector<string>& playerName, vector<int>& playerNumber) {

    string tempName;
    int tempNumber;
    string temp;

    cout << "Enter name: ";
    getline(cin, temp);
    getline(cin, tempName);
    playerName.push_back(tempName);

    cout << "Enter number: ";
    cin >> tempNumber;
    playerNumber.push_back(tempNumber);
    cout << endl;
}

void UpdatePlayer(vector<string>& playerName, vector<int>& playerNumber) {

    int playerToUpdate;
    int newPlayerNumber;

    DisplayRoster(playerName, playerNumber);

    cout << "Which player would you like to update? ";
    cin >> playerToUpdate;

    while (playerToUpdate < 1 || playerToUpdate > playerName.size()) {
        cout << "ERROR: Invalid Option:\n\n";
        cout << "Which player would you like to update? ";
        cin >> playerToUpdate;
    }

    cout << playerName.at(playerToUpdate - 1) << "'s new number? ";
    cin >> newPlayerNumber;
    playerNumber.at(playerToUpdate - 1) = newPlayerNumber;
    cout << endl;
}

void DeletePlayer(vector<string>& playerName, vector<int>& playerNumber) {

    int playerToDelete;

    DisplayRoster(playerName, playerNumber);

    cout << "Which player would you like to delete? ";
    cin >> playerToDelete;

    while (playerToDelete < 1 || playerToDelete > playerName.size()) {
        cout << "ERROR: Invalid Option:\n\n";
        cout << "Which player would you like to delete?\n ";
        cin >> playerToDelete;
    }
    cout << playerName.at(playerToDelete - 1) << " has been deleted.\n\n";

    for (int i = playerToDelete - 1; i < playerName.size() - 1; i++) {
        playerName.at(i) = playerName.at(i + 1);
        playerNumber.at(i) = playerNumber.at(i + 1);
    }
    playerName.pop_back();
}

/*
void UnitTest() {

    cout << "Testing function...\n";

    vector<string> tempName = { "John", "Jane", "Alex" };
    vector<int> tempNumber = { 23, 90, 45 };
    int previousVectorSize = tempName.size();

    DeletePlayer(tempName, tempNumber);

    assert(previousVectorSize != tempName.size());
    if (previousVectorSize != tempName.size()) {
        cout << "Testing Complete.";
    }
    else {
        cout << "Testing Failed.";
    }
    assert(previousVectorSize == tempName.size() + 1);
    if (previousVectorSize == tempName.size() + 1) {
        cout << "Testing Complete.";
    }
    else {
        cout << "Testing Failed.";
    }
}
*/

int main() {

    int userOption;
    vector<string> playerName;
    vector<int> playerNumber;

    DisplayMainMenu();

    cin >> userOption;
    cout << endl;

    while (userOption != 5) {
        switch (userOption) {
        case 1:
            DisplayRoster(playerName, playerNumber);
            break;
        case 2:
            AddPlayer(playerName, playerNumber);
            break;
        case 3:
            UpdatePlayer(playerName, playerNumber);
            break;
        case 4:
            DeletePlayer(playerName, playerNumber);
            break;
        default:
            cout << "ERROR: Invaid Option.\n\n";
        }

        DisplayMainMenu();

        cin >> userOption;
        cout << endl;
    }

    // UnitTest();
}