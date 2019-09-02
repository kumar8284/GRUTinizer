#ifndef __TGRUTUTILITIES_H_
#define __TGRUTUTILITIES_H_

#include <fstream>
#include <string>
#include <vector>

#include "TGRUTTypes.h"

bool file_exists(const char *filename);
bool all_files_exist(const std::vector<std::string>& filenames);

std::string get_short_filename(std::string filename);
std::string get_run_number(std::string input);

EColor FindColor(std::string);

void CalculateParameters();

inline size_t FindFileSize(const char* fname) {
  std::ifstream temp;
  temp.open(fname, std::ios::in | std::ios::ate);
  size_t fsize = temp.tellg();
  temp.close();
  return fsize;
}

std::vector<std::string> glob(const std::string& pattern);
bool is_bash_pattern(const std::string& pattern);
std::vector<int> MakeVectorFromFile(const char *fname);

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);

int count_newlines(const std::string& str);

#endif
