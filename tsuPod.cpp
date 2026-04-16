#include "tsuPod.h"
#include <iostream>
#include <ctime>


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

void TsuPod::clearSongList(){
    Node* current = head;
    while (current!=nullptr)
    {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    usedMemory = 0;
    
}

void TsuPod::showSongList() const {
    Node* current = head;
    while (current!=nullptr)
    {
        cout << current->song.getTitle() << " | " << current->song.getArtist() << " | " << current->song.getSize() << "MB" << endl;
        current = current->next;
    }
    
}

int TsuPod::getTotalMemory() const {
    return maxMemory;
}

int TsuPod::getRemainingMemory()const {
    return maxMemory - usedMemory;
}

void TsuPod::sortSongList(){

    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node* previous = head;
        Node* current = previous->next;
        while (current!=nullptr)
        {
            if (previous->song > current->song)
            {
                Song temp = previous->song;
                previous->song = current->song;
                current->song = temp;
                swapped = true;
            }
            previous = current;
            current = current->next;
        }
    }
}

void TsuPod::shuffle(){
    int count = 0;
    Node* temp = head;

    //counting the number of songs
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    if (count < 2) return;

    //random number generator
    srand(time(0));

    Node* current = head;
    while (current != nullptr)
    {
        // get a random node
        int r = rand() % count;
        Node* target = head;
        for (int i = 0; i < r; i++)
        {
            target = target->next;
        }

        Song temp = current->song;
        current->song = target->song;
        target->song = temp;

        current = current->next;
    }
}