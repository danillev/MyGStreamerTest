#pragma once
#include <gst/gst.h>

typedef struct _CustomData {
    GstElement* pipeline;
    GstElement* source;
    GstElement* convert;
    GstElement* resample;
    GstElement* sink;
    GstElement* audioenc;
    GstElement* qtmux;
} CustomData;

class MyGst
{
private:
    CustomData data;
    bool _terminate = false;


public:
    // Конструктор при создании объекта
    MyGst(int argc, char* argv[]);

    /* Set the URI to play */
    void GstSetURIPlay(const gchar* uri, const gchar* location);

    int GstStartPlaying();

    bool GstGetTerminate();

private:
    /* This function will be called by the pad-added signal */
    static void pad_added_handler(GstElement* src, GstPad* new_pad, CustomData* data);
    bool GstReadyElements();
};

