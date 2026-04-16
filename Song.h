#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

// Song class - stores title, artist, and size of a song
class Song
{
private:
    string title;   // song name
    string artist;  // artist name
    int size;       // size in MB

public:
    // setters
    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setSize(int newSize);

    // getters
    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    // compare two songs by title, then artist, then size
    bool operator==(const Song& s) const;
    bool operator<(const Song& s) const;
    bool operator>(const Song& s) const;
};

#endif // SONG_H