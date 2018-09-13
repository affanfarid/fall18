//Name: Affan Farid
//UIN: 671466593
//NetID: afarid4
//
//CS 342 HW 1

public class GameTester {
	
	public static void printInfo() {
		//method for displaying identifying info
		System.out.println("Affan Farid\nUIN:671466593\n");
	}
	
	public static void main(String args[]) {
		
		printInfo();
		
		//initializes game
		String gamename = "game1";
		Game game = new Game(gamename);
		
		//hard coding the Six Places example
		Place entranceHall = new Place(12,"Entrance Hall",
				"*You are standing in the entrance hall of the great six-room dungeon\n" + 
				"*There are doors to the east and north, and a stairway leading down\n" + 
				"*The main exit ( from the game ) is to the west"
		);
		
		
		Place ogresLair = new Place(13,"Ogre's Lair",
				"*You have entered the Ogre's Lair!  Better leave before he wakes up . . .\n" + 
				"*There are doors to the south and the east"
		);
		
		Place treasureStoreroom = new Place(23,"Treasure Storeroom",
				"*You have found a storeroom full of gold, jewels, and treasure!\n" + 
				"*There are doors to the north and south."
		);
		
		Place poolEnchantment = new Place(22,"Pool of Enchantment",
				"*You are in a round room with a clear enchanting pool of water.\n" + 
				"*There are doors to the north and west.\n" + 
				"*There is a slide leading downwards to the floor below."
		);
		
		Place potionsLab = new Place(21,"Potions Lab",
				"*There is a cauldron of thick green goop here, \n" + 
				"*bubbling slowly over a cool blue flame.\n" + 
				"*Doors lead to the west and east."
		);
		
		Place potionsStoreroom = new Place(11,"Potions Storeroom",
				"*This room has shelves full of bottles and jars\n" + 
				"*Some labels read \"Powdered bat's wings\" and \"Toad eyes\".\n" + 
				"*There is a door to the east, and a stairway leading up."
		);
		
		Place exit = new Place(0,"Exit","The exit");
		
		//adds places to the actual game
		game.addPlace(entranceHall);
		game.addPlace(ogresLair);
		game.addPlace(treasureStoreroom);
		game.addPlace(poolEnchantment);
		game.addPlace(potionsLab);
		game.addPlace(potionsStoreroom);
		
		//adds respective directions to each place
		entranceHall.addDirection(new Direction(4,entranceHall, ogresLair, "N") );
		entranceHall.addDirection(new Direction(8,entranceHall, poolEnchantment, "E") );
		entranceHall.addDirection(new Direction(7,entranceHall, exit, "W") );
		entranceHall.addDirection(new Direction(10,entranceHall, potionsStoreroom, "D") );
		
		ogresLair.addDirection(new Direction(2,ogresLair, treasureStoreroom, "E") );
		ogresLair.addDirection(new Direction(3,ogresLair, entranceHall, "S") );
		
		treasureStoreroom.addDirection(new Direction(1,treasureStoreroom, ogresLair, "N") );
		treasureStoreroom.addDirection(new Direction(6,treasureStoreroom, poolEnchantment, "S") );
		
		poolEnchantment.addDirection(new Direction(5,poolEnchantment, treasureStoreroom, "N",true) ); //LOCKED
		poolEnchantment.addDirection(new Direction(9,poolEnchantment, entranceHall, "W") );
		poolEnchantment.addDirection(new Direction(12,poolEnchantment, potionsLab, "D") );
		
		potionsStoreroom.addDirection(new Direction(11,potionsStoreroom, entranceHall, "U") ); 
		potionsStoreroom.addDirection(new Direction(14,potionsStoreroom, potionsLab, "E",true) ); //LOCKED
		
		potionsLab.addDirection(new Direction(13,potionsLab, null, "E",true) ); //LOCKED
		potionsLab.addDirection(new Direction(15,potionsLab, potionsStoreroom, "W") );
		
		
		
		
		
		
		//Starts game
		System.out.println("STARTING GAME\n");
		
		game.play();
		
		
		
	}

}
