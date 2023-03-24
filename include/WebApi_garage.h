// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <ESPAsyncWebServer.h>

class WebApiGarageClass {
public:
    void init(AsyncWebServer* server);
    void loop();

private:
    void open(AsyncWebServerRequest* request);
    void close(AsyncWebServerRequest* request);

    AsyncWebServer* _server;
};