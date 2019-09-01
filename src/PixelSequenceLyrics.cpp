#include "PixelSequenceLyrics.h"
#include "PixelSequences.h"
#include "Util.h"

#include "WindowManager.h"

std::string qLyricAuthor = "?";
std::vector<Lyric> qLyrics;

bool _qLyricsInit(std::stringstream &ws) {
    if (!ws) {
        return false;
    }

    qLyricAuthor = "?";
    qLyrics = {};

    int color = 0xaa;

    String author;
    std::getline(ws, author);
    String title;
    std::getline(ws, title);

    qLyricAuthor = author;
    printf("LOADED LYRIC, %s\n", qLyricAuthor.c_str());

    if (author == "1FlAMUpKrjY4NdaqsXjl1w") {
        color = 0x2000F0;
    } else if (author == "0PiRp1VzEBHp68wY1M7zMs") {
        // color = 0x200000;
        color = 0xD0;
    } else if (author == "3JPXFD2aJ4dHPMnGwo41bO") {
        color = 0xFF071585;
    }
    
    String line;
    while (std::getline(ws, line)) {
        std::stringstream linestrm(line);
        std::string ts;
        std::getline(linestrm, ts, '$');
        std::string lyric;
        std::getline(linestrm, lyric);

        auto col = color;

        // Color randomizer
        if (!color) {
            auto red = randr(0x10, 100);
            auto green = randr(0x10, 100);
            auto blue = randr(0x10, 100);
            col = pack(0x10, blue, green, red);
            // color = 0xAA;
        }

        qLyrics.push_back({ std::stoi(ts), lyric, 0, col });
        // printf("LYRIC: %s $ %s\n", ts.c_str(), lyric.c_str());
    }

    for (int i = 0; i < qLyrics.size(); i++) {
        auto &lyric = qLyrics[i];
        if ((i + 1) < qLyrics.size()) {
            auto next = qLyrics[i + 1];
            auto completeby = abs(next.msdelay - lyric.msdelay);
            lyric.mscompletion = next.msdelay;
            // printf("complete by: %d\n", lyric.mscompletion);
        } else {
            lyric.mscompletion = 3000;
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
    wLimitWriteRegion(WIDTH - 15, 8);
    auto idelay = qLyrics[0].msdelay - currentms;

    long long late_correction = 0;

    if (idelay < 0) {
        late_correction = idelay*-1;
        printf("late_correction=%lld\n", late_correction);
    } else {
        delay(idelay);
    }

    printf("%d - %d = %d sleep\n", qLyrics[0].msdelay, currentms, idelay);
    std::string lasttext = "";
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

        // fprintf(stderr, "[%s]",lyric.line.c_str());
        if (lyric.line == "" && lasttext != "") {
            // writeFlashingTimed(lasttext, 0, MAX(10, display_time / 2));
            wipe(MAX(10, display_time / 2));
            writeFlashingTimed(lyric.line, 0, MAX(10, display_time / 2), true);
        } else {
            writeFlashingTimed(lyric.line, /*0xF1*/lyric.color, MAX(10, display_time), true);
        }
        lasttext = lyric.line;

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