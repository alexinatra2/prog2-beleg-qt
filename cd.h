#ifndef CD_H
#define CD_H

#include "medium.h"
#include <string>

class Cd : public Medium
{
public:
    explicit Cd(QObject *parent = nullptr);
    std::string GetArtist() {
        return this->_artist;
    }
    void SetArtist(std::string artist) {
        this->_artist = artist;
    }
    int GetTracks() {
        return this->_tracks;
    }
    void SetTracks(int tracks) {
        this->_tracks = tracks;
    }
    double GetLength() {
        return this->_length;
    }
    void SetLength(double length) {
        this->_length = length;
    }
    std::ostream &Show(std::ostream &os) {
        os << "type: " << GetType() << '\n';
        os << "title: " << GetTitle() << '\n';
        os << "artist: " << GetArtist() << '\n';
        os << "number of tracks: " << GetTracks() << '\n';
        os << "total length in minutes: " << GetLength();
        os << "description: " << GetDescription();
        return os;
    }

public:
    std::string _artist;
    int _tracks;
    double _length;
};

#endif // CD_H
