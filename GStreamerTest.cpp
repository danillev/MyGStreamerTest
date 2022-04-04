#include "MyGst.h"

int main(int argc, char* argv[]) {
    MyGst gst = MyGst(argc, argv);
    if (gst.GstGetTerminate()) return -1;
    gst.GstSetURIPlay("https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", "dumpaudio5.aac");
    if (gst.GstGetTerminate()) return -1;
    gst.GstStartPlaying();
    return 0;
}
