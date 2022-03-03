//
// Created by Lay on 3/3/2022.
//

#include "network.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include "Arduino_JSON.h"
#include "sd_drv.h"
#include "FS.h"
#include "SD.h"

//static String serverPath= "";
//String jsonBuffer;
//static String jsonBuffer = httpGETRequest(serverPath.c_str());
//JSONVar tab_data_json = JSON.parse(jsonBuffer);


String httpGETRequest(const char* serverName)
{
    WiFiClient client;
    HTTPClient http;
    http.setUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64)");
    //text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
    http.addHeader("Accept","application/json");
//    // zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6
    http.addHeader("Accept-Language","zh-CN");
    http.begin(client, serverName);
//    http.addHeader();
    int httpResponseCode = http.GET();
    String payload = "{}";

    if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

    return payload;
}

void wifi_connect(const char * ssid,const char * password)
{
        WiFi.begin(ssid, password);
        Serial.println("Connecting");
        while(WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.println("");
        Serial.print("Connected to WiFi network with IP Address: ");
        Serial.println(WiFi.localIP());
}
