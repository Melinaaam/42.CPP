#include<iostream>
#include<fstream>

std::string SearchAndReplace(std::string str, std::string s1, std::string s2)
{
    size_t pos = str.find(s1);

    while(pos != std::string::npos)
    {
        if (pos == std::string::npos){
            return (NULL);
        }
        else{
            str.erase(pos, s1.length());
            str.insert(pos, s2);
        }
        pos = str.find(s1);
    }
    return (str);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return 1;
    else 
    {
        std::ifstream   openFile(av[1]);
        if(!openFile)
            return 1;
        std::string const test = av[1];
        std::string const test2 = test + ".replace";
        std::ofstream   createAndWriteFile(test2.c_str());
        if (!createAndWriteFile)
            return 1;
        
        std::string s1 = av[2];
        std::string s2 = av[3]; 
        std::string str = "";  
        while(std::getline(openFile, str))
        {
            if (s1 != s2)
                str = SearchAndReplace(str, s1, s2);
            createAndWriteFile << str << std::endl;
        }
    }
    return 0;
}
