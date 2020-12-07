/*
Написать собственный класс, в соответствии с вариантом.Продемонстрироватьв кодеинкапсуляциюданных,
применениеконструкторов без параметрови с параметрамидля  инициализации  данных.Класс  должен  содержать  метод
serialize()длясохраненияданных классав файли метод deserialize()для чтения данных класса из  файлапо  умолчанию
в  текущей  директории, а  также  перегруженные  методы serialize(conststd::string& filename)и
deserialize(cons tstd::string & filename)для работы с файломсуказаннымв параметре именем.

ласс МАГАЗИН.Данные:название, адрес, год основания, номер, суммарная прибыль.Создать два объекта - магазина в куче
и один в стеке.Данные первых двух заполнить с помощью  сеттеров, а  третий  проинициализировать  с  помощью
конструктора  с параметрами.В  главной  функции  проимитировать  отдельно  продажи  за  сентябрь, октябрь и ноябрь.
Вывести всемагазины отдельно в двух рейтинговых списках(сначала один, затем второй) :
1) отсортировать в порядке убывания общей прибыли за 3 месяца;
2) отсортировать в порядке убывания среднего прироста прибыли за 3 месяца
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

class Market {
private:
	std::string name, adress;
	int yearFoundation, nomber;
	double totalProfit, mediumProfit, september, october, november;
public:
	Market(std::string inputName = "unknown", std::string inputAdress = "unknown", int inputYearFoundation = NULL, int inputNomber = NULL) {
		name = inputName;
		adress = inputAdress;
		yearFoundation = inputYearFoundation;
		nomber = inputNomber;
	}
	void setParametr(std::string inputName = "unknown", std::string inputAdress = "unknown", int inputYearFoundation = NULL, int inputNomber = NULL) {
		name = inputName;
		adress = inputAdress;
		yearFoundation = inputYearFoundation;
		nomber = inputNomber;
	}
	void setProfit(double septemberProfit, double octoberProfit, double novemberProfit) {
		september = septemberProfit;
		october = octoberProfit;
		november = novemberProfit;
		totalProfit = september + november + november;
		mediumProfit = (september + november + november) / 3;
	}
	void printInformationTotalProfit(){
		std::cout << "name: " << name << "\n" << "nomber: " << nomber << "\n" << "adress: " << adress << "\n" << "yearFoundation: " << yearFoundation << "\n" << "totalProfit($): " << totalProfit << "\n----------" << std::endl;
	}
	void printInformationMidProfit(){
		std::cout << "name: " << name << "\n" << "nomber: " << nomber << "\n" << "adress: " << adress << "\n" << "yearFoundation: " << yearFoundation << "\n" << "mediumProfit($): " << mediumProfit << "\n----------" << std::endl;
	}
	double getTotalProfit() {
		return totalProfit;
	}
	double getMediumProfit() {
		return mediumProfit;
	}
	void serialize() {
		std::ofstream file;
		file.open(name + ".txt");
		file << name << "\n";
		file << nomber << "\n";
		file << adress << "\n";
		file << yearFoundation << "\n";
		file << totalProfit << "\n";
		file << mediumProfit;
		file.close();
	}
	void deSerialize() {
		std::ifstream file;
		file.open(name + ".txt");
		if (file.is_open()) {
			std::getline(file, name);
			std::getline(file, nomber);
			std::getline(file, adress);
			std::getline(file, yearFoundation);
			std::getline(file, totalProfit);
			std::getline(file, mediumProfit);
		}
		file.close();
	}
	void serialize(const std::string& filename) {
		std::ofstream file;
		file.open(filename);
		file << name << "\n";
		file << nomber << "\n";
		file << adress << "\n";
		file << yearFoundation << "\n";
		file << totalProfit << "\n";
		file << mediumProfit;
		file.close();
	}
	void deSerialize(const std::string& filename) {
		std::ifstream file;
		file.open(filename);
		if (file.is_open()) {
			std::getline(file, name);
			std::getline(file, nomber);
			std::getline(file, adress);
			std::getline(file, yearFoundation);
			std::getline(file, totalProfit);
			std::getline(file, mediumProfit);
		}
		file.close();
	}
};

int main() {
	Market market1;
	Market market2;
	Market market3("GameOver", "prs.Teatralnyu", 2014, 3);
	market1.setParametr("Globus", "bul.Shevchenko", 2016, 1);
	market2.setParametr("Shaurma", "Shetinina.str", 2019, 2);
	market1.setProfit(300, 380, 350);
	market2.setProfit(700, 400, 220);
	market3.setProfit(1300, 800, 1100);

	market1.serialize();

	double messMediumProfit[3];
	messMediumProfit[0] = market1.getMediumProfit();
	messMediumProfit[1] = market2.getMediumProfit();
	messMediumProfit[2] = market3.getMediumProfit();
	std::sort(messMediumProfit, messMediumProfit + 2);

	double messTotalProfit[3];
	messTotalProfit[0] = market1.getTotalProfit();
	messTotalProfit[1] = market2.getTotalProfit();
	messTotalProfit[2] = market3.getTotalProfit();
	std::sort(messTotalProfit, messTotalProfit + 2);

	std::cout << "##########\n" << "Medium profit\n" << "##########" << std::endl;

	for (int i = 2; i >= 0; --i) {
		if (messMediumProfit[i] == market1.getMediumProfit()) {
			market1.printInformationMidProfit();
		}
		else if (messMediumProfit[i] == market2.getMediumProfit()) {
			market2.printInformationMidProfit();
		}
		else {
			market3.printInformationMidProfit();
		}
	}

	std::cout << "##########\n" << "Total profit\n" << "##########" << std::endl;

	for (int i = 2; i >= 0; --i) {
		if (messTotalProfit[i] == market1.getTotalProfit()) {
			market1.printInformationTotalProfit();
		}
		else if (messTotalProfit[i] == market2.getTotalProfit()) {
			market2.printInformationTotalProfit();
		}
		else {
			market3.printInformationTotalProfit();
		}
	}
}