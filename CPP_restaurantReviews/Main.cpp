#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Review {
public:
    void SetUserName(string revUserName) {
        userName = revUserName;
    }
    void SetRating(int revRating) {
        rating = revRating;
    }
    string GetUserName() const { return userName; }
    int GetRating() const { return rating; }

private:
    string userName = "NoName";
    int rating = -1;
};


void ReadReviews(string& restaurantName, vector<Review>& reviewList) {
    ifstream inFS;     // Input file stream
    string userName;
    int userRating;
    Review currentReview;

    // Open file
    inFS.open("Trattoria_Reviews.txt");

    if (!inFS.is_open()) {
        cout << "Could not open file Trattoria_Reviews.txt." << endl;
    }

    getline(inFS, restaurantName);

    while (!inFS.eof()) {
        inFS >> userName;
        inFS >> userRating;

        if (!inFS.fail()) {
            currentReview.SetUserName(userName);
            currentReview.SetRating(userRating);
            reviewList.push_back(currentReview);
        }
    }

    // Close file when done reading
    inFS.close();
}

double CalcAvgRating(const vector<Review>& reviewList) {
    int i;
    double ratingAvg = 0;

    for (i = 0; i < reviewList.size(); ++i) {
        ratingAvg += reviewList.at(i).GetRating();
    }
    return ratingAvg /= reviewList.size();
}

void DisplayReviews(const string& restaurantName,
    const vector<Review>& reviewList,
    const double ratingAvg) {
    int i;

    cout << endl << restaurantName << endl;
    cout << "Average rating: " << ratingAvg << endl;
    cout << "--------------------" << endl;

    for (i = 0; i < reviewList.size(); ++i) {
        cout << "User name: " << reviewList.at(i).GetUserName() << endl;
        cout << "   Rating: " << reviewList.at(i).GetRating() << endl;
        cout << endl;
    }
}

int main() {
    double ratingAvg;
    vector<Review> reviewList;
    string restaurantName;

    // Reads restaurant name and reviews from input file at program start
    ReadReviews(restaurantName, reviewList);

    ratingAvg = CalcAvgRating(reviewList);
    DisplayReviews(restaurantName, reviewList, ratingAvg);

    return 0;
}