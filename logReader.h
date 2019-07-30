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
        int getMacInfo();

    private:
        std::string basedir = "\\\\aria-data\\Va_Transfer\\TDS\\";
        struct machInfoType {
            std::string MachSerNo;
            std::string MachName;
        } ;
        machInfoType machInfo[10];
        //struct machInfo[0].MachName = {"Edge1"};
        //machInfo[0].MachSerNo = "H192124";
        //machInfo[0].MachName = "Edge1"; 
        
        
        //struct machInfoType machInfo;
};