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

void parseMovieFile(string &filename, vector<Movie> &movieVector, map<int,Movie> &moviesmap){
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
    
    //adds movie to vector and map
    movieVector.push_back(movie1);
    moviesmap.insert ( pair<int,Movie>( stoi(id),movie1) );
  }

  cout<<">> Reading movies... "<<movieVector.size()<<endl;
}
void parseReviewFile(string &filename, vector<Review> &reviewVector, map<int,Review> &reviewsmap){
  ifstream file(filename);

  string line, rid, mid, uid, rate, date;

  //checks if file exists
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
    
    //saves each review in vector and map
    reviewVector.push_back(review1);
    reviewsmap.insert ( pair<int,Review>(stoi(rid),review1) );
  }

  cout<<">> Reading reviews... "<<reviewVector.size()<<endl;
}

void sortMovies(vector<Movie> &movies){
  //sorts movies
  sort(movies.begin(), movies.end(), 
    [=](Movie &a, Movie &b) -> bool{ 
        return a.getMovieRating() > b.getMovieRating(); 
    }
  );

  

}
void printTop10Movies(vector<Movie> &movies, vector<Review> &reviews){

  //searches movies vector and calculates reviews 
  for(auto &m: movies){
    m.calcuateAvgReview(reviews);
  }

  //sorts the movies in he movies vector
  sortMovies(movies);

  //prints movies
  cout<<endl<<">> Top-10 Movies <<"<<endl<<endl;

  cout<<"Rank\tID\tReviews\tAvg\tName"<<endl;

  for(int i =0; i<10; i++){
    cout<<i+1<<".\t"<<movies[i].getMovieID()<<"\t"<<movies[i].getNumReviews()<<
    "\t"<<movies[i].getMovieRating()<<"\t'"<<movies[i].getMovieName()<<"'"<<endl;

  }

}


void printReview(Review &r, map<int,Movie> movies){

  string movieName;

  //gets the movie name from the review id
  movieName = (movies.find( r.getMovieID() )->second).getMovieName();

  //prints information
  cout<<"Movie: "<<r.getMovieID() <<"\t("<<movieName<<")"<<endl;
  cout<<"Num stars:\t"<<r.getRating()<<endl;;
  cout<<"User id:\t"<<r.getUserID()<<endl;
  cout<<"Date:\t\t"<<r.getReviewDate()<<endl;
  cout<<endl;

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
  cout<<endl;

}


void movieReviewInfo(map<int,Movie> &movies, map<int,Review> &reviews, vector<Review> &reviewsVEC){
  //inputs the maps of movies and the reviews vector
  //determines if the input is a movie id, review id, or neither and prints out respective info
  string input;
  int num;
  bool found;

  cout<<endl<<">> Movie and Review Information <<"<<endl<<endl;

  //continues loops always asks for new input
  while(true){

    //prints prompt and takes in input as integer, resets the found variable to false
    found = false;
    cout<<"Please enter a movie ID (< 100,000), a review ID (>= 100,000), 0 to stop> ";
    cin>>input;
    num = stoi(input);
    cout<<endl;

    //quits the loop if input is 0
    if(num == 0) return;
    //prints invalid id if input is negative
    else if(num < 0) {
      cout<<"**invalid id..."<<endl<<endl; continue;
    }

    //searches reviews if input is greater than 100000
    else if(num>100000){
      //check if reviews map contains the actual review that was inputted
      if( reviews.find(num) != reviews.end()  ){
        //prints the review and marks it as found
        printReview( reviews.find(num)->second , movies );
        found = true;
      }
      //prints if review is not found
      if (!found)cout<<"review not found..."<<endl<<endl;
      continue;
    }

    //searches movies
    else {
      if( movies.find(num) != movies.end() ){
        //calculates the average rating and then prints movie info
        (movies.find(num)->second).calcuateAvgReview(reviewsVEC);
        printMovie( movies.find(num)->second );
        found = true;
      }
      //prints if movie is not found
      if(!found)cout<<"movie not found..."<<endl<<endl;
      continue;
    }

  }

}


int main()
{

  //declares vectors and maps
  string moviesFN, reviewsFN;
  vector<Movie> movies;
  vector<Review> reviews;
  map<int,Movie> moviesmap;
  map<int,Review> reviewsmap;

  //prints title
  cout << "** Netflix Movie Review Analysis **" << endl;
  cout << endl;

  // input the filenames to process:
  cin >> moviesFN;
  cin >> reviewsFN;

  cout << endl;

  //parses the files and adds them to the vectors and maps
  parseMovieFile(moviesFN,movies,moviesmap);
  parseReviewFile(reviewsFN,reviews,reviewsmap);

  //PART 1
  //uses vectors in part 1
  printTop10Movies(movies,reviews);

  //PART 2
  //uses maps in part 2
  movieReviewInfo(moviesmap,reviewsmap,reviews);

  cout << "** DONE! **" << endl << endl;

  return 0;
}
