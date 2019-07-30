#include"logReader.h"

std::string logReader::getBaseDir() { return basedir; }
std::string logReader::getMachSer(int machId) { 
    std::string Ser = machInfo[machId].MachSerNo;
    return Ser; }
std::string logReader::getMachName(int machId) { 
    std::string Name = machInfo[machId].MachName;
    return Name; }


// TODO Fix write machine info to settings file   
int logReader::setMacInfo(int machId, std::string MachSerNo, std::string MachName)
{
    std::string filename = "settings.inf";
    std::ofstream outfile;
    outfile.open(filename, std::ios::out);
    // std::size_t found;
    // infile.open(filename);
    // if (!infile)
    // {
    //     std::cout << "\nUnable to open file\or No file found for this MPC check\n\n";
        
    //     return 0;
    // }
    machInfo[0].MachSerNo = "H192124";
    machInfo[0].MachName = "Edge1"; 
    machInfo[1].MachSerNo = "H192435";
    machInfo[1].MachName = "Edge2";
    machInfo[2].MachSerNo = "H193860";
    machInfo[2].MachName = "VT5";
    //outfile << "10\n";
    outfile << machInfo[0].MachSerNo << " ";
    outfile << machInfo[0].MachName << "\n";

    outfile.close();

    return 0;
}


int logReader::getMacInfo()  //TODO Fix file read
{
    std::string filename = "settings.inf";
    std::ifstream infile;
    std::string serNum, machName;
    infile.open(filename, std::ios::in);
    // std::string numberOfMachines;
    // infile >> numberOfMachines;
    // std::cout << numberOfMachines << "\n";
    // int maxMachines = std::stoi(numberOfMachines);
    int i = 0;

    while (infile >> serNum >> machName)
    {
        std::cout << serNum << " " << machName << "\n";
        machInfo[i].MachSerNo = serNum;
        machInfo[i].MachName = machName; 
        i++;
    }

    infile.close();

    return 0;
}