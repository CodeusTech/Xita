#ifndef LOGGER_H
#define LOGGER_H
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
 void write()
 {
   std::ofstream f("logs.txt");
    for(std::vector<std::string>::const_iterator i = records.begin(); i != records.end(); ++i) 
    {
      f << *i << '\n';
    }
    f.close();
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

      std::time_t myTime = time(NULL); 
      std:: string time = ctime(&myTime);
      time.pop_back();
      time = removeDay(time);
      
    record+= "[" + time + "][" + urgency + "]" + category + ": "+ message;
    
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