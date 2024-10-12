# Player-Management-System

  This is a C program that allows users to manage information about players, including details such as jersey number, name, number of matches played, runs scored, and wickets taken. The program supports functionalities like adding, displaying, searching, updating, and removing player records.

**Features**
- Add Player Information: Insert details of players, including jersey number, name, matches played, runs, and wickets.
- Display Player Information: View all player records.
- Search Player: Find players by jersey number or name.
- Remove Player: Delete player records based on jersey number or name.
- Update Player Information: Modify existing player details.
- Sort Players: Sort player records by runs, wickets, or jersey number in ascending or descending order.

**Prerequisites**
- C compiler (e.g., GCC)
- Basic understanding of C programming and data structures

**Usage**

Upon running the program, you will see a menu with the following options:
- Insert player Information
- Display player Information
- Search Player
- Remove Player
- Update Player Information
- Sort player
- Exit

**Code Structure**

Player Structure:
  
  - Defines the player's details.

Functionality:
- storeInfo: Store player information.
- displayInfo: Display all player records.
- searchByName: Search for a player by name.
- searchByJerseyNo: Search for a player by jersey number.
- removePlayer: Remove a player from records.
- updatePlayer: Update player details.
- sortByRuns, sortByWickets, sortByJerseyNo: Sort players by specified criteria.

**Memory Management**
 
  The program dynamically allocates memory for player records and supports increasing memory allocation as needed.
