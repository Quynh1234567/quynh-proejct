#include <DHT.h>

// ----------------------
// CẤU HÌNH CẢM BIẾN DHT11
// ----------------------
#define DHTPIN 4        // Chân DATA của DHT11 nối với GPIO4 trên ESP32
#define DHTTYPE DHT11   // Chọn loại cảm biến là DHT11

DHT dht(DHTPIN, DHTTYPE);  // Tạo đối tượng cảm biến DHT

void setup() {
  Serial.begin(115200);     // Bật Serial Monitor ở tốc độ 115200 baud
  dht.begin();              // Khởi động cảm biến DHT11

  Serial.println("Bắt đầu đọc dữ liệu từ cảm biến DHT11...");
}

void loop() {
  delay(2000); // Đợi 2 giây giữa mỗi lần đọc (DHT11 không đọc quá nhanh được)

  float doAm = dht.readHumidity();           // Đọc độ ẩm (%)
  float nhietDo = dht.readTemperature();     // Đọc nhiệt độ (°C)

  // Kiểm tra lỗi khi đọc dữ liệu
  if (isnan(doAm) || isnan(nhietDo)) {
    Serial.println("❌ Không thể đọc dữ liệu từ cảm biến DHT11!");
    return;
  }

  // Hiển thị dữ liệu lên Serial Monitor
  Serial.println("===== DỮ LIỆU DHT11 =====");
  Serial.print("🌡️ Nhiệt độ: ");
  Serial.print(nhietDo);
  Serial.println(" °C");

  Serial.print("💧 Độ ẩm: ");
  Serial.print(doAm);
  Serial.println(" %");
  Serial.println("=========================\n");
}