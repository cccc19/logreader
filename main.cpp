#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
#include<algorithm>
#include<sys/stat.h>
#include"logReader.h"


logReader myReader;    //create a logReader object
                          
std::string baseDir = myReader.getBaseDir();    // get the base directory



int getResults(std::string filename);
void getDirList(std::string searchDate, std::string searchMach);

bool wayToSort(std::string i, std::string j) { return i > j; }

int main()
{
    
    myReader.getMacInfo();

    std::string searchDate;
   
    //enter main loop keep giong until user types 'q'
    do
    {
    
    std::cout << "\nEnter the date in the exact format yyyy-mm-dd  'q' to end: ";
    std::cin >> searchDate;
    
    if(searchDate == "q")
        break;
    for(int i = 0; i < myReader.getMaxMachines(); i++)
    {
        std::cout << std::endl << myReader.getMachName(i) << std::endl;
        getDirList(searchDate, myReader.getMachSer(i));
    }
    } while(searchDate != "q");

    return 0;
}

void getDirList(std::string searchDate, std::string searchMach)
{
    std::string str = "H192124";
    std::string str2 = searchDate;
    
    std::string str3 = "GeometryCheckTemplate6x";
    
    std::size_t found; 
    
    std::string line[11350];   // Create enough storage for all rows generated by search   

    std::filesystem::directory_iterator dirToShow(baseDir);  // create directory object using basePath
    int i = 0;
    
    for (const auto& part : dirToShow) // get each element (directory) and stick it in 'part' which has type path(). Run through full list from directory
    {
        
        line[i] = part.path().string();  //convert path type to a sting type and stick it in array line[]. 
     
        found = line[i].find(searchMach);
        if (found!=std::string::npos)
        {
           
            line[i].append("/MPCChecks");
            std::filesystem::directory_iterator dirSub1ToShow(line[i]);  // create directory object using basePath
         
            std::string linesub1[11350];
            int j = 0;
            for (const auto& part1 : dirSub1ToShow) // get each element (directory) and stick it in 'part1' which has type path().
            {
                linesub1[j] = part1.path().string();
                found = linesub1[j].find(str2);
                if (found!=std::string::npos)
                {                    
                    found = linesub1[j].find(str3);
                    if (found!=std::string::npos)
                    {
                        std::string filename = linesub1[j] += "\\Results.csv";
                        
                      
                        if(std::filesystem::exists(filename))
                        {                                                     
                            getResults(filename);     // get the results from the file                      
                        }
                        
                        j++;
                    }
                }
            }
    
        }
        i++;
    }  
   
}


int getResults(std::string filename)
{
    std::string line;
    std::string str = "MLCBacklashLeaf";
    std::string str2 = "Marginal";
    std::string str3 = "CollimationGroup/MLCBacklashGroup/MLCBacklash";
    std::string str4 = "/MLCBacklash";

    
    std::replace(filename.begin(),filename.end(),'/','\\');   // Fixes Slashes in file name so they all point correct way for MicroSoft.. and add escape for c++ strings
    
    
  
    std::ifstream infile;
    std::vector<std::string> leafFile;
    std::size_t found;

    infile.open(filename);
   
    if (!infile)
    {
        std::cout << "\nUnable to open file\nor No file found for this MPC check\n\n";
        
        return 1;
    }

    

    std::cout << "\nMPC Check\n";
    std::cout << filename << "\n";
    std::cout << "Leaves with poor backlash: \n\n";

    while (!infile.eof() )
    {
        std::getline(infile, line);
        found = line.find(str);
        if (found!=std::string::npos){
            line.replace(line.find(str3),str3.length(),"");  //Tidy up the output
            line.replace(line.find(str4),str4.length()," "); //Tidy up the output
            std::cout << line << '\n';
            leafFile.push_back(line);
            myReader.putmlcData(line);

            /*found = line.find(str2);
            if (found!=std::string::npos){
                
                line.replace(line.find(str3),str3.length(),"");  //Tidy up the output
                line.replace(line.find(str4),str4.length()," "); //Tidy up the output
                std::cout << line << '\n';
               
            }*/
           
        }
    }
 /*   std::sort(leafFile.begin(), leafFile.end(), wayToSort);
    for(int i = 0;i <= 10;++i)
        std::cout << leafFile[i] << std::endl;*/
    std::cout << "MPC Check END\n\n";
    infile.close();
    return 0;
}

