#include <LCD_I2C.h>

#include "WifiCredentials.h"

WiFiClient client;
LCD_I2C lcd(0x27);

const long SPEED = 19200;

int HTTP_PORT = 80;
String HTTP_METHOD = "GET";             // or "POST"
char HOST_NAME[] = "example.phpoc.com"; // hostname of web server:
String PATH_NAME = "";

bool connectToWifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    for (int i = 0; i < 5; i++)
    {
        delay(1000);
    }

    return WiFi.status() == WL_CONNECTED;
}

void setup()
{
    Serial.begin(SPEED);

    connectToWifi();

    lcd.begin();

    lcd.backlight();
    lcd.setCursor(0, 0);

    if (client.connect(HOST_NAME, HTTP_PORT))
    {
        lcd.print("Connected to server");
    }
    else
    {
        lcd.print("Failed");
    }
}

void loop()
{
    while (client.available())
    {
        char c = client.read();
        lcd.print(c);
    }

    if (!client.connected())
    {
        lcd.print("disconnected");
        client.stop();
    }
}
