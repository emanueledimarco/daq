////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// CYGTFeatures                                                               //
//                                                                            //
// Begin_Html <!--
/*-->

<!--*/
// --> End_Html
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

/* Generated header file containing necessary includes                        */
#include "generated/CYGTFeaturesGeneratedIncludes.h"

////////////////////////////////////////////////////////////////////////////////
/*  This header was generated by ROMEBuilder. Manual changes above the        *
 * following line will be lost next time ROMEBuilder is executed.             */
/////////////////////////////////////----///////////////////////////////////////

#include "generated/CYGWindow.h"
#include "generated/CYGAnalyzer.h"
#include "tabs/CYGTFeatures.h"
#include "generated/CYGEvent.h"
#include "TCanvas.h"
#include "TH1F.h"

// uncomment if you want to include headers of all folders
//#include "CYGAllFolders.h"


ClassImp(CYGTFeatures)

//______________________________________________________________________________
void CYGTFeatures::Init()
{

  TGVerticalFrame *fVerticalFrame = new TGVerticalFrame(this,1600,900,kVerticalFrame);

  fCanvas = new TRootEmbeddedCanvas("fCanvasFeat",this,700,300);
  Int_t wfCanvas = fCanvas->GetCanvasWindowId();
  TCanvas *c123 = new TCanvas("c123Feat", 680, 280,wfCanvas);
  fCanvas->AdoptCanvas(c123);
  fVerticalFrame->AddFrame(fCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));

  AddFrame(fVerticalFrame, new TGLayoutHints(kLHintsRight | kLHintsTop,2,2,2,2));

}

//______________________________________________________________________________
void CYGTFeatures::EndInit()
{
}

//______________________________________________________________________________
void CYGTFeatures::EventHandler()
{

  CYGEvent *event = gAnalyzer->GetEvent();
  
  fCanvas->GetCanvas()->cd();

  if(event->GetCamPictureSize() > 0){
    Picture *pic = event->GetCamPictureAt(0);
    pic->GetLightHisto()->Draw("colz");
  }

  fCanvas->GetCanvas()->Update();

}

//______________________________________________________________________________
void CYGTFeatures::MenuClicked(TGPopupMenu * /* menu */, Long_t /* param */)
{
}

//______________________________________________________________________________
void CYGTFeatures::TabSelected()
{
}

//______________________________________________________________________________
void CYGTFeatures::TabUnSelected()
{
}

