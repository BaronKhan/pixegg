// pixegg.ino
// Arduino Uno (ATmega328P)

#include "pixegg.h"

Pixegg GetPixegg()
{
    static Pixegg pixegg;
    return pixegg;
}

void setup()
{
    GetPixegg().Start();
}

void loop()
{
    GetPixegg().Loop();
}
