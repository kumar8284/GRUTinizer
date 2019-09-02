#include "TGlobRawFile.h"

#include "TGRUTUtilities.h"
#include <algorithm>

namespace {
  const std::chrono::system_clock::duration time_between_checks =
    std::chrono::seconds(10);
}

TGlobRawFile::TGlobRawFile(std::string pattern, kFileType file_type)
  : fPattern(pattern), fFileType(file_type),
    fPreviousCheck(std::chrono::system_clock::now() - 2*time_between_checks) {
  // bug fix for when glob is launched from a script
  fPattern.erase(std::remove_if(fPattern.begin(), fPattern.end(), [](char c) { return c == '"'; }),fPattern.end());
}

void TGlobRawFile::CheckForFiles() {
  auto now = std::chrono::system_clock::now();
  auto time_since_check = now - fPreviousCheck;
  if(time_since_check < time_between_checks){
    return;
  }
  for(auto& filename : glob(fPattern)) {
    if(fFilesAdded.count(filename) == 0) {
      auto new_file = TRawEventSource::EventSource(filename.c_str(),
                                                   true, false, fFileType);
      fWrapped.AddFile(new_file);
      fFilesAdded.insert(filename);
    }
  }

  fPreviousCheck = now;
}
