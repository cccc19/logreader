#include"logReader.h"

std::string logReader::getBaseDir() { return basedir; }
std::string logReader::getMachSer(int machId) { 
    std::string Ser = machInfo[machId].MachSerNo;
    return Ser; }
std::string logReader::getMachName(int machId) { 
    std::string Name = machInfo[machId].MachName;
    return Name; }
    
int logReader::setMacInfo(int machId, std::string MachSerNo, std::string MachName)
{
    // std::string filename = ".\\settings.inf";
    // std::ifstream infile;
    // std::size_t found;

    // infile.open(filename);
    // if (!infile)
    // {
    //     std::cout << "\nUnable to open file\nor No file found for this MPC check\n\n";
        
    //     return 0;
    // }
    machInfo[0].MachSerNo = "H192124";
    machInfo[0].MachName = "Edge1"; 
    machInfo[1].MachSerNo = "H192435";
    machInfo[1].MachName = "Edge2";
    machInfo[2].MachSerNo = "H193860";
    machInfo[2].MachName = "VT5";
    return 0;
}