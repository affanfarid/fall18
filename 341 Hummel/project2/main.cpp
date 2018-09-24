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

class Movie;
class Review;

class Review{
  private:

  int reviewID;
  int movieID;
  int userID;
  int rating;
  string reviewDate;

  //Movie movieReviewed;

  public:
  
  Review(int rid, int mid, int uid, int rate, string date){
    reviewID = rid;
    movieID = mid;
    userID = uid;
    rating = rate;
    reviewDate = date;

  }

  int getReviewID(){return reviewID;}
  int getMovieID(){return movieID;}
  int getUserID(){return userID;}
  int getRating(){return rating;}
  string getReviewDate(){return reviewDate;}
};

class Movie{
  private:

  int movieID;
  string movieName;
  int yearPublished;

  int numReviews;
  double averageRating = 0.0;

  int starFrequencies[6] = {-1,0,0,0,0,0};

  vector<Review> movieReviews;

  public:

  Movie();

  Movie(int id, string name, int year){
    movieID = id;
    movieName = name;
    yearPublished = year;

  }

  void calcuateAvgReview(vector<Review> &reviews){

    for(Review r: reviews){

      if (r.getMovieID() == movieID){
        movieReviews.push_back(r);
        averageRating += r.getRating();
        numReviews++;
      }
    }

    averageRating = double(averageRating)/double(numReviews);

    //makes sure averageRating is not NaN
    if(averageRating != averageRating){
      averageRating = 0;
    }

    return;
  }
  void calculateFrequencies(){
    starFrequencies[0] = -1;
    for(auto &r: movieReviews){
      starFrequencies[r.getRating()]++;
    }
  }

  int getNumStars(int starnum){return starFrequencies[starnum];}
  int getMovieID(){return movieID;}
  string getMovieName(){return movieName;}
  int getMovieYear(){return yearPublished;}
  int getNumReviews(){return numReviews;}
  double getMovieRating(){return averageRating;}

  void setRating(double x){averageRating = x;}

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

  cout<<">> Reading movies... "<<movieVector.size()<<endl;
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

  cout<<">> Reading reviews... "<<reviewVector.size()<<endl;
}
void sortMovies(vector<Movie> &movies){
  sort(movies.begin(), movies.end(), 
    [=](Movie &a, Movie &b) -> bool{ 
        return a.getMovieRating() > b.getMovieRating(); 
    }
  );

  

}
void printTop10Movies(vector<Movie> &movies, vector<Review> &reviews){

  for(auto &m: movies){
    m.calcuateAvgReview(reviews);
  }

  sortMovies(movies);

  cout<<endl<<">> Top-10 Movies <<"<<endl<<endl;

  cout<<"Rank\tID\tReviews\tAvg\tName"<<endl;

  for(int i =0; i<10; i++){
    cout<<i+1<<".\t"<<movies[i].getMovieID()<<"\t"<<movies[i].getNumReviews()<<
    "\t"<<movies[i].getMovieRating()<<"\t'"<<movies[i].getMovieName()<<"'"<<endl;

  }

}

//TODO
void printReview(Review &r, vector<Movie> movies){

  string movieName;

  for(auto &m: movies){
    if(r.getMovieID() == m.getMovieID()){
      movieName = m.getMovieName();
      break;
    }
  }

  cout<<"Movie: "<<r.getMovieID() <<"\t("<<movieName<<")"<<endl;
  cout<<"Num stars:\t"<<r.getRating()<<endl;;
  cout<<"User id:\t"<<r.getUserID()<<endl;
  cout<<"Date:\t\t"<<r.getReviewDate()<<endl;

}

void printMovie(Movie & m){
  //calculates the number of each star from all the movie's reviews
  m.calculateFrequencies();

  //prints info
  cout<<"Movie:\t\t"<<m.getMovieName()<<endl;
  cout<<"Year:\t\t"<<m.getMovieYear()<<endl;
  cout<<"Avg rating:\t"<<m.getMovieRating()<<endl;
  cout<<"Num reviews:\t"<<m.getNumReviews()<<endl;

  //prints the star lines
  int i = 1;
  cout<<" "<<i<<" star:\t"<<m.getNumStars(i)<<endl;
  for(int i =2; i<=5; i++){
    cout<<" "<<i<<" stars:\t"<<m.getNumStars(i)<<endl;
  }
}

void movieReviewInfo(vector<Movie> &movies, vector<Review> &reviews){
  string input;
  int num;
  bool found;

  cout<<endl<<">> Movie and Review Information <<"<<endl<<endl;

  while(true){
    found = false;
    cout<<"Please enter a movie ID (< 100,000), a review ID (>= 100,000), 0 to stop> ";
    cin>>input;
    num = stoi(input);
    cout<<endl;

    
    if(num == 0) return;
    else if(num < 0) {
      cout<<"**invalid id..."<<endl<<endl; continue;
    }
    else if(num>100000){
      //searches reviews
      for(auto &r: reviews){
        if(r.getReviewID() == num){
          printReview(r,movies);
          found = true;
          break;
        }
      }
      //TODO
      if (!found)cout<<"review not found..."<<endl<<endl;
      continue;

    }
    else {
      //searches movies
      for(auto &m: movies){
        if(m.getMovieID() == num){
          m.calcuateAvgReview(reviews);
          printMovie(m);
          found = true;
          break;
        }
      }
      //TODO
      if(!found)cout<<"movie not found..."<<endl<<endl;
      continue;
    }

  }

}



int main()
{

  string moviesFN, reviewsFN;
  vector<Movie> movies;
  vector<Review> reviews;

  cout << "** Netflix Movie Review Analysis **" << endl;
  cout << endl;

  // input the filenames to process:
  moviesFN ="movies.csv";
  reviewsFN ="reviews.csv";
  // UN COMMENT WHEN DONE
  // cin >> moviesFN;
  // cin >> reviewsFN;

  cout << endl;

  parseMovieFile(moviesFN,movies);
  parseReviewFile(reviewsFN,reviews);

  //PART 1
  //printTop10Movies(movies,reviews);

  //PART 2
  movieReviewInfo(movies,reviews);

  cout << "** DONE! **" << endl << endl;

  return 0;
}
