// Name:Erin Stacey
// Date:10/18/2024
// Class: Optimization Techniques
#include"Wave.h"
#include "Stopwatch.h"
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string.h>
#include<xmm.h>
#include<xmm-int.h>
using namespace std;

int main(int argc, char* argv[])
{

    string filename = "BackgroundSoundMoth.wav";

    Wave w(filename);
    Stopwatch swatch;
    swatch.start();
    //xmmu8 masks(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    unsigned bytesPerSample = w.format.bitsPerSample / 8;
    unsigned totalBytes = w.numFrames * w.format.numChannels * bytesPerSample;

    std::uint8_t* data = (std::uint8_t*)w.data();

    // Step 1: Swap chunks from beginning to end
    std::uint8_t* start = data;
    std::uint8_t* end = data + totalBytes - 16;

    while (start < end) {
        xmmu8 frontChunk(start);
        xmmu8 backChunk(end);

        backChunk.store(start);
        frontChunk.store(end);

        start += 16;
        end -= 16;
    }

    // Step 2: Reverse bytes within EVERY 16-byte chunk
    xmmu8 masks(14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1);

    for (unsigned i = 0; i < totalBytes; i += 16) {
        if (i + 16 <= totalBytes) {
            xmmu8 chunk(data + i);
            xmmu8 reversed = chunk.shuffle(masks);
            reversed.store(data + i);
        }
    }

    swatch.stop();
    cout << swatch.elapsed_us() << "usec\n";
    w.write("out.wav");

    return 0;
}
