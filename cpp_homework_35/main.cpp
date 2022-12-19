//
//  main.cpp
//  cpp_homework_35
//
//  Created by Mark Semenov on 19.12.2022.
//

#include <iostream>
#include <vector>
using namespace std;

struct Movie {
private:
    string title;
    unsigned short yearOfIssue : 11;
    unsigned short rating : 7;
    vector <string> directors;
    vector <string> scriptAuthors;
    vector <string> genres;
    vector <string> comments;

public:
    // setters
    void setTitle(string title) { this->title = title; }
    void setYearOfIssue(short yearOfIssue) { this->yearOfIssue = yearOfIssue; }
    void setRating(short rating) { this->rating = rating; }
    void setDirectors(vector <string> directors) { this->directors = directors; }
    void setScriptAuthors(vector <string> scriptAuthors) { this->scriptAuthors = scriptAuthors; }
    void setGenres(vector <string> genres) { this->genres = genres; }
    void setComments(vector <string> comments) { this->comments = comments; }

    // getters
    string getTitle() { return title; }
    short getYearOfIssue() { return yearOfIssue; }
    short getRating() { return rating; }
    vector <string> getDirectors() { return directors; }
    vector <string> getScriptAuthors() { return scriptAuthors; }
    vector <string> getGenres() { return genres; }
    vector <string> getComments() { return comments; }

    Movie newMovie() {
        Movie tmp;
        string title;
        short yearOfIssue, rating, num1, num2, num3, num4;

        // title
        cout << "Please, enter title of movie: ";
        cin >> title;
        cout << endl;
        tmp.setTitle(title);

        // year of issue
        cout << "Please, enter year of issue of movie: ";
        cin >> yearOfIssue;
        cout << endl;
        tmp.setYearOfIssue(yearOfIssue);

        // rating
        cout << "Please, enter rating (from 0 to 100) of movie: ";
        cin >> rating;
        cout << endl;
        tmp.setRating(rating);

        // directors
        cout << "Please, enter number of directors: ";
        cin >> num1;
        vector <string> directors(num1);
        for (int i = 0; i < num1; i++) {
            cout << "Please, enter " << i + 1 << " director: ";
            cin >> directors[i];
        }
        cout << endl;
        tmp.setDirectors(directors);

        // script authors
        cout << "Please, enter number of script authors: ";
        cin >> num2;
        vector <string> scriptAuthors(num2);
        for (int i = 0; i < num2; i++) {
            cout << "Please, enter " << i + 1 << " author of script: ";
            cin >> scriptAuthors[i];
        }
        cout << endl;
        tmp.setScriptAuthors(scriptAuthors);

        // genres
        cout << "Please, enter number of genres: ";
        cin >> num3;
        vector <string> genres(num3);
        for (int i = 0; i < num3; i++) {
            cout << "Please, enter " << i + 1 << " genre: ";
            cin >> genres[i];
        }
        cout << endl;
        tmp.setGenres(genres);

        // comments
        cout << "Please, enter number of comments: ";
        cin >> num4;
        vector <string> comments(num4);
        for (int i = 0; i < num4; i++) {
            cout << "Please, enter " << i + 1 << " comment: ";
            cin >> comments[i];
        }
        cout << endl;
        tmp.setComments(comments);

        return tmp;
    }

    void showAllFilms(Movie films[], int size) {
        for (int i = 0; i < size; i++) {
            cout << "Film #" << i + 1 << endl;

            cout << "Title: " << films[i].getTitle() << endl;

            cout << "Year of issue: " << films[i].getYearOfIssue() << endl;

            cout << "Rating: " << films[i].getRating() << "%" << endl;

            cout << "Directors: ";
            for (int j = 0; j < films[i].getDirectors().size(); j++) {
                cout << films[i].getDirectors()[j] << ", ";
            }
            cout << endl;

            cout << "Script authors: ";
            for (int j = 0; j < films[i].getScriptAuthors().size(); j++) {
                cout << films[i].getScriptAuthors()[j] << ", ";
            }
            cout << endl;

            cout << "Genres: ";
            for (int j = 0; j < films[i].getGenres().size(); j++) {
                cout << films[i].getGenres()[j] << ", ";
            }
            cout << endl;

            cout << "Comments: ";
            for (int j = 0; j < films[i].getComments().size(); j++) {
                cout << films[i].getComments()[j] << ", ";
            }
            cout << endl << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int size;
    cout << "How many movies? ";
    cin >> size;
    Movie* films = new Movie[size];
    for (int i = 0; i < size; i++) {
        films[i] = films[i].newMovie();
    }
    films->showAllFilms(films, size);
    delete[] films;
}
