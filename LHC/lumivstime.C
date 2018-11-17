{
  TCanvas* c1 = new TCanvas();
  TF1* lumi = new TF1("Luminosity","[0]/(([0]*[1]*[4]/([3]*[2])*0.036*x+1)*([0]*[1]*[4]/([3]*[2])*0.036*x+1))",0.,13.75);
  lumi->SetTitle("Luminosity vs time");
  lumi->SetParNames("L^{0}","#sigma_{tot}","N_{p_{bunch}}","N_{bunches}","N_{int}");
  lumi->SetNpx(200);
  lumi->SetParameter(0,20.); 
  lumi->SetParameter(1,100);
  lumi->SetParameter(2,1.1);
  lumi->SetParameter(3,2544);
  lumi->SetParameter(4,2);
  lumi->GetXaxis()->SetTitle("time (hours)");
  lumi->GetYaxis()->SetTitle("luminosity (10^{33} cm^{-2}s^{-1})");
  lumi->GetYaxis()->SetRangeUser(0,lumi->GetParameter(0)*1.2);
  TList labels;
  TLatex* t1 = new TLatex(8,19,TString::Format("%s = %3.0f mb",lumi->GetParName(1),lumi->GetParameter(1)));
  TLatex* t2 = new TLatex(8,18,TString::Format("%s = %3.0f #times 10^{33} cm^{-2}s^{-1}",lumi->GetParName(0),lumi->GetParameter(0)));
  TLatex* t3 = new TLatex(8,17,TString::Format("%s = %3.1f #times 10^{11} protons",lumi->GetParName(2),lumi->GetParameter(2)));
  TLatex* t4 = new TLatex(8,16,TString::Format("%s = %3.0f",lumi->GetParName(3),lumi->GetParameter(3)));
  TLatex* t5 = new TLatex(8,15,TString::Format("%s = %3.0f",lumi->GetParName(4),lumi->GetParameter(4)));
  labels.Add(t1);
  labels.Add(t2);
  labels.Add(t3);
  labels.Add(t4);
  labels.Add(t5);
  t1->SetTextSize(.03);
  t2->SetTextSize(.03);
  t3->SetTextSize(.03);
  t4->SetTextSize(.03);
  t5->SetTextSize(.03);
  lumi->Draw();
  labels.Draw();
  c1->Print("lumivstime.png");
  
}
