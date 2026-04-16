#ifndef TSUPOD_H
#define TSUPOD_H

#include "Song.h"

// each node holds a song and a pointer to the next node
struct Node
{
    Song song;
    Node* next;
};

// TsuPod manages a song collection using a linked list
class TsuPod
{
private:
    Node* head;       // pointer to first node
    int maxMemory;    // max storage in MB
    int usedMemory;   // current used storage in MB

public:
    TsuPod(int memory);  // constructor
    ~TsuPod();           // destructor - frees all nodes

    int addSong(const Song& s);      // returns 0, -1, or -2
    void insertSong(Node*& sortedHead, Node* newNode);
    int removeSong(const Song& s);   // returns 0 or -1
    void showSongList() const;       // prints all songs
    void sortSongList();             // sorts by title, artist, size
    void shuffle();                  // randomizes order
    void clearSongList();            // removes all songs
    int getTotalMemory() const;      // returns max capacity
    int getRemainingMemory() const;  // returns available memory
};

#endif // TSUPOD_H