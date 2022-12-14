#ifndef SETTINGS_H
#define SETTINGS_H
#include <QFont>
#include <QObject>

class Settings
{
public:
    Settings();
    static void writeSettings(QString last_file, QFont font, bool load_recent, bool word_wrap, bool status_bar);
    static void readSettings(QString* last_file, QFont* font, bool* load_recent, bool* word_wrap, bool* status_bar);
};

#endif // SETTINGS_H
