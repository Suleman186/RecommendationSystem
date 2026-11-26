
#include <iostream>
#include "NetflixSystem.h"

using namespace std;

int main() {

    NetflixSystem netflix;

    netflix.loadMovies();

    int choice;

    do {

        cout << "\n\n";
        cout << "========================================\n";
        cout << "       NETFLIX RECOMMENDATION SYSTEM    \n";
        cout << "========================================\n";

        cout << "1. Display All Movies\n";
        cout << "2. Add New Movie\n";
        cout << "3. Search Movie\n";
        cout << "4. Recommend Movies\n";
        cout << "5. Watch Movie\n";
        cout << "6. View Watch History\n";
        cout << "7. Sort Movies by Rating\n";
        cout << "8. Save Movies\n";
        cout << "9. Load Movies\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                netflix.displayMovies();
                break;

            case 2:
                netflix.addMovie();
                break;

            case 3:
                netflix.searchMovie();
                break;

            case 4:
                netflix.recommendMovies();
                break;

            case 5:
                netflix.watchMovie();
                break;

            case 6:
                netflix.displayHistory();
                break;

            case 7:
                netflix.sortByRating();
                break;

            case 8:
                netflix.saveMovies();
                break;

            case 9:
                netflix.loadMovies();
                break;

            case 0:
                cout << "\nThank you for using Netflix System!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
