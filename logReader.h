#include<string>
#include<iostream>

class logReader 
{

    public:         
        std::string logReader::getBaseDir();
        std::string logReader::getMachSer(int machId);
        std::string logReader::getMachName(int machId);
        void setMacInfo(int machId, std::string MachSerNo, std::string MachName);

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