struct Node
{
    Song song;
    Node* next;
};

class Tsupod
{
private:
    Node* head;
    int maxMemory;
    int usedSize;
public:
    Tsupod(int memory);
    ~Tsupod();

    int addSong(const Song& s);
    int removeSong(const Song& s);
    void showSongList() const;
    void sortSongList();
    void shuffle();
    void clearSongList();
    int getTotalMemory() const;
    int getRemainingMemory() const;

};