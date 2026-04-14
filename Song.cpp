#include "Song.h"

void Song::setTitle(string newTitle) {
    title = newTitle;
}
void Song::setArtist(string newArtist) {
    artist = newArtist;
}
void Song::setSize(int newSize) {
    size = newSize;
}

string Song::getTitle() const {
    return title;
}
string Song::getArtist() const {
    return artist;
}
int Song::getSize() const {
    return size;
}

bool Song::operator==(const Song& s) const {
    if (title == s.title && artist == s.artist && size == s.size){
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator<(const Song& s) const {
    if (title < s.title) {
        return true;
    }
    else if (title == s.title) {
        if (artist < s.artist) {
            return true;
        }
        else if (artist == s.artist) {
            if (size < s.size) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Song::operator>(const Song& s) const {
    if (title > s.title) {
        return true;
    }
    else if (title == s.title) {
        if (artist > s.artist) {
            return true;
        }
        else if (artist == s.artist) {
            if (size > s.size) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}