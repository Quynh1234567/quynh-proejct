#include <WiFi.h>
#include <esp_now.h>

void onReceive(const uint8_t *mac, const uint8_t *data, int len) {
  Serial.print("Nhận từ MAC: ");

  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", mac[i]);
    if (i < 5) Serial.print(":");
  }

  Serial.print(" -> Nội dung: ");
  Serial.write(data, len); // In nội dung nhận được
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  // Bắt buộc cho ESP-NOW

  // In ra địa chỉ MAC của ESP nhận để copy qua bên gửi
  Serial.print("Địa chỉ MAC của ESP này: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("Lỗi khởi tạo ESP-NOW!");
    return;
  }

  // Đăng ký callback khi có dữ liệu đến
  esp_now_register_recv_cb(onReceive);

  Serial.println("Sẵn sàng nhận dữ liệu...");
}

void loop() {
  // Không cần làm gì, chỉ chờ dữ liệu đến
}
