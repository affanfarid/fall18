//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 2


//import java.util.Scanner;
import java.util.*;

//Game class declaration
public class Game {
	
	//private data
	private String gameName;
	private Vector<Place> places = new Vector<Place>(0);
	private Place currentPlace;
	
	static HashMap<Integer, Place> map = new HashMap<Integer, Place>();
	private Vector<Artifact> inventory = new Vector<Artifact>(0);
	
	//constructor
	Game(String name){
		gameName = name;
		
	}
	
	//constructor for scanner input
	Game(Scanner input){

		//booleans to check what input is being read
	  	boolean direcOn = false;
	  	boolean placeOn = false;
	  	boolean artOn = false;
	  	
	  	//initializes number of directions, places, and arts
	  	int numDirecs = 0;
	  	int numPlaces = 0;
	  	int numArts = 0;
	  	  
	  	int numDirecsProcessed = 0;
	  	int numPlacesProcessed = 0;
	  	int numArtsProcessed = 0;
	  	
	  	//loops through each of the lines in the file
		while (  input.hasNextLine()  ) {
		  //parses through each line and splits it into tokens based on whitespace
	  	  String line = input.nextLine();
	  	  String tokens[] = line.split("\\s+");
	  	  
	  	  //checks if input is the Game Data Line
	  	  if(tokens[0].equals("GDF")) {
	  		  //parse first line
	  		  //set title
	  		  
	  		  String gameNameInput = tokens[2];
	  		  
	  		  int i = 3;
	  		  while(!tokens[i].matches("(//).*") || i==20) {
	  		  //while(!tokens[i].equals("//")) {
	  			  gameNameInput = gameNameInput.concat(" "+tokens[i]);
	  			  i++;
	  		  }
	  		  
	  		  gameName = gameNameInput;
	  		  //System.out.println(gameName);
	  		    
	  	  }
	  	  
	  	  //checks if line is the Places input
	  	  if(tokens[0].equals("PLACES")) {
	  		  numPlaces = Integer.parseInt(tokens[1] );
	  		  //System.out.println("in places bois: " + numPlaces);
	  
	  		  direcOn = false;
	  		  artOn = false;
	  		  placeOn = true;
 
	  	  }
	  	  
	  	  //checks if line is the artifacts input
	  	  if(tokens[0].equals("ARTIFACTS")) {
	  		  numArts = Integer.parseInt(tokens[1]);
	  		  //System.out.println("in artifacts bois: " + numArts);
	  		  
	  		  direcOn = false;
	  		  artOn = true;
	  		  placeOn = false;

	  	  }
	  	  
	  	  //checks if line is the Directions input line
	  	  if(tokens[0].equals("DIRECTIONS")) {
	  		  
	  		  numDirecs = Integer.parseInt(tokens[1]);
	  		  //System.out.println("in directions: " + numDirecs);
	  		  
	  		  direcOn = true;
	  		  artOn = false;
	  		  placeOn = false;

	  	  }
	  	  //if its checking places, then reads in places input
	  	  if(placeOn /*&& (numPlacesProcessed <= numPlaces) */&& !(line.isEmpty()) ) {
	  		  
	  		  //checks if the amount of places processed has met its limit
	  		  if(numPlacesProcessed == numPlaces) {
	  			  placeOn = false;
	  		  }
	  		  //only reads line if line starts with a number
	  		  if( (tokens[0] == "") || (  !Character.isDigit(tokens[0].charAt(0) )  )    ) {
	  			  continue;
	  		  }
	  		  else {
	  			  //takes in first input
	  			  int placeId = Integer.parseInt(tokens[0]);
	  			  
	  			  //takes in input and sets place name
	  			  String placeName = tokens[1];
		  		  int i = 2;
		  		  while(!tokens[i].matches("(//).*") || i==20) {
		  			  placeName = placeName.concat(" "+tokens[i]);
		  			  i++;
		  		  }
		  		  
		  		  //takes in number of description lines
		  		  String l1 = input.nextLine();
		  		  int numDescriptionLines = Integer.parseInt( l1 );

		  		  //stores descriptions
		  		  String description = "";
		  		  for(int j = 0; j<numDescriptionLines;j++) {
		  			  description = description.concat( "\n" + input.nextLine());
		  		  }
	  			  //creates place and adds it to game and map of places
	  			  Place p = new Place(placeId,placeName,description);
	  			  
	  			  //System.out.println(p.name());
	  			  //p.print();
	  			  numPlacesProcessed++;
	  			  places.add(p);
	  			  map.put(placeId, p);
	  		  }
 
	  	  }

	  	  //reads in direction input lines
	  	  if(direcOn && !(line.isEmpty()) ) {
	  		  
	  		  if(numDirecsProcessed == numDirecs) {
	  			  direcOn = false;
	  		  }
	  		  //only takes in lines that start with a number
	  		  if( (tokens[0] == "") || (  !Character.isDigit(tokens[0].charAt(0) )  )    ) {
	  			  //System.out.println("skipped line");
	  			  continue;
	  		  }
	  		  else {
	  			  
	  			  //process inputs and creates a new direction
	  			  int direcId = Integer.parseInt(tokens[0]);
	  			  Place from = map.get(Integer.parseInt( tokens[1] ) );
	  			  //TODO change from String to direc??
	  			  String direc = tokens[2];
	  			  Place to = map.get(Integer.parseInt( tokens[3] ) );
	  			  int lockPattern = Integer.parseInt( tokens[4] );
	  			  
	  			  numDirecsProcessed++;
	  			  
	  			  //adds direction to the places
	  			  from.addDirection(new Direction(direcId,from, to, direc, lockPattern)  );
	  			  
	  			  //System.out.println("Dir: " + direcId);

	  		  }
	  		   
	  	  }

	  	  //process artifact lines
	  	  if(artOn && !(line.isEmpty() ) ) {
	  		  
	  		  if(numArtsProcessed == numArts) {
	  			  artOn = false;
	  		  }
	  		  
	  		  //only takes input if the line starts with a number
	  		  if( (tokens[0] == "") || (  !Character.isDigit(tokens[0].charAt(0) )  )    ) {
	  			  //System.out.println("skipped line");
	  			  continue;
	  		  }
	  		  else {

	  			  
	  			  //reads in place input
	  			  int placeId = Integer.parseInt(tokens[0]);
	  			  
	  			  //reads in information from next line
	  			  String infoLine = input.nextLine();
	  			  String infoTokens[] = infoLine.split("\\s+");
	  			  
	  			  int artId = Integer.parseInt(infoTokens[0]);
	  			  int artValue = Integer.parseInt(infoTokens[1]);
	  			  int artMobility = Integer.parseInt(infoTokens[2]);
	  			  int artKeyPattern = Integer.parseInt(infoTokens[3]);
	  			  
	  			  //takes in artifact name
	  			  String artName = infoTokens[4];
		  		  int i = 5;
		  		  while(!infoTokens[i].matches("(//).*") || i<6) {
		  		  
		  			  artName = artName.concat(" "+infoTokens[i]);
		  			  i++;
		  			  if (infoTokens.length <= i) break;
		  		  }
  
		  		  //gets number of description lines
		  		  String l1 = input.nextLine();  
		  		  int numDescriptionLines = Integer.parseInt( l1 );

		  		  //reads in description
		  		  String description = "";
		  		  for(int j = 0; j<numDescriptionLines;j++) {
		  			  description = description.concat( "\n" + input.nextLine());
		  		  }
		  		  
		  		  //creates artifact
		  		  Artifact a = new Artifact(artName, description, artValue, artMobility, artKeyPattern);
		  		  
	  			  //System.out.println(a.name());
		  		  
		  		  numArtsProcessed++;
	  			  
		  		  //adds artifact to the correct place
	  			  map.get(placeId).addArtifact(a);
	  
	  		  }

	  	  }

	      //System.out.println(line);
	    }
		
		//updates the personal map for each place
		for(Place p: map.values()) {
			p.updateMap(map);
		}
		
		//closes scanner
		input.close();
	}
	
	
	
