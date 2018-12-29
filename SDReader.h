#include <SPI.h>
#include <SD.h>

#define fname "database.txt"
#define CHIPSELECT 10

class SDReader
{
  private:
    
  public:
    SDReader();
    void SD_init();
    void testPrint();
  
};
