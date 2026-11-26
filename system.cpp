
#include "NetflixSystem.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

// =================================
// CONSTRUCTOR: SAMPLE MOVIE DATABASE
// =================================

NetflixSystem::NetflixSystem() {

    movies = {
        {1, "Interstellar", "Sci-Fi",
         "space time travel science", 8.7},

        {2, "Inception", "Sci-Fi",
         "dreams mind science thriller", 8.8},

        {3, "Tenet", "Sci-Fi",
         "time travel action thriller", 7.8},

        {4, "The Matrix", "Sci-Fi",
         "science technology artificial intelligence", 8.7},

        {5, "The Dark Knight", "Action",
         "batman crime joker action", 9.0},

        {6, "Iron Man", "Action",
         "technology superhero armor action", 7.9},

        {7, "Avengers", "Action",
         "superhero battle universe action", 8.0}
    };

    rebuildIndex();
}

// =================================
// REBUILD MOVIE INDEX
// =================================

void NetflixSystem::rebuildIndex() {

    movieIndex.clear();

    for (int i = 0; i < movies.size(); i++) {
        movieIndex[movies[i].id] = i;
    }
}

// =================================
// CALCULATE MOVIE SIMILARITY
// =================================

int NetflixSystem::calculateSimilarity(
    const Movie& a, const Movie& b) {

    int score = 0;

    if (a.genre == b.genre) {
        score += 3;
    }

    unordered_set<string> wordsA;
    unordered_set<string> wordsB;

    string word;

    stringstream streamA(a.description);

    while (streamA >> word) {

        for (char& c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }

        wordsA.insert(word);
    }

    stringstream streamB(b.description);

    while (streamB >> word) {

        for (char& c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }

        wordsB.insert(word);
    }

    for (const string& w : wordsA) {

        if (wordsB.count(w)) {
            score++;
        }
    }

    return score;
}

// =================================
// ADD NEW MOVIE
// =================================

