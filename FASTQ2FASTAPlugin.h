#ifndef FASTQ2FASTAPLUGIN_H
#define FASTQ2FASTAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class FASTQ2FASTAPlugin : public Plugin
{
public: 
 std::string toString() {return "FASTQ2FASTA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> fastqFiles;
 std::string mode;
};

#endif
