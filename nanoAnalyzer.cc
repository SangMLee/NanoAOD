#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TTreeReader.h"

inline bool MuonSelection(float mu_Pt, float mu_Eta, float mu_Iso, bool mu_Id){
  if(mu_Pt < 10 || mu_Eta > 2.4 || mu_Iso > 0.25 || !mu_Id) return false;
  else return true;
}

inline bool ElecSelection (float elec_Pt, float elec_Eta, float elec_Iso){
  if(elec_Pt < 10 || elec_Eta > 2.5 || elec_Iso > 0.15) return false;
  else return true;
}

inline bool JetSelection (float jet_Pt, float jet_Eta){
  if(jet_Pt < 30 || jet_Eta > 4.7) return false;
  else return true;
}

void nanoAnalyzer()
{
  //Reading Tree from nano file
  TFile* nanoFile = TFile::Open("/cms/scratch/tt8888tt/nanolzma_1.root", "read");
  TTreeReader r("Events", nanoFile);
  TTreeReaderValue<unsigned int> nMus(r, "nMuon");
  TTreeReaderArray<float> mu_pt(r, "Muon_pt");
  TTreeReaderArray<float> mu_eta(r, "Muon_eta");
  TTreeReaderArray<float> mu_iso(r, "Muon_pfRelIso04_all");
  TTreeReaderArray<bool>  mu_id(r, "Muon_tightId");
  TTreeReaderArray<int> mu_charge(r, "Muon_charge");
  TTreeReaderArray<float> mu_phi(r, "Muon_phi");
  TTreeReaderArray<float> mu_M(r, "Muon_mass");

  TTreeReaderValue<unsigned int> nElecs(r, "nElectron");
  TTreeReaderArray<float> elec_pt(r, "Electron_pt");
  TTreeReaderArray<float> elec_eta(r, "Electron_eta");
  TTreeReaderArray<float> elec_iso(r, "Electron_miniPFRelIso_all");

  TTreeReaderValue<unsigned int> nJets(r, "nJet");
  TTreeReaderArray<float> jet_pt(r, "Jet_pt");
  TTreeReaderArray<float> jet_eta(r, "Jet_eta");
  TTreeReaderArray<float> jet_CMVA(r, "Jet_btagCMVA");

  unsigned int Event_No = 0;
  TLorentzVector Dilep;
  TLorentzVector Mu1;
  TLorentzVector Mu2;

  unsigned int nMuon;
  std::vector<float> vMu_Pt;
  std::vector<float> vMu_Eta;
  std::vector<int> vMu_Charge;
  std::vector<bool> vMu_Id;
  std::vector<float> vMu_Phi;
  std::vector<float> vMu_M;

  unsigned int nElectron;
  std::vector<float> vElectron_Pt;
  std::vector<float> vElectron_Eta;
  
  unsigned int nJet;
  std::vector<float> vJet_Pt;
  std::vector<float> vJet_Eta;
  std::vector<float> vJet_CMVA;
  

  TFile* f = new TFile("cattreeByCpp.root", "recreate");
  TTree* All = new TTree("nEvent", "nEvent");
  TTree* Cat1 = new TTree("Cat1", "Cat1");
  TTree* Cat2 = new TTree("Cat2", "Cat2");
  TTree* Cat3 = new TTree("Cat3", "Cat3");
  TTree* Cat4 = new TTree("Cat4", "Cat4");

  All->Branch("Event_No", &Event_No, "Event_No");
  All->Branch("Dilep", "TLorentzVector", &Dilep);
  All->Branch("Mu1", "TLorentzVector", &Mu1);
  All->Branch("Mu2", "TLorentzVector", &Mu2);
  All->Branch("Mu_Pt", &vMu_Pt);
  All->Branch("Mu_Eta", &vMu_Eta);
  All->Branch("El_Pt", &vElectron_Pt);
  All->Branch("El_Eta", &vElectron_Eta);
  All->Branch("Jet_Pt", &vJet_Pt);
  All->Branch("Jet_Eta", &vJet_Eta);
  
  Cat1->Branch("Event_No", &Event_No, "Event_No");
  Cat1->Branch("Dilep", "TLorentzVector", &Dilep);
  Cat1->Branch("Mu1", "TLorentzVector", &Mu1);
  Cat1->Branch("Mu2", "TLorentzVector", &Mu2);
  Cat1->Branch("Mu_Pt", &vMu_Pt);
  Cat1->Branch("Mu_Eta", &vMu_Eta);
  Cat1->Branch("El_Pt", &vElectron_Pt);
  Cat1->Branch("El_Eta", &vElectron_Eta);
  Cat1->Branch("Jet_Pt", &vJet_Pt);
  Cat1->Branch("Jet_Eta", &vJet_Eta);

  Cat2->Branch("Event_No", &Event_No, "Event_No");
  Cat2->Branch("Dilep", "TLorentzVector", &Dilep);
  Cat2->Branch("Mu1", "TLorentzVector", &Mu1);
  Cat2->Branch("Mu2", "TLorentzVector", &Mu2);
  Cat2->Branch("Mu_Pt", &vMu_Pt);
  Cat2->Branch("Mu_Eta", &vMu_Eta);
  Cat2->Branch("El_Pt", &vElectron_Pt);
  Cat2->Branch("El_Eta", &vElectron_Eta);
  Cat2->Branch("Jet_Pt", &vJet_Pt);
  Cat2->Branch("Jet_Eta", &vJet_Eta);

  Cat3->Branch("Event_No", &Event_No, "Event_No");
  Cat3->Branch("Dilep", "TLorentzVector", &Dilep);
  Cat3->Branch("Mu1", "TLorentzVector", &Mu1);
  Cat3->Branch("Mu2", "TLorentzVector", &Mu2);
  Cat3->Branch("Mu_Pt", &vMu_Pt);
  Cat3->Branch("Mu_Eta", &vMu_Eta);
  Cat3->Branch("El_Pt", &vElectron_Pt);
  Cat3->Branch("El_Eta", &vElectron_Eta);
  Cat3->Branch("Jet_Pt", &vJet_Pt);
  Cat3->Branch("Jet_Eta", &vJet_Eta);

  Cat4->Branch("Event_No", &Event_No, "Event_No");
  Cat4->Branch("Dilep", "TLorentzVector", &Dilep);
  Cat4->Branch("Mu1", "TLorentzVector", &Mu1);
  Cat4->Branch("Mu2", "TLorentzVector", &Mu2);
  Cat4->Branch("Mu_Pt", &vMu_Pt);
  Cat4->Branch("Mu_Eta", &vMu_Eta);
  Cat4->Branch("El_Pt", &vElectron_Pt);
  Cat4->Branch("El_Eta", &vElectron_Eta);
  Cat4->Branch("Jet_Pt", &vJet_Pt);
  Cat4->Branch("Jet_Eta", &vJet_Eta);

  while(r.Next())
  {
    //Initialize values
    vMu_Pt.clear();
    vMu_Eta.clear();
    vMu_Charge.clear();
    vMu_Id.clear();
    vMu_Phi.clear();
    vMu_M.clear();

    vElectron_Pt.clear();
    vElectron_Eta.clear();
    
    vJet_Pt.clear();
    vJet_Eta.clear();
    vJet_CMVA.clear();

    nMuon = 0;
    nElectron = 0;
    nJet = 0;
    
    for(int i = 0; i < *nMus; i++)
    {
      if(MuonSelection(mu_pt[i], mu_eta[i], mu_iso[i], mu_id[i]))
      {
        vMu_Pt.push_back(mu_pt[i]);
        vMu_Eta.push_back(mu_eta[i]);
        vMu_Charge.push_back(mu_charge[i]);
        vMu_Phi.push_back(mu_phi[i]);
        vMu_M.push_back(mu_M[i]);
        nMuon++;
      }
    }
    if (nMuon < 2) continue;

    for(int i = 0; i < *nElecs; i++)
    {
      if(ElecSelection(elec_pt[i], elec_eta[i], elec_iso[i]))
      {
        vElectron_Pt.push_back(elec_pt[i]);
        vElectron_Eta.push_back(elec_eta[i]);
        nElectron++;
      }
    }

    for(int i = 0; i < *nJets; i++)
    {
      if(JetSelection(jet_pt[i], jet_eta[i]))
      {
        vJet_Pt.push_back(jet_pt[i]);
        vJet_Eta.push_back(jet_eta[i]);
        vJet_CMVA.push_back(jet_CMVA[i]);
        nJet++;
      }
    }

    bool Charge = false;
    for(int i = 1; i < nMuon; i++)
    {
      if (vMu_Charge[0] * vMu_Charge[i] < 0)
      {
        Mu1.SetPtEtaPhiM(vMu_Pt[0], vMu_Eta[0], vMu_Phi[0], vMu_M[0]);
        Mu2.SetPtEtaPhiM(vMu_Pt[i], vMu_Eta[i], vMu_Phi[i], vMu_M[i]);
        Charge = true;
        break;
      }
    }
    if(!Charge) continue;
    Dilep = Mu1 + Mu2;

    Event_No = 1;

    //CATEGORY

    // Category 1 : 1 Electron
    if (nElectron == 1)
    {
      if(nMuon > 2) continue;
      else Cat1->Fill();
    }

    // Category 2 : 2 Electron
    if (nElectron == 2)
    {
      if(nMuon > 2) continue;
      else Cat2->Fill();
    }
    
   
    // Category 3 : 3 Muons
    if (nMuon == 3)
    {
      if(nElectron >0) continue;
      else Cat3->Fill();
    }

    // Category 4 : 4 Muons
    if (nMuon == 4)
    {
      if(nElectron > 0) continue;
      else Cat4->Fill();
    }

    Event_No = 1;
    All->Fill();
  }
  f->Write();
  f->Close();
  return;
}