void NetflixSystem::addMovie() {

    Movie m;

    cout << "\nEnter Movie ID: ";
    cin >> m.id;

    if (movieIndex.count(m.id)) {
        cout << "Movie ID already exists!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Movie Title: ";
    getline(cin, m.title);

    cout << "Enter Genre: ";
    getline(cin, m.genre);

    cout << "Enter Description Keywords: ";
    getline(cin, m.description);

    cout << "Enter Rating (0-10): ";
    cin >> m.rating;

    if (m.rating < 0 || m.rating > 10) {
        cout << "Invalid rating!\n";
        return;
    }

    if (m.title.empty() || m.genre.empty()) {
        cout << "Title and genre cannot be empty!\n";
        return;
    }

    movies.push_back(m);

    rebuildIndex();

    cout << "\nMovie added successfully!\n";
}

// =================================
// DISPLAY ALL MOVIES
// =================================

void NetflixSystem::displayMovies() {

    if (movies.empty()) {
        cout << "\nNo movies available.\n";
        return;
    }

    cout << "\n========== MOVIE DATABASE ==========\n";

    for (const Movie& m : movies) {

        cout << "\nID: " << m.id;
        cout << "\nTitle: " << m.title;
        cout << "\nGenre: " << m.genre;
        cout << "\nRating: " << m.rating;
        cout << "\nDescription: " << m.description;

        cout << "\n------------------------------------\n";
    }
}

// =================================
// SEARCH MOVIE
// =================================

void NetflixSystem::searchMovie() {

    string title;

    cin.ignore();

    cout << "\nEnter movie title: ";
    getline(cin, title);

    bool found = false;

    for (const Movie& m : movies) {

        if (m.title == title) {

            cout << "\nMovie Found!\n";

            cout << "Title: " << m.title << endl;
            cout << "Genre: " << m.genre << endl;
            cout << "Rating: " << m.rating << endl;
            cout << "Description: " << m.description << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nMovie not found!\n";
    }
}

// =================================
// RECOMMEND MOVIES
// =================================

void NetflixSystem::recommendMovies() {

    int id;

    cout << "\nEnter Movie ID: ";
    cin >> id;

    if (!movieIndex.count(id)) {
        cout << "Movie not found!\n";
        return;
    }

    int index = movieIndex[id];

    vector<pair<int, int>> recommendations;

    for (int i = 0; i < movies.size(); i++) {

        if (i == index)
            continue;

        int score = calculateSimilarity(
            movies[index], movies[i]
        );

        recommendations.push_back({i, score});
    }

    sort(
        recommendations.begin(),
        recommendations.end(),

        [](const pair<int, int>& a,
           const pair<int, int>& b) {

            if (a.second == b.second)
                return a.first < b.first;

            return a.second > b.second;
        }
    );

    cout << "\nRecommendations for "
         << movies[index].title << ":\n";

    cout << "====================================\n";

    int count = 0;

    for (const auto& r : recommendations) {

        if (r.second == 0)
            continue;

        cout << "\nMovie: " << movies[r.first].title;
        cout << "\nGenre: " << movies[r.first].genre;
        cout << "\nRating: " << movies[r.first].rating;
        cout << "\nSimilarity Score: " << r.second;

        cout << "\n------------------------------------\n";

        count++;

        if (count == 3)
            break;
    }

    if (count == 0) {
        cout << "No similar movies found.\n";
    }
}

// =================================
// WATCH MOVIE
// =================================

void NetflixSystem::watchMovie() {

    int id;

    cout << "\nEnter Movie ID: ";
    cin >> id;

    if (!movieIndex.count(id)) {
        cout << "Movie not found!\n";
        return;
    }

    int index = movieIndex[id];

    watchHistory.push(movies[index].title);

    cout << "\nNow Watching: "
         << movies[index].title << endl;
}

// =================================
// DISPLAY WATCH HISTORY
// =================================

void NetflixSystem::displayHistory() {

    if (watchHistory.empty()) {
        cout << "\nWatch history is empty.\n";
        return;
    }

    queue<string> temp = watchHistory;

    cout << "\n========== WATCH HISTORY ==========\n";

    while (!temp.empty()) {

        cout << temp.front() << endl;

        temp.pop();
    }
}

// =================================
// SORT MOVIES BY RATING
// =================================

void NetflixSystem::sortByRating() {

    vector<Movie> sortedMovies = movies;

    sort(
        sortedMovies.begin(),
        sortedMovies.end(),

        [](const Movie& a, const Movie& b) {
            return a.rating > b.rating;
        }
    );

    cout << "\n========== TOP RATED MOVIES ==========\n";

    for (const Movie& m : sortedMovies) {

        cout << m.title
             << " | Rating: "
             << fixed << setprecision(1)
             << m.rating << endl;
    }
}

// =================================
// SAVE MOVIES TO FILE
// =================================

void NetflixSystem::saveMovies() {

    ofstream file("movies.txt");

    if (!file) {
        cout << "Unable to open file!\n";
        return;
    }

    for (const Movie& m : movies) {

        file << m.id << '\n'
             << m.title << '\n'
             << m.genre << '\n'
             << m.description << '\n'
             << m.rating << '\n';
    }

    file.close();

    cout << "\nMovies saved successfully!\n";
}

// =================================
// LOAD MOVIES FROM FILE
// =================================

void NetflixSystem::loadMovies() {

    ifstream file("movies.txt");

    if (!file) {
        cout << "\nNo saved database found. Using sample movies.\n";
        return;
    }

    vector<Movie> loadedMovies;

    Movie m;

    while (file >> m.id) {

        file.ignore();

        if (!getline(file, m.title) ||
            !getline(file, m.genre) ||
            !getline(file, m.description) ||
            !(file >> m.rating)) {

            cout << "Invalid movie database format!\n";
            return;
        }

        file.ignore();

        if (m.rating < 0 || m.rating > 10) {
            cout << "Invalid rating in database!\n";
            return;
        }

        loadedMovies.push_back(m);
    }

    file.close();

    movies = loadedMovies;

    rebuildIndex();

    cout << "\nMovies loaded successfully!\n";
}
