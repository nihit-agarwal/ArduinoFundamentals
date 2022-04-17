// ECE Individual Poject
/*Aim: To create a device to meausre temperature and humdidity in surrounding
 and display on LCD screen. */

// Libraries Included:
#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

// Defining terms
#define DHT_SENSOR_TYPE DHT_TYPE_11

// Setting constants
const int DHT_SENSOR_PIN = 2; // CHECK if adding  static makes any difference to code.

// Initialize libraries
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

/**
 * Helper Function to measure and store temperature and humidity.
 * Returns true if measurement was successful.
 */
static bool measure_environment(float *t, float *h)
{
  static unsigned long measurement_timestamp = millis();
  // In order to measure every 4 seconds
  if (millis() - measurement_timestamp > 3000ul)
  {
    if (dht_sensor.measure(t, h) == true)
    {
      measurement_timestamp = millis();
      return true;
    }
  }
  return false;
}


void setup() {
  // put your setup code here, to run once:
  // Setting up the LCD no. of columns and no. of rows
  lcd.begin(16, 2);

  // Printing Labels
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  // Initializing temperature and humiditiy variables
  float temperature; // Trying making it static.
  float humidity;
  /* Measure temperature and humidity using helper function which returns 
   *  true only when measurement is available. */
  if (measure_environment(&temperature, &humidity) == true)
  {
     lcd.setCursor(13,0);
     int temp_f = (int) (((9 * temperature) / 5) + 32);
     lcd.print(temp_f);
     lcd.print("F");
     lcd.setCursor(10,1);
     lcd.print(humidity, 1);
     lcd.print("%");
  }
   
  
 

}
