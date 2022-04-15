#include<KRtelegram.h>
char* ssid  =  "isi nama wifi";
char* pass  =  "isi password wifi";
char* token =  "isi token:telegram";

void setup() {
  Serial.begin(115200);
  setTelegram(ssid, pass, token);
}

void loop() {
  TBMessage msg;
  if (myBot.getNewMessage(msg)) {
    String pesan = msg.text;
    Serial.println(pesan);
    myBot.sendMessage(msg, pesan);
  }
}
