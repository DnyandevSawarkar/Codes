

/*//SPI V
#define SD_CS         21
#define SD_MOSI      23
#define SD_MISO      19
#define SD_SCK       18
*/
///SPI H

#define SD_MOSI      23
#define SD_MISO      19
#define SD_SCK       14

#define SD_CS_PIN 15

File myFile;
SPIClass SPISD(HSPI);
void SD_Init()
{
  //  SPIClass SPI2(HSPI);


    SPISD.begin(SD_SCK, SD_MISO, SD_MOSI);
    if (!SD.begin(SD_CS_PIN,SPISD)) {  //SD_CS_PIN this pin is just the dummy pin since the SD need the input 
    Serial.println(F("failed!"));
    return;
    }
    else Serial.println(F("SD read!"));
    myFile = SD.open("/test.txt", "a"); //append to file
  if (myFile)
  {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  }
  else
  {
    Serial.println("error opening test.txt to write");
  }
  myFile = SD.open("/test.txt", "r"); //read from file
  if (myFile)
  {
    Serial.println("test.txt:");
    String inString;  //need to use Strings because of the ESP32 webserver
    while (myFile.available())
    {
      inString += myFile.readString();
    }
    myFile.close();
    Serial.print(inString);
  }
  else
  {
    Serial.println("error opening test.txt to read");
  }
}


void setup(){
  Serial.begin(9600);
  //dht.begin();
  SD_Init();
}

void loop(){
 // int ir_value = analogRead(ir_pin);
  
  }

/*
if(!SD.begin()){
      Serial.println("Card Mount Failed");
      return;
      }
 // createDir(SD, "/mydir");
  writeFile(SD, "/datalog_ESP32.txt", "0");
  for(int i=1;i<=10;i++)
  {
    appendFile(SD, "/datalog_ESP32.txt", i);
    
  delay(200);
  }
  */



















void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void createDir(fs::FS &fs, const char * path){
  Serial.printf("Creating Dir: %s\n", path);
  if(fs.mkdir(path)){
    Serial.println("Dir created");
  } else {
    Serial.println("mkdir failed");
  }
}

void appendFile(fs::FS &fs, const char * path, int message){
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}
