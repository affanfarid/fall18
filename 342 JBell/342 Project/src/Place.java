//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 2

import java.util.*;

//class declaration
public class Place {
	
	//private data
	private int placeID;
	private String placeName;
	private String placeDescription;
	private Vector<Direction> directions = new Vector<Direction>(0);
	
	private Vector<Artifact> artifacts = new Vector<Artifact>(0);
	static HashMap<Integer, Place> map = new HashMap<Integer, Place>();
	
	//constructor
	Place (int ID, String name, String description){
		placeID = ID;
		placeName = name;
		placeDescription = description;
		
	}
	
	//constructor that takes scanner input
	Place (Scanner input ){
		//TODO
	  	String line = input.nextLine();
	  	System.out.println(line);
	  	String tokens[] = line.split("\\s+");
	  	
	  	
	  	
	}
	
	//returns vector of artifacts for that place
	public Vector<Artifact> getArtifacts(){
		return artifacts;
	}
	
	//checks if artifact exists based on input name
	public boolean checkIfArtifactExists(String name) {
		boolean exists = false;
		for(Artifact a: artifacts) {
			if(a.name().equals(name)) {
				exists = true;
				break;
			}
			
		}
		return exists;
	}

	//removes the artifact from the vector, returns it
	public Artifact removeArtifact(String name) {
		Artifact x = null;
		for(Artifact a: artifacts) {
			if(a.name().equals(name)) {
				artifacts.remove(a);
				x = a;
				break;
			}
		}
		return x;
	}
	
	//updates map to include global map
	public void updateMap(HashMap<Integer,Place> m) {
		map = m;
	}
	
	//uses the key
	public void useKey(Artifact a) {
		//TODO
		for (Direction d: directions) {
			d.useKey(a);
		}
	}
	
	//based on id returns the place
	public static Place getPlaceByID(int id) {
		
		if(map.containsKey(id)) {
			return map.get(id);
		}
		else {
			System.out.println("No such place exists");
			return null;
		}
		
	}
	
	//adds artifact to the vector of artifacts
	public void addArtifact(Artifact artifact) {
		artifacts.add(artifact);
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
		System.out.println("NAME: " + placeName);
		System.out.println("Place ID: " + placeID);
		System.out.println("Description: " + placeDescription);
		
		System.out.println("Directions: ");
		for(Direction d: directions) {
			d.print();
		}
		
		System.out.println("Artifacts: ");
		for(Artifact a: artifacts) {
			a.print();
			
		}
		
		
		return;
	}
	
	//displays current description of the place
	public void display() {
		System.out.println("Current place Description: \n" + placeDescription+"\n");
	}
	
	//returns the name of the place
	public String name() {
		return placeName; 
	}
	
	//returns current description of place
	public String description() {
		return placeDescription;
	}
}

