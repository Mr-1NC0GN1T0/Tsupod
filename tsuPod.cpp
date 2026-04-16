#include "tsuPod.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//empty pod
TsuPod::TsuPod(int memory) {
    head = nullptr;
    maxMemory = memory;
    usedMemory = 0;
}

//destructor
TsuPod::~TsuPod() {
    clearSongList();
}

// adding the song to the front if it fits
int TsuPod::addSong(const Song& s){
    if (s.getTitle() == "" || s.getArtist() =="" || s.getSize() <= 0)
        return -2;

    if (usedMemory + s.getSize() > maxMemory)
        return -1;

    Node* newNode = new Node();
    newNode->song = s;
    newNode->next = head;
    head = newNode;

    usedMemory += s.getSize();
    return 0;
}

// find a song and remove it from the list
int TsuPod::removeSong(const Song& s){
    Node* current = head;
    Node* previous = nullptr;
    while(current != nullptr){
        if(current->song == s){
            if (previous == nullptr)
                head = current->next;
            else
                previous->next = current->next;
                
            usedMemory -= current->song.getSize();
            delete current;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

//clear out the whole list
void TsuPod::clearSongList(){
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    usedMemory = 0;
}


// print the whole list
void TsuPod::showSongList() const {
    Node* current = head;
    if (current == nullptr) {
        cout << "Song list is empty." << endl;
        return;
    }
    while (current != nullptr) {
        cout << current->song.getTitle() << " | " 
             << current->song.getArtist() << " | " 
             << current->song.getSize() << "MB" << endl;
        current = current->next;
    }
}



int TsuPod::getTotalMemory() const {
    return maxMemory;
}

int TsuPod::getRemainingMemory() const {
    return maxMemory - usedMemory;
}

// wedge a node into the right alphabetical spot
void TsuPod::insertSong(Node*& sortedHead, Node* newNode) {

    // if list is empty or newNode belongs at the very front
    if (sortedHead == nullptr || newNode->song < sortedHead->song) {
        newNode->next = sortedHead;
        sortedHead = newNode;
    } 
    else {

        // if not then find the insertion point
        Node* curr = sortedHead;
        while (curr->next != nullptr && curr->next->song < newNode->song) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

//sorting in order 
void TsuPod::sortSongList() {
    if (head == nullptr || head->next == nullptr) return;

    Node* sortedHead = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next; // Save pointer to the rest of the unsorted list
        insertSong(sortedHead, curr); // Insert current node into the new list
        curr = nextNode;
    }

    head = sortedHead; // Point tsuPod head to the new sorted list
}

//shuffles in random order
void TsuPod::shuffle() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (count < 2) return;

    srand(time(0));

    // Repeat the random swapping multiple times for better randomness
    for (int i = 0; i < count * 3; i++) {
        // Pick two random nodes
        int r1 = rand() % count;
        int r2 = rand() % count;

        Node* n1 = head;
        for (int j = 0; j < r1; j++) n1 = n1->next;

        Node* n2 = head;
        for (int j = 0; j < r2; j++) n2 = n2->next;

        // Swap the song data
        Song tempSong = n1->song;
        n1->song = n2->song;
        n2->song = tempSong;
    }
}