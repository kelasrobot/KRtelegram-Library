#define USE_CLIENTSSL true
#include <AsyncTelegram2.h>
#include <time.h>
#define MYTZ "WIB-7"
#include <ESP8266WiFi.h>
BearSSL::WiFiClientSecure client;
BearSSL::Session   session;
BearSSL::X509List  certificate(telegram_cert);
AsyncTelegram2 myBot(client);

void setTelegram(char* ssid, char* pass, char* token) {
  Serial.println("\nMemulai TelegramBot...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println("Menghubungkan ke WiFi...");
  delay(500);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  configTime(MYTZ, "time.google.com", "time.windows.com", "pool.ntp.org");
  client.setSession(&session);
  client.setTrustAnchors(&certificate);
  client.setBufferSizes(1024, 1024);
  myBot.setUpdateTime(2000);
  myBot.setTelegramToken(token);
  Serial.print("\nCek Koneksi ke Telegram Bot... ");
  myBot.begin() ? Serial.println("Koneksi OK") : Serial.println("Koneksi Buruk");
}