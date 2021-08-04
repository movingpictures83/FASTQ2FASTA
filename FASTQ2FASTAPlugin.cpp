#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FASTQ2FASTAPlugin.h"

bool fastqFile(std::string file) {
        int len = file.size();
     	return (file[len-5] == 'f' &&
			file[len-4] == 'a' &&
			file[len-3] == 's' &&
			file[len-2] == 't' &&
			file[len-1] == 'q');
}

void FASTQ2FASTAPlugin::input(std::string file) {
 inputfile = file;
 if (fastqFile(inputfile)){
    mode = "single";
 }
 else {
    mode = "multiple";
    std::ifstream infile(file.c_str(), std::ios::in);
    std::string singlefile, oldsingle;
    while (!infile.eof()) {
       infile >> singlefile;
       if (singlefile.size() != 0 && singlefile != oldsingle)
       fastqFiles.push_back(singlefile);
       oldsingle = singlefile;
    }
 }
}

void FASTQ2FASTAPlugin::run() {}

void FASTQ2FASTAPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 if (mode == "single") {
myCommand += "bioconvert";
myCommand += " ";
myCommand += "fastq2fasta";
myCommand += " ";
myCommand += inputfile + " ";
myCommand += outputfile + " ";
myCommand += "--force";
myCommand += " ";
 }
 else {
    myCommand += "fq2fa ";
    myCommand += "--merge --filter ";
    for (int i = 0; i < fastqFiles.size(); i++)
       myCommand += std::string(PluginManager::prefix()) + "/" + fastqFiles[i] + " ";
    myCommand += outputfile;
 }
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<FASTQ2FASTAPlugin> FASTQ2FASTAPluginProxy = PluginProxy<FASTQ2FASTAPlugin>("FASTQ2FASTA", PluginManager::getInstance());
