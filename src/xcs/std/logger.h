#ifndef XCS_LOGGER_H
#define XCS_LOGGER_H
#include <ctime> 
#include <fstream>
#include <iterator>


class Logger{

public:

std::vector<std::string> records;
  

Logger()
{
    // the constructor, doesn't currently need to do anything, we can just
  //have it set the size of our vector
  
  records.resize(0);
}

 //  Writes the logs to local file
 void write()
 {
   FILE* file;

   file = fopen("xcs.log", "w");

    for (unsigned long i = 0; i < records.size(); ++i) 
      fprintf(file, "%s\n", records[i].c_str());

   fclose(file);
 }
 void write(std::string fileName)
 {
   std::ofstream f(fileName);
   for(std::vector<std::string>::const_iterator i = records.begin(); i != records.end(); ++i) 
    {
      f << *i << '\n';
    }
    f.close();

 }
 void log(char urgency, std::string category, std::string message){
    std::string record ="";
    std::string _urgency;

      switch(urgency)
      {
        case 'v':
        case 'V':
          _urgency = "VERBOSE";
          break;
        case 'd':
        case 'D':
          _urgency = "DEBUG";
          break;
        case 'e':
        case 'E':
          _urgency = "ERROR";
          break; 
        case 'c':
        case 'C':
          _urgency = "CRITICAL";
          break;
        default:
          //  Do Nothing
          break;
      }

      std::time_t myTime = time(NULL); 
      std:: string time = ctime(&myTime);
      time.pop_back();
      time = removeDay(time);
      
    record+= "[" + time + "][" + _urgency + "]" + category + ": "+ message;
    
    records.push_back(record);
 }
 void log(std::string urgency, std::string category, std::string message){
    std::string record ="";

      std::time_t myTime = time(NULL); 
      std:: string time = ctime(&myTime);
      time.pop_back();
      time = removeDay(time);
      
    record+= "[" + time + "][" + getFirstChar(urgency) + "]" + category + ": "+ message;
    
    records.push_back(record);
 }

 char getFirstChar(std::string word)
 {
   if(word.size()>0)
   return word[0];
   return'*';
 }
std::string removeDay(std::string date)
{
  return date.erase(0,4);
}

//  Test function for printing contents of the logs
void printLogs()
{
 for(std::vector<std::string>::const_iterator i = records.begin(); i != records.end(); ++i) 
    {
     // std::cout<< *i << '\n';
    }

    if(records.size()==0)
    {
        //std::cout<<" sorry nothing to print\n";
    }
}
~Logger(){}
};


#endif