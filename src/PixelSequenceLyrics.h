#pragma once

#include <string>
#include <vector>

struct Lyric {
    // How long to delay() before rendering this line
    // delay(CurrentMS - msdelay)
    int msdelay = 0;
    std::string line;
    int mscompletion = 0; //<- How much MS max rendering this line can take
};

extern std::string qLyricAuthor;
extern std::vector<Lyric> qLyrics;

bool qLyricsInit();

bool qLyricsInitSpotifyID(std::string spotify_id);

bool qLyricsRun(int currentms = 0);

inline std::string qLyricsGetAuthor() {
    return qLyricAuthor;
}