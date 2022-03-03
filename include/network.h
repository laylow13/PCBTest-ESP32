//
// Created by Lay on 3/3/2022.
//

#ifndef PCBTEST_NETWORK_H
#define PCBTEST_NETWORK_H

#include "Arduino.h"
#include "Arduino_JSON.h"

String httpGETRequest(const char* serverName);
void tab_data_update(JSONVar * tab_data_json);

void wifi_connect(const char * ssid,const char * password);



#endif //PCBTEST_NETWORK_H
