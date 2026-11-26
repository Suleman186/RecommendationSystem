
#ifndef NETFLIXSYSTEM_H
#define NETFLIXSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "Movie.h"

using namespace std;

class NetflixSystem {

private:

    vector<Movie> movies;

    unordered_map<int, int> movieIndex;

    queue<string> watchHistory;

    int calculateSimilarity(const Movie& a, const Movie& b);

    void rebuildIndex();

public:

    NetflixSystem();

    void addMovie();

    void displayMovies();

    void searchMovie();

    void recommendMovies();

    void watchMovie();

    void displayHistory();

    void sortByRating();

    void saveMovies();

    void loadMovies();
};

#endif
