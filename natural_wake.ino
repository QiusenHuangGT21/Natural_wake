String comdata;
String temp;
float r;
float g;
float b;
float B;
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      20

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void initial() {
  r = 10;
  g = 0;
  b = 0;
  //check r

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    delay(100);
  }

  for (r = 10; r < 255; r++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }
  for (r = 255; r >= 0; r--) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }

  r = 0;

  //check b
  for (g = 0; g < 255; g++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }
  for (g = 255; g >= 0; g--) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }
  g = 0;


  //check b
  for (b = 0; b < 255; b++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }
  for (b = 255; b >= 0; b--) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1);
  }
  b = 0;

  //flash g for 3 times indicating intialization complete
  bool a = false;
  for (int i = 0; i < 5; i++) {
    a = !a;
    if (a) {
      g = 50;
    } else {
      g = 0;
    }
    pixels.setPixelColor(1, pixels.Color(r, g, b));
    pixels.show();
    delay(300);
  }
}


void wake(float rate) {
  //0-10
  float s1 = rate / 2 * 60;
  Serial.println(s1);
  for (int a = 0; a <= s1; a++) {
    float temp = a / s1;

    r = temp * 25;
    g = temp * 5;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s1 ");
    Serial.println(temp);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
  float s2 = rate / 4 * 60;
  Serial.println("s2");
  for (int a = 0; a <= s2; a++) {
    float temp = a / s2;
    r = 25 + temp * 65;
    g = 5 + temp * 30;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s2 ");
    Serial.println(a / s2);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
  float s3 = rate / 8 * 60;;
  Serial.println("s3");
  for (int a = 0; a <= s3; a++) {
    float temp = a / s3;
    r = 90 + temp * 130;
    g = 35 + temp * 49;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s3 ");
    Serial.println(a / s3);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
  float s4 = rate / 8 * 60;
  Serial.println("s4");
  for (int a = 0; a <= s4; a++) {
    float temp = a / s4;
    r = 220 + temp * 35;
    g = 84 + temp * 26;
    b = temp * 45;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s4 ");
    Serial.println(a / s4);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
}

void sleep(float rate) {

  float s4 = rate / 8 * 60;
  Serial.println("s4");
  for (int a = (int)s4; a >= 0 ; a--) {
    float temp = a / s4;
    r = 255 - temp * 35;
    g = 110 - temp * 26;
    b = temp * 45;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s4 ");
    Serial.println(a / s4);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }

  float s3 = rate / 8 * 60;;
  Serial.println("s3");
  for (int a = (int)s3; a >= 0; a--) {
    float temp = a / s3;
    r = 220 - temp * 130;
    g = 84 - temp * 49;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s3 ");
    Serial.println(a / s3);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
  float s2 = rate / 4 * 60;
  Serial.println("s2");
  for (int a = (int)s2; a >= 0; a--) {
    float temp = a / s2;
    r = 90 - temp * 65;
    g = 35 - temp * 30;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s2 ");
    Serial.println(a / s2);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
  float s1 = rate / 2 * 60;
  Serial.println(s1);
  for (int a = (int)s1; a >= 0; a--) {
    float temp = a / s1;

    r = temp * 25;
    g = temp * 5;
    b = 0;
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
    delay(1000);
    Serial.print("s1 ");
    Serial.println(temp);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    Serial.println(millis());
  }
}

//////////////////////////////////////////////
void setup() {

  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  initial();
  //wake(8);
  sleep(8);

}

void loop() {

  while (Serial.available() > 0) {

    comdata += char(Serial.read());
    delay(2);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }

  }
  if (comdata != "") {
    temp = comdata.substring(0, 3);
    r = temp.toInt();
    temp = comdata.substring(3, 6);
    g = temp.toInt();
    temp = comdata.substring(6, 9);
    b = temp.toInt();
    temp = comdata.substring(9, 12);
    B = temp.toInt();

    if (b != 255) {
      r = map(r, 0, 255, 0, B);
      g = map(g, 0, 255, 0, B);
      b = map(b, 0, 255, 0, B);
    }



    if ((r <= 255) && (g <= 255) && (b <= 255)) {
      Serial.print(r);
      Serial.print(g);
      Serial.print(b);
      Serial.println(B);



      for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(r, g, b)); // Moderately bright green color.

        pixels.show();
      }
    } else {
      Serial.println("ValueExceedLimit!");
    }
  }
  comdata = "";
  delay(1000);

}
