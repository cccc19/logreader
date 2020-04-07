#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<filesystem>

class logReader 
{

    public:
        logReader::logReader();        
        std::string logReader::getBaseDir();     
        std::string logReader::getMachSer(int machId);
        std::string logReader::getMachName(int machId);
        int setMacInfo(int machId, std::string MachSerNo, std::string MachName);
        int logReader::getMaxMachines();
        int getMacInfo();

    private:
        std::string basedir = "\\\\aria-file01
        \\Va_Transfer\\TDS\\";
        int MAX_MACHINES;
        struct machInfoType {
            std::string MachSerNo;
            std::string MachName;
        } ;
       // Struct to hold the list of machines from settings.inf created as a vector. Size set in Constrctor. 
        std::vector<struct machInfoType> machInfo;
};