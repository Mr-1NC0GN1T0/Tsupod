#include "tsuPod.h"
#include <iostream>

TsuPod::TsuPod(int memory) {
    head = nullptr;
    maxMemory = memory;
    usedMemory = 0;
}
TsuPod::~TsuPod() {
    clearSongList(); 
}
int TsuPod::addSong(const Song& s){
    if (
        s.getTitle() == "" || s.getArtist() =="" || s.getSize() <= 0
    )
    {

        return -2;
    }
    if (usedMemory + s.getSize() > maxMemory)
    {
        return -1;
    }

    Node* newNode = new Node();
    newNode->song = s;
    newNode->next = nullptr;
    newNode->next = head;
    head = newNode;
    
    
    
    
}