//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 1


//import java.util.Scanner;
import java.util.*;

//Game class declaration
public class Game {
	
	//private data
	private String gameName;
	private Vector<Place> places = new Vector<Place>(0);
	private Place currentPlace;
	
	//constructor
	Game(String name){
		gameName = name;
		
	}
	
	//adds a place to the vector of places contained by the game
	public void addPlace (Place place) {
		places.addElement(place);
		
	}
	
	//print function for debugging purposes
	public void print() {
		//NEEDS WORK
		return;
		
	}
	
	//called to start and play the game
	public void play() {
		
		//sets the starting place to the first place that is added to the place vector
		currentPlace = places.get(0);
		System.out.println ("You started in: "+ currentPlace.name() );
		
		
		boolean gameover = false;
		
		//sets up a scanner to take input via console
		Scanner scanner = new Scanner(System.in);
		
		//game loop that continually takes input
		while(!gameover) {
			
			//takes reads input string and parses it by words separated by space
			String s = scanner.nextLine();
			String tokens[] = s.split("\\b");
			
			//code to quit if input triggers it
			if( tokens[0].equals("QUIT") || tokens[0].equals("EXIT") || currentPlace.name().equals("Exit") ) {
				System.out.println("EXITING...");
				gameover = true;
				break;
			}
			
			//displays the description of current room if user inputs "LOOK"
			else if( tokens[0].equals("LOOK") ) {
				
				currentPlace.display();
			}
			
			//changes place if user types in "GO X" where X is a valid direction
			else if(tokens[0].equals("GO")) {
				
				//takes in the inputted direction and changes the place to follow that inputted direction
				currentPlace = currentPlace.followDirection(tokens[2]);
				System.out.println ("You have entered: "+ currentPlace.name() );
				
				
				
			}
			
			//guides user how to put in input if they have done so incorrectly
			else System.out.println("Incorrect input. Please Enter 'LOOK' , 'GO X' (where X is N, S, E, W, U, D) or 'EXIT' or 'QUIT' ");
			
			
		}
		
	}
}
