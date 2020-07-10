#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FASTQ2FASTAPlugin.h"

void FASTQ2FASTAPlugin::input(std::string file) {
 inputfile = file;
}

void FASTQ2FASTAPlugin::run() {}

void FASTQ2FASTAPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "bioconvert";
myCommand += " ";
myCommand += "fastq2fasta";
myCommand += " ";
myCommand += inputfile + " ";
myCommand += outputfile + " ";
myCommand += "--force";
myCommand += " ";
 system(myCommand.c_str());
}

PluginProxy<FASTQ2FASTAPlugin> FASTQ2FASTAPluginProxy = PluginProxy<FASTQ2FASTAPlugin>("FASTQ2FASTA", PluginManager::getInstance());
