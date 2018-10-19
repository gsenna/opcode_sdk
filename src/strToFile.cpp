/*
    Copyright (C) 2018 Rory Walsh

    You should have received a copy of the GNU Lesser General Public
    License along with Csound; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
    02110-1301 USA
 */

#include <plugin.h>
#include <string>
#include <vector>
#include <modload.h>
#include <iostream>
#include <fstream>

//removes a number of occurrences of one string from another
struct StrToFile : csnd::Plugin<1, 2> 
{  
  int init() 
  {
    return parseStringAndFillStruct(this);
  }

  int kperf() 
  {
    return parseStringAndFillStruct(this);
  }

  int parseStringAndFillStruct(Plugin* opcodeData)
  {

    if (opcodeData->in_count()<3)
    {
        csound->message("You did not pass have enough arguments to strtofile\n");
        return NOTOK;
    }

    char* fileName = opcodeData->inargs.str_data(1).data;
    char* inString = opcodeData->inargs.str_data(2).data;
    int mode = opcodeData->inargs[0];
    std::ofstream fileStream;
    if (mode == 0)
        fileStream.open ("example.txt", std::ios::in|std::ios::trunc);
    else
        fileStream.open ("example.txt", std::ios::in|std::ios::app);

    fileStream << inString;
    fileStream.close();

    return OK;
  }
};
  
void csnd::on_load(Csound *csound) 
{
  csnd::plugin<StrToFile>(csound, "strremove.ii", "S", "SSo", csnd::thread::i);
}

