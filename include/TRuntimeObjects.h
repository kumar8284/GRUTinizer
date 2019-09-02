#ifndef _RUNTIMEOBJECTS_H_
#define _RUNTIMEOBJECTS_H_

#include <string>
#include <map>
#include <cmath>

#include "TCutG.h"
#include "TDirectory.h"
#include "TList.h"

#include "TUnpackedEvent.h"

class TH1;
class TH2;
class TFile;
class TProfile;

class GH1D;
class GH2D;
class TDetector;

/// Object passed to the online histograms.
/**
   For each event, an instance of this type will be passed to the custom histogrammer.
   This class contains all detectors present, and all existing cuts and histograms.
 */
class TRuntimeObjects : public TNamed {
public:
  /// Constructor
  TRuntimeObjects(TUnpackedEvent *detectors,
                  TList* objects,
                  TList* gates,
                  std::vector<TFile*>& cut_files,
                  TDirectory* directory=NULL,
                  const char *name="default");
  TRuntimeObjects(TList* objects,
                  TList* gates,
                  std::vector<TFile*>& cut_files,
                  TDirectory* directory=NULL,
                  const char *name="default");

  /// Returns a pointer to the detector of type T
  template<typename T>
  T* GetDetector(){
    return detectors->GetDetector<T>();
  }
  TDetector *GetDetector(std::string dname) const { 
    return detectors->GetDetector(dname);
  }

  TCutG* GetCut(const std::string& name);

  TList& GetObjects();
  TList& GetGates();

  TList* GetObjectsPtr()    { return objects;   }
  TList* GetGatesPtr()      { return gates;     }


  TH1* FillHistogram(const char* name,
                     int bins, double low, double high, double value,
                     double weight=1);
  TH2* FillHistogram(const char* name,
                     int Xbins, double Xlow, double Xhigh, double Xvalue,
                     int Ybins, double Ylow, double Yhigh, double Yvalue,
                     double weight=1);

  GH1D* InitHistogram(const char* name,const char *title,int bins, double low, double high);
  GH2D* InitHistogram(const char* name,const char *title,int Xbins, double Xlow, double Xhigh,
                                                        int Ybins, double Ylow, double Yhigh);
  GH1D* InitHistogram(const char* dir,const char* name,const char *title,int bins, double low, double high);
  GH2D* InitHistogram(const char* dir,const char* name,const char *title,int Xbins, double Xlow, double Xhigh,
                                                                        int Ybins, double Ylow, double Yhigh);
  int   FillHistogram(const char* name);
  int   FillHistogram(const char* dir,const char* name);
  
  
  
  
  
  TProfile* FillProfileHist(const char* name,
			    int Xbins, double Xlow, double Xhigh, double Xvalue,
			    double Yvalue);
  TH2* FillHistogramSym(const char* name,
			int Xbins, double Xlow, double Xhigh, double Xvalue,
			int Ybins, double Ylow, double Yhigh, double Yvalue);


  TH1* FillHistogram(const std::string& name,
                     int bins, double low, double high, double value,
                     double weight=1){
    return FillHistogram(name.c_str(),
                         bins, low, high, value,
                         weight);
  }
  TH2* FillHistogram(const std::string& name,
                     int Xbins, double Xlow, double Xhigh, double Xvalue,
                     int Ybins, double Ylow, double Yhigh, double Yvalue,
                     double weight=1) {
    return FillHistogram(name.c_str(),
                         Xbins, Xlow, Xhigh, Xvalue,
                         Ybins, Ylow, Yhigh, Yvalue,
                         weight);
  }
  TProfile* FillProfileHist(const std::string& name,
			    int Xbins, double Xlow, double Xhigh, double Xvalue,
			    double Yvalue) {
    return FillProfileHist(name.c_str(),
			   Xbins, Xlow, Xhigh, Xvalue,
			   Yvalue);
  }
  TH2* FillHistogramSym(const std::string& name,
                        int Xbins, double Xlow, double Xhigh, double Xvalue,
                        int Ybins, double Ylow, double Yhigh, double Yvalue) {
    return FillHistogramSym(name.c_str(),
                            Xbins, Xlow, Xhigh, Xvalue,
                            Ybins, Ylow, Yhigh, Yvalue);
  }
  //---------------------------------------------------------------------
  TDirectory* FillHistogram(const char* dirname,const char* name,
                            int bins, double low, double high, double value,
                            double weight=1);
  TDirectory* FillHistogram(const char* dirname,const char* name,
                            int Xbins, double Xlow, double Xhigh, double Xvalue,
                            int Ybins, double Ylow, double Yhigh, double Yvalue,
                            double weight=1);
  TDirectory* FillProfileHist(const char* dirname,const char* name,
			      int Xbins, double Xlow, double Xhigh, double Xvalue,
			      double Yvalue);
  TDirectory* FillHistogramSym(const char* dirname,const char* name,
                               int Xbins, double Xlow, double Xhigh, double Xvalue,
                               int Ybins, double Ylow, double Yhigh, double Yvalue);


  TDirectory* FillHistogram(const std::string& dirname,const std::string& name,
                            int bins, double low, double high, double value,
                            double weight=1) {
    return FillHistogram(dirname.c_str(), name.c_str(),
                         bins, low, high, value,
                         weight);
  }
  TDirectory* FillHistogram(const std::string& dirname,const std::string& name,
                            int Xbins, double Xlow, double Xhigh, double Xvalue,
                            int Ybins, double Ylow, double Yhigh, double Yvalue,
                            double weight=1) {
    return FillHistogram(dirname.c_str(), name.c_str(),
                         Xbins, Xlow, Xhigh, Xvalue,
                         Ybins, Ylow, Yhigh, Yvalue,
                         weight);
  }
  TDirectory* FillProfileHist(const std::string& dirname,const std::string& name,
			      int Xbins, double Xlow, double Xhigh, double Xvalue,
			      double Yvalue) {
    return FillProfileHist(dirname.c_str(), name.c_str(),
			   Xbins, Xlow, Xhigh, Xvalue,
			   Yvalue);
  }
  TDirectory* FillHistogramSym(const std::string& dirname,const std::string& name,
                               int Xbins, double Xlow, double Xhigh, double Xvalue,
                               int Ybins, double Ylow, double Yhigh, double Yvalue) {
    return FillHistogramSym(dirname.c_str(), name.c_str(),
                            Xbins, Xlow, Xhigh, Xvalue,
                            Ybins, Ylow, Yhigh, Yvalue);
  }


  double GetVariable(const char* name);

  static TRuntimeObjects *Get(std::string name="default") { if(fRuntimeMap.count(name)) return fRuntimeMap.at(name); return 0; }

  void SetDetectors(TUnpackedEvent *det) { detectors = det; }

private:
  static std::map<std::string,TRuntimeObjects*> fRuntimeMap;
  TUnpackedEvent *detectors;
  TList* objects;
  TList* gates;
  std::vector<TFile*>& cut_files;

  TDirectory* directory;



  ClassDef(TRuntimeObjects, 0);
};

#endif /* _RUNTIMEOBJECTS_H_ */
