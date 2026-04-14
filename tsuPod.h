
#ifndef TSUPOD_H
#define TSUPOD_H

#include "Song.h"

struct Node
{
    Song song;
    Node* next;
};

class TsuPod
{
private:
    Node* head;
    int maxMemory;
    int usedMemory;
public:
    TsuPod(int memory);
    ~TsuPod();

    int addSong(const Song& s);
    int removeSong(const Song& s);
    void showSongList() const;
    void sortSongList();
    void shuffle();
    void clearSongList();
    int getTotalMemory() const;
    int getRemainingMemory() const;

};

#endif // TSUPOD_H