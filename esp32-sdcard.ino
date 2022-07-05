#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SD_CS 5

char input; // for incoming serial data

void setup(){
  Serial.begin(9600);
  SD.begin(SD_CS);
  if (!SD.begin(SD_CS)) {
    Serial.println("Gagal Memuat Kartu SD");
    return;
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("Tidak Ada Kartu SD");
    return;
  }
  Serial.println("Menginisialisasi kartu SD...");
}

void loop(){
  if (Serial.available() > 0) {
    input = Serial.read();
  }

  if (input=='w'){
    writeFile(SD, "/RobotikID.txt", "Hai, Ini Robotik Indonesia ");
    /*
    Menyimpan Tulisan atau String "Hai, Ini Robotik Indonesia "
    pada file yang bernama RobotikID.txt
    */ 
  }

  if (input=='r'){
    readFile(SD, "/RobotikID.txt");
    /*
    Membaca Tulisan atau String atau nilai yang berada
    pada file yang bernama RobotikID.txt
    */ 
  }

  if (input=='a'){
    appendFile(SD, "/RobotikID.txt", "Kita akan belajar bersama ");
    /*
    Menambahkan String "Kita akan belajar bersama "
    pada file yang bernama RobotikID.txt
    Sehingga akan menjadi "Hai, Ini Robotik Indonesia Kita akan belajar bersama"
    */ 
  }

  if (input=='l'){
    listDir(SD, "/", 0);
    /*
    Melihat list file atau folder yang ada pada Kartu SD
    */ 
  }

  if (input=='n'){
    renameFile(SD, "/RobotikID.txt", "/RobotikIndonesia.txt");
    /*
    Mengganti nama File RobotikID.txt menjadi RobotikIndonesia.txt
    */ 
  }

  if (input=='d'){
    deleteFile(SD, "/RobotikIndonesia.txt");
    /*
    Menghapus file yang bernama RobotikIndonesia.txt
    */ 
  }
}
