//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 1


//class declaration
public class Direction {
	
	//private data
	private boolean isDirectionLocked;
	private int direcID;
	private Place direcFrom;
	private Place direcTo;
	private String direcString;
	
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
		return;
	}

}
