#include<Servo.h>
const int ledPin = 13; // Chân LED (hoặc kết nối với một đèn ngoài)
Servo myservo;  // create Servo object to control a servo
void setup() {
  pinMode(ledPin, OUTPUT); // Cấu hình chân LED là đầu ra
  Serial.begin(9600);      // Khởi động Serial với tốc độ 9600 baud
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  if (Serial.available() > 0) {  // Kiểm tra nếu có dữ liệu gửi đến
    String data = Serial.readStringUntil('\n'); // Đọc dữ liệu cho đến khi gặp ký tự xuống dòng
    data.trim();  // Loại bỏ khoảng trắng hoặc ký tự xuống dòng

    if (data == "00") {
      Serial.println("Command '00' received: LED blinked."); // Phản hồi lại Python
      myservo.write(0);
    }else if (data =="01"){
      myservo.write(70);
    } else {
      Serial.println("Unknown command."); // Phản hồi nếu lệnh không hợp lệ
    }
  }
}

