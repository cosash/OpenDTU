// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2022 Thomas Basler and others
 */
#include "WebApi_mqtt.h"
#include "Configuration.h"
#include "MqttHandleHass.h"
#include "MqttSettings.h"
#include "WebApi.h"
#include "WebApi_errors.h"
#include "helper.h"
#include <AsyncJson.h>
#include "MessageOutput.h"
#include <HTTPClient.h>

void WebApiGarageClass::init(AsyncWebServer* server)
{
    using std::placeholders::_1;

    _server = server;

    _server->on("/api/garage/open", HTTP_GET, std::bind(&WebApiGarageClass::open, this, _1));
    _server->on("/api/garage/close", HTTP_GET, std::bind(&WebApiGarageClass::close, this, _1));
}

void WebApiGarageClass::loop()
{
}

void WebApiGarageClass::open(AsyncWebServerRequest* request)
{
    MessageOutput.println(F("Got open request"));    

    digitalWrite(22, LOW);
    delay(500);
    digitalWrite(22, HIGH);
    AsyncWebServerResponse* response = request->beginResponse(200, "text/plain", "OPENOKAY");
    response->addHeader("Connection", "close");
    response->addHeader("Access-Control-Allow-Origin", "*");
    request->send(response);
    yield();
}

void WebApiGarageClass::close(AsyncWebServerRequest* request)
{
    MessageOutput.println(F("Got close request"));    
    AsyncWebServerResponse* response = request->beginResponse(200, "text/plain", "CLOSEOKAY");
    response->addHeader("Connection", "close");
    response->addHeader("Access-Control-Allow-Origin", "*");
    request->send(response);
    yield();
}
