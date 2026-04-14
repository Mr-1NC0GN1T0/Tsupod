#include "tsuPod.h"
#include <iostream>


//initializing 
TsuPod::TsuPod(int memory) {
    head = nullptr;
    maxMemory = memory;
    usedMemory = 0;
}

// calling clearsongList 
TsuPod::~TsuPod() {
    clearSongList(); 
}

//adding the song while checking if inputs are valid
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

    //use Linked lists to add songs to the list
    Node* newNode = new Node();
    newNode->song = s;
    newNode->next = nullptr;
    newNode->next = head;
    head = newNode;

    //update memory
    usedMemory += s.getSize();

    return 0;    
    
}

int TsuPod::removeSong(const Song& s){
    Node* current = head;
    Node* previous = nullptr;
    while(current!=nullptr){
        if(current->song == s){
            if (previous == nullptr)
            {
                head = current->next;
            }
            if (previous != nullptr)
            {
                previous->next = current->next;
            }
            usedMemory -= s.getSize();
            delete current;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
    
}
