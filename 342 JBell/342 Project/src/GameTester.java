//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 2
import java.io.File;
import java.io.IOException;
import java.util.*;

public class GameTester {
	
	public static void printInfo() {
		//method for displaying identifying info
		System.out.println("Affan Farid\nUIN:671466593\nNet id: afarid4\n");
	}
	
	//initializes game
	public static Game initGame() {
		boolean breaker = false;
		Game game = null;
		
		//initializes scanner input
		Scanner input = new Scanner(System.in);
		
		//continually asks for file name
		while (!breaker) {
			System.out.print("Enter the full file path with extension : ");
			
			//used for testing
			//String filePathStart = "/Users/affanfarid/eclipse-workspace/342 Project/src/";
			
			String nextLine = input.nextLine();

			//File file = new File(filePathStart + nextLine);
			
			//takes in input path 
			File file = new File( nextLine);

			//checks if file is valid
			if (file.isFile() && file.canRead()) {
				  try {

					  
					  //breaks loop if file is found
					  breaker = true;
					  try {
						  //fileInput = new Scanner(file);
						  
						  //changes scanner input to read from the file
						  input = new Scanner(file);
						  
						  //initializes game and plays it
						  game = new Game(input);
						  game.play();
						  
						  //closes scanner
						  input.close();
						  
					  }
					  finally {
						  //closes input
						  input.close();

					  }

				  }

				  //prints error message if input is not a file
				  catch (IOException ex) {
					  System.out.println("Not a file, try again");
					  
				  }
				
			}
			
			//quits program if input is quit
			else if(nextLine.toUpperCase().equals("QUIT")) {
				System.out.println("Program Quit");
				breaker = true;
				
			}
			//prints error message in other instance
			else {
				System.out.println("Not a file, try again");
				
			}

		}
		
		//closes input
		input.close();
		
		return game;
		
		
	}
	
	public static void main(String args[]) {
		
		//prints my personal info
		printInfo();
		
		//initializes and plays game
		Game game = initGame();


	}

}
