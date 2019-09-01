#include <vector>
#include <string>

#include "InterfaceSpotify.h"
#include "WebGet.h"
#include "Util.h"
#define PICOJSON_USE_INT64
#include "picojson.h"
#include "PixelSequences.h"
#include "PixelSequenceLyrics.h"

std::string api_key = "";

std::string last_playing_id = "";

const std::string SpotifyAPINowPlayingEndpoint = "https://api.spotify.com/v1/me/player/currently-playing";

void iSpotifyInit() {
    api_key = slurp("../data/spotify_apikey.txt");
    printf("Got %d len API key\n", api_key.size());
}

void iSpotifyNPLTick() {
    auto init_time = CurrentTimeMS();
    WebGet webget;
    std::vector<std::string> h = { "Accept: application/json", "Content-Type: application/json", "Authorization: Bearer " + api_key };
    auto json = webget.Get(SpotifyAPINowPlayingEndpoint, h);
    // printf("Spot: %s\n", json.c_str());

    picojson::value v;
    std::string err = picojson::parse(v, json);
    if (!err.empty()) {
        // printf("Spot: %s\n", json.c_str());
        // printf("ispot: Failed to parse JSON.\n");
        return;
        // std:cerr << err << std::endl;
    }

    picojson::object &o = v.get<picojson::object>();

    if (!o["error"].is<picojson::null>()) {
        printf("Spot: %s\n", json.c_str());
        printf("ispot: Request failed.\n");
        return;
    }

    if (!o["item"].is<picojson::null>()) {
        auto timestamp = o["timestamp"].get<int64_t>();
        auto cprogres = o["progress_ms"].get<int64_t>();

        auto item = o["item"].get<picojson::object>();
        // printf("Item: %s\n", item["name"].serialize().c_str());
        auto np_id = item["id"].get<std::string>();
        if (np_id == last_playing_id) {
            return;
        } else {
            last_playing_id = np_id;
        }

    printf("cp is %d", childThreadPID);

        killChildThread();
        programMode = DisplayingDefault;

        auto np_name = item["name"].get<std::string>();
        printf("Now Playing: %s\n", np_name.c_str());

        // auto have_lyrics = qLyricAuthor == np_id;

        // if (!have_lyrics) {
        //     have_lyrics = qLyricsInitSpotifyID(np_id);
        // }

        auto have_lyrics = qLyricsInitSpotifyID(np_id);

        if (have_lyrics) {
            printf("HAVE THE LYRICS FOR THE SONG!\n");
            auto curtime = CurrentTimeMS();
            // timestamp appears to be wrong in API
            // https://github.com/spotify/web-api/issues/640
            // auto tdelta = curtime - timestamp;
            auto tdelta = curtime - init_time;
            // auto tdelta2 = timestamp - curtime;
            auto newdelay = cprogres + tdelta;
            printf("Delay for curtime(%lld)-timestamp(%lld)=%lld, %lld - %lld=%lld\n", curtime, timestamp, tdelta, cprogres, tdelta, newdelay);
            executeOnChildThread([&]() {
                qLyricsRun(newdelay);
                programMode = DisplayingDefault;
            });
            printf("PROG MODE IS NOW BLOCK!!!\n");
            programMode = Minimal;
        } else {
            // printf("(%s != %s)\n", qLyricAuthor.c_str(), np_id.c_str());
            // writeScrollable("NP", 0x2F00, 500);
            // for (int i = 16; i < 48; i++) {
            //     if ((i % 2) == 0)
            //         draw(i, 0, 0x2000);
            //     // else
            //     //     draw(i, 7, 0x2000);
            // }
            flushLeft();
            write("NP", 0x2000);
            render();
            delay(1000);
            // writeScrollable(np_name, 0x2F00, 100);
            delay(500);
        }

        // writeScrollable("NP", 0x2F00, 500);
    }

    // std::cout << "Spot: " << json << std::endl;
}