/*main.cpp*/

//
// Netflix movie review analysis.
//
// Affan Farid
// UIN 671466593
// U. of Illinois, Chicago
// CS 341: Fall 2018
// Project 02
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;

class Movie{
  private:

  int movieID;
  string movieName;
  int yearPublished;

  int numReviews;
  double averageRating;

  public:

  Movie(int id, string name, int year){
    movieID = id;
    movieName = name;
    yearPublished = year;

  }

  int getMovieID(){return movieID;}
  string getMovieName(){return movieName;}
  int getMovieYear(){return yearPublished;}
  int getNumReviews(){return numReviews;}
  double getMovieRating(){return averageRating;}

};

class Review{
  private:

  int reviewID;
  int movieID;
  int userID;
  int rating;
  string reviewDate;

  public:
  
  Review(int rid, int mid, int uid, int rate, string date){
    reviewID = rid;
    movieID = mid;
    userID = uid;
    rating = rate;
    reviewDate = date;

  }

};

void parseMovieFile(string &filename, vector<Movie> &movieVector){
  ifstream file(filename);

  string line, id, name, year;

  if (!file.good()){ 
    cout  <<  "cannot  open  file!"  <<  endl;
    return;  
  }

  //skips header
  getline(file,  line);

  while  (getline(file, line)){
    
    stringstream  ss(line);
    
    //parse line
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, year);
    
    Movie movie1(stoi(id),name,stoi(year));
    
    movieVector.push_back(movie1);
  }
}

void parseReviewFile(string &filename, vector<Review> &reviewVector){
  ifstream file(filename);

  string line, rid, mid, uid, rate, date;

  if (!file.good()){ 
    cout  <<  "cannot  open  file!"  <<  endl;
    return;  
  }

  //skips header
  getline(file,  line);

  while  (getline(file, line)){
    
    stringstream  ss(line);
    
    //parse line
    getline(ss, rid, ',');
    getline(ss, mid, ',');
    getline(ss, uid, ',');
    getline(ss, rate, ',');
    getline(ss, date);
    
    Review review1(stoi(rid),stoi(mid),stoi(uid),stoi(rate), date);
    
    reviewVector.push_back(review1);
  }
}

int main()
{

  string moviesFN, reviewsFN;
  vector<Movie> movies;
  vector<Review> reviews;

  cout << "** Netflix Movie Review Analysis **" << endl;
  cout << endl;

  //
  // input the filenames to process:
  //
  

  cin >> moviesFN;
  cin >> reviewsFN;

  //cout << moviesFN << endl;
  //cout << reviewsFN << endl;
  cout << endl;

  //
  // TODO:
  //

  parseMovieFile(moviesFN,movies);
  parseReviewFile(reviewsFN,reviews);



  


  //
  // done:
  //
  cout << "** DONE! **" << endl << endl;

  return 0;
}
