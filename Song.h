//file header for Song class


#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song
{
private:
    string title;
    string artist;
    int size;
public:
    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setSize(int newSize);

    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    bool operator==(const Song& s) const;
    bool operator<(const Song& s) const;
    bool operator>(const Song& s) const;
};

#endif // SONG_H