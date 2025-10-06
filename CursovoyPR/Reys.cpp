#include "Reys.h"

// Геттеры
int Reys::getNomerReysa() const { return nomerReysa; };
string Reys::getTipAvtobusa() const { return tipAvtobusa; };
string Reys::getPunktNaznacheniya() const { return punktNaznacheniya; };
string Reys::getDataOtpravleniya() const { return dataOtpravleniya; };
string Reys::getVremyaOtpravleniya() const { return vremyaOtpravleniya; };
string Reys::getVremyaPribitiya() const { return vremyaPribitiya; };
float Reys::getStoimostBileta() const { return stoimostBileta; };
int Reys::getKolichestvoOstavshihsyaBiletov() const { return kolichestvoOstavshihsyaBiletov; };
int Reys::getKolichestvoProdannyhBiletov() const { return kolichestvoProdannyhBiletov; };

// Сеттеры
void Reys::setNomerReysa(int nomer) { nomerReysa = nomer; };
void Reys::setTipAvtobusa(const string& tip) { tipAvtobusa = tip; };
void Reys::setPunktNaznacheniya(const string& punkt) { punktNaznacheniya = punkt; };
void Reys::setDataOtpravleniya(const string& data) { dataOtpravleniya = data; };
void Reys::setVremyaOtpravleniya(const string& vremya) { vremyaOtpravleniya = vremya; };
void Reys::setVremyaPribitiya(const string& vremya) { vremyaPribitiya = vremya; };
void Reys::setStoimostBileta(float stoimost) { stoimostBileta = stoimost; };
void Reys::setKolichestvoOstavshihsyaBiletov(int kolichestvo) { kolichestvoOstavshihsyaBiletov = kolichestvo; };
void Reys::setKolichestvoProdannyhBiletov(int kolichestvo) { kolichestvoProdannyhBiletov = kolichestvo; };

// Метод для записи рейса в файл
void Reys::zapisatVFile() const {
    ofstream file(REYS_FILE_NAME, ios::app);
    if (file.is_open()) {
        file << nomerReysa << ";";
        file << tipAvtobusa << ";";
        file << punktNaznacheniya << ";";
        file << dataOtpravleniya << ";";
        file << vremyaOtpravleniya << ";";
        file << vremyaPribitiya << ";";
        file << stoimostBileta << ";";
        file << kolichestvoOstavshihsyaBiletov << ";";
        file << kolichestvoProdannyhBiletov << endl;
        file.close();
    };
};

// Метод для последовательного чтения рейсов из файла
void Reys::prochitatReysyIzFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            if (line.empty()) continue;

            size_t pos = 0;
            vector<string> fields;

            while ((pos = line.find(';')) != string::npos) {
                fields.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            };
            fields.push_back(line);

            if (fields.size() == 9) {
                Reys tempReys;
                tempReys.setNomerReysa(stoi(fields[0]));
                tempReys.setTipAvtobusa(fields[1]);
                tempReys.setPunktNaznacheniya(fields[2]);
                tempReys.setDataOtpravleniya(fields[3]);
                tempReys.setVremyaOtpravleniya(fields[4]);
                tempReys.setVremyaPribitiya(fields[5]);
                tempReys.setStoimostBileta(stof(fields[6]));
                tempReys.setKolichestvoOstavshihsyaBiletov(stoi(fields[7]));
                tempReys.setKolichestvoProdannyhBiletov(stoi(fields[8]));

                // МЕСТО ДЛЯ ВАШИХ ДЕЙСТВИЙ
                // Здесь вы можете работать с tempReys

            };
        };
        file.close();
    };
};