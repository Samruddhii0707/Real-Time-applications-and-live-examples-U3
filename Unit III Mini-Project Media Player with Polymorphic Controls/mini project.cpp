#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Media
{
protected:
    string title;

public:
    Media(string t)
        : title(t)
    {
    }

    virtual void play() const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual void showDetails() const = 0;

    virtual ~Media() = default;
};

class Audio : public Media
{
private:
    string artist;

public:
    Audio(string t, string a)
        : Media(t), artist(a)
    {
    }

    void play() const override
    {
        cout << "Playing audio: " << title << endl;
    }

    void pause() const override
    {
        cout << "Pausing audio: " << title << endl;
    }

    void stop() const override
    {
        cout << "Stopping audio: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "Audio | Title: " << title
             << " | Artist: " << artist << endl;
    }
};

class Video : public Media
{
private:
    string resolution;

public:
    Video(string t, string r)
        : Media(t), resolution(r)
    {
    }

    void play() const override
    {
        cout << "Playing video: " << title << endl;
    }

    void pause() const override
    {
        cout << "Pausing video: " << title << endl;
    }

    void stop() const override
    {
        cout << "Stopping video: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "Video | Title: " << title
             << " | Resolution: " << resolution << endl;
    }
};

class Image : public Media
{
private:
    string format;

public:
    Image(string t, string f)
        : Media(t), format(f)
    {
    }

    void play() const override
    {
        cout << "Displaying image: " << title << endl;
    }

    void pause() const override
    {
        cout << "Image pause operation: " << title << endl;
    }

    void stop() const override
    {
        cout << "Closing image: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "Image | Title: " << title
             << " | Format: " << format << endl;
    }
};

int main()
{
    vector<Media*> mediaItems;

    mediaItems.push_back(new Audio("Tum Hi Ho", "Arijit Singh"));
    mediaItems.push_back(new Video("Nature Documentary", "1080p"));
    mediaItems.push_back(new Image("Mountain View", "JPG"));

    cout << "=== Media Player ===" << endl;

    for (Media* media : mediaItems)
    {
        media->showDetails();
        media->play();
        media->pause();
        media->stop();

        cout << endl;
    }

    for (Media* media : mediaItems)
    {
        delete media;
    }

    return 0;
}
