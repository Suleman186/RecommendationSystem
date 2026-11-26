# Netflix Recommendation System

A C++-based Netflix-style Movie Recommendation System developed as a Data Structures and Algorithms (DSA) project.

## Project Overview

The Netflix Recommendation System is a console-based application that simulates how streaming platforms recommend movies to users based on similarities between movie genres and descriptions.

Users can browse movies, search for specific titles, receive personalized-style recommendations, maintain watch history, and manage a movie database.

The project demonstrates the practical implementation of fundamental Data Structures and Algorithms using C++.

## Features

- **Movie Database:** Store and manage movie information, including ID, title, genre, description, and rating.
- **Movie Search:** Search for movies by their titles.
- **Content-Based Recommendations:** Recommend movies based on matching genres and description keywords.
- **Movie Similarity:** Calculate similarity scores between movies.
- **Watch History:** Maintain a record of watched movies using a queue.
- **Movie Sorting:** Sort movies according to their ratings.
- **File Handling:** Save and load movie information using text files.
- **Interactive Menu:** Navigate through the system using a console-based menu.

## Data Structures and Algorithms Used

| Data Structure / Algorithm | Application |
|---|---|
| Vector | Dynamic storage of movies |
| Structure (`struct`) | Organizing movie information |
| Hash Map (`unordered_map`) | Movie ID lookup |
| Hash Set (`unordered_set`) | Identifying unique keywords |
| Queue | Maintaining watch history |
| Linear Search | Searching movie titles |
| Sorting | Ranking recommendations and movie ratings |
| String Processing | Extracting and comparing keywords |

## Recommendation Algorithm

The system uses a content-based filtering approach.

1. The user selects a movie.
2. The system compares its genre with other movies.
3. It extracts keywords from movie descriptions.
4. It calculates similarity scores based on matching genres and keywords.
5. Movies with the highest similarity scores are recommended.

Movies with matching genres receive additional similarity points.

## Technologies Used

- Programming Language: C++
- Standard Template Library (STL)
- File Handling
- Object-Oriented Programming
- Data Structures and Algorithms

## Project Structure

```text
NetflixRecommendationSystem/
│
├── main.cpp
├── Movie.h
├── NetflixSystem.h
├── NetflixSystem.cpp
├── movies.txt
└── README.md
```

## How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Navigate to the Project Folder

```bash
cd NetflixRecommendationSystem
```

### 3. Compile the Project

```bash
g++ -std=c++17 main.cpp NetflixSystem.cpp -o netflix
```

### 4. Run the Program

On macOS and Linux:

```bash
./netflix
```

On Windows:

```bash
netflix.exe
```

## Available Operations

1. Display All Movies
2. Add New Movie
3. Search Movie
4. Recommend Movies
5. Watch Movie
6. View Watch History
7. Sort Movies by Rating
8. Save Movies
9. Load Movies
0. Exit

## Future Improvements

- Implement graph-based movie recommendations.
- Introduce collaborative filtering based on user preferences.
- Add multiple user profiles.
- Implement a graphical user interface.
- Integrate a larger movie dataset.
- Improve recommendation accuracy using advanced similarity algorithms.

## Disclaimer

This project is an educational simulation of a movie recommendation system. It does not use Netflix's actual recommendation algorithm or access Netflix's database.

Developed as a university Data Structures and Algorithms project.
