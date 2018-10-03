//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 2

import java.util.*;

//class declaration
public class Artifact {
	private String name;
	private String description;
	private int value;
	private int mobility;
	private int keyPattern;
	
	//constructor using input parameters
	Artifact(String artName, String artDescription, int artValue, int artMobility, int artKeyPattern){
		name = artName;
		description = artDescription;
		value = artValue;
		mobility = artMobility;
		keyPattern = artKeyPattern;
		
	}
	
	//constructor with scanner
	Artifact(Scanner sc){
		
	}
	
	//uses artifact
	public void use() {
		//TODO
		
	}
	
	//methods that return class info
	public String name() { return name;}
	public String description() { return description;}
	public int value() { return value;}
	public int size() { return mobility;}
	public int keyPattern() { return keyPattern;}

	//prints information 
	public void print() {
		//used for debugging purposes
		System.out.println("Name" + name);
		System.out.println("Description" + description);
		System.out.println("Value" + value);
		System.out.println("Mobility" + mobility);
		System.out.println("Key Pattern" + keyPattern);
		
	}
	
	//displays artifact information
	public void display() {
		System.out.println("Name: " + name);
		System.out.println("Description: " + description);
		System.out.println("Value ($): " + value);
		System.out.println("Mobility (pounds): " + mobility);
		System.out.println("");

	}
	

	
	
	

}
