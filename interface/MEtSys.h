#ifndef HTT_MEtSys_KIT_h
#define HTT_MEtSys_KIT_h

#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TString.h>
#include <TRandom.h>
#include <TMath.h>
#include <assert.h>

namespace kit{

class MEtSys {
  
 public:
  MEtSys(TString fileName);
  ~MEtSys(){};

  void ApplyMEtSys(float metPx,
		   float metPy,
		   float genVPx,
		   float genVPy,
		   float visVPx,
		   float visVPy,
		   int njets,
		   int sysType,
		   int shiftType,
		   float & metShiftPx,
		   float & metShiftPy);

  void ShiftMEt(float metPx,
		float metPy,
		float genVPx, 
		float genVPy,
		float visVPx,
		float visVPy,
		int njets,
		int sysType,
		float sysShift,
		float & metShiftPx,
		float & metShiftPy);

  void ShiftResponseMet(float metPx,
			float metPy,
			float genVPx, 
			float genVPy,
			float visVPx,
			float visVPy,
			int njets,
			float sysShift,
			float & metShiftPx,
			float & metShiftPy);

  
  void ShiftResolutionMet(float metPx,
			  float metPy,
			  float genVPx, 
			  float genVPy,
			  float visVPx,
			  float visVPy,
			  int njets,
			  float sysShift,
			  float & metShiftPx,
			  float & metShiftPy);

  enum ProcessType{BOSON=0, EWK=1, TOP=2};
  enum SysType{Response=0, Resolution=1};
  enum SysShift{Up=0, Down=1};

 private:

  void ComputeHadRecoilFromMet(float metX,
			       float metY,
			       float genVPx, 
			       float genVPy,
			       float visVPx,
			       float visVPy,
			       float & Hparal,
			       float & Hperp);


  void ComputeMetFromHadRecoil(float Hparal,
			       float Hperp,
			       float genVPx, 
			       float genVPy,
			       float visVPx,
			       float visVPy,
			       float & metX,
			       float & metY);
  
  
  int nJetBins;
  TH1D * responseHist[3];
  float sysUnc[2][3];
  // first index : type of uncertainty 0=response, 1=resolution
  // second index  : jet multiplicity bin (0,1,2);

};
}

#endif
