/*  SD card test
  created  28 Mar 2011  by Limor Fried
  modified 24 July 2020 by Tom Igoe

  modified 09 March 2026 for ET-4000 v2
*/

#include <SPI.h>
#include <SD.h>

Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = A0;

void setup() {
  Serial.begin(115200);
  while(!Serial);


  Serial.print("\nInitializing SD card...");

  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
     Serial.println("initialization failed. Things to check:");
     Serial.println("* is a card inserted?");
     Serial.println("* is your wiring correct?");
     Serial.println("* did you change the chipSelect pin to match your shield or module?");
     Serial.println("Note: press reset button on the board and reopen this Serial Monitor after fixing your issue!");
     while (1);
     }
  else
     Serial.println("Wiring is correct and a card is present.");


  Serial.println();
  Serial.print("Card type:         ");
  switch (card.type()) {
     case SD_CARD_TYPE_SD1:
        Serial.println("SD1");
        break;
     case SD_CARD_TYPE_SD2:
        Serial.println("SD2");
        break;
     case SD_CARD_TYPE_SDHC:
        Serial.println("SDHC");
        break;
     default:
        Serial.println("Unknown");
    }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
     Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
     while(1);
     }

  Serial.print("Clusters:          ");
  Serial.println(volume.clusterCount());
  Serial.print("Blocks x Cluster:  ");
  Serial.println(volume.blocksPerCluster());

  Serial.print("Total Blocks:      ");
  Serial.println(volume.blocksPerCluster() * volume.clusterCount());
  Serial.println();

  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("Volume type is:    FAT");
  Serial.println(volume.fatType(), DEC);

  volumesize = volume.blocksPerCluster();
  volumesize *= volume.clusterCount();
  volumesize /= 2;
  Serial.print("Volume size (KB):  ");
  Serial.println(volumesize);
  Serial.print("Volume size (MB):  ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (GB):  ");
  Serial.println((float)volumesize / 1024.0);

  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
}

void loop(void) {
  // no loop content in this example.
}

