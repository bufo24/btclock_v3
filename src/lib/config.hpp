#pragma once;
#include <WiFiClientSecure.h>
#include <Preferences.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_NeoPixel.h>

#include "shared.hpp"
#include <esp_system.h>
#include <esp_netif.h>
#include <esp_sntp.h>
#include "epd.hpp"
#include "improv.hpp"

#include "lib/screen_handler.hpp"
#include "lib/webserver.hpp"
#include "lib/block_notify.hpp"
#include "lib/price_notify.hpp"
#include "lib/button_handler.hpp"

#define NTP_SERVER "pool.ntp.org"
#define DEFAULT_MEMPOOL_INSTANCE "mempool.space"
#define TIME_OFFSET_SECONDS 3600
#define USER_AGENT "BTClock/2.0"
#define MCP_DEV_ADDR 0x20

#define BITCOIND_HOST ""
#define BITCOIND_PORT 8332
#define BITCOIND_RPC_USER ""
#define BITCOIND_RPC_PASS ""

void setup();
void setupTime();
void setupPreferences();
void setupWebsocketClients();
void setupHardware();
void tryImprovSetup();
void setupTimers();
void finishSetup();

std::vector<std::string> getLocalUrl();
bool improv_connectWifi(std::string ssid, std::string password);
void improvGetAvailableWifiNetworks();
bool onImprovCommandCallback(improv::ImprovCommand cmd);
void onImprovErrorCallback(improv::Error err);
void improv_set_state(improv::State state);
void improv_send_response(std::vector<uint8_t> &response);
void improv_set_error(improv::Error error);
void blinkDelay(int d, int times);