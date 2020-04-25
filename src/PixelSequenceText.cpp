#include <vector>

#include "PixelSequenceText.h"
#include "PixelSequences.h"
#include "Util.h"
#define PICOJSON_USE_INT64
#include "picojson.h"

struct SequenceLine {
	std::string text;
	int fontCode = 0;
	int delay = 1000;
	bool center = true;
};

std::vector<SequenceLine> sequenceLines;

bool qTextInit() {
	auto data = slurp("../data/sequence.json");
	printf("Read %d sequence bytes\n", data.size());

	picojson::value v;
	std::string err = picojson::parse(v, data);
	if (!err.empty()) {
		printf("qtext: Failed to parse JSON.\n");
		fprintf(stderr, "%s", err.c_str());
		// std:cerr << err << std::endl;
		return false;
	}

	picojson::object &o = v.get<picojson::object>();

	if (o["v"].is<picojson::null>()) {
		printf("qtext: Not a valid sequence JSON file\n");
		return false;
	}

	auto version = o["v"].get<int64_t>();
	if (version != 1) {
		printf("qtext: invalid version, must be 1: %lld\n", version);
		return false;
	}

	// printf("ok\n");

	auto lines = o["lines"].get<picojson::array>();

	for (picojson::array::iterator it = lines.begin(); it != lines.end(); it++) {
		auto &line = it->get<picojson::object>();

		auto text = line["text"].get<std::string>();
		auto font = line["font"].get<int64_t>();
		auto delay= line["delay"].get<int64_t>();

		printf("[qtext] line='%s', font=%d, delay=%d\n", text.c_str(), font, delay);
		sequenceLines.push_back({ text, font, delay });
	}

	return true;
}

bool qTextRun() {
	printf("qTextRun for %d lines\n", sequenceLines.size());
	for (auto seq : sequenceLines) {
            // write("PARKCHESTER", 0x20, 0xffff, 0, FontType::Old);
		flush();
		write(seq.text, 0x20, seq.center ? 0xffff : 0, 0, FontType::Old);
		render();
		delay(seq.delay);

		flush();
		write("THIS IS", 0x20, seq.center ? 0xffff : 0, 0, FontType::Old);
		render();
		delay(seq.delay);
	}
}

int lastRun = 0;

bool qNYRunCountdown() {
			flushLeft();
			write("5", 0x202020, 14, 0, FontType::New); render();
			delay(1000);
		// } else if (lastRun == 1) {
			flushLeft();
			write("4", 0x202020, 14, 0, FontType::New); render();
			delay(1000);
		// } else if (lastRun == 2) {
			flushLeft();
			write("3", 0x202020, 14, 0, FontType::New); render();
			delay(1000);

			flushLeft();
			write("2", 0xf0, 14, 0, FontType::New); render();
			delay(1000);

			flushLeft();
			write("1", 0x202020, 14, 0, FontType::New); render();
			delay(1000);
}

bool qNewYearRun(int loops) {
	// qNYRunCountdown();
	// if (true) {

		// if (lastRun == 0) {
			flushLeft();
			write("Happy", 0x30, 0, 0, FontType::New); render();
			delay(1000);
		// } else if (lastRun == 1) {
			flushLeft();
			write("New", 0x30, 0, 0, FontType::New); render();
			delay(1000);
		// } else if (lastRun == 2) {
			flushLeft();
			write("Year", 0x30, 0, 0, FontType::New); render();
			delay(1000);
		// }

		// if (++lastRun > 2) {
			// lastRun = 0;
		// }
	// }
	
	// writeFlashing("Happy New Year", 0xaa, 1000);
	// render();
	// delay(1000);
}