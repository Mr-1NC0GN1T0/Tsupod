#include <iostream>
#include "tsuPod.h"
#include "Song.h"
using namespace std;

int main() {
    // verifying initialization and empty state
    cout << "--- TEST: Initialization ---" << endl;
    TsuPod myPod(100); 
    cout << "Memory Cap set to: " << myPod.getTotalMemory() << "MB" << endl;
    cout << "Initial Remainder: " << myPod.getRemainingMemory() << "MB" << endl << endl;

    // adding songs and checking the math on memory usage
    cout << "--- TEST: Adding Songs & Memory Update ---" << endl;
    Song s1; s1.setTitle("Humble"); s1.setArtist("Kendrick Lamar"); s1.setSize(10);
    Song s2; s2.setTitle("Bad"); s2.setArtist("Michael Jackson"); s2.setSize(12);
    Song s3; s3.setTitle("Bad"); s3.setArtist("Michael Jackson"); s3.setSize(5); // testing size tiebreaker
    Song s4; s4.setTitle("Humble"); s4.setArtist("A-List Artist"); s4.setSize(8); // testing artist tiebreaker

    myPod.addSong(s1);
    myPod.addSong(s2);
    myPod.addSong(s3);
    myPod.addSong(s4);
    
    myPod.showSongList();
    cout << "Remaining Space (Should be 65): " << myPod.getRemainingMemory() << "MB" << endl << endl;

    // testing the extra credit sort and tiebreaker logic
    cout << "--- TEST: Sorting Tiebreakers ---" << endl;
    myPod.sortSongList();
    myPod.showSongList(); 

    // checking memory after removing a song
    cout << "--- TEST: Memory Update after Removal ---" << endl;

    cout << "\nRemoved " << s1.getTitle() << " | " 
             << s1.getArtist() << " | " 
             << s1.getSize() << "MB" << endl << endl;
    myPod.removeSong(s1); // Kendrick (10MB)
    myPod.showSongList(); 
    cout << "\nRemaining Space (Should be 75): " << myPod.getRemainingMemory() << "MB" << endl;

    // final check on clearing the pod
    cout << "\n--- TEST: Memory Update after Clear ---" << endl;
    myPod.clearSongList();
    cout << "Remaining Space (Should be 100): " << myPod.getRemainingMemory() << "MB" << endl;

    return 0;
}