	//adds a place to the vector of places contained by the game
	public void addPlace (Place place) {
		places.addElement(place);
		
	}
	
	//gets the current place
	public Place getCurrentPlace() {
		return currentPlace;
	}
	
	//print function for debugging purposes
	public void print() {
		//NEEDS WORK
		System.out.println("Name"+ gameName);
		System.out.println("Current Place"+ currentPlace);
		for(Place p: places) {
			System.out.print("Place:"+ p.name());
		}
		
		for(Artifact a: inventory) {
			System.out.print("Artifact:"+ a.name());
		}
		
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
			String tokens[] = s.split("\\s+");
			
			String firstword = tokens[0].toUpperCase();
			
			//code to quit if input triggers it
			if( firstword.equals("QUIT") || firstword.equals("EXIT") || currentPlace.name().equals("Exit") ) {
				System.out.println("EXITING...");
				scanner.close();
				gameover = true;
				break;
			}
			
			//displays the description of current room if user inputs "LOOK"
			else if( firstword.equals("LOOK") ) {
				
				currentPlace.display();
			}
			
			//changes place if user types in "GO X" where X is a valid direction
			else if(firstword.equals("GO")) {
				
				//takes in the inputted direction and changes the place to follow that inputted direction
				currentPlace = currentPlace.followDirection(tokens[1].toUpperCase());
				System.out.println ("You have entered: "+ currentPlace.name() );
				
				
			}
			
			//adds artifact to inventory
			else if(firstword.equals("GET")) {
				//get artifact

				//checks if it exists and is current attainable
				boolean exists = false;
				boolean isInRoom = false;;
				String artifactName = tokens[1];
				
				if(tokens.length == 3) {
					artifactName.concat(tokens[2]);
				}
				
				Vector<Artifact> currPlaceArts = currentPlace.getArtifacts();
				
				for(Artifact a: currPlaceArts ) {
					if( (a.name().equals(artifactName)) ) {
						exists = true;
					}
				}
				
				for(Place p: map.values()) {
					if(p.checkIfArtifactExists(artifactName)) {
						isInRoom = true;
					}
				}
				
				//if its attainable, removes it from room and adds it to inventory
				if(exists && isInRoom) {
					inventory.add(currentPlace.removeArtifact(artifactName));
				}
				else {
					System.out.print("Could not add artifact to inventory");
				}
				
				
			}
			
			//drops artifact
			else if(firstword.equals("DROP")) {
				//drop artifact
				
				//checks if artifact input is valid
				boolean valid = false;
				
				String artifactName = tokens[1];
				
				if(tokens.length == 3) {
					artifactName.concat(tokens[2]);
				}
				
				//if its valid, drops item
				for(Artifact a: inventory) {
					if(a.name().equals(artifactName)) {
						currentPlace.addArtifact(a);
						inventory.remove(a);
						valid = true;
						break;
					}
				}
				
				if(!valid) {
					System.out.print("Could not drop item");
				}

			}
			
			//uses the artifact
			else if(firstword.equals("USE")) {
				//user artifact

				boolean found = false;
				
				String artifactName = tokens[1];
				
				if(tokens.length == 3) {
					artifactName.concat(tokens[2]);
				}
				
				//if its valid, uses the artifact
				for(Artifact a: inventory ) {
					if( (a.name().equals(artifactName)) ) {
						a.use();
						found = true;
					}
				}
				
				//otherwise prints error message
				if (!found) {
					System.out.println("Couldnt find artifact with that name");
				}
				
				
			}
			
			else if(firstword.equals("INVE") || firstword.equals("INVENTORY")) {
				//list all artifacts in possesion along with total value and total mobility

				for(Artifact a: inventory) {
					a.display();
				}
				
			}
			
			//guides user how to put in input if they have done so incorrectly
			else {
				System.out.println("Incorrect input. Please Enter 'LOOK' , 'GO X' (where X is N, S, E, W, U, D) or 'EXIT' or 'QUIT' ");
				System.out.println("Or input: 'GET x', 'DROP x' , 'USE x' or 'INVE' where x is the fullname of an artifact");
			}
			
			
		}
		scanner.close();
		
	}
}
