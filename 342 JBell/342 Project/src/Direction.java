//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 2

import java.util.*;

//class declaration
public class Direction {
	
	//private data
	private boolean isDirectionLocked;
	private int direcID;
	private Place direcFrom;
	private Place direcTo;
	
	private int lockPattern;
	
	//TODO
	private String direcString;
	private DirType direc;
	
	//uses enum to define direction
	private enum DirType{
		NONE	("NONE", "None"), 
		N		("N", "North"), 
		S		("S", "South"), 
		E		("E", "East"),		 
		W		("W", "West"), 
		U		("U", "Up"), 
		D		("D", "Down"), 
		NE		("NE", "Northeast"), 
		NW		("NW", "Northwest"), 
		SE		("SE", "Southeast"), 
		SW		("SW", "Southwest"), 
		NNE		("NNE", "North-northeast"), 
		NNW		("NNW", "North-northwest"), 
		ENE		("ENE", "East-northeast"), 
		WNW		("WNW", "West-northwest"), 
		ESE		("ESE", "East-southeast"), 
		WSW		("WSW", "West-southwest"), 
		SSE		("SSE", "South-southeast"), 
		SSW		("SSW", "South-southwest");
		
		private final String abbr;
		private final String full;
		
		private DirType(String abbrName, String fullName) {
			abbr = abbrName;
			full = fullName;
			
		}
		
		public String getFullName() {return abbr;}
		public String getAbbrName() {return full;}
	}
	
	//constructor with default direction/path as unlocked
	Direction(int ID, Place from, Place to, String dir){
		direcID = ID;
		direcFrom = from;
		direcTo = to;
		direcString = dir;
		isDirectionLocked = false;
		
	}
	
	//constructor where input can decide if path is locked or not
	Direction(int ID, Place from, Place to, String dir, boolean isLocked){
		direcID = ID;
		direcFrom = from;
		direcTo = to;
		direcString = dir;
		isDirectionLocked = isLocked;
		
	}
	
	//constructor using lock pattern
	Direction(int ID, Place from, Place to, String dir, int lockPat){
		direcID = ID;
		direcFrom = from;
		direcTo = to;
		direcString = dir;
		lockPattern = lockPat;
		
	}
	
	//constructor using scanner
	Direction(Scanner sc){
		
		
	}
	
	//uses key to unlock direction
	public void useKey(Artifact a) {
		if(a.keyPattern() > 0 && a.keyPattern() == lockPattern) {
			unlock();
		}
	}
	
	//sees if input matches the direction 
	public boolean match(String s) {
		//NEEDS WORK
		if(s.equals(direcString)) {
			return true;
		}
		return false;
	}
	
	//locks direction
	public void lock() {
		isDirectionLocked = true;
		
	}
	
	//unlocks direction
	public void unlock() {
		isDirectionLocked = false;
		
	}
	
	//returns if a direction is locked or not
	public boolean isLocked() {
		return isDirectionLocked;
		
	}
	
	//returns the next place if it isnt locked, otherwise returns the same place
	public Place follow() {
		
		if(!isDirectionLocked) {
			return direcTo;
		}
		else return direcFrom;
		
	}
	
	//prints out information for debugging purposes
	public void print() {
		System.out.println(lockPattern);
		return;
	}

}
