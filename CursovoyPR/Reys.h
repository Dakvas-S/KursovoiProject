#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "globals.h"
using namespace std;

class Reys
{
private:
    string DBforReys = "";
    int nomerReysa;
    string tipAvtobusa;
    string punktNaznacheniya;
    string dataOtpravleniya;
    string vremyaOtpravleniya;
    string vremyaPribitiya;
    float stoimostBileta;
    int kolichestvoOstavshihsyaBiletov;
    int kolichestvoProdannyhBiletov;

public:
    // Геттеры
    int getNomerReysa() const;
    string getTipAvtobusa() const;
    string getPunktNaznacheniya() const;
    string getDataOtpravleniya() const;
    string getVremyaOtpravleniya() const;
    string getVremyaPribitiya() const;
    float getStoimostBileta() const;
    int getKolichestvoOstavshihsyaBiletov() const;
    int getKolichestvoProdannyhBiletov() const;

    // Сеттеры
    void setNomerReysa(int nomer);
    void setTipAvtobusa(const string& tip);
    void setPunktNaznacheniya(const string& punkt);
    void setDataOtpravleniya(const string& data);
    void setVremyaOtpravleniya(const string& vremya);
    void setVremyaPribitiya(const string& vremya);
    void setStoimostBileta(float stoimost);
    void setKolichestvoOstavshihsyaBiletov(int kolichestvo);
    void setKolichestvoProdannyhBiletov(int kolichestvo);

    // Методы для работы с файлом
    void zapisatVFile() const;
    void prochitatReysyIzFile(const string& filename);
};