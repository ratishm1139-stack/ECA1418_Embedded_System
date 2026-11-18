#include <Arduino.h>
void HighTask(void *pvParameters)
{
  while (1)
  {
    Serial.println("HighTask is running");
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
void MediumTask(void *pvParameters)
{
  while (1)
  {
    Serial.println("MediumTask is running");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void LowTask(void *pvParameters)
{
  while (1)
  {
    Serial.println("LowTask is running");
    vTaskDelay(pdMS_TO_TICKS(1500));
  }
}
void setup()
{
  Serial.begin(115200);
  xTaskCreate(HighTask, "HighTask", 2048, NULL, 3, NULL);
  xTaskCreate(MediumTask, "MediumTask", 2048, NULL, 2,
NULL);
  xTaskCreate(LowTask, "LowTask", 2048, NULL, 1, NULL);
  Serial.println("All tasks created");
}
void loop()
{
  delay(1000);
}
