#include"logReader.h"

std::string logReader::getBaseDir() { return basedir; }
std::string logReader::getMachSer(int machId) { 
    std::string Ser = machInfo[machId].MachSerNo;
    return Ser; }
std::string logReader::getMachName(int machId) { 
    std::string Name = machInfo[machId].MachName;
    return Name; }
int logReader::getMaxMachines() { return MAX_MACHINES; }

logReader::logReader()  // Constructor
{
    std::string filename = "settings.inf";
    std::ifstream infile;
    std::string line;
    infile.open(filename, std::ios::in);
    if (!infile)
    {
        std::cout << "\nCant find settings.inf\n\n";
        exit(1);
    }
    MAX_MACHINES = 0;
    while (std::getline(infile, line))
    {
        // Create space for the list of machines
        machInfo.push_back(machInfoType());
        MAX_MACHINES++;  // Add 1 to MAX_MACHINES for each line in settings.inf
    }
    infile.close();
}
// TODO Fix write machine info to settings file   
int logReader::setMacInfo(int machId, std::string MachSerNo, std::string MachName)
{
    std::string filename = "settings.inf";
    std::ofstream outfile;
    outfile.open(filename, std::ios::out);
    if (!outfile)
    {
        std::cout << "\nCant find settings.inf\n\n";
        
        return 1;
    }
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
    // Read settings.inf file and load machine id's into array.
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
    std::cout << getMaxMachines() << " Machines found in settings.inf\n";
    infile.close();

    return 0;
}