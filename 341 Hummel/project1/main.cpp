/*main.cpp*/

//
// Grade Analysis program in modern C++.
//
// Affan Farid
// U. of Illinois, Chicago
// CS 341: Fall 2018
// Project 01
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include <cstdio>

using namespace std;


class Course
{
private:
    string Dept;
    string Number;
    string Title;
    double A, B, C, D, F, I, NR, S, U, W;
    string Instructor;
    
    

public:
    Course(string dept, string num, string title, int a, int b, int c, int d, int f, int i, int nr, int s, int u, int w, string instructor)
    {
        Dept = dept;
        Number = num;
        Title = title;
        A = a;
        B = b;
        C = c;
        D = d;
        F = f;
        I = i;
        NR = nr;
        S = s;
        U = u;
        W = w;
        Instructor = instructor;
        
    }
    
    string getDept(){return Dept;}
    string getCourseNum(){return Number;}
    string getInstructor(){return Instructor;}
    
    double getAs(){ return A;}
    double getBs(){ return B;}
    double getCs(){ return C;}
    double getDs(){ return D;}
    double getFs(){ return F;}
    double getWs(){ return W;}
    
    int getNumGrades(){
        return A+B+C+D+F;
    }
    
    int getNumStudents(){
        return getNumGrades() + I + NR + S + U + W;
    }
    
    double getDFWrate(){
        double dfw = D + F + W;
        double denom = getNumGrades() + W;
        return (dfw/denom)*100 ;
    }

};

struct less_than_dept
{
    inline bool operator() (Course& struct1, Course& struct2)
    {
        return (struct1.getDept() < struct2.getDept() );
    }
};

void printTotal(vector<Course> &courses, string s){
    int numCourses = 0;
    int numGrades = 0;
    double pA, pB, pC, pD, pF;
    
    numCourses = courses.size();
    
    for (Course c : courses){
        numGrades += c.getNumGrades();
        pA += c.getAs();
        pB += c.getBs();
        pC += c.getCs();
        pD += c.getDs();
        pF += c.getFs();
    }
    
    
    pA = (pA / numGrades)*100;
    pB = (pB / numGrades)*100;
    pC = (pC / numGrades)*100;
    pD = (pD / numGrades)*100;
    pF = (pF / numGrades)*100;
    
    cout<<s<<":"<<endl;
    cout<<"  Num courses:  "<<numCourses<<endl;
    cout<<"  Num grades:   "<<numGrades<<endl;
    cout<<"  Distribution: "<<pA<<"%, "<<pB<<"%, "<<pC<<"%, "<<pD<<"%, "<<pF<<"%"<<endl;

 
}

void printByDepartment(vector<Course> &courses){
    
    vector<string> depTypes;
    
    
    //Adds all departments to a department list vector
    for( Course c: courses){
        if(find( depTypes.begin(), depTypes.end(), c.getDept() ) == depTypes.end()){
            depTypes.push_back(c.getDept());
        }
    }
    
    
    for(string d : depTypes){
        vector<Course> subcourses;
        for (Course c : courses){
            if(d == c.getDept()){
                subcourses.push_back(c);
            }
        }
        printTotal(subcourses,d);
        
    }
    
}





void printCourseInfo(Course &c1){
    int numStudents = -1;
    int numGrades = -1;
    double pA, pB, pC, pD, pF;
    
    numGrades = c1.getNumGrades();
    numStudents =c1.getNumStudents();
    
    pA = (c1.getAs() / numGrades)*100;
    pB = (c1.getBs() / numGrades)*100;
    pC = (c1.getCs() / numGrades)*100;
    pD = (c1.getDs() / numGrades)*100;
    pF = (c1.getFs() / numGrades)*100;

    
    cout<<c1.getDept()<< " "<<c1.getCourseNum()<<" ("<<c1.getInstructor()<<""<<endl;
    cout<<"  Num students: "<<numStudents<<endl;
    
    if(c1.getNumGrades()==0){
        cout<<"  Distribution: "<<"no report"<<endl;
    }
    else{
        cout<<"  Distribution: "<<pA<<"%, "<<pB<<"%, "<<pC<<"%, "<<pD<<"%, "<<pF<<"%"<<endl;
    }
    
    if(c1.getDFWrate() > 0){
        
        cout<<"  DFW rate: "<<c1.getDFWrate()<<"%"<<endl;
        
    }
    else cout<<"  DFW rate: "<<"0.00%"<<endl;
    
    
}

void printByInstructor(vector<Course> &courses){

    string input;
    
    while(input!="#"){
        cout<<"Please enter instructor's name (or prefix or #)> "<<endl;
        cin >> input;
        
        if(input == "#") return;
        
        //performs search
        for(Course c: courses){

            
            if( (c.getInstructor().find(input) != string::npos) && (c.getInstructor()[0] == input[0])     ){

                printCourseInfo(c);
            }
            

            
            
        }
        
    }
    
}





int main()
{

    string  filename;


    cin >> filename;
    cout << filename << endl;
    cout << endl;

    cout << std::fixed;
    cout << std::setprecision(2);

    ifstream file(filename);
    string line ,dept,number,title,a,b,c,d,f,i,nr,s,u,w,instructor;
    
    if (!file.good())
    {
        
        cout  <<  "cannot  open  file!"  <<  endl;
        return  -1;
        
    }
    
    //  Input  data  into  a  vector
    //  of  Student  objects:
    vector<Course>  courses;
    getline(file,  line);    //  skip  header:
    
    while  (getline(file,  line))
    {
        
        stringstream  ss(line);
        
        
        //parse line
        getline(ss, dept, ',');
        getline(ss, number, ',');
        getline(ss, title, ',');
        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, c, ',');
        getline(ss, d, ',');
        getline(ss, f, ',');
        getline(ss, i, ',');
        getline(ss, nr, ',');
        getline(ss, s, ',');
        getline(ss, u, ',');
        getline(ss, w, ',');
        getline(ss, instructor);
        
        Course Course1(dept,number,title,stoi(a), stoi(b), stoi(c), stoi(d), stoi(f), stoi(i), stoi(nr), stoi(s), stoi(u), stoi(w), instructor);
        
        courses.push_back(Course1);
    }
    
    //Sorts vector by department
    //sort(courses.begin(), courses.end(), less_than_dept());
    
    
    //PART 1:
    string collegetitle = "College of Engineering";
    printTotal(courses,collegetitle);
    cout<<endl;
    
    //PART2:
    printByDepartment(courses);
    cout<<endl;
    
    //PART3:
    printByInstructor(courses);
    





  //
  // done:
  //
  cout << endl;
  return 0;
}
