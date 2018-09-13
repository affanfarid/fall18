//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 1

import java.util.*;

//class declaration
public class Place {
	
	//private data
	private int placeID;
	private String placeName;
	private String placeDescription;
	private Vector<Direction> directions = new Vector<Direction>(0);
	
	//constructor
	Place (int ID, String name, String description){
		placeID = ID;
		placeName = name;
		placeDescription = description;
		
	}
	
	//returns the name of the place
	public String name() {
		return placeName; 
	}
	
	//displays current description of the place
	public void display() {
		System.out.println("Current place Description: \n" + placeDescription+"\n");
	}
	
	//returns current description of place
	public String description() {
		return placeDescription;
	}
	
	//adds a new direction to the vector of directions
	public void addDirection(Direction direc) {
		//NEEDS WORK
		directions.addElement(direc);
	}
	
	//returns the next place in a corresponding direction
	public Place followDirection(String s) {
		//loops through all directions to see if input is a valid one and direction exists for that place
		for(int i =0; i< directions.size(); i++) {
			
			//if direction is valid returns the new place which the direction is going TO
			if ( directions.get(i).match(s) ) {
				return directions.get(i).follow();
				
			}
		}
		
		//if it doesnt match stay in the same place
		return this;
	}
	
	//prints info for debugging purposes
	public void print(){
		return;
	}

}

