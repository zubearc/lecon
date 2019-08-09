#include "PixelSequenceLyrics.h"
#include "PixelSequences.h"
#include "Util.h"

std::string qLyricAuthor = "?";
std::vector<Lyric> qLyrics;

bool _qLyricsInit(std::stringstream &ws) {
    if (!ws) {
        return false;
    }

    qLyricAuthor = "?";
    qLyrics = {};

    String author;
    std::getline(ws, author);
    String title;
    std::getline(ws, title);

    qLyricAuthor = author;
    printf("LOADED LYRIC, %s\n", qLyricAuthor.c_str());

    String line;
    while (std::getline(ws, line)) {
        std::stringstream linestrm(line);
        std::string ts;
        std::getline(linestrm, ts, '$');
        std::string lyric;
        std::getline(linestrm, lyric);

        qLyrics.push_back({ std::stoi(ts), lyric, 0 });
        // printf("LYRIC: %s $ %s\n", ts.c_str(), lyric.c_str());
    }

    for (int i = 0; i < qLyrics.size(); i++) {
        auto &lyric = qLyrics[i];
        if ((i + 1) < qLyrics.size()) {
            auto next = qLyrics[i + 1];
            auto completeby = abs(next.msdelay - lyric.msdelay);
            lyric.mscompletion = next.msdelay;
            // printf("complete by: %d\n", lyric.mscompletion);
        }
    }
    return true;
}

bool qLyricsInit() {
    auto ws = slurps("../data/lyrics.txt");
    return _qLyricsInit(ws);
}

bool qLyricsInitSpotifyID(std::string spotify_id) {
    auto ws = slurps("../data/lyrics_" + spotify_id + ".txt");
    if (!ws) {
        printf("../data/lyrics_%s.txt was not found, not playing lyrics.\n", spotify_id.c_str());
        return false;
    } else {
        printf("FOUND.\n");
    }
    return _qLyricsInit(ws);
}

bool qLyricsRun(int currentms) {
    auto idelay = qLyrics[0].msdelay - currentms;

    long long late_correction = 0;

    if (idelay < 0) {
        late_correction = idelay*-1;
        printf("late_correction=%lld\n", late_correction);
    } else {
        delay(idelay);
    }

    printf("%d - %d = %d sleep\n", qLyrics[0].msdelay, currentms, idelay);
    // long long last_delay = 0;
    for (auto lyric : qLyrics) {
        auto starttime = CurrentTimeMS();
        // last_delay = lyric.msdelay;
        // if (last_delay)
        // delay(lyric.msdelay);
        // flush(); write(lyric.line, 0x20); render();
            // printf("complete by: %d\n", lyric.mscompletion);

        long long display_time = lyric.mscompletion - late_correction;

        printf("disp for %d\n", display_time);

        writeFlashingTimed(lyric.line, 0xF1, MAX(10, display_time));

        auto curtime = CurrentTimeMS();

        if (display_time < 0) {
            // late_correction = ((curtime - starttime) - lyric.mscompletion) + (display_time*-1); // Time correction
            late_correction = ((curtime - starttime) - 10) + display_time * -1;
        } else {
            late_correction = ((curtime - starttime) - display_time);
        }


        printf("Lyrics: Correction (%lld) %d seconds\n", (curtime - starttime), late_correction);
    }
    return true;
}