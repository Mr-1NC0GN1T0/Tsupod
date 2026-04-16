#include <iostream>
#include "tsuPod.h"
#include "Song.h"

using namespace std;

int main() {
    // 1. Initialization and Total Memory Test
    // Testing initialization with a storage size of 100MB
    TsuPod myPod(100);
    cout << "--- Test: Total Memory Display ---" << endl;
    cout << "Total Memory (Expected 100): " << myPod.getTotalMemory() << "MB" << endl << endl;

    // 2. Successful song addition with tiebreaker cases
    cout << "--- Test: Successful Additions (Including Tiebreakers) ---" << endl;
    
    Song s1; s1.setTitle("Humble"); s1.setArtist("Kendrick Lamar"); s1.setSize(10);
    Song s2; s2.setTitle("Thriller"); s2.setArtist("Michael Jackson"); s2.setSize(15);
    Song s3; s3.setTitle("Humble"); s3.setArtist("Kendrick Lamar"); s3.setSize(5); // Size tiebreaker
    Song s4; s4.setTitle("Humble"); s4.setArtist("A-List Artist"); s4.setSize(8); // Artist tiebreaker

    myPod.addSong(s1);
    myPod.addSong(s2);
    myPod.addSong(s3);
    myPod.addSong(s4);
    
    myPod.showSongList(); //
    cout << endl;

    // 3. Unsuccessful song addition
    // Testing memory limit and blank input rejection
    cout << "--- Test: Unsuccessful Additions ---" << endl;
    Song sBad; sBad.setTitle(""); sBad.setArtist("Unknown"); sBad.setSize(5);
    cout << "Blank title result (Expected -2): " << myPod.addSong(sBad) << endl;

    Song sHuge; sHuge.setTitle("Big"); sHuge.setArtist("Big"); sHuge.setSize(200);
    cout << "Exceed memory result (Expected -1): " << myPod.addSong(sHuge) << endl << endl;

    // 4. Dedicated Remaining Memory Test
    cout << "--- Test: Remaining Memory ---" << endl;
    cout << "Remaining (100 - 38 used = 62): " << myPod.getRemainingMemory() << "MB" << endl << endl;

    // 5. Sorting functionality (Testing Title > Artist > Size)
    cout << "--- Test: Sorting (Alphabetical Title, then Artist, then Size) ---" << endl;
    myPod.sortSongList();
    myPod.showSongList();
    cout << endl;

    // 6. Shuffle functionality
    cout << "--- Test: Shuffle ---" << endl;
    myPod.shuffle();
    myPod.showSongList();
    cout << endl;

    // 7. Removal tests (Successful and Unsuccessful)
    cout << "--- Test: Removal ---" << endl;
    int remSuccess = myPod.removeSong(s2);
    cout << "Remove 'Thriller' result (Expected 0): " << remSuccess << endl;
    
    Song sMissing; sMissing.setTitle("No"); sMissing.setArtist("No"); sMissing.setSize(1);
    int remFail = myPod.removeSong(sMissing);
    cout << "Remove non-existent result (Expected -1): " << remFail << endl << endl;

    // 8. Clearing the song list and final memory check
    cout << "--- Test: Clear Song List ---" << endl;
    myPod.clearSongList();
    cout << "Remaining Memory after clear (Expected 100): " << myPod.getRemainingMemory() << "MB" << endl;

    return 0;
}