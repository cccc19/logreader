#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>

class logReader 
{

    public:         
        std::string logReader::getBaseDir();     
        std::string logReader::getMachSer(int machId);
        std::string logReader::getMachName(int machId);
        int setMacInfo(int machId, std::string MachSerNo, std::string MachName);
        int logReader::getMaxMachines();
        int getMacInfo();

    private:
        std::string basedir = "\\\\aria-data\\Va_Transfer\\TDS\\";
        static const int MAX_MACHINES = 3;
        struct machInfoType {
            std::string MachSerNo;
            std::string MachName;
        } ;
        machInfoType machInfo[MAX_MACHINES];  // Struct to hold 
};