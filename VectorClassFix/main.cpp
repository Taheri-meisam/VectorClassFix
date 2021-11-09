#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Player (){
public:
	Player() : id{ 0 }, Name=" "  {
		Uniq_ID = "P#" + std::to_string(id);
	}
	void create_Uniq_ID(int id) {
		Uniq_ID = "P#" + std::to_string(id);
	}
	int id;
	std::string Uniq_ID;
	std::string Name;

};

class FileManage :: public Player {

public:
	string buff;
	std::fstream 1PlayerFile;
	std::string address;
	// default constructor keeps the address just in case there is no file entered 
	FileManage() {
		address = "c:\vectorfile.txt";
		if (PlayerFile.fail()) {
			PlayerFile.open(address, std::ios::in | std::ios::out | std::ios::trunc);
		}
		else {
			PlayerFile.open(address, std::ios::in | std::ios::out | std::ios::app);
		}
	}
	// Default constructor override 
	void FileMange(std::string addressIN) {
		address = addressIN;
		if (PlayerFile.fail()) {
			PlayerFile.open(address, std::ios::int | std::ios::out | std::ios::trunc);
		}
		else {
			PlayerFile.open(address, std::ios::in && std::ios::out | std::ios::app);
		}
	}
	void FileReOpen() {
		PlayerFile.open(address, std::ios::in | std::ios::out | std::ios::app);
	}
	void FileWrite(Player p) {
		try {
			if (PlayerFile.failed()) {
				throw "The file is either open or stream is broken \n";
			}
			else {
				PlayerFile.write((char*)&p, sizeof(p));
			}
		}
		catch (std::string e) {
			std::cout << e;
		}
		PlayerFile.Close();
	}
	void Fileread(std::vector<Player>& readVec) {
		PlayerFile.clear();
		PlayerFile.seekg(0);
		if (!PlayerFile.is_open()) {
			FileReOpen();
		}
		Player tempObj;
		PlayerFile.read((char*)&tempObj, sizeof(tempObj));
		readVec.push_back(tempObj);
		try {
			while (!PlayerFile.eof()) {
				PlayerFile.read((char*)&tempObj, sizeof(tempObj));
				readVec.push_back(tempObj);
			}
		}
		catch (std::exception& e) {
			e.what();
		}
		std::cout << "size of the vector " << readVec.size() << std::endl;
		PlayerFile.close();
	}
};


std::vector <Player> playerVec;

void AddPlayerGen(std::vector<Player>& Pv, int count) {

	for (int i = 0; i < count; i++) {
		Player obj;
		obj.create_Uniq_ID(i);
		Pv.push_back(obj);
	}
	for (auto i : Pv) {
		std::cout << i.Uniq_ID << std::endl;
	}
}

Player  AddPlayerman(std::vector<Player>& Pv) {
	Player obj;
	if (Pv.size() == 0) {
		obj.create_Uniq_ID(0);
		Pv.push_back(obj);
	}
	else {
		int loc = Pv.size();
		obj.create_Uniq_ID(loc);
		Pv.push_back(obj);
	}
	std::cout << "\n";
	for (auto i : Pv) {
		std::cout << i.Uniq_ID << std::endl;
	}
	return obj;
}


int main() {
	FileManage f1;
	std::vector<Player> tempPlayervec{};
	//AddPlayerGen(playerVec, 10);
	//AddPlayerman(playerVec);
	f1.FileWrite(AddPlayerman(playerVec));
	f1.Fileread(tempPlayervec);
	return 0;